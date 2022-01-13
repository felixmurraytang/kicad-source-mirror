/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2018 Jean-Pierre Charras jp.charras at wanadoo.fr
 * Copyright (C) 1992-2021 KiCad Developers, see AUTHORS.txt for contributors.
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

#ifndef PCB_SHAPE_H
#define PCB_SHAPE_H

#include <board_item.h>
#include <eda_shape.h>


class LINE_READER;
class EDA_DRAW_FRAME;
class FOOTPRINT;
class MSG_PANEL_ITEM;


class PCB_SHAPE : public BOARD_ITEM, public EDA_SHAPE
{
public:
    PCB_SHAPE( BOARD_ITEM* aParent, KICAD_T idtype, SHAPE_T shapetype );

    PCB_SHAPE( BOARD_ITEM* aParent = NULL, SHAPE_T shapetype = SHAPE_T::SEGMENT );

    // Do not create a copy constructor & operator=.
    // The ones generated by the compiler are adequate.

    ~PCB_SHAPE();

    static inline bool ClassOf( const EDA_ITEM* aItem )
    {
        return aItem && PCB_SHAPE_T == aItem->Type();
    }

    wxString GetClass() const override
    {
        return wxT( "PCB_SHAPE" );
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

    void    SetPosition( const VECTOR2I& aPos ) override { setPosition( aPos ); }
    VECTOR2I GetPosition() const override { return getPosition(); }

    VECTOR2I GetCenter() const override { return getCenter(); }

    bool HasLineStroke() const override { return true; }

    STROKE_PARAMS GetStroke() const override { return m_stroke; }
    void SetStroke( const STROKE_PARAMS& aStroke ) override { m_stroke = aStroke; }

    /**
     * Allows items to return their visual center rather than their anchor. For some shapes this
     * is similar to GetCenter(), but for unfilled shapes a point on the outline is better.
     */
    const VECTOR2I GetFocusPosition() const override;

    /**
     * Return the parent footprint or NULL if PCB_SHAPE does not belong to a footprint.
     *
     * @return the parent footprint or NULL.
     */
    FOOTPRINT* GetParentFootprint() const;

    /**
     * Make a set of SHAPE objects representing the PCB_SHAPE.  Caller owns the objects.
     */
    std::shared_ptr<SHAPE> GetEffectiveShape( PCB_LAYER_ID aLayer = UNDEFINED_LAYER ) const override;

    void GetMsgPanelInfo( EDA_DRAW_FRAME* aFrame, std::vector<MSG_PANEL_ITEM>& aList ) override;

    const EDA_RECT GetBoundingBox() const override { return getBoundingBox(); }

    bool HitTest( const VECTOR2I& aPosition, int aAccuracy = 0 ) const override
    {
        return hitTest( aPosition, aAccuracy );
    }

    bool HitTest( const EDA_RECT& aRect, bool aContained, int aAccuracy = 0 ) const override
    {
        return hitTest( aRect, aContained, aAccuracy );
    }

    virtual void Move( const VECTOR2I& aMoveVector ) override;

    virtual void Rotate( const VECTOR2I& aRotCentre, const EDA_ANGLE& aAngle ) override;

    virtual void Flip( const VECTOR2I& aCentre, bool aFlipLeftRight ) override;

    void Scale( double aScale );

    /**
     * Convert the shape to a closed polygon.
     *
     * Used in filling zones calculations.  Circles and arcs are approximated by segments.
     *
     * @param aCornerBuffer is a buffer to store the polygon.
     * @param aClearanceValue is the clearance around the pad.
     * @param aError is the maximum deviation from a true arc.
     * @param aErrorLoc whether any approximation error shoule be placed inside or outside
     * @param ignoreLineWidth is used for edge cut items where the line width is only
     *        for visualization
     */
    void TransformShapeWithClearanceToPolygon( SHAPE_POLY_SET& aCornerBuffer,
                                               PCB_LAYER_ID aLayer, int aClearanceValue,
                                               int aError, ERROR_LOC aErrorLoc,
                                               bool ignoreLineWidth = false ) const override;

    virtual wxString GetSelectMenuText( EDA_UNITS aUnits ) const override;

    virtual BITMAPS GetMenuImage() const override;

    virtual EDA_ITEM* Clone() const override;

    virtual const BOX2I ViewBBox() const override;

    virtual void SwapData( BOARD_ITEM* aImage ) override;

    struct cmp_drawings
    {
        bool operator()( const BOARD_ITEM* aFirst, const BOARD_ITEM* aSecond ) const;
    };

#if defined(DEBUG)
    void Show( int nestLevel, std::ostream& os ) const override { ShowDummy( os ); }
#endif

protected:
    double getParentOrientation() const override;
    VECTOR2I getParentPosition() const override;
};

#endif  // PCB_SHAPE_H
