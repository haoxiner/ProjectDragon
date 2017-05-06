#pragma once
#include "Input.h"
#include <SDL\SDL.h>
#undef main
namespace PD
{
class Display {
public:
    bool Startup(int xResolution, int yResolution);
    void Update();
    void Shutdown();
    bool Running();
    const Input* GetInput() const;
private:
    bool running_ = false;
    SDL_Window* window_ = nullptr;
    Input input_;
};
}