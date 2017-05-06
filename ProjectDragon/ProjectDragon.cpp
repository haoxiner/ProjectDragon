#include "Game.h"
#include "Display.h"
#include "PerformanceTimer.h"
#include "RenderingSystem.h"
int main()
{
    constexpr int xResolution = 800;
    constexpr int yResolution = 600;
    PD::Display display;
    if (!display.Startup(xResolution, yResolution)) {
        return 1;
    }
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    auto input = display.GetInput();

    float deltaTime = 0.0f;

    PD::PerformanceTimer performanceTimer;
    performanceTimer.Reset();
    while (display.Running())
    {
        performanceTimer.Tick();
        deltaTime = performanceTimer.GetDeltaTime();
        display.Update();
        if (input->Quit())
        {
            display.Shutdown();
        }
    }
    return 0;
}