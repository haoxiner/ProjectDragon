#pragma once
#include "Dragon.h"
#include "SkinnedMeshRenderer.h"
#include <list>
namespace PD
{
class World
{
public:
    void Update(float deltaTime);
    std::list<Dragon> dragons_;
};
}