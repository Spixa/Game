#include "Game.h"

Game* Game::m_instance = nullptr;


Game::Game() : GameEngine("Kewl Game", {720,560}) {

}

Game* Game::getInstance() { 
    if (m_instance == nullptr) {
        return new Game();
    }
    return m_instance;

 }


void Game::run() {
    init();
}

void Game::game_init() {
    scene_man = new SceneManager();
    pushObject(scene_man);
}

void Game::update() {
    if (myRect != NULL) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            myRect->move(-200 * deltaTime,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            myRect->move(200 * deltaTime,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            myRect->move(0,-200 * deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            myRect->move(0,200 * deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            eraseDrawable(myRect);
            scene_man->getCurrentScene()->erase();
        } 
    }

}

void Game::eraseDrawable(sf::Drawable* drawable) {
    int index = util::getIndex(getRenderStack(),drawable); 
    if (index <= getRenderStack().size()) {
        render_stack.erase(render_stack.begin() + index);
    }
}

Game& getGame() {
    return *Game::getInstance();
}