#pragma once
#include "Dragon.h"
#include "SkinnedMeshRenderer.h"
#include <list>
namespace PD
{
class Game
{
public:
    void Update(float deltaTime);
private:
    std::list<Dragon> dragons_;
};
}