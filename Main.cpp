#include "Tests/ParticleTest.h"
#include "tests/ForceTest.h"
#include "tests/JointTest.h"
#include "tests/CollisionTest.h"

int main(int argc, char* argv[])
{

    Test* test = new CollisionTest();
    test->Initialize();

    while (!test->IsQuit()) {
        test->Run();
    
    }

    delete test;

    return 0;
}