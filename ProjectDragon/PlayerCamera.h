#pragma once
#include "Camera.h"
#include "Player.h"
namespace PD
{
class PlayerCamera : public Camera
{
public:
    bool Startup(float x, float y, float z, float pitch, float yaw, float roll);
    void Update(float deltaTime, const Input* input, Player* player);
};
}