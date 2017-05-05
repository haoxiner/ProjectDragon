#pragma once
#include "Model.h"
#include "System.h"
#include "MathUtil.h"
#include <vector>
namespace PD
{
class Entity
{
    Vector3f position_;
    Vector3f rotation_;
    float scale_;
    std::vector<System*> systems_;
};
}