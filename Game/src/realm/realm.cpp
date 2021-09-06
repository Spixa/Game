#include <Game/realm/realm.h>

Realm::Realm() : GameObject("realm", GameObject::Type::Ingame),
    m_tilemap()
{

    m_tilemap.load("tileset.png", sf::Vector2u(32,32), level, 32, 32);
    m_player = new Player();
}

void Realm::render(sf::RenderWindow* window) {
    window->draw(m_tilemap);
    window->draw(*m_player);
}

void Realm::update(float deltaTime) {
    m_player->animateRow(1, deltaTime);
    m_player->update(deltaTime);
}

void Realm::start() {

}