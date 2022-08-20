/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2004 Jean-Pierre Charras, jaen-pierre.charras@gipsa-lab.inpg.com
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

#ifndef PCB_TEXTBOX_H
#define PCB_TEXTBOX_H

#include <eda_text.h>
#include <pcb_shape.h>


class LINE_READER;
class MSG_PANEL_ITEM;


class PCB_TEXTBOX : public PCB_SHAPE, public EDA_TEXT
{
public:
    PCB_TEXTBOX( BOARD_ITEM* parent );

    // Do not create a copy constructor & operator=.
    // The ones generated by the compiler are adequate.

    ~PCB_TEXTBOX();

    static inline bool ClassOf( const EDA_ITEM* aItem )
    {
        return aItem && PCB_TEXTBOX_T == aItem->Type();
    }

    bool IsType( const std::initializer_list<KICAD_T>& aScanTypes ) const override
    {
        if( BOARD_ITEM::IsType( aScanTypes ) )
            return true;

        for( KICAD_T scanType : aScanTypes )
        {
            if( scanType == PCB_LOCATE_TEXT_T )
                return true;
        }

        return false;
    }

    VECTOR2I GetTopLeft() const override;
    VECTOR2I GetBotRight() const override;

    void SetTop( int aVal ) override;
    void SetLeft( int aVal ) override;
    void SetRight( int aVal ) override;
    void SetBottom( int aVal ) override;

    int GetTextMargin() const;

    VECTOR2I GetDrawPos() const override;

    wxString GetShownText( int aDepth = 0 ) const override;

    /// PCB_TEXTBOXes are always visible:
    void SetVisible( bool aVisible ) override { /* do nothing */}
    bool IsVisible() const override { return true; }

    bool Matches( const wxFindReplaceData& aSearchData, void* aAuxData ) const override
    {
        return BOARD_ITEM::Matches( GetShownText(), aSearchData );
    }

    std::vector<VECTOR2I> GetAnchorAndOppositeCorner() const;

    void Move( const VECTOR2I& aMoveVector ) override;

    void Rotate( const VECTOR2I& aRotCentre, const EDA_ANGLE& aAngle ) override;

    void Flip( const VECTOR2I& aCentre, bool aFlipLeftRight ) override;

    void GetMsgPanelInfo( EDA_DRAW_FRAME* aFrame, std::vector<MSG_PANEL_ITEM>& aList ) override;

    bool HitTest( const VECTOR2I& aPosition, int aAccuracy ) const override;

    bool HitTest( const EDA_RECT& aRect, bool aContained, int aAccuracy = 0 ) const override;

    wxString GetClass() const override
    {
        return wxT( "PCB_TEXTBOX" );
    }

    /**
     * Function TransformTextShapeWithClearanceToPolygon
     * Convert the text to a polygonSet describing the actual character strokes (one per segment).
     * Used in 3D viewer
     * Circles and arcs are approximated by segments
     * @aCornerBuffer = SHAPE_POLY_SET to store the polygon corners
     * @aClearanceValue = the clearance around the text
     * @aError = the maximum error to allow when approximating curves
     */
    void TransformTextShapeWithClearanceToPolygon( SHAPE_POLY_SET& aCornerBuffer,
                                                   PCB_LAYER_ID aLayer, int aClearanceValue,
                                                   int aError, ERROR_LOC aErrorLoc ) const;

    void TransformShapeWithClearanceToPolygon( SHAPE_POLY_SET& aCornerBuffer, PCB_LAYER_ID aLayer,
                                               int aClearanceValue, int aError, ERROR_LOC aErrorLoc,
                                               bool aIgnoreLineWidth = false ) const override;

    // @copydoc BOARD_ITEM::GetEffectiveShape
    virtual std::shared_ptr<SHAPE> GetEffectiveShape( PCB_LAYER_ID aLayer = UNDEFINED_LAYER,
            FLASHING aFlash = FLASHING::DEFAULT ) const override;

    wxString GetSelectMenuText( EDA_UNITS aUnits ) const override;

    BITMAPS GetMenuImage() const override;

    ///< @copydoc VIEW_ITEM::ViewGetLOD
    double ViewGetLOD( int aLayer, KIGFX::VIEW* aView ) const override;

    // Virtual function
    EDA_ITEM* Clone() const override;

    virtual void SwapData( BOARD_ITEM* aImage ) override;
};

#endif  // #define PCB_TEXTBOX_H
