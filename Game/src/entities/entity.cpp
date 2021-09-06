
#include <Game/entities/entity.h>

Entity::Entity(const std::string& entity_name, const double health, const std::string& file, sf::Vector2u spritesheet_size, const EntityType& type) :
    m_name(entity_name), m_health(health), m_filename(file), m_spritesheet_size(spritesheet_size), m_type(type), m_row(0)
{
    // Could not load textures
    if (!m_texture.loadFromFile(file)) {
        outl("Error: Cannot load textue for " << entity_name << " (at: " << file << ")");
    }
    m_sprite = sf::Sprite(m_texture);

    m_animation = new Animation(&m_texture, m_spritesheet_size, ANIMATION_SPEED);
}

// SFML Draw call 

////////////////////////////////
//          Inherited         //
////////////////////////////////
void Entity::update(float deltaTime) {
    m_sprite.setTextureRect(m_animation->animRect);
}

////////////////////////////////
//     </>  Inherited         //
////////////////////////////////