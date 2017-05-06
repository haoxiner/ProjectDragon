#pragma once
#include "Entity.h"
#include <vector>
namespace PD
{
class System
{
public:
    void Process(Entity* entity);
protected:
    std::vector<Entity*> entities_;
};
}