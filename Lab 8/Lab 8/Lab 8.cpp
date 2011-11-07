// Lab 8.cpp : main project file.
/**
** Lab created by Russell Mah and William Weiskopf
** Questions:
** 1) Our program assumes that a plane can't crash once it has started landing
**    The users input for interval between take off and landings is exactly what they want
**    Therefore planes appear in the queue only on that interval with no randomness.
**    We assume that the landing planes have a higher priority, regardless of wait time, than the departing ones
**    We assume that a plane prepares to land and depart on the first turn.
**    We assume that a plane is able to land the first turn it enters the queue
**    We assume that the user will not want negative numbers except for removing the Maximum Air time it as a factor.
** 2) Time for plane to land changes how long a plane takes up the tarmack to either land or takeoff depending on the variable
**      Time plane can stay in the air is the time a plane that is in the queue to land can wait before it crashes and is removed from the queue
**	  Time between is arrivals is how many turns it takes for a new plane to enter the queue since the previous one entered for landing or taking off respectively
**	  Finally, steps in simulation indicates the amount of time we are sampling.
**	3) Our results are reasonable given the input.  If we increase time to land then it has a direct impact on wait time of the planes in the queue
**     The reduction of air time to crash increases the number of plane crashes, but decreases wait time
**     The decrease in interval between take off and landings increases crashes and wait time.
**     Finally changing arrivals and departures seperately shows a priority for landing planes.  And that only landing planes increases the number of crashes.
**  4) You would want to add another tarmack when the wait time of departures becomes longer than the time it takes for them to enter the queue, or when wait time for
**     Arriving planes is close to the maximum air time.  In order to implement this all you would have to do is make an array of tarmacks and replace the tarmack if 
**     statements with a for loop looping over that queue.
**/

#include "Form1.h"


using namespace Lab8;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
