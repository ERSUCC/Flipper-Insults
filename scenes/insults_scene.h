#pragma once

#include <gui/scene_manager.h>

#include "insults_scene_insult.h"
#include "insults_scene_start.h"

enum InsultsScene {
    InsultsSceneStart,
    InsultsSceneInsult
};

extern const SceneManagerHandlers scene_handlers;
