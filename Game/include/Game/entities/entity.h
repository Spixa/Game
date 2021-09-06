#ifndef ENTITY_H
#define ENTITY_H

#define ANIMATION_SPEED 0.2f

#include <Game/GameEngine/gameengine.h>

// Features:
#include <Game/component/animation.h>

enum class EntityType{None, Player};
class Entity : public sf::Drawable, public sf::Transformable 
{
private:
    std::string m_name;
    double m_health;
    std::string m_filename;
    sf::Vector2u m_spritesheet_size;
    EntityType m_type;  


public:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    Animation* m_animation;
    int m_row;
public:
    Entity(const std::string&, const double, const std::string&, sf::Vector2u, const EntityType&); 
    void update(float deltaTime);

    // getters
    const std::string& getName() { return m_name; }
    const double getHealth() { return m_health; }
    const EntityType& getType() { return m_type; }

    // setters
    void setHealth(const double value) { m_health = value; }
    void animate(float deltaTime) { m_animation->update(m_row, deltaTime);}
    void animateRow(int row, float deltaTime) {
        m_row = row;    
        m_animation->update(m_row, deltaTime);
    }
};

#endif