#include "Tests/ParticleTest.h"
#include "tests/ForceTest.h"
#include "tests/JointTest.h"

int main(int argc, char* argv[])
{

    Test* test = new JointTest();
    test->Initialize();

    while (!test->IsQuit()) {
        test->Run();
    
    }

    delete test;

    return 0;
}