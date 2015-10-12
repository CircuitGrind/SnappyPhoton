// This #include statement was automatically added by the Particle IDE.
#include "Robot.h"

// This #include statement was automatically added by the Particle IDE.
#include "Command.h"

void setup()
{
    setupSteppers();
    
    // Listen for commands from the web!
    Particle.function("command", processCommand);
    
    /*
     * ==================================
     * Add your commands below this line!
     * ==================================
     */
    
    addCommand(forward);
    addCommand(back);
    addCommand(left);
    addCommand(right);
}

void loop()
{
    if(isDoneMoving() && commands.size())
    {
        runCommand(commands.front());
        commands.pop();
    }
    
    stepperLeft.run();
    stepperRight.run();
}