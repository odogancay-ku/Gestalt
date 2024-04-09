#ifndef GESTALT_RENDERER_H
#define GESTALT_RENDERER_H

#include "Gestalt/src/Gestalt/pch.h"


namespace Gestalt {

    class Renderer {
    public:
        static void Init();
        static void Shutdown();
        static void OnWindowResize(uint32_t width, uint32_t height);
        static void BeginScene();
        static void EndScene();
        static void RenderFrame();

    };

}




#endif //GESTALT_RENDERER_H
