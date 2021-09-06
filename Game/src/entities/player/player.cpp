#include <Game/entities/player/player.h>

Player::Player()
    : Entity("player", 20.0, "res/textures/player/player.png", {4, 4}, EntityType::Player) 
{

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // override states that are given to suit the Entity class
    states.transform *= getTransform();
    states.texture = &m_texture;

    // Draw it to the render target
    target.draw(m_sprite, states);
}
