#include "insults_scene.h"

void (*const on_enter_handlers[])(void*) = {insults_scene_insult_display_on_enter};
bool (*const on_event_handlers[])(void*, SceneManagerEvent) = {
    insults_scene_insult_display_on_event};
void (*const on_exit_handlers[])(void*) = {insults_scene_insult_display_on_exit};

const SceneManagerHandlers scene_handlers =
    {on_enter_handlers, on_event_handlers, on_exit_handlers, 1};

void insults_scene_insult_display_on_enter(void* context) {
    InsultsApp* app = (InsultsApp*)context;

    view_dispatcher_switch_to_view(app->view_dispatcher, InsultsViewInsultDisplay);
}

bool insults_scene_insult_display_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);

    return false;
}

void insults_scene_insult_display_on_exit(void* context) {
    UNUSED(context);
}
