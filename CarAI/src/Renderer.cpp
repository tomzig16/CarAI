#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow* window)
    : m_window(window)
{};

Renderer::~Renderer()
{
    // TODO clear the queue
}

void Renderer::Draw()
{
    m_window->clear();
    for (int i = 0; i < m_objectsToDraw.size(); i++)
    {
        m_window->draw(*m_objectsToDraw.front());
        m_objectsToDraw.push(m_objectsToDraw.front());
        m_objectsToDraw.pop();
    }
    m_window->display();
}

void Renderer::AddObjectToRender(sf::Drawable* objToAdd)
{
    m_objectsToDraw.push(objToAdd);
}