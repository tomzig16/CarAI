#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "GameObject.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Window");
    
    // Do other stuff here
    Renderer renderer(&window);
    GameObject gobject("Test Object");
    gobject.SetTexture("C:\\dev\\CarAI\\CarAI\\resources\\testtex.jpg");
    renderer.AddObjectToRender(&gobject);


    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        renderer.Draw();
    }

    printf("\n\nPROGRAM IS CLOSING FROM MAIN\n");
    system("PAUSE");
    return EXIT_SUCCESS;
}
