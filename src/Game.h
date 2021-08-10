#ifndef GAME_h
#define GAME_H
#include "gameengine.h"
#include "scenes.h"

class GUI : public GameObject {
public:
    GUI();

    sf::Vector2f getGUILoc(sf::View* view) {
        return sf::Vector2f(view->getCenter().x - (view->getSize().x / 2), view->getCenter().y - (view->getSize().y / 2));
    }
private:    

};


class Game : GameEngine{
public:
    static Game* getInstance();
    void run();
    void update() override;
    void game_init() override;
private:
    Game();
    static Game* m_instance;
    sf::RectangleShape* myRect;

    enum class State {MenuState,GameState,PauseState} m_state = State::MenuState;

    void eraseDrawable(sf::Drawable* K);

    SceneManager* scene_man; 
};




Game& getGame();

#endif