
#include <Game/entities/entity.h>

Entity::Entity(const std::string& entity_name, const double health, const std::string& file, sf::Vector2u spritesheet_size, const EntityType& type) :
    m_name(entity_name), m_health(health), m_filename(file), m_spritesheet_size(spritesheet_size), m_type(type)
{
    if (!texture.loadFromFile(file)) {
        outl("Error: Cannot load textue for " << entity_name << " (at: " << file << ")");
    }
}
