#include "Camera.h"

const PD::Vector3f& PD::Camera::GetPosition() const
{
    return position_;
}

const PD::Matrix4x4f& PD::Camera::GetViewMatrix() const
{
    Quaternion cameraRotation(0.0f, 0.0f, 0.0f, 0.0f);
    
    return Matrix4x4f();
}
