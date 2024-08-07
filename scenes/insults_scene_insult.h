#pragma once

#include <gui/canvas.h>
#include <gui/scene_manager.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/dialog_ex.h>

#include "../insults_app.h"
#include "../insults_files.h"

void insults_scene_insult_on_enter(void* context);
bool insults_scene_insult_on_event(void* context, SceneManagerEvent event);
void insults_scene_insult_on_exit(void* context);

void insults_scene_insult_dialog_callback(DialogExResult result, void* context);

void insults_scene_insult_set_text(void* context);
