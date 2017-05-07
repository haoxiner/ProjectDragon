#pragma once
#include "Model.h"
#include "Entity.h"
namespace PD
{
class RenderingSystem
{
public:
    void EnableDepthTest();
    void DisableDepthTest();
    void EnableCullFace();
    void DisableCullFace();
    void SetViewport(int x, int y, int width, int height);
    void Render(Model* model);
    void Render(Entity* entity);
private:

};
}