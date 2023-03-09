#include <MyWindow.hpp>
#include <glad/glad.h>

int main(int argc, char *argv[])
{
    MyWindow mainWindow;

    if(!mainWindow.Initialize())
    {
        std::cout << "Unable to run!" << std::endl;
        return 0;
    }
    
    if(!mainWindow.Start())
    {
        std::cout << "Unable to run!" << std::endl;
        return 0;
    }
    
    while(mainWindow.isOpen())
    {
        mainWindow.Interacting();
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        mainWindow.draw();
        mainWindow.updateWithGL();
    }

    mainWindow.shutdown();

	return 0;
}

