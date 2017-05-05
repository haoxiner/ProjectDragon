#include "World.h"
int main()
{
    PD::World world;
    while (true)
    {
        world.Update(1.0f);
    }
    return 0;
}