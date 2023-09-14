/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2007-2017 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 1992-2022 KiCad Developers, see AUTHORS.TXT for contributors.
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

#ifndef BITMAPS_PNG_BITMAPS_LIST__H
#define BITMAPS_PNG_BITMAPS_LIST__H

/**
 * A list of all bitmap identifiers.  These map to multiple actual images, i.e. light and dark icon
 * themes, and eventually multi-resolution icons.
 */
enum class BITMAPS : unsigned int
{
    /*
     * Bitmap 0 is reserved for the invalid marker, so that classes using BITMAPS can forward-
     * declare this enum and zero-initialize it, which cuts down on the number of files that need
     * to be rebuilt when this enum is changed
     */
    INVALID_BITMAP = 0,

    about,
    add_aligned_dimension,
    add_arc,
    add_board,
    add_bus,
    add_bus2bus,
    add_center_dimension,
    add_class_flag,
    add_circle,
    add_component,
    add_corner,
    add_dashed_line,
    add_document,
    add_gerber,
    add_glabel,
    add_graphical_polygon,
    add_graphical_segments,
    add_hierar_pin,
    add_hierarchical_label,
    add_hierarchical_subsheet,
    add_junction,
    add_keepout_area,
    add_label,
    add_leader,
    add_library,
    add_line,
    add_line2bus,
    add_line_label,
    add_orthogonal_dimension,
    add_pcb_target,
    add_power,
    add_radial_dimension,
    add_rectangle,
    add_symbol_to_schematic,
    add_textbox,
    add_tracks,
    add_via,
    add_zone,
    add_zone_cutout,
    align_items,
    align_items_bottom,
    align_items_center,
    align_items_left,
    align_items_middle,
    align_items_right,
    align_items_top,
    anchor,
    annotate,
    annotate_down_right,
    annotate_right_down,
    apply_pad_settings,
    array,
    att_bridge,
    att_pi,
    att_splitter,
    att_tee,
    auto_associate,
    auto_delete_track,
    auto_track_width,
    autoplace_fields,
    axis3d,
    axis3d_back,
    axis3d_bottom,
    axis3d_front,
    axis3d_left,
    axis3d_right,
    axis3d_top,
    break_bus,
    break_line,
    bug,
    bus_definition_tool,
    c_microstrip,
    calculator,
    cancel,
    chamfer,
    change_entry_orient,
    change_glabel,
    change_hlabel,
    change_label,
    change_text,
    checked_ok,
    creepage_clearance,
    coax,
    color_code_multiplier,
    color_code_tolerance,
    color_code_value,
    color_code_value_and_name,
    color_materials,
    component_select_alternate_shape,
    component_select_unit,
    config,
    contrast_mode,
    convert,
    copper_layers_setup,
    copy,
    copy_pad_settings,
    cpw,
    cpw_back,
    cursor,
    cursor_shape,
    curved_ratsnest,
    custom_pad_to_primitives,
    cut,
    datasheet,
    delete_association,
    delete_cursor,
    delete_gerber,
    delete_sheet,
    dialog_warning,
    directory,
    directory_browser,
    directory_open,
    display_options,
    distribute_horizontal,
    distribute_vertical,
    down,
    drag,
    drag_segment_withslope,
    drc,
    drc_off,
    dummy_item,
    duplicate,
    e_24,
    e_48,
    e_96,
    e_192,
    edge_to_copper_clearance,
    edit,
    edit_cmp_symb_links,
    edit_comp_footprint,
    edit_comp_ref,
    edit_comp_value,
    editor,
    eeschema,
    enter_sheet,
    erc,
    erc_green,
    ercerr,
    ercwarn,
    exchange,
    exit,
    export3d,
    export_cmp,
    export_dsn,
    export_file,
    export_footprint_names,
    export_idf,
    export_module,
    export_part,
    export_png,
    export_step,
    export_svg,
    export_to_pcbnew,
    fabrication,
    file_bom,
    file_drl,
    file_dsn,
    file_gbr,
    file_gerber_job,
    file_html,
    file_idf,
    file_pdf,
    file_pos,
    file_svg,
    fill_zone,
    fillet,
    filter,
    find,
    find_replace,
    flag,
    flip_board,
    fonts,
    gbr_select_mode0,
    gbr_select_mode1,
    gbr_select_mode2,
    general_deletions,
    general_ratsnest,
    gerber_file,
    gerbview_clear_layers,
    gerbview_show_negative_objects,
    git_add,
    git_changed_ahead,
    git_modified,
    git_conflict,
    git_delete,
    git_good_check,
    git_out_of_date,
    go_down,
    go_up,
    grid,
    grid_override,
    grid_select,
    grid_select_axis,
    group,
    group_enter,
    group_leave,
    group_remove,
    group_ungroup,
    heal_shapes,
    help,
    help_online,
    hidden_pin,
    hide_ratsnest,
    hierarchy_nav,
    hole_to_copper_clearance,
    hole_to_hole_clearance,
    hotkeys,
    hv45mode,
    icon_3d,
    icon_bitmap2component,
    icon_bitmap2component_16,
    icon_bitmap2component_24,
    icon_bitmap2component_32,
    icon_cvpcb,
    icon_cvpcb_24,
    icon_eeschema,
    icon_eeschema_16,
    icon_eeschema_24,
    icon_eeschema_32,
    icon_footprint_browser,
    icon_gerbview,
    icon_gerbview_16,
    icon_gerbview_24,
    icon_gerbview_32,
    icon_kicad,
    icon_kicad_16,
    icon_kicad_24,
    icon_kicad_32,
    icon_kicad_nightly,
    icon_kicad_nightly_16,
    icon_kicad_nightly_24,
    icon_kicad_nightly_32,
    icon_libedit,
    icon_libedit_16,
    icon_libedit_24,
    icon_libedit_32,
    icon_modedit,
    icon_modedit_16,
    icon_modedit_24,
    icon_modedit_32,
    icon_pagelayout_editor,
    icon_pagelayout_editor_16,
    icon_pagelayout_editor_24,
    icon_pagelayout_editor_32,
    icon_pcbcalculator,
    icon_pcbcalculator_16,
    icon_pcbcalculator_24,
    icon_pcbcalculator_32,
    icon_pcbnew,
    icon_pcbnew_16,
    icon_pcbnew_24,
    icon_pcbnew_32,
    icon_pcm,
    icon_pcm_24,
    image,
    import,
    import3d,
    import_brd_file,
    import_document,
    import_footprint_names,
    import_hierarchical_label,
    import_module,
    import_part,
    import_project,
    import_vector,
    info,
    insert_module_board,
    intersect_polygons,
    invisible_text,
    kicad_icon_small,
    label_align_left,
    label_align_right,
    label_align_top,
    label_align_bottom,
    language,
    layers_manager,
    leave_sheet,
    left,
    lib_next,
    lib_previous,
    libedit,
    library,
    library_archive,
    library_archive_as,
    library_browser,
    library_table,
    lines_any,
    lines90,
    list_nets,
    list_nets_16,
    load_drill,
    load_gerber,
    load_module_board,
    lock_unlock,
    locked,
    marker_exclude,
    marker_next,
    marker_previous,
    measurement,
    merge_polygons,
    microstrip,
    microstrip_zodd_zeven,
    minus,
    mirror_h,
    mirror_v,
    mode_module,
    mode_track,
    module,
    module_editor,
    module_filtered_list,
    module_full_list,
    module_library_list,
    module_name_filtered_list,
    module_options,
    module_pin_filtered_list,
    module_wizard,
    morgan1,
    morgan2,
    move,
    move_exactly,
    move_relative,
    mw_add_gap,
    mw_add_line,
    mw_add_shape,
    mw_add_stub,
    mw_add_stub_arc,
    net_highlight,
    net_highlight_schematic,
    net_locked,
    net_unlocked,
    netlist,
    new_board,
    new_component,
    new_document,
    new_footprint,
    new_generic,
    new_library,
    new_page_layout,
    new_project,
    new_project_from_template,
    new_python,
    noconn,
    notifications,
    normal,
    open_project,
    open_project_demo,
    opt_show_polygon,
    options_3drender,
    options_board,
    options_generic,
    options_generic_16,
    options_pad,
    options_schematic,
    ortho,
    pack_footprints,
    pad,
    pad_enumerate,
    pad_number,
    pad_sketch,
    pads_mask_layers,
    pads_npth,
    pads_npth_bottom,
    pads_npth_top,
    pads_npth_top_bottom,
    pads_remove,
    pads_remove_unused,
    pads_remove_unused_keep_bottom,
    pads_reset_unused,
    pagelayout_normal_view_mode,
    pagelayout_special_view_mode,
    part_properties,
    paste,
    paste_special,
    path,
    pcb_target,
    pcbnew,
    pin,
    pin2pin,
    pin_show_etype,
    pin_size_to,
    pin_table,
    pinorient_down,
    pinorient_left,
    pinorient_right,
    pinorient_up,
    pinshape_active_low_input,
    pinshape_active_low_output,
    pinshape_clock_active_low,
    pinshape_clock_fall,
    pinshape_clock_invert,
    pinshape_clock_normal,
    pinshape_invert,
    pinshape_nonlogic,
    pinshape_normal,
    pintype_3states,
    pintype_bidi,
    pintype_input,
    pintype_nic,
    pintype_noconnect,
    pintype_notspecif,
    pintype_opencoll,
    pintype_openemit,
    pintype_output,
    pintype_passive,
    pintype_powerinput,
    pintype_poweroutput,
    plot,
    polar_coord,
    post_bom,
    post_compo,
    post_d356,
    post_drill,
    post_gencad,
    post_gerber,
    post_module,
    post_rpt,
    preference,
    primitives_to_custom_pad,
    print_button,
    project,
    project_close,
    project_kicad,
    ps_diff_pair,
    ps_diff_pair_gap,
    ps_diff_pair_tune_length,
    ps_diff_pair_tune_phase,
    ps_diff_pair_via_gap,
    ps_router,
    ps_tune_length,
    push_pad_settings,
    puzzle_piece,
    py_script,
    question_mark,
    reannotate_down_left,
    reannotate_down_right,
    reannotate_left_down,
    reannotate_left_up,
    reannotate_right_down,
    reannotate_right_up,
    reannotate_up_left,
    reannotate_up_right,
    recent,
    rectwaveguide,
    red,
    redo,
    refresh,
    regul,
    regul_3pins,
    reload,
    render_mode,
    repaint,
    rescue,
    resize_sheet,
    right,
    rotate_ccw,
    rotate_ccw_x,
    rotate_ccw_y,
    rotate_ccw_z,
    rotate_cw,
    rotate_cw_x,
    rotate_cw_y,
    rotate_cw_z,
    router_len_tuner,
    router_len_tuner_amplitude_decr,
    router_len_tuner_amplitude_incr,
    router_len_tuner_dist_decr,
    router_len_tuner_dist_incr,
    router_len_tuner_setup,
    save,
    save_as,
    search_tree,
    select_layer_pair,
    select_same_sheet,
    select_w_layer,
    set_origin,
    shape_3d,
    shape_3d_back,
    sheetset,
    show_all_back_layers,
    show_all_copper_layers,
    show_all_front_layers,
    show_all_layers,
    show_back_assembly_layers,
    show_dcodenumber,
    show_dnp,
    show_footprint,
    show_front_assembly_layers,
    show_graphics_mode,
    show_mod_edge,
    show_no_copper_layers,
    show_no_layers,
    show_ratsnest,
    show_not_in_posfile,
    show_other,
    show_tht,
    show_smt,
    show_zone,
    show_zone_disable,
    show_zone_outline_only,
    show_zone_triangulation,
    showtrack,
    sim_add_plot,
    sim_add_signal,
    sim_command,
    sim_probe,
    sim_run,
    sim_stop,
    sim_tune,
    simulator,
    slice_line,
    small_down,
    small_edit,
    small_folder,
    small_library,
    small_plus,
    small_refresh,
    small_sort_desc,
    small_trash,
    small_up,
    small_warning,
    special_tools,
    splash,
    spreadsheet,
    stripline,
    stroke_dash,
    stroke_dashdot,
    stroke_dashdotdot,
    stroke_dot,
    stroke_solid,
    subtract_polygons,
    swap,
    swap_layer,
    switch_corner_rounding_shape,
    teardrop_sizes,
    teardrop_rect_sizes,
    teardrop_track_sizes,
    text,
    text_align_left,
    text_align_center,
    text_align_right,
    text_align_top,
    text_align_middle,
    text_align_bottom,
    text_valign_top,
    text_valign_center,
    text_valign_bottom,
    text_horizontal,
    text_vertical,
    text_bold,
    text_italic,
    text_mirrored,
    text_sketch,
    thermal_spokes,
    three_d,
    tool_ratsnest,
    tools,
    track_locked,
    track_sketch,
    track_unlocked,
    trash,
    tree_nosel,
    tree_sel,
    tune_diff_pair_length_legend,
    tune_diff_pair_skew_legend,
    tune_single_track_length_legend,
    twistedpair,
    undelete,
    undo,
    unit_inch,
    unit_mil,
    unit_mm,
    unknown,
    unlocked,
    unzip,
    up,
    update_fields,
    update_pcb_from_sch,
    update_sch_from_pcb,
    via,
    via_annulus,
    via_buried,
    via_diameter,
    via_hole_diameter,
    via_microvia,
    via_sketch,
    viacalc,
    viewlibs_icon,
    visibility,
    visibility_off,
    width_conn,
    width_track,
    width_track_via,
    wizard_add_fplib_icon,
    wizard_add_fplib_small,
    www,
    zip,
    zone_duplicate,
    zone_fillet,
    zone_unfill,
    zoom,
    zoom_area,
    zoom_auto_fit_in_page,
    zoom_center_on_screen,
    zoom_fit_in_page,
    zoom_fit_to_objects,
    zoom_in,
    zoom_out,
    zoom_page,
    zoom_selection,
};


inline bool operator!( const BITMAPS& aBitmap ) { return aBitmap == BITMAPS::INVALID_BITMAP; }

#endif // BITMAPS_PNG_BITMAPS_LIST__H
