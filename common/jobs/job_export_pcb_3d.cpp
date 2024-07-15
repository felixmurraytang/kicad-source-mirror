/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2023 Mark Roszko <mark.roszko@gmail.com>
 * Copyright (C) 2023-2024 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <jobs/job_export_pcb_3d.h>
#include <jobs/job_registry.h>
#include <i18n_utility.h>

NLOHMANN_JSON_SERIALIZE_ENUM( JOB_EXPORT_PCB_3D::FORMAT,
                              {
                                      { JOB_EXPORT_PCB_3D::FORMAT::UNKNOWN, nullptr },
                                      { JOB_EXPORT_PCB_3D::FORMAT::STEP, "step" },
                                      { JOB_EXPORT_PCB_3D::FORMAT::BREP, "brep" },
                                      { JOB_EXPORT_PCB_3D::FORMAT::GLB, "step" },
                                      { JOB_EXPORT_PCB_3D::FORMAT::VRML, "vrml" },
                                      { JOB_EXPORT_PCB_3D::FORMAT::XAO, "xao" },
                              } )


NLOHMANN_JSON_SERIALIZE_ENUM( JOB_EXPORT_PCB_3D::VRML_UNITS,
                              {
                                      { JOB_EXPORT_PCB_3D::VRML_UNITS::INCHES, "in" },
                                      { JOB_EXPORT_PCB_3D::VRML_UNITS::METERS, "m" },
                                      { JOB_EXPORT_PCB_3D::VRML_UNITS::MILLIMETERS, "mm" },
                                      { JOB_EXPORT_PCB_3D::VRML_UNITS::TENTHS, "tenths" },
                              } )

wxString EXPORTER_STEP_PARAMS::GetDefaultExportExtension() const
{
    switch( m_Format )
    {
    case EXPORTER_STEP_PARAMS::FORMAT::STEP: return wxS( "step" );
    case EXPORTER_STEP_PARAMS::FORMAT::BREP: return wxS( "brep" );
    case EXPORTER_STEP_PARAMS::FORMAT::XAO:  return wxS( "xao" );
    case EXPORTER_STEP_PARAMS::FORMAT::GLB:  return wxS( "glb" );
    default:                                 return wxEmptyString; // shouldn't happen
    }
}


wxString EXPORTER_STEP_PARAMS::GetFormatName() const
{
    switch( m_Format )
    {
        // honestly these names shouldn't be translated since they are mostly industry standard acronyms
    case EXPORTER_STEP_PARAMS::FORMAT::STEP: return wxS( "STEP" );
    case EXPORTER_STEP_PARAMS::FORMAT::BREP: return wxS( "BREP" );
    case EXPORTER_STEP_PARAMS::FORMAT::XAO:  return wxS( "XAO" );
    case EXPORTER_STEP_PARAMS::FORMAT::GLB:  return wxS( "Binary GLTF" );
    default:                                 return wxEmptyString; // shouldn't happen
    }
}


JOB_EXPORT_PCB_3D::JOB_EXPORT_PCB_3D( bool aIsCli ) :
    JOB( "3d", false, aIsCli ),
    m_hasUserOrigin( false ),
    m_filename(),
    m_format( JOB_EXPORT_PCB_3D::FORMAT::UNKNOWN ),
    m_vrmlUnits( JOB_EXPORT_PCB_3D::VRML_UNITS::METERS ),
    m_vrmlModelDir( wxEmptyString ),
    m_vrmlRelativePaths( false )
{
    m_params.emplace_back(
            new JOB_PARAM<bool>( "overwrite", &m_3dparams.m_Overwrite, m_3dparams.m_Overwrite ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "use_grid_origin", &m_3dparams.m_UseGridOrigin,
                                                m_3dparams.m_UseGridOrigin ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "use_drill_origin", &m_3dparams.m_UseDrillOrigin,
                                                m_3dparams.m_UseDrillOrigin ) );
    m_params.emplace_back(
            new JOB_PARAM<bool>( "board_only", &m_3dparams.m_BoardOnly, m_3dparams.m_BoardOnly ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "include_unspecified",
                                                &m_3dparams.m_IncludeUnspecified,
                                                m_3dparams.m_IncludeUnspecified ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "include_dnp", &m_3dparams.m_IncludeDNP,
                                                m_3dparams.m_IncludeDNP ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "subst_models", &m_3dparams.m_SubstModels,
                                                m_3dparams.m_SubstModels ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "optimize_step", &m_3dparams.m_OptimizeStep,
                                                m_3dparams.m_OptimizeStep ) );
    m_params.emplace_back( new JOB_PARAM<double>( "user_origin.x", &m_3dparams.m_Origin.x,
                                                  m_3dparams.m_Origin.x ) );
    m_params.emplace_back( new JOB_PARAM<double>( "user_origin.y", &m_3dparams.m_Origin.y,
                                                  m_3dparams.m_Origin.y ) );
    m_params.emplace_back( new JOB_PARAM<double>( "board_outlines_chaining_epsilon",
                                                  &m_3dparams.m_BoardOutlinesChainingEpsilon,
                                                  m_3dparams.m_BoardOutlinesChainingEpsilon ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "export_board_body", &m_3dparams.m_ExportBoardBody,
                                                m_3dparams.m_ExportBoardBody ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "export_components", &m_3dparams.m_ExportComponents,
                                                m_3dparams.m_ExportComponents ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "export_tracks", &m_3dparams.m_ExportTracksVias,
                                                m_3dparams.m_ExportTracksVias ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "export_pads", &m_3dparams.m_ExportPads,
                                                m_3dparams.m_ExportPads ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "export_zones", &m_3dparams.m_ExportZones,
                                                m_3dparams.m_ExportZones ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "export_inner_copper",
                                                &m_3dparams.m_ExportInnerCopper,
                                                m_3dparams.m_ExportInnerCopper ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "export_silkscreen", &m_3dparams.m_ExportSilkscreen,
                                                m_3dparams.m_ExportInnerCopper ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "export_soldermask", &m_3dparams.m_ExportSoldermask,
                                                m_3dparams.m_ExportSoldermask ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "fuse_shapes", &m_3dparams.m_FuseShapes,
                                                m_3dparams.m_FuseShapes ) );
    m_params.emplace_back( new JOB_PARAM<wxString>( "vrml_model_dir", &m_vrmlModelDir, m_vrmlModelDir ) );
    m_params.emplace_back( new JOB_PARAM<bool>( "vrml_relative_paths", &m_vrmlRelativePaths,
                                                m_vrmlRelativePaths ) );
}


wxString JOB_EXPORT_PCB_3D::GetDescription()
{
    return wxString::Format( _( "3D model export" ) );
}

REGISTER_JOB( pcb_export_3d, _HKI( "PCB: Export 3D Model" ), KIWAY::FACE_PCB, JOB_EXPORT_PCB_3D );
