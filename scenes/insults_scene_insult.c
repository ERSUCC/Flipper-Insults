#include "insults_scene_insult.h"

void insults_scene_insult_on_enter(void* context) {
    InsultsApp* insults_app = (InsultsApp*)context;

    insults_app->insult_string = insults_files_get_insult(insults_app->insults_files);

    text_box_set_text(insults_app->insult_display, insults_app->insult_string);

    view_dispatcher_switch_to_view(insults_app->view_dispatcher, InsultsViewInsult);
}

bool insults_scene_insult_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);

    return false;
}

void insults_scene_insult_on_exit(void* context) {
    InsultsApp* insults_app = (InsultsApp*)context;

    free(insults_app->insult_string);
}
