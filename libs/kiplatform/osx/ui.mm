/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2020 Ian McInerney <Ian.S.McInerney at ieee.org>
 * Copyright (C) 2020 KiCad Developers, see AUTHORS.txt for contributors.
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

#include <kiplatform/ui.h>

#import <Cocoa/Cocoa.h>

#include <wx/nonownedwnd.h>
#include <wx/toplevel.h>
#include <wx/button.h>


bool KIPLATFORM::UI::IsDarkTheme()
{
    // TODO(ISM): Write this function
    return false;
}


void KIPLATFORM::UI::ForceFocus( wxWindow* aWindow )
{
    // On OSX we need to forcefully give the focus to the window
    [[aWindow->GetHandle() window] makeFirstResponder: aWindow->GetHandle()];
}


void KIPLATFORM::UI::ReparentQuasiModal( wxNonOwnedWindow* aWindow )
{
    wxTopLevelWindow* parent =
            static_cast<wxTopLevelWindow*>( wxGetTopLevelParent( aWindow->GetParent() ) );

    wxASSERT_MSG(parent, "QuasiModal windows require a parent.");

    NSWindow* parentWindow = parent->GetWXWindow();
    NSWindow* theWindow    = aWindow->GetWXWindow();

    [parentWindow addChildWindow:theWindow ordered:NSWindowAbove];
}


void KIPLATFORM::UI::FixupCancelButtonCmdKeyCollision( wxWindow *aWindow )
{
    wxButton* button = dynamic_cast<wxButton*>( wxWindow::FindWindowById( wxID_CANCEL, aWindow ) );

    if( button )
    {
        static const wxString placeholder = wxT( "{amp}" );

        wxString buttonLabel = button->GetLabel();
        buttonLabel.Replace( wxT( "&&" ), placeholder );
        buttonLabel.Replace( wxT( "&" ), wxEmptyString );
        buttonLabel.Replace( placeholder, wxT( "&" ) );
        button->SetLabel( buttonLabel );
    }
}


bool KIPLATFORM::UI::IsStockCursorOk( wxStockCursor aCursor )
{
    switch( aCursor )
    {
    case wxCURSOR_SIZING:
    case wxCURSOR_BULLSEYE:
    case wxCURSOR_HAND:
    case wxCURSOR_ARROW:
        return true;
    default:
        return false;
    }
}


void KIPLATFORM::UI::EllipsizeChoiceBox( wxChoice* aChoice )
{
    // Not implemented
}
