#include "SYSTEM.hpp"
#include <Window.hpp>

int main(int argc, char *argv[])
{

    MyWindow main;

    if(!main.Initialization())
    {
        return -1;
    }

    main.Start();
    main.loadBackground(GLOBAL::BGFolder, "home.bmp");
    main.render();

    while(main.isOpen())
    {
        main.Interacting();
    }
    
    main.shutdown();

	return 0;
}

