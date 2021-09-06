#include <Game/Game.h>
Game* Game::m_instance = 0;


Game::Game() : GameEngine("Kewl Game", {1024,576}) 
{
    outl("Game initialized.");
}

Game* Game::getInstance() { 
    if (m_instance == 0) {
        m_instance = new Game();
    }
    return m_instance;

 }


void Game::run() {
    init();
}

void Game::game_init() {
    scene_man = new SceneManager();
    scene_man->pushScene(new MenuScene());
    scene_man->pushScene(new GameScene());
    pushObject(scene_man);
}

void Game::update() {
    
}

// void Game::eraseDrawable(sf::Drawable* drawable) {
//     int index = util::getIndex(getRenderStack(),drawable); 
//     if (index <= getRenderStack().size()) {
//         render_stack.erase(render_stack.begin() + index);
//     }
// }

Game* getGame() {
    return Game::getInstance();
}