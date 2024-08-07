#include "insults_app.h"

InsultsApp* insults_app_alloc(void) {
    InsultsApp* insults_app = (InsultsApp*)malloc(sizeof(InsultsApp));

    insults_app->gui = furi_record_open(RECORD_GUI);

    insults_app->scene_manager = scene_manager_alloc(&scene_handlers, insults_app);

    insults_app->view_dispatcher = view_dispatcher_alloc();

    view_dispatcher_enable_queue(insults_app->view_dispatcher);
    view_dispatcher_set_event_callback_context(insults_app->view_dispatcher, insults_app);
    view_dispatcher_set_navigation_event_callback(
        insults_app->view_dispatcher, insults_navigation_event_callback);
    view_dispatcher_set_custom_event_callback(
        insults_app->view_dispatcher, insults_custom_event_callback);

    insults_app->start_menu = submenu_alloc();

    submenu_add_item(
        insults_app->start_menu,
        "New insult",
        InsultsSceneStartIndexNew,
        insults_scene_start_submenu_callback,
        insults_app);

    view_dispatcher_add_view(
        insults_app->view_dispatcher, InsultsViewStart, submenu_get_view(insults_app->start_menu));

    insults_app->insult_display = text_box_alloc();

    insults_app->insults_files = insults_files_alloc();

    view_dispatcher_add_view(
        insults_app->view_dispatcher,
        InsultsViewInsult,
        text_box_get_view(insults_app->insult_display));

    view_dispatcher_attach_to_gui(
        insults_app->view_dispatcher, insults_app->gui, ViewDispatcherTypeFullscreen);

    return insults_app;
}

void insults_app_free(InsultsApp* insults_app) {
    insults_files_free(insults_app->insults_files);

    view_dispatcher_remove_view(insults_app->view_dispatcher, InsultsViewInsult);

    text_box_free(insults_app->insult_display);

    free(insults_app->insult_string);

    view_dispatcher_remove_view(insults_app->view_dispatcher, InsultsViewStart);

    submenu_free(insults_app->start_menu);

    view_dispatcher_free(insults_app->view_dispatcher);

    scene_manager_free(insults_app->scene_manager);

    furi_record_close(RECORD_GUI);

    insults_app->gui = NULL;

    free(insults_app);
}

bool insults_navigation_event_callback(void* context) {
    InsultsApp* insults_app = (InsultsApp*)context;

    return scene_manager_handle_back_event(insults_app->scene_manager);
}

bool insults_custom_event_callback(void* context, uint32_t event) {
    InsultsApp* insults_app = (InsultsApp*)context;

    return scene_manager_handle_custom_event(insults_app->scene_manager, event);
}
