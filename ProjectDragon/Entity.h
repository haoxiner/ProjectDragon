#pragma once
#include "Model.h"
#include "MathUtil.h"
#include <vector>
namespace PD
{
class Entity
{
    Vector3f position_;
    Vector3f rotation_;
    float scale_;
    Model* model_;
};
}