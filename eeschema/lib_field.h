/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2019 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 2004-2021 KiCad Developers, see AUTHORS.txt for contributors.
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

/**
 * @file lib_field.h
 */

#ifndef CLASS_LIBENTRY_FIELDS_H
#define CLASS_LIBENTRY_FIELDS_H

#include <eda_text.h>
#include <lib_item.h>


class SCH_LEGACY_PLUGIN_CACHE;


/**
 * Field object used in symbol libraries.  At least MANDATORY_FIELDS are always present in a
 * RAM-resident library symbol.  All constructors must ensure this because the symbol property
 * editor assumes it.
 * <p>
 * A field is a string linked to a symbol.  Unlike purely graphical text, fields can be used in
 * netlist generation and other tools (BOM).
 *
 *  The first 4 fields have a special meaning:
 *
 *  0 = REFERENCE_FIELD
 *  1 = VALUE_FIELD
 *  2 = FOOTPRINT_FIELD (default Footprint)
 *  3 = DATASHEET_FIELD (user doc link)
 *
 *  others = free fields
 * </p>
 *
 * @see enum MANDATORY_FIELD_T
 */
class LIB_FIELD : public LIB_ITEM, public EDA_TEXT
{
public:
    LIB_FIELD( int aId = 2 );

    LIB_FIELD( int aId, const wxString& aName );

    LIB_FIELD( LIB_SYMBOL* aParent, int aId = 2 );

    // Do not create a copy constructor.  The one generated by the compiler is adequate.

    ~LIB_FIELD();

    wxString GetClass() const override
    {
        return wxT( "LIB_FIELD" );
    }

    wxString GetTypeName() const override
    {
        return _( "Field" );
    }

    /**
     * Object constructor initialization helper.
     */
    void Init( int aId );

    /**
     * Return the field name (not translated).
     *
     * The first four field IDs are reserved and therefore always return their respective
     * names.
     *
     * The user definable fields will return FieldN where N is the ID of the field when the
     * m_name member is empty unless false is passed to \a aUseDefaultName.
     */
    wxString GetName( bool aUseDefaultName = true ) const;

    /**
     * Get a non-language-specific name for a field which can be used for storage, variable
     * look-up, etc.
     */
    wxString GetCanonicalName() const;

    /**
     * Set a user definable field name to \a aName.
     *
     * Reserved fields such as value and reference are not renamed.  If the field name is
     * changed, the field modified flag is set.  If the field is the child of a symbol, the
     * parent symbol's modified flag is also set.
     *
     * @param aName - User defined field name.
     */
    void SetName( const wxString& aName );

    int GetId() const { return m_id; }
    void SetId( int aId );

    int GetPenWidth() const override;

    KIFONT::FONT* GetDrawFont() const override;

    /**
     * Copy parameters of this field to another field. Pointers are not copied.
     *
     * @param aTarget Target field to copy values to.
     */
    void Copy( LIB_FIELD* aTarget ) const;

    void ViewGetLayers( int aLayers[], int& aCount ) const override;

    const BOX2I GetBoundingBox() const override;

    void GetMsgPanelInfo( EDA_DRAW_FRAME* aFrame, std::vector<MSG_PANEL_ITEM>& aList ) override;

    bool HitTest( const VECTOR2I& aPosition, int aAccuracy = 0 ) const override;

    LIB_FIELD& operator=( const LIB_FIELD& field );

    /**
     * Return the text of a field.
     *
     * If the field is the reference field, the unit number is used to
     * create a pseudo reference text.  If the base reference field is U,
     * the string U?A will be returned for unit = 1.
     *
     * @param unit - The package unit number.  Only effects reference field.
     * @return Field text.
     */
    wxString GetFullText( int unit = 1 ) const;

    wxString GetShownText( int aDepth = 0 ) const override;

    SCH_LAYER_ID GetDefaultLayer() const;

    void BeginEdit( const VECTOR2I& aStartPoint ) override;

    void Offset( const VECTOR2I& aOffset ) override;

    void MoveTo( const VECTOR2I& aPosition ) override;

    VECTOR2I GetPosition() const override { return EDA_TEXT::GetTextPos(); }

    void MirrorHorizontal( const VECTOR2I& aCenter ) override;
    void MirrorVertical( const VECTOR2I& aCenter ) override;
    void Rotate( const VECTOR2I& aCenter, bool aRotateCCW = true ) override;

    void Plot( PLOTTER* aPlotter, bool aBackground, const VECTOR2I& aOffset,
               const TRANSFORM& aTransform ) const override;

    wxString GetSelectMenuText( EDA_UNITS aUnits ) const override;

    BITMAPS GetMenuImage() const override;

    EDA_ITEM* Clone() const override;

    bool IsMandatory() const;

    bool IsAutoAdded() const { return m_autoAdded; }
    void SetAutoAdded( bool aAutoAdded ) { m_autoAdded = aAutoAdded; }

    bool IsNameShown() const { return m_showName; }
    void SetNameShown( bool aShown = true ) { m_showName = aShown; }

private:

    /**
     * @copydoc LIB_ITEM::compare()
     *
     * The field specific sort order is as follows:
     *
     *      - Field ID, REFERENCE, VALUE, etc.
     *      - Field string, case insensitive compare.
     *      - Field horizontal (X) position.
     *      - Field vertical (Y) position.
     *      - Field width.
     *      - Field height.
     */
    int compare( const LIB_ITEM& aOther, int aCompareFlags = 0 ) const override;

    /**
     * Print the field.
     *
     * If \a aData not NULL, \a aData must point a wxString which is used instead of
     * the m_Text
     */
    void print( const RENDER_SETTINGS* aSettings, const VECTOR2I& aOffset, void* aData,
                const TRANSFORM& aTransform ) override;

    /**
     * Calculate the new circle at \a aPosition when editing.
     *
     * @param aPosition - The position to edit the circle in drawing coordinates.
     */
    void CalcEdit( const VECTOR2I& aPosition ) override;

    friend class SCH_LEGACY_PLUGIN_CACHE;   // Required to access m_name.

    int      m_id;         ///< @see enum MANDATORY_FIELD_T
    wxString m_name;       ///< Name (not the field text value itself, that is #EDA_TEXT::m_Text)
    bool     m_autoAdded;  ///< Was this field automatically added to a LIB_SYMBOL?
    bool     m_showName;   ///< Render the field's name in addition to its value
};

#endif  //  CLASS_LIBENTRY_FIELDS_H
