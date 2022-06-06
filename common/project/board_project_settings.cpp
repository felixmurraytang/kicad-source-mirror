/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2020 Jon Evans <jon@craftyjon.com>
 * Copyright (C) 2020-2022 KiCad Developers, see AUTHORS.txt for contributors.
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

#include <functional>
#include <project/board_project_settings.h>

using namespace std::placeholders;


PARAM_LAYER_PRESET::PARAM_LAYER_PRESET( const std::string& aPath,
                                        std::vector<LAYER_PRESET>* aPresetList ) :
        PARAM_LAMBDA<nlohmann::json>( aPath,
                                      std::bind( &PARAM_LAYER_PRESET::presetsToJson, this ),
                                      std::bind( &PARAM_LAYER_PRESET::jsonToPresets, this, _1 ),
                                      {} ),
        m_presets( aPresetList )
{
    wxASSERT( aPresetList );
}


nlohmann::json PARAM_LAYER_PRESET::presetsToJson()
{
    nlohmann::json ret = nlohmann::json::array();

    for( const LAYER_PRESET& preset : *m_presets )
    {
        nlohmann::json js = {
                { "name", preset.name },
                { "activeLayer", preset.activeLayer }
        };

        nlohmann::json layers = nlohmann::json::array();

        for( PCB_LAYER_ID layer : preset.layers.Seq() )
            layers.push_back( static_cast<int>( layer ) );

        js["layers"] = layers;

        nlohmann::json renderLayers = nlohmann::json::array();

        for( GAL_LAYER_ID layer : preset.renderLayers.Seq() )
            renderLayers.push_back( static_cast<int>( layer ) );

        js["renderLayers"] = renderLayers;

        ret.push_back( js );
    }

    return ret;
}


void PARAM_LAYER_PRESET::jsonToPresets( const nlohmann::json& aJson )
{
    if( aJson.empty() || !aJson.is_array() )
        return;

    m_presets->clear();

    for( const nlohmann::json& preset : aJson )
    {
        if( preset.contains( "name" ) )
        {
            LAYER_PRESET p( preset.at( "name" ).get<wxString>() );

            if( preset.contains( "activeLayer" ) &&
                preset.at( "activeLayer" ).is_number_integer() )
            {
                int active = preset.at( "activeLayer" ).get<int>();

                if( active >= 0 && active < PCB_LAYER_ID_COUNT )
                    p.activeLayer = static_cast<PCB_LAYER_ID>( active );
            }

            if( preset.contains( "layers" ) && preset.at( "layers" ).is_array() )
            {
                p.layers.reset();

                for( const nlohmann::json& layer : preset.at( "layers" ) )
                {
                    if( layer.is_number_integer() )
                    {
                        int layerNum = layer.get<int>();

                        if( layerNum >= 0 && layerNum < PCB_LAYER_ID_COUNT )
                            p.layers.set( layerNum );
                    }
                }
            }

            if( preset.contains( "renderLayers" )
                && preset.at( "renderLayers" ).is_array() )
            {
                p.renderLayers.reset();

                for( const nlohmann::json& layer : preset.at( "renderLayers" ) )
                {
                    if( layer.is_number_integer() )
                    {
                        int layerNum = layer.get<int>();

                        if( layerNum >= GAL_LAYER_ID_START
                            && layerNum < GAL_LAYER_ID_END )
                            p.renderLayers.set( static_cast<GAL_LAYER_ID>( layerNum ) );
                    }
                }
            }

            m_presets->emplace_back( p );
        }
    }
}


PARAM_VIEWPORT::PARAM_VIEWPORT( const std::string& aPath, std::vector<VIEWPORT>* aViewportList ) :
        PARAM_LAMBDA<nlohmann::json>( aPath,
                                      std::bind( &PARAM_VIEWPORT::viewportsToJson, this ),
                                      std::bind( &PARAM_VIEWPORT::jsonToViewports, this, _1 ),
                                      {} ),
        m_viewports( aViewportList )
{
    wxASSERT( aViewportList );
}


nlohmann::json PARAM_VIEWPORT::viewportsToJson()
{
    nlohmann::json ret = nlohmann::json::array();

    for( const VIEWPORT& viewport : *m_viewports )
    {
        nlohmann::json js = {
                { "name", viewport.name },
                { "x", viewport.rect.GetX() },
                { "y", viewport.rect.GetY() },
                { "w", viewport.rect.GetWidth() },
                { "h", viewport.rect.GetHeight() }
        };

        ret.push_back( js );
    }

    return ret;
}


void PARAM_VIEWPORT::jsonToViewports( const nlohmann::json& aJson )
{
    if( aJson.empty() || !aJson.is_array() )
        return;

    m_viewports->clear();

    for( const nlohmann::json& viewport : aJson )
    {
        if( viewport.contains( "name" ) )
        {
            VIEWPORT v( viewport.at( "name" ).get<wxString>() );

            if( viewport.contains( "x" ) )
                v.rect.SetX( viewport.at( "x" ).get<double>() );

            if( viewport.contains( "y" ) )
                v.rect.SetY( viewport.at( "y" ).get<double>() );

            if( viewport.contains( "w" ) )
                v.rect.SetWidth( viewport.at( "w" ).get<double>() );

            if( viewport.contains( "h" ) )
                v.rect.SetHeight( viewport.at( "h" ).get<double>() );

            m_viewports->emplace_back( v );
        }
    }
}


PARAM_VIEWPORT3D::PARAM_VIEWPORT3D( const std::string& aPath,
                                    std::vector<VIEWPORT3D>* aViewportList ) :
        PARAM_LAMBDA<nlohmann::json>( aPath,
                                      std::bind( &PARAM_VIEWPORT3D::viewportsToJson, this ),
                                      std::bind( &PARAM_VIEWPORT3D::jsonToViewports, this, _1 ),
                                      {} ),
        m_viewports( aViewportList )
{
    wxASSERT( aViewportList );
}


nlohmann::json PARAM_VIEWPORT3D::viewportsToJson()
{
    nlohmann::json ret = nlohmann::json::array();

    for( const VIEWPORT3D& viewport : *m_viewports )
    {
        nlohmann::json js = {
                { "name", viewport.name },
                { "xx", viewport.matrix[0].x },
                { "xy", viewport.matrix[0].y },
                { "xz", viewport.matrix[0].z },
                { "xw", viewport.matrix[0].w },
                { "yx", viewport.matrix[1].x },
                { "yy", viewport.matrix[1].y },
                { "yz", viewport.matrix[1].z },
                { "yw", viewport.matrix[1].w },
                { "zx", viewport.matrix[2].x },
                { "zy", viewport.matrix[2].y },
                { "zz", viewport.matrix[2].z },
                { "zw", viewport.matrix[2].w },
                { "wx", viewport.matrix[3].x },
                { "wy", viewport.matrix[3].y },
                { "wz", viewport.matrix[3].z },
                { "ww", viewport.matrix[3].w }
        };

        ret.push_back( js );
    }

    return ret;
}


void PARAM_VIEWPORT3D::jsonToViewports( const nlohmann::json& aJson )
{
    if( aJson.empty() || !aJson.is_array() )
        return;

    m_viewports->clear();

    for( const nlohmann::json& viewport : aJson )
    {
        if( viewport.contains( "name" ) )
        {
            VIEWPORT3D v( viewport.at( "name" ).get<wxString>() );

            if( viewport.contains( "xx" ) )
                v.matrix[0].x = viewport.at( "xx" ).get<double>();

            if( viewport.contains( "xy" ) )
                v.matrix[0].y = viewport.at( "xy" ).get<double>();

            if( viewport.contains( "xz" ) )
                v.matrix[0].z = viewport.at( "xz" ).get<double>();

            if( viewport.contains( "xw" ) )
                v.matrix[0].w = viewport.at( "xw" ).get<double>();

            if( viewport.contains( "yx" ) )
                v.matrix[1].x = viewport.at( "yx" ).get<double>();

            if( viewport.contains( "yy" ) )
                v.matrix[1].y = viewport.at( "yy" ).get<double>();

            if( viewport.contains( "yz" ) )
                v.matrix[1].z = viewport.at( "yz" ).get<double>();

            if( viewport.contains( "yw" ) )
                v.matrix[1].w = viewport.at( "yw" ).get<double>();

            if( viewport.contains( "zx" ) )
                v.matrix[2].x = viewport.at( "zx" ).get<double>();

            if( viewport.contains( "zy" ) )
                v.matrix[2].y = viewport.at( "zy" ).get<double>();

            if( viewport.contains( "zz" ) )
                v.matrix[2].z = viewport.at( "zz" ).get<double>();

            if( viewport.contains( "zw" ) )
                v.matrix[2].w = viewport.at( "zw" ).get<double>();

            if( viewport.contains( "wx" ) )
                v.matrix[3].x = viewport.at( "wx" ).get<double>();

            if( viewport.contains( "wy" ) )
                v.matrix[3].y = viewport.at( "wy" ).get<double>();

            if( viewport.contains( "wz" ) )
                v.matrix[3].z = viewport.at( "wz" ).get<double>();

            if( viewport.contains( "ww" ) )
                v.matrix[3].w = viewport.at( "ww" ).get<double>();

            m_viewports->emplace_back( v );
        }
    }
}