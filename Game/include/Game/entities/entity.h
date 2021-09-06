#ifndef ENTITY_H
#define ENTITY_H

#include <Game/GameEngine/gameengine.h>

// Include all entities

enum class EntityType{None, Player};
class Entity // : sf::Drawable, sf::Transformable 
{
private:
    std::string m_name;
    double m_health;
    std::string m_filename;
    sf::Vector2f m_spritesheet_size;
    EntityType m_type;  

private:
    sf::Texture texture;
public:
    Entity(const std::string&, const double, const std::string&, sf::Vector2u, const EntityType&); 
};

#endif