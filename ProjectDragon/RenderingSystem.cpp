#include "RenderingSystem.h"

void PD::RenderingSystem::EnableDepthTest()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void PD::RenderingSystem::DisableDepthTest()
{
    glDisable(GL_DEPTH_TEST);
}

void PD::RenderingSystem::EnableCullFace()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
}

void PD::RenderingSystem::DisableCullFace()
{
    glDisable(GL_CULL_FACE);
}

void PD::RenderingSystem::SetViewport(int x, int y, int width, int height)
{
    glViewport(x, y, width, height);
}

void PD::RenderingSystem::SetMaterial(Material* material)
{
}

void PD::RenderingSystem::Render(Model* model)
{
    model->Render();
}
