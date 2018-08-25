#ifndef RENDERER_H
#define RENDERER_H

#include <queue>
#include <SFML\Graphics.hpp>

class Renderer
{
private:
    sf::RenderWindow* m_window;
    std::queue<sf::Drawable*> m_objectsToDraw;
public:
    Renderer(sf::RenderWindow*);
    ~Renderer();
    void Draw();
    void AddObjectToRender(sf::Drawable*);
};

#endif // !RENDERER_H




