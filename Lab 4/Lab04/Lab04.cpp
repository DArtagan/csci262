// Lab04.cpp : main project file.

#include "Form1.h"

using namespace ProgramForm;

// Actions performed every time when the scene is redrawn
void Scene::Draw(Graphics^ g)
{
	MyShape* shape;

    for (list.begin(); !list.end(); ++list)
    {
        shape = *list;
        shape->draw(g);
    }
}


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Scene());
	return 0;
}
