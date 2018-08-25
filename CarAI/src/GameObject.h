#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML\Graphics.hpp>
#include <string>

#include "Vector3.h"

class GameObject : public sf::Drawable
{
private:
    std::string m_name;
    sf::Sprite m_sprite;
    Vector3 m_position;

public:
    sf::Texture m_texture;

public:
    GameObject(std::string);
    ~GameObject();
    void SetTexture(const std::string&);
    void Move(Vector3);
    void SetPosition(Vector3);
    Vector3 GetPosition();
    sf::Sprite* GetSpritePtr();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // From sf:Drawable
};

#endif
