#include "Renderer.h"
#include "Gestalt/src/Gestalt/Events/ApplicationEvent.h"

namespace Gestalt {


    void Renderer::Init() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        EventBus::Subscribe(EventType::AppRender, [](Event &) {
            Renderer::RenderFrame();
        });

    }


}
