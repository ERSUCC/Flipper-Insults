#pragma once

#include <gui/scene_manager.h>
#include <gui/view_dispatcher.h>

#include "insults_app.h"

enum InsultsScene {
    InsultsSceneInsultDisplay
};

extern const SceneManagerHandlers scene_handlers;

void insults_scene_insult_display_on_enter(void* context);
bool insults_scene_insult_display_on_event(void* context, SceneManagerEvent event);
void insults_scene_insult_display_on_exit(void* context);
