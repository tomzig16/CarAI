#include "GameObject.h"


GameObject::GameObject(std::string name)
{
    m_name = name == "" ? "Unnamed object" : name;
}

GameObject::~GameObject()
{

}

void GameObject::SetTexture(const std::string& path)
{
    if (!m_texture.loadFromFile(path))
    {
        printf("Error loading texture file for \"%s\" object. Validate the path.\n", m_name.c_str());
        return;
    }
    m_texture.setSmooth(true);
    m_texture.setRepeated(false);

    m_sprite.setTexture(m_texture);
}


void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}

void GameObject::Move(Vector3 vector)
{
    m_position.x += vector.x;
    m_position.y -= vector.y;
    m_position.z += vector.z;
    
}

void GameObject::SetPosition(Vector3 vector)
{
    m_position = vector;
    m_position.y = vector.y * -1;
}

Vector3 GameObject::GetPosition()
{
    return m_position;
}

sf::Sprite* GameObject::GetSpritePtr()
{
    return &m_sprite;
}
