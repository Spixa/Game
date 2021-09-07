#include <Game/realm/realm.h>
#include <Game/utils/utils.h>
#include <windows.h>

Realm::Realm() : GameObject("realm", GameObject::Type::Ingame),
    m_tilemap(), level({
        3,3,3,3,
        2,2,2,2,
        1,1,1,1,
        0,0,0,0,

    })
{  

    m_tilemap.load("tileset.png", sf::Vector2u(16,16), level, 4, 4);
    m_tilemap.setScale({3.0, 3.0});
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