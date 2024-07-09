///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "panel_zone_properties_base.h"

///////////////////////////////////////////////////////////////////////////

PANEL_ZONE_PROPERTIES_BASE::PANEL_ZONE_PROPERTIES_BASE( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizerMiddle;
	bSizerMiddle = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bLeftColumn;
	bLeftColumn = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbGeneral;
	sbGeneral = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("General") ), wxHORIZONTAL );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_zoneNameLabel = new wxStaticText( sbGeneral->GetStaticBox(), wxID_ANY, _("Zone name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_zoneNameLabel->Wrap( -1 );
	m_zoneNameLabel->SetToolTip( _("A unique name for this zone to identify it for DRC") );

	fgSizer1->Add( m_zoneNameLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_tcZoneName = new wxTextCtrl( sbGeneral->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_tcZoneName, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );


	sbGeneral->Add( fgSizer1, 1, wxEXPAND|wxTOP|wxBOTTOM, 5 );


	bLeftColumn->Add( sbGeneral, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wxStaticBoxSizer* m_ExportableSetupSizer;
	m_ExportableSetupSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Shape") ), wxHORIZONTAL );

	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 5, 5 );
	gbSizer1->SetFlexibleDirection( wxBOTH );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_cbLocked = new wxCheckBox( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, _("Locked"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer1->Add( m_cbLocked, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxBOTTOM|wxRIGHT, 5 );

	m_staticTextStyle = new wxStaticText( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, _("Outline display:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStyle->Wrap( -1 );
	gbSizer1->Add( m_staticTextStyle, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5 );

	wxString m_OutlineDisplayCtrlChoices[] = { _("Line"), _("Hatched"), _("Fully hatched") };
	int m_OutlineDisplayCtrlNChoices = sizeof( m_OutlineDisplayCtrlChoices ) / sizeof( wxString );
	m_OutlineDisplayCtrl = new wxChoice( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_OutlineDisplayCtrlNChoices, m_OutlineDisplayCtrlChoices, 0 );
	m_OutlineDisplayCtrl->SetSelection( 0 );
	gbSizer1->Add( m_OutlineDisplayCtrl, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), 0, 5 );

	m_stBorderHatchPitchText = new wxStaticText( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, _("Outline hatch pitch:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stBorderHatchPitchText->Wrap( -1 );
	gbSizer1->Add( m_stBorderHatchPitchText, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_outlineHatchPitchCtrl = new wxTextCtrl( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer1->Add( m_outlineHatchPitchCtrl, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	m_outlineHatchUnits = new wxStaticText( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_outlineHatchUnits->Wrap( -1 );
	gbSizer1->Add( m_outlineHatchUnits, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL, 5 );

	m_staticline4 = new wxStaticLine( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline4, wxGBPosition( 3, 0 ), wxGBSpan( 1, 3 ), wxEXPAND | wxALL, 5 );

	m_staticTextSmoothing = new wxStaticText( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, _("Corner smoothing:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSmoothing->Wrap( -1 );
	gbSizer1->Add( m_staticTextSmoothing, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	wxString m_cornerSmoothingChoiceChoices[] = { _("None"), _("Chamfer"), _("Fillet") };
	int m_cornerSmoothingChoiceNChoices = sizeof( m_cornerSmoothingChoiceChoices ) / sizeof( wxString );
	m_cornerSmoothingChoice = new wxChoice( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_cornerSmoothingChoiceNChoices, m_cornerSmoothingChoiceChoices, 0 );
	m_cornerSmoothingChoice->SetSelection( 1 );
	gbSizer1->Add( m_cornerSmoothingChoice, wxGBPosition( 4, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	m_cornerRadiusLabel = new wxStaticText( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, _("Chamfer distance:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cornerRadiusLabel->Wrap( -1 );
	gbSizer1->Add( m_cornerRadiusLabel, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_cornerRadiusCtrl = new wxTextCtrl( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer1->Add( m_cornerRadiusCtrl, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	m_cornerRadiusUnits = new wxStaticText( m_ExportableSetupSizer->GetStaticBox(), wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cornerRadiusUnits->Wrap( -1 );
	gbSizer1->Add( m_cornerRadiusUnits, wxGBPosition( 5, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL, 5 );


	gbSizer1->AddGrowableCol( 0 );

	m_ExportableSetupSizer->Add( gbSizer1, 1, wxEXPAND|wxBOTTOM|wxRIGHT, 5 );


	bLeftColumn->Add( m_ExportableSetupSizer, 1, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );


	bSizerMiddle->Add( bLeftColumn, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	wxBoxSizer* bMiddleColumn;
	bMiddleColumn = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Electrical Properties") ), wxVERTICAL );

	wxGridBagSizer* gbSizerSettings;
	gbSizerSettings = new wxGridBagSizer( 0, 0 );
	gbSizerSettings->SetFlexibleDirection( wxBOTH );
	gbSizerSettings->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_clearanceLabel = new wxStaticText( sbSizer5->GetStaticBox(), wxID_ANY, _("Clearance:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_clearanceLabel->Wrap( -1 );
	m_clearanceLabel->SetToolTip( _("Copper clearance for this zone (set to 0 to use the netclass clearance)") );

	gbSizerSettings->Add( m_clearanceLabel, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT, 5 );

	m_clearanceCtrl = new wxTextCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizerSettings->Add( m_clearanceCtrl, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_clearanceUnits = new wxStaticText( sbSizer5->GetStaticBox(), wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_clearanceUnits->Wrap( -1 );
	gbSizerSettings->Add( m_clearanceUnits, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT, 5 );

	m_minWidthLabel = new wxStaticText( sbSizer5->GetStaticBox(), wxID_ANY, _("Minimum width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_minWidthLabel->Wrap( -1 );
	m_minWidthLabel->SetToolTip( _("Minimum thickness of filled areas.") );

	gbSizerSettings->Add( m_minWidthLabel, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT, 5 );

	m_minWidthCtrl = new wxTextCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizerSettings->Add( m_minWidthCtrl, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_minWidthUnits = new wxStaticText( sbSizer5->GetStaticBox(), wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_minWidthUnits->Wrap( -1 );
	gbSizerSettings->Add( m_minWidthUnits, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT, 5 );

	m_staticline2 = new wxStaticLine( sbSizer5->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizerSettings->Add( m_staticline2, wxGBPosition( 2, 0 ), wxGBSpan( 1, 3 ), wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	m_connectionLabel = new wxStaticText( sbSizer5->GetStaticBox(), wxID_ANY, _("Pad connections:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_connectionLabel->Wrap( -1 );
	m_connectionLabel->SetToolTip( _("Default pad connection type to zone.\nThis setting can be overridden by local  pad settings") );

	gbSizerSettings->Add( m_connectionLabel, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );

	wxString m_PadInZoneOptChoices[] = { _("Solid"), _("Thermal reliefs"), _("Reliefs for PTH"), _("None") };
	int m_PadInZoneOptNChoices = sizeof( m_PadInZoneOptChoices ) / sizeof( wxString );
	m_PadInZoneOpt = new wxChoice( sbSizer5->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_PadInZoneOptNChoices, m_PadInZoneOptChoices, 0 );
	m_PadInZoneOpt->SetSelection( 0 );
	gbSizerSettings->Add( m_PadInZoneOpt, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxEXPAND|wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );

	m_antipadLabel = new wxStaticText( sbSizer5->GetStaticBox(), wxID_ANY, _("Thermal relief gap:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_antipadLabel->Wrap( -1 );
	m_antipadLabel->SetToolTip( _("The distance that will be kept clear between the filled area of the zone and a pad connected by thermal relief spokes.") );

	gbSizerSettings->Add( m_antipadLabel, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP, 5 );

	m_antipadCtrl = new wxTextCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_antipadCtrl->SetToolTip( _("Clearance between pads in the same net and filled areas.") );

	gbSizerSettings->Add( m_antipadCtrl, wxGBPosition( 4, 1 ), wxGBSpan( 1, 1 ), wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_antipadUnits = new wxStaticText( sbSizer5->GetStaticBox(), wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_antipadUnits->Wrap( -1 );
	gbSizerSettings->Add( m_antipadUnits, wxGBPosition( 4, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT, 5 );

	m_spokeWidthLabel = new wxStaticText( sbSizer5->GetStaticBox(), wxID_ANY, _("Thermal spoke width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_spokeWidthLabel->Wrap( -1 );
	gbSizerSettings->Add( m_spokeWidthLabel, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxTOP, 5 );

	m_spokeWidthCtrl = new wxTextCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_spokeWidthCtrl->SetToolTip( _("Width of copper in thermal reliefs.") );

	gbSizerSettings->Add( m_spokeWidthCtrl, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxEXPAND|wxALL, 5 );

	m_spokeWidthUnits = new wxStaticText( sbSizer5->GetStaticBox(), wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_spokeWidthUnits->Wrap( -1 );
	gbSizerSettings->Add( m_spokeWidthUnits, wxGBPosition( 5, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );


	gbSizerSettings->AddGrowableCol( 1 );

	sbSizer5->Add( gbSizerSettings, 0, wxEXPAND, 5 );


	bMiddleColumn->Add( sbSizer5, 1, wxEXPAND|wxRIGHT, 5 );


	bSizerMiddle->Add( bMiddleColumn, 1, wxEXPAND|wxALL, 5 );

	wxStaticBoxSizer* sbSizerZoneStyle;
	sbSizerZoneStyle = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Fill") ), wxVERTICAL );

	wxGridBagSizer* gbSizer3;
	gbSizer3 = new wxGridBagSizer( 5, 5 );
	gbSizer3->SetFlexibleDirection( wxBOTH );
	gbSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	gbSizer3->SetEmptyCellSize( wxSize( -1,10 ) );

	m_staticTextGridFillType = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("Fill type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextGridFillType->Wrap( -1 );
	gbSizer3->Add( m_staticTextGridFillType, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	wxString m_GridStyleCtrlChoices[] = { _("Solid fill"), _("Hatch pattern") };
	int m_GridStyleCtrlNChoices = sizeof( m_GridStyleCtrlChoices ) / sizeof( wxString );
	m_GridStyleCtrl = new wxChoice( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_GridStyleCtrlNChoices, m_GridStyleCtrlChoices, 0 );
	m_GridStyleCtrl->SetSelection( 0 );
	gbSizer3->Add( m_GridStyleCtrl, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticTextGrindOrient = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("Orientation:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextGrindOrient->Wrap( -1 );
	gbSizer3->Add( m_staticTextGrindOrient, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP, 5 );

	m_tcGridStyleOrientation = new wxTextCtrl( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer3->Add( m_tcGridStyleOrientation, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticTextRotUnits = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRotUnits->Wrap( -1 );
	gbSizer3->Add( m_staticTextRotUnits, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP, 5 );

	m_staticTextStyleThickness = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("Hatch width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStyleThickness->Wrap( -1 );
	gbSizer3->Add( m_staticTextStyleThickness, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_tcGridStyleThickness = new wxTextCtrl( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer3->Add( m_tcGridStyleThickness, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_GridStyleThicknessUnits = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GridStyleThicknessUnits->Wrap( -1 );
	gbSizer3->Add( m_GridStyleThicknessUnits, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );

	m_staticTextGridGap = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("Hatch gap:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextGridGap->Wrap( -1 );
	gbSizer3->Add( m_staticTextGridGap, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_tcGridStyleGap = new wxTextCtrl( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer3->Add( m_tcGridStyleGap, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_GridStyleGapUnits = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GridStyleGapUnits->Wrap( -1 );
	gbSizer3->Add( m_GridStyleGapUnits, wxGBPosition( 3, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );

	m_staticTextGridSmoothingLevel = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("Smoothing effort:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextGridSmoothingLevel->Wrap( -1 );
	m_staticTextGridSmoothingLevel->SetToolTip( _("Value of smoothing effort\n0 = no smoothing\n1 = chamfer\n2 = round corners\n3 = round corners (finer shape)") );

	gbSizer3->Add( m_staticTextGridSmoothingLevel, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_spinCtrlSmoothLevel = new wxSpinCtrl( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 3, 0 );
	gbSizer3->Add( m_spinCtrlSmoothLevel, wxGBPosition( 4, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticTextGridSmootingVal = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("Smoothing amount:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextGridSmootingVal->Wrap( -1 );
	m_staticTextGridSmootingVal->SetToolTip( _("Ratio between smoothed corners size and the gap between lines\n0 = no smoothing\n1.0 = max radius/chamfer size (half gap value)") );

	gbSizer3->Add( m_staticTextGridSmootingVal, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_spinCtrlSmoothValue = new wxSpinCtrlDouble( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1, 0.1, 0.1 );
	m_spinCtrlSmoothValue->SetDigits( 2 );
	gbSizer3->Add( m_spinCtrlSmoothValue, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticline5 = new wxStaticLine( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer3->Add( m_staticline5, wxGBPosition( 6, 0 ), wxGBSpan( 1, 3 ), wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	m_staticText40 = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("Remove islands:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	m_staticText40->SetToolTip( _("Choose what to do with unconnected copper islands") );

	gbSizer3->Add( m_staticText40, wxGBPosition( 7, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	wxString m_cbRemoveIslandsChoices[] = { _("Always"), _("Never"), _("Below area limit") };
	int m_cbRemoveIslandsNChoices = sizeof( m_cbRemoveIslandsChoices ) / sizeof( wxString );
	m_cbRemoveIslands = new wxChoice( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_cbRemoveIslandsNChoices, m_cbRemoveIslandsChoices, 0 );
	m_cbRemoveIslands->SetSelection( 0 );
	gbSizer3->Add( m_cbRemoveIslands, wxGBPosition( 7, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_islandThresholdLabel = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("Minimum island size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_islandThresholdLabel->Wrap( -1 );
	m_islandThresholdLabel->Enable( false );
	m_islandThresholdLabel->SetToolTip( _("Isolated islands smaller than this will be removed") );

	gbSizer3->Add( m_islandThresholdLabel, wxGBPosition( 8, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_tcIslandThreshold = new wxTextCtrl( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_tcIslandThreshold->Enable( false );

	gbSizer3->Add( m_tcIslandThreshold, wxGBPosition( 8, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_islandThresholdUnits = new wxStaticText( sbSizerZoneStyle->GetStaticBox(), wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_islandThresholdUnits->Wrap( -1 );
	m_islandThresholdUnits->Enable( false );

	gbSizer3->Add( m_islandThresholdUnits, wxGBPosition( 8, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );


	gbSizer3->AddGrowableCol( 0 );

	sbSizerZoneStyle->Add( gbSizer3, 1, wxBOTTOM|wxEXPAND, 5 );


	bSizerMiddle->Add( sbSizerZoneStyle, 0, wxBOTTOM|wxEXPAND|wxRIGHT|wxTOP, 5 );


	this->SetSizer( bSizerMiddle );
	this->Layout();
	bSizerMiddle->Fit( this );

	// Connect Events
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( PANEL_ZONE_PROPERTIES_BASE::OnUpdateUI ) );
	m_tcZoneName->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( PANEL_ZONE_PROPERTIES_BASE::OnZoneNameChanged ), NULL, this );
	m_GridStyleCtrl->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PANEL_ZONE_PROPERTIES_BASE::OnStyleSelection ), NULL, this );
	m_cbRemoveIslands->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PANEL_ZONE_PROPERTIES_BASE::OnRemoveIslandsSelection ), NULL, this );
}

PANEL_ZONE_PROPERTIES_BASE::~PANEL_ZONE_PROPERTIES_BASE()
{
	// Disconnect Events
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( PANEL_ZONE_PROPERTIES_BASE::OnUpdateUI ) );
	m_tcZoneName->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( PANEL_ZONE_PROPERTIES_BASE::OnZoneNameChanged ), NULL, this );
	m_GridStyleCtrl->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PANEL_ZONE_PROPERTIES_BASE::OnStyleSelection ), NULL, this );
	m_cbRemoveIslands->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PANEL_ZONE_PROPERTIES_BASE::OnRemoveIslandsSelection ), NULL, this );

}
