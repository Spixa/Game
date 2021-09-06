#include <Game/realm/realm.h>

Realm::Realm() : GameObject("realm", GameObject::Type::Ingame),
    m_tilemap()
{

    m_tilemap.load("tileset.png", sf::Vector2u(32,32), level, 32, 32);
}

void Realm::render(sf::RenderWindow* window) {
    window->draw(m_tilemap);
}

void Realm::update(float deltaTime) {

}

void Realm::start() {

}