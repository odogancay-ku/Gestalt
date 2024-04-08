//
// Created by ofarukdogancay on 4/8/24.
//

#ifndef GESTALT_ENTITY_H
#define GESTALT_ENTITY_H


#include <utility>
#include <memory>
#include "Scene.h"
#include "Gestalt/src/Gestalt/pch.h"


namespace gestalt {

    class Entity {
    private:
        uint id;

        std::vector<std::shared_ptr<Component>> components;

    };

}


#endif //GESTALT_ENTITY_H
