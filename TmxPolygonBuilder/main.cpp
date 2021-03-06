#include <iostream>
#include <Box2D/Box2D.h>
#include "simulator.h"
#include <stdio.h>
int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    b2Vec2 gravity(0.0f, -10.0f);

        // Construct a world object, which will hold and simulate the rigid bodies.
    b2World world(gravity);
    
    //Start Simulation frpm here
     Simulator* sim = new Simulator(&world,"example.tmx");
     sim->initSDL();
     sim->initOpenGL();
     sim->initializeSimulator();
     sim->simulatorLoop();

    return 0;
}



