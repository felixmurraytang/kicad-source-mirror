/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2018 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 2013 Wayne Stambaugh <stambaughw@verizon.net>
 * Copyright (C) 1992-2018 KiCad Developers, see AUTHORS.txt for contributors.
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

#ifndef FP_SHAPE_H
#define FP_SHAPE_H


#include <pcb_shape.h>


class LINE_READER;
class MSG_PANEL_ITEM;


class FP_SHAPE : public PCB_SHAPE
{
public:
    FP_SHAPE( FOOTPRINT* parent, SHAPE_T aShape = SHAPE_T::SEGMENT );

    // Do not create a copy constructor & operator=.
    // The ones generated by the compiler are adequate.

    ~FP_SHAPE();

    static inline bool ClassOf( const EDA_ITEM* aItem )
    {
        return aItem && PCB_FP_SHAPE_T == aItem->Type();
    }

    bool IsType( const KICAD_T aScanTypes[] ) const override
    {
        if( BOARD_ITEM::IsType( aScanTypes ) )
            return true;

        for( const KICAD_T* p = aScanTypes; *p != EOT; ++p )
        {
            if( *p == PCB_LOCATE_GRAPHIC_T )
                return true;
            else if( *p == PCB_LOCATE_BOARD_EDGE_T )
                return m_layer == Edge_Cuts;
        }

        return false;
    }

    /**
     * Sets the angle for arcs, and normalizes it within the range 0 - 360 degrees.
     * @param aAngle is tenths of degrees, but will soon be degrees.
     */
    void SetArcAngleAndEnd0( double aAngle, bool aCheckNegativeAngle = false );

    void SetArcGeometry0( const VECTOR2I& aStart, const VECTOR2I& aMid, const VECTOR2I& aEnd );

    /**
     * Move an edge of the footprint.
     * This is a footprint shape modification.
     * (should be only called by a footprint editing function)
     */
    void Move( const VECTOR2I& aMoveVector ) override;

    /**
     * Mirror an edge of the footprint.
     * Do not change the layer
     * This is a footprint shape modification.
     * (should be only called by a footprint editing function)
     */
    void Mirror( const VECTOR2I& aCentre, bool aMirrorAroundXAxis );

    /**
     * Rotate an edge of the footprint.
     * This is a footprint shape modification.
     * (should be only called by a footprint editing function )
     */
    void Rotate( const VECTOR2I& aRotCentre, const EDA_ANGLE& aAngle ) override;

    /**
     * Flip entity relative to aCentre.
     * The item is mirrored, and layer changed to the paired corresponding layer if it is on a
     * paired layer.
     * This function should be called only from FOOTPRINT::Flip because it is not usual to flip
     * an item alone, without flipping the parent footprint (consider Mirror() instead).
     */
    void Flip( const VECTOR2I& aCentre, bool aFlipLeftRight ) override;

    bool IsParentFlipped() const;

    void            SetStart0( const VECTOR2I& aPoint ) { m_start0 = aPoint; }
    const VECTOR2I& GetStart0() const { return m_start0; }

    void            SetEnd0( const VECTOR2I& aPoint ) { m_end0 = aPoint; }
    const VECTOR2I& GetEnd0() const { return m_end0; }

    void            SetBezierC1_0( const VECTOR2I& aPoint ) { m_bezierC1_0 = aPoint; }
    const VECTOR2I& GetBezierC1_0() const { return m_bezierC1_0; }

    void            SetBezierC2_0( const VECTOR2I& aPoint ) { m_bezierC2_0 = aPoint; }
    const VECTOR2I& GetBezierC2_0() const { return m_bezierC2_0; }

    VECTOR2I GetCenter0() const;
    void    SetCenter0( const VECTOR2I& aPt );

    VECTOR2I GetArcMid0() const;

    /**
     * Set relative coordinates from draw coordinates.
     * Call in only when the geometry or the footprint is modified and therefore the relative
     * coordinates have to be updated from the draw coordinates.
     */
    void SetLocalCoord();

    /**
     * Set draw coordinates (absolute values ) from relative coordinates.
     * Must be called when a relative coordinate has changed in order to see the changes on screen
     */
    void SetDrawCoord();

    void GetMsgPanelInfo( EDA_DRAW_FRAME* aFrame, std::vector<MSG_PANEL_ITEM>& aList ) override;

    wxString GetClass() const override
    {
        return wxT( "MGRAPHIC" );
    }

    wxString GetParentAsString() const { return m_parent->m_Uuid.AsString(); }

    wxString GetSelectMenuText( EDA_UNITS aUnits ) const override;

    BITMAPS GetMenuImage() const override;

    EDA_ITEM* Clone() const override;

    double ViewGetLOD( int aLayer, KIGFX::VIEW* aView ) const override;

#if defined(DEBUG)
    void Show( int nestLevel, std::ostream& os ) const override { ShowDummy( os ); }
#endif

protected:
    VECTOR2I m_start0; ///< Start point or circle center, relative to footprint origin, orient 0.
    VECTOR2I m_end0;   ///< End point or circle edge, relative to footprint origin, orient 0.
    VECTOR2I m_arcCenter0;   ///< Center of arc, relative to footprint origin, orient 0.
    VECTOR2I m_bezierC1_0; ///< Bezier Control Point 1, relative to footprint origin, orient 0.
    VECTOR2I m_bezierC2_0;   ///< Bezier Control Point 2, relative to footprint origin, orient 0.
};

#endif    // FP_SHAPE_H
