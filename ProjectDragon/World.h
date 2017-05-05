#pragma once
#include "Dragon.h"
#include <vector>
namespace PD
{
class World
{
public:
    void Update(float deltaTime);
private:
    std::vector<Dragon*> dragons_;
};
}