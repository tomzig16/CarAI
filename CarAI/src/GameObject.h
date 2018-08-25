#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML\Graphics.hpp>
#include <string>

class GameObject : public sf::Drawable
{
private:
    std::string m_name;
    sf::Sprite m_sprite;
public:
    sf::Texture m_texture;

public:
    GameObject(std::string name);
    ~GameObject();
    void SetTexture(const std::string& path);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // From sf:Drawable
};

#endif
