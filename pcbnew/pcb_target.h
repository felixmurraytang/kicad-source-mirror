/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2004 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 1992-2022 KiCad Developers, see AUTHORS.txt for contributors.
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

#ifndef PCB_TARGET_H
#define PCB_TARGET_H

#include <board_item.h>


class LINE_READER;


class PCB_TARGET : public BOARD_ITEM
{
public:
    PCB_TARGET( BOARD_ITEM* aParent );

    // Do not create a copy constructor.  The one generated by the compiler is adequate.

    PCB_TARGET( BOARD_ITEM* aParent, int aShape, PCB_LAYER_ID aLayer, const VECTOR2I& aPos,
                int aSize, int aWidth );

    // Do not create a copy constructor & operator=.
    // The ones generated by the compiler are adequate.

    ~PCB_TARGET();

    static inline bool ClassOf( const EDA_ITEM* aItem )
    {
        return aItem && PCB_TARGET_T == aItem->Type();
    }

    void     SetPosition( const VECTOR2I& aPos ) override { m_pos = aPos; }
    VECTOR2I GetPosition() const override { return m_pos; }

    void SetShape( int aShape )     { m_shape = aShape; }
    int GetShape() const            { return m_shape; }

    void SetSize( int aSize )       { m_size = aSize; }
    int GetSize() const             { return m_size; }

    void SetWidth( int aWidth )     { m_lineWidth = aWidth; }
    int GetWidth() const            { return m_lineWidth; }

    void Move( const VECTOR2I& aMoveVector ) override
    {
        m_pos += aMoveVector;
    }

    void Rotate( const VECTOR2I& aRotCentre, const EDA_ANGLE& aAngle ) override;

    void Flip( const VECTOR2I& aCentre, bool aFlipLeftRight ) override;

    wxString GetClass() const override
    {
        return wxT( "PCB_TARGET" );
    }

    bool HitTest( const VECTOR2I& aPosition, int aAccuracy = 0 ) const override;
    bool HitTest( const BOX2I& aRect, bool aContained, int aAccuracy = 0 ) const override;

    // Virtual function
    const BOX2I GetBoundingBox() const override;

    std::shared_ptr<SHAPE>
    GetEffectiveShape( PCB_LAYER_ID aLayer, FLASHING aFlash = FLASHING::DEFAULT ) const override;

    wxString GetSelectMenuText( UNITS_PROVIDER* aUnitsProvider ) const override;

    BITMAPS GetMenuImage() const override;

    EDA_ITEM* Clone() const override;

    virtual void SwapData( BOARD_ITEM* aImage ) override;

    void GetMsgPanelInfo( EDA_DRAW_FRAME* aFrame, std::vector<MSG_PANEL_ITEM>& aList ) override;

    /**
     * Convert the shape to a closed polygon.
     *
     * Used in filling zones calculations.  Circles and arcs are approximated by segments.
     *
     * @param aCornerBuffer is a buffer to store the polygon.
     * @param aClearanceValue is the clearance around the pad.
     * @param aError is the maximum deviation from a true arc.
     * @param aErrorLoc whether any approximation error should be placed inside or outside
     * @param ignoreLineWidth is used for edge cut items where the line width is only
     *        for visualization
     */
    void TransformShapeWithClearanceToPolygon( SHAPE_POLY_SET& aCornerBuffer,
                                               PCB_LAYER_ID aLayer, int aClearanceValue,
                                               int aError, ERROR_LOC aErrorLoc,
                                               bool ignoreLineWidth = false ) const override;

#if defined(DEBUG)
    void Show( int nestLevel, std::ostream& os ) const override { ShowDummy( os ); }
#endif

private:
    int      m_shape;            // bit 0 : 0 = draw +, 1 = draw X
    int      m_size;
    int      m_lineWidth;
    VECTOR2I m_pos;
};


#endif
