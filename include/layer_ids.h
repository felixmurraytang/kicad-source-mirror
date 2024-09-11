/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2014 SoftPLC Corporation, Dick Hollenbeck <dick@softplc.com>
 * Copyright (C) 2010 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 2007-2023 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef LAYER_IDS_H
#define LAYER_IDS_H

#include <set>
#include <vector>
#include <bitset>
#include <stdexcept>
#include <wx/string.h>
#include <kicommon.h>


/**
 * A quick note on layer IDs:
 *
 * The layers are stored in separate enums so that certain functions can
 * take in the enums as data types and don't have to know about layers from
 * other applications.
 *
 * Layers that are shared between applications should be in the GAL_LAYER_ID enum.
 *
 * The PCB_LAYER_ID struct must start at zero for compatibility with legacy board files.
 *
 * Some functions accept any layer ID, so they start at zero (i.e. F_Cu) and go up to
 * the LAYER_ID_COUNT, which needs to be kept up-to-date if new enums are added.
 */


/**
 * This is the definition of all layers used in Pcbnew.
 *
 * The PCB layer types are fixed at value 0 through LAYER_ID_COUNT to ensure compatibility
 * with legacy board files.
 */
enum PCB_LAYER_ID: int
{
    UNDEFINED_LAYER = -1,
    UNSELECTED_LAYER = -2,

    F_Cu = 0,
    B_Cu = 2,
    In1_Cu = 4,
    In2_Cu = 6,
    In3_Cu = 8,
    In4_Cu = 10,
    In5_Cu = 12,
    In6_Cu = 14,
    In7_Cu = 16,
    In8_Cu = 18,
    In9_Cu = 20,
    In10_Cu = 22,
    In11_Cu = 24,
    In12_Cu = 26,
    In13_Cu = 28,
    In14_Cu = 30,
    In15_Cu = 32,
    In16_Cu = 34,
    In17_Cu = 36,
    In18_Cu = 38,
    In19_Cu = 40,
    In20_Cu = 42,
    In21_Cu = 44,
    In22_Cu = 46,
    In23_Cu = 48,
    In24_Cu = 50,
    In25_Cu = 52,
    In26_Cu = 54,
    In27_Cu = 56,
    In28_Cu = 58,
    In29_Cu = 60,
    In30_Cu = 62,

    F_Mask = 1,
    B_Mask = 3,

    F_SilkS = 5,
    B_SilkS = 7,
    F_Adhes = 9,
    B_Adhes = 11,
    F_Paste = 13,
    B_Paste = 15,

    Dwgs_User = 17,
    Cmts_User = 19,
    Eco1_User = 21,
    Eco2_User = 23,

    Edge_Cuts = 25,
    Margin = 27,

    B_CrtYd = 29,
    F_CrtYd = 31,

    B_Fab = 33,
    F_Fab = 35,

    Rescue = 37,

    // User definable layers.
    User_1 = 39,
    User_2 = 41,
    User_3 = 43,
    User_4 = 45,
    User_5 = 47,
    User_6 = 49,
    User_7 = 51,
    User_8 = 53,
    User_9 = 55,


    PCB_LAYER_ID_COUNT = 64
};

constexpr PCB_LAYER_ID PCBNEW_LAYER_ID_START = F_Cu;

#define MAX_CU_LAYERS       32

/**
 * Enum used during connectivity building to ensure we do not query connectivity while building
 * the database
 */
enum class FLASHING
{
    DEFAULT,                // Flashing follows connectivity
    ALWAYS_FLASHED,         // Always flashed for connectivity
    NEVER_FLASHED,          // Never flashed for connectivity
};

/// Dedicated layers for net names used in Pcbnew
enum NETNAMES_LAYER_ID: int
{

    NETNAMES_LAYER_ID_START = PCB_LAYER_ID_COUNT,

    /// Reserved space for board layer netnames

    NETNAMES_LAYER_ID_RESERVED = NETNAMES_LAYER_ID_START + PCB_LAYER_ID_COUNT,

    /// Additional netnames layers (not associated with a PCB layer)

    LAYER_PAD_FR_NETNAMES,
    LAYER_PAD_BK_NETNAMES,
    LAYER_PAD_NETNAMES,
    LAYER_VIA_NETNAMES,

    NETNAMES_LAYER_ID_END
};

/// Macro for obtaining netname layer for a given PCB layer
#define NETNAMES_LAYER_INDEX( layer )   ( static_cast<int>( NETNAMES_LAYER_ID_START ) + layer )

#define GAL_UI_LAYER_COUNT 10

/**
 *  GAL layers are "virtual" layers, i.e. not tied into design data.
 *  Some layers here are shared between applications.
 *
 *  NOTE: Be very careful where you add new layers here.  Layers up to GAL_LAYER_ID_BITMASK_END
 *  must never be re-ordered and new layers must always be added after this value, because the
 *  layers before this value are mapped to bit locations in legacy board files.
 *
 *  The values in this enum that are used to store visibility state are explicitly encoded with an
 *  offset from GAL_LAYER_ID_START, which is explicitly encoded itself. The exact value of
 *  GAL_LAYER_ID_START is not that sensitive, but the offsets should never be changed or else any
 *  existing visibility settings will be disrupted.
 */
enum GAL_LAYER_ID: int
{
    GAL_LAYER_ID_START = NETNAMES_LAYER_ID_END,

    LAYER_VIAS               = GAL_LAYER_ID_START +  0, ///< Meta control for all vias opacity/visibility
    LAYER_VIA_MICROVIA       = GAL_LAYER_ID_START +  1, ///< to draw micro vias
    LAYER_VIA_BBLIND         = GAL_LAYER_ID_START +  2, ///< to draw blind/buried vias
    LAYER_VIA_THROUGH        = GAL_LAYER_ID_START +  3, ///< to draw usual through hole vias
    LAYER_NON_PLATEDHOLES    = GAL_LAYER_ID_START +  4, ///< handle color for not plated holes (holes, not pads)
    LAYER_FP_TEXT            = GAL_LAYER_ID_START +  5,
//  LAYER_MOD_TEXT_BK deprecated                  +  6,
//  LAYER_HIDDEN_TEXT        = GAL_LAYER_ID_START +  7, ///< DEPRECATED, UNUSED SINCE 9.0. text marked as invisible
    LAYER_ANCHOR             = GAL_LAYER_ID_START +  8, ///< anchor of items having an anchor point (texts, footprints)
    LAYER_PADS_SMD_FR        = GAL_LAYER_ID_START +  9, ///< smd pads, front layer
    LAYER_PADS_SMD_BK        = GAL_LAYER_ID_START + 10, ///< smd pads, back layer
    LAYER_RATSNEST           = GAL_LAYER_ID_START + 11,
    LAYER_GRID               = GAL_LAYER_ID_START + 12,
    LAYER_GRID_AXES          = GAL_LAYER_ID_START + 13,
//  LAYER_NO_CONNECTS deprecated                  + 14, ///< show a marker on pads with no nets
    LAYER_FOOTPRINTS_FR      = GAL_LAYER_ID_START + 15, ///< show footprints on front
    LAYER_FOOTPRINTS_BK      = GAL_LAYER_ID_START + 16, ///< show footprints on back
    LAYER_FP_VALUES          = GAL_LAYER_ID_START + 17, ///< show footprints values (when texts are visible)
    LAYER_FP_REFERENCES      = GAL_LAYER_ID_START + 18, ///< show footprints references (when texts are visible)
    LAYER_TRACKS             = GAL_LAYER_ID_START + 19,
    LAYER_PADS_TH            = GAL_LAYER_ID_START + 20, ///< multilayer pads, usually with holes
    LAYER_PAD_PLATEDHOLES    = GAL_LAYER_ID_START + 21, ///< to draw pad holes (plated)
    LAYER_VIA_HOLES          = GAL_LAYER_ID_START + 22, ///< to draw via holes (pad holes do not use this layer)
    LAYER_DRC_ERROR          = GAL_LAYER_ID_START + 23, ///< layer for drc markers with SEVERITY_ERROR
    LAYER_DRAWINGSHEET       = GAL_LAYER_ID_START + 24, ///< drawingsheet frame and titleblock
    LAYER_GP_OVERLAY         = GAL_LAYER_ID_START + 25, ///< general purpose overlay
    LAYER_SELECT_OVERLAY     = GAL_LAYER_ID_START + 26, ///< currently selected items overlay
    LAYER_PCB_BACKGROUND     = GAL_LAYER_ID_START + 27, ///< PCB background color
    LAYER_CURSOR             = GAL_LAYER_ID_START + 28, ///< PCB cursor
    LAYER_AUX_ITEMS          = GAL_LAYER_ID_START + 29, ///< Auxiliary items (guides, rule, etc)
    LAYER_DRAW_BITMAPS       = GAL_LAYER_ID_START + 30, ///< to handle and draw images bitmaps

    /// This is the end of the layers used for visibility bit masks in legacy board files
    GAL_LAYER_ID_BITMASK_END = GAL_LAYER_ID_START + 31,

    // Layers in this section have visibility controls but were not present in legacy board files.

    LAYER_PADS               = GAL_LAYER_ID_START + 32, ///< Meta control for all pads opacity/visibility (color ignored)
    LAYER_ZONES              = GAL_LAYER_ID_START + 33, ///< Control for copper zone opacity/visibility (color ignored)

    LAYER_PAD_HOLEWALLS      = GAL_LAYER_ID_START + 34,
    LAYER_VIA_HOLEWALLS      = GAL_LAYER_ID_START + 35,
    LAYER_DRC_WARNING        = GAL_LAYER_ID_START + 36, ///< layer for drc markers with SEVERITY_WARNING
    LAYER_DRC_EXCLUSION      = GAL_LAYER_ID_START + 37, ///< layer for drc markers which have been individually excluded
    LAYER_MARKER_SHADOWS     = GAL_LAYER_ID_START + 38, ///< shadows for drc markers

    LAYER_LOCKED_ITEM_SHADOW = GAL_LAYER_ID_START + 39, ///< shadow layer for locked items

    LAYER_CONFLICTS_SHADOW   = GAL_LAYER_ID_START + 40, ///< shadow layer for items flagged conficting
    LAYER_SHAPES             = GAL_LAYER_ID_START + 41, ///< Copper graphic shape opacity/visibility (color ignored)

    // Add layers below this point that do not have visibility controls, so don't need explicit
    // enum values

    LAYER_DRAWINGSHEET_PAGE1,      ///< for drawingsheetEditor previewing
    LAYER_DRAWINGSHEET_PAGEn,      ///< for drawingsheetEditor previewing

    LAYER_PAGE_LIMITS,             ///< color for drawing the page extents (visibility stored in
                                   ///<   PCBNEW_SETTINGS::m_ShowPageLimits)

    /// Virtual layers for stacking zones and tracks on a given copper layer
    LAYER_ZONE_START,
    LAYER_ZONE_END = LAYER_ZONE_START + PCB_LAYER_ID_COUNT,

    /// Virtual layers for background images per board layer
    LAYER_BITMAP_START,
    LAYER_BITMAP_END = LAYER_BITMAP_START + PCB_LAYER_ID_COUNT,

    // Layers for drawing on-canvas UI
    LAYER_UI_START,
    LAYER_UI_END = LAYER_UI_START + GAL_UI_LAYER_COUNT,

    GAL_LAYER_ID_END
};

/// Use this macro to convert a GAL layer to a 0-indexed offset from LAYER_VIAS
#define GAL_LAYER_INDEX( x ) ( x - GAL_LAYER_ID_START )

/// Macros for getting the extra layers for a given board layer
#define BITMAP_LAYER_FOR( boardLayer ) ( LAYER_BITMAP_START + boardLayer )
#define ZONE_LAYER_FOR( boardLayer ) ( LAYER_ZONE_START + boardLayer )

constexpr int GAL_LAYER_ID_COUNT = GAL_LAYER_ID_END - GAL_LAYER_ID_START;

inline GAL_LAYER_ID operator++( GAL_LAYER_ID& a )
{
    a = GAL_LAYER_ID( int( a ) + 1 );
    return a;
}

inline GAL_LAYER_ID ToGalLayer( int aInteger )
{
    wxASSERT( aInteger >= GAL_LAYER_ID_START && aInteger <= GAL_LAYER_ID_END );
    return static_cast<GAL_LAYER_ID>( aInteger );
}

/// Used for via types
inline GAL_LAYER_ID operator+( const GAL_LAYER_ID& a, int b )
{
    GAL_LAYER_ID t = GAL_LAYER_ID( int( a ) + b );
    wxASSERT( t <= GAL_LAYER_ID_END );
    return t;
}


/// @brief Wraps a std::bitset
typedef std::bitset<GAL_LAYER_ID_COUNT> GAL_BASE_SET;


/// Helper for storing and iterating over GAL_LAYER_IDs
class KICOMMON_API GAL_SET : public GAL_BASE_SET
{

private:
    static constexpr int start = static_cast<int>( GAL_LAYER_ID_START );

public:
    GAL_SET() : std::bitset<GAL_LAYER_ID_COUNT>()
    {
    }

    GAL_SET( const GAL_SET& aOther ) : std::bitset<GAL_LAYER_ID_COUNT>( aOther )
    {
    }

    GAL_SET( const GAL_LAYER_ID* aArray, unsigned aCount );

    GAL_SET& set()
    {
        GAL_BASE_SET::set();
        return *this;
    }

    GAL_SET& set( int aPos, bool aVal = true )
    {
        GAL_BASE_SET::set( aPos, aVal );
        return *this;
    }

    GAL_SET& set( GAL_LAYER_ID aPos, bool aVal = true )
    {
        GAL_BASE_SET::set( static_cast<std::size_t>( aPos ) - start, aVal );
        return *this;
    }

    bool Contains( GAL_LAYER_ID aPos )
    {
        return test( static_cast<std::size_t>( aPos ) - start );
    }

    std::vector<GAL_LAYER_ID> Seq() const;

    static GAL_SET DefaultVisible();
};

/// Eeschema drawing layers
enum SCH_LAYER_ID : int
{
    SCH_LAYER_ID_START = GAL_LAYER_ID_END,

    LAYER_WIRE = SCH_LAYER_ID_START,
    LAYER_BUS,
    LAYER_JUNCTION,
    LAYER_LOCLABEL,
    LAYER_GLOBLABEL,
    LAYER_HIERLABEL,
    LAYER_PINNUM,
    LAYER_PINNAM,
    LAYER_REFERENCEPART,
    LAYER_VALUEPART,
    LAYER_FIELDS,
    LAYER_INTERSHEET_REFS,
    LAYER_NETCLASS_REFS,
    LAYER_RULE_AREAS,
    LAYER_DEVICE,
    LAYER_NOTES,
    LAYER_PRIVATE_NOTES,
    LAYER_NOTES_BACKGROUND,
    LAYER_PIN,
    LAYER_SHEET,
    LAYER_SHEETNAME,
    LAYER_SHEETFILENAME,
    LAYER_SHEETFIELDS,
    LAYER_SHEETLABEL,
    LAYER_NOCONNECT,
    LAYER_DANGLING,
    LAYER_DNP_MARKER,
    LAYER_ERC_WARN,
    LAYER_ERC_ERR,
    LAYER_ERC_EXCLUSION,
    LAYER_EXCLUDED_FROM_SIM,
    LAYER_DEVICE_BACKGROUND,
    LAYER_SHEET_BACKGROUND,
    LAYER_SCHEMATIC_GRID,
    LAYER_SCHEMATIC_GRID_AXES,
    LAYER_SCHEMATIC_BACKGROUND,
    LAYER_SCHEMATIC_CURSOR,
    LAYER_HOVERED,
    LAYER_BRIGHTENED,
    LAYER_HIDDEN,
    LAYER_NET_COLOR_HIGHLIGHT,
    LAYER_SELECTION_SHADOWS,
    LAYER_SCHEMATIC_DRAWINGSHEET,
    LAYER_SCHEMATIC_PAGE_LIMITS,
    LAYER_BUS_JUNCTION,
    LAYER_SCHEMATIC_AUX_ITEMS,
    LAYER_SCHEMATIC_ANCHOR,
    LAYER_OP_VOLTAGES,
    LAYER_OP_CURRENTS,

    SCH_LAYER_ID_END
};

#define SCH_LAYER_ID_COUNT ( SCH_LAYER_ID_END - SCH_LAYER_ID_START )

#define SCH_LAYER_INDEX( x ) ( x - SCH_LAYER_ID_START )

inline SCH_LAYER_ID operator++( SCH_LAYER_ID& a )
{
    a = SCH_LAYER_ID( int( a ) + 1 );
    return a;
}

// number of draw layers in Gerbview
#define GERBER_DRAWLAYERS_COUNT static_cast<int>( PCB_LAYER_ID_COUNT )

/// GerbView draw layers
enum GERBVIEW_LAYER_ID: int
{
    GERBVIEW_LAYER_ID_START = SCH_LAYER_ID_END,

    /// GerbView draw layers and d-code layers
    GERBVIEW_LAYER_ID_RESERVED = GERBVIEW_LAYER_ID_START + ( 2 * GERBER_DRAWLAYERS_COUNT ),

    LAYER_DCODES,
    LAYER_NEGATIVE_OBJECTS,
    LAYER_GERBVIEW_GRID,
    LAYER_GERBVIEW_AXES,
    LAYER_GERBVIEW_BACKGROUND,
    LAYER_GERBVIEW_DRAWINGSHEET,
    LAYER_GERBVIEW_PAGE_LIMITS,

    GERBVIEW_LAYER_ID_END
};

#define GERBER_DRAW_LAYER( x ) ( GERBVIEW_LAYER_ID_START + x )

#define GERBER_DCODE_LAYER( x ) ( GERBER_DRAWLAYERS_COUNT + x )

#define GERBER_DRAW_LAYER_INDEX( x ) ( x - GERBVIEW_LAYER_ID_START )


/// 3D Viewer virtual layers for color settings
enum LAYER_3D_ID : int
{
        LAYER_3D_START = GERBVIEW_LAYER_ID_END,

        LAYER_3D_BACKGROUND_BOTTOM,
        LAYER_3D_BACKGROUND_TOP,
        LAYER_3D_BOARD,
        LAYER_3D_COPPER_TOP,
        LAYER_3D_COPPER_BOTTOM,
        LAYER_3D_SILKSCREEN_BOTTOM,
        LAYER_3D_SILKSCREEN_TOP,
        LAYER_3D_SOLDERMASK_BOTTOM,
        LAYER_3D_SOLDERMASK_TOP,
        LAYER_3D_SOLDERPASTE,
        LAYER_3D_ADHESIVE,
        LAYER_3D_USER_COMMENTS,
        LAYER_3D_USER_DRAWINGS,
        LAYER_3D_USER_ECO1,
        LAYER_3D_USER_ECO2,
        LAYER_3D_TH_MODELS,
        LAYER_3D_SMD_MODELS,
        LAYER_3D_VIRTUAL_MODELS,
        LAYER_3D_MODELS_NOT_IN_POS,
        LAYER_3D_MODELS_MARKED_DNP,
        LAYER_3D_AXES,
        LAYER_3D_BOUNDING_BOXES,
        LAYER_3D_OFF_BOARD_SILK,

        LAYER_3D_END
};

/// Must update this if you add any enums after GerbView!
#define LAYER_ID_COUNT LAYER_3D_END


/**
 * Returns the string equivalent of a given layer
 * @param aLayer is a valid layer ID
 */
KICOMMON_API wxString LayerName( int aLayer );


// Some elements do not have yet a visibility control
// from a dialog, but have a visibility control flag.
// Here is a mask to set them visible, to be sure they are displayed
// after loading a board for instance
#define MIN_VISIBILITY_MASK int( ( 1 << GAL_LAYER_INDEX( LAYER_PAD_PLATEDHOLES ) ) +\
                                 ( 1 << GAL_LAYER_INDEX( LAYER_VIA_HOLES ) ) +\
                                 ( 1 << GAL_LAYER_INDEX( LAYER_SELECT_OVERLAY ) ) +\
                                 ( 1 << GAL_LAYER_INDEX( LAYER_GP_OVERLAY ) ) +\
                                 ( 1 << GAL_LAYER_INDEX( LAYER_RATSNEST ) ) )


/**
 * Test whether a given integer is a valid layer index, i.e. can
 * be safely put in a PCB_LAYER_ID
 *
 * @param aLayerId = Layer index to test. It can be an int, so its useful during I/O
 * @return true if aLayerIndex is a valid layer index
 */
inline bool IsValidLayer( int aLayerId )
{
    return unsigned( aLayerId ) < PCB_LAYER_ID_COUNT;
}

/**
 * Test whether a layer is a valid layer for Pcbnew
 *
 * @param aLayer = Layer to test
 * @return true if aLayer is a layer valid in Pcbnew
 */
inline bool IsPcbLayer( int aLayer )
{
    return aLayer >= F_Cu && aLayer < PCB_LAYER_ID_COUNT;
}

/**
 * Tests whether a layer is a copper layer.
 *
 * @param aLayerId = Layer  to test
 * @return true if aLayer is a valid copper layer
 */
inline bool IsCopperLayer( int aLayerId )
{
    return !( aLayerId & 1 ) && aLayerId <= PCB_LAYER_ID_COUNT;
}

/**
 * Test whether a layer is a non copper layer.
 *
 * @param aLayerId = Layer to test
 * @return true if aLayer is a non copper layer
 */
inline bool IsNonCopperLayer( int aLayerId )
{
    return ( aLayerId & 1 ) && aLayerId <= PCB_LAYER_ID_COUNT;
}

/**
 * Tests whether a layer is a copper layer, optionally including synthetic copper layers such
 * as LAYER_VIA_THROUGH, LAYER_PADS_SMD_FR, etc.
 *
 * @param aLayerId
 * @param aIncludeSyntheticCopperLayers
 * @return
 */
inline bool IsCopperLayer( int aLayerId, bool aIncludeSyntheticCopperLayers )
{
    if( aIncludeSyntheticCopperLayers )
        return !IsNonCopperLayer( aLayerId );
    else
        return IsCopperLayer( aLayerId );
}

inline bool IsViaPadLayer( int aLayer )
{
    return aLayer == LAYER_VIA_THROUGH
            || aLayer == LAYER_VIA_MICROVIA
            || aLayer == LAYER_VIA_BBLIND;
}

inline bool IsHoleLayer( int aLayer )
{
    return aLayer == LAYER_VIA_HOLES
            || aLayer == LAYER_VIA_HOLEWALLS
            || aLayer == LAYER_PAD_PLATEDHOLES
            || aLayer == LAYER_PAD_HOLEWALLS
            || aLayer == LAYER_NON_PLATEDHOLES;
}

/**
 * Test whether a layer is a non copper and a non tech layer.
 *
 * @param aLayerId = Layer to test
 * @return true if aLayer is a user layer
 */
inline bool IsUserLayer( PCB_LAYER_ID aLayerId )
{
    return aLayerId >= Dwgs_User && aLayerId <= Eco2_User;
}


/*
 * IMPORTANT: If a layer is not a front layer that doesn't necessarily mean it's a back layer.
 *
 * So a layer can be:
 *   - Front
 *   - Back
 *   - Neither (internal or auxiliary)
 *
 * The check most frequent is for back layers, since it involves flips.
 */

/**
 * Layer classification: check if it's a front layer
 */
inline bool IsFrontLayer( PCB_LAYER_ID aLayerId )
{
    switch( aLayerId )
    {
    case F_Cu:
    case F_Adhes:
    case F_Paste:
    case F_SilkS:
    case F_Mask:
    case F_CrtYd:
    case F_Fab:
        return true;
    default:
        ;
    }

    return false;
}


/**
 * Layer classification: check if it's a back layer
 */
inline bool IsBackLayer( PCB_LAYER_ID aLayerId )
{
    switch( aLayerId )
    {
    case B_Cu:
    case B_Adhes:
    case B_Paste:
    case B_SilkS:
    case B_Mask:
    case B_CrtYd:
    case B_Fab:
        return true;
    default:
        return false;
    }
}


/**
 * Returns true if copper aLayerA is placed lower than aLayerB, false otherwise.
 */
inline bool IsCopperLayerLowerThan( PCB_LAYER_ID aLayerA, PCB_LAYER_ID aLayerB )
{
    if( aLayerA == aLayerB )
        return false;

    if( aLayerA == B_Cu )
        return true;

    if( aLayerB == B_Cu )
        return false;

    return aLayerA > aLayerB;
}


/**
 * @return the layer number after flipping an item
 * some (not all) layers: external copper, and paired layers( Mask, Paste, solder ... )
 * are swapped between front and back sides
 * internal layers are flipped only if the copper layers count is known
 * @param aLayerId = the PCB_LAYER_ID to flip
 * @param aCopperLayersCount = the number of copper layers. if 0 (in fact if < 4 )
 *  internal layers will be not flipped because the layer count is not known
 */
KICOMMON_API PCB_LAYER_ID FlipLayer( PCB_LAYER_ID aLayerId, int aCopperLayersCount = 0 );


/**
 * Returns a netname layer corresponding to the given layer.
 */
inline int GetNetnameLayer( int aLayer )
{
    if( IsCopperLayer( aLayer ) )
        return NETNAMES_LAYER_INDEX( aLayer );
    else if( aLayer == LAYER_PADS_TH )
        return LAYER_PAD_NETNAMES;
    else if( aLayer == LAYER_PADS_SMD_FR )
        return LAYER_PAD_FR_NETNAMES;
    else if( aLayer == LAYER_PADS_SMD_BK )
        return LAYER_PAD_BK_NETNAMES;
    else if( IsViaPadLayer( aLayer ) )
        return LAYER_VIA_NETNAMES;

    // Fallback
    return Cmts_User;
}

/**
 * Test whether a layer is a netname layer.
 *
 * @param aLayer = Layer to test
 * @return true if aLayer is a valid netname layer
 */
inline bool IsNetnameLayer( int aLayer )
{
    return aLayer >= NETNAMES_LAYER_INDEX( F_Cu ) && aLayer < NETNAMES_LAYER_ID_END;
}


inline bool IsZoneFillLayer( int aLayer )
{
    return aLayer >= LAYER_ZONE_START && aLayer <= LAYER_ZONE_END;
}


inline bool IsDCodeLayer( int aLayer )
{
    return aLayer >= ( GERBVIEW_LAYER_ID_START + GERBER_DRAWLAYERS_COUNT )
            && aLayer < ( GERBVIEW_LAYER_ID_START + ( 2 * GERBER_DRAWLAYERS_COUNT ) );
}


/**
 * Checks if the given layer is "net copper", meaning it is eligible for net coloring.
 *
 * @param aLayer is the layer to test
 * @return true if the layer is one that participates in net coloring
 */
inline bool IsNetCopperLayer( int aLayer )
{
    static std::set<int> netCopperLayers =
            {
                LAYER_PADS_SMD_FR,
                LAYER_PADS_SMD_BK,
                LAYER_PADS_TH,
                LAYER_PAD_HOLEWALLS,
                LAYER_VIA_THROUGH,
                LAYER_VIA_BBLIND,
                LAYER_VIA_MICROVIA,
                LAYER_VIA_HOLEWALLS
            };

    return IsCopperLayer( aLayer ) || netCopperLayers.count( aLayer );
}


KICOMMON_API PCB_LAYER_ID ToLAYER_ID( int aLayer );

#endif // LAYER_IDS_H
