#ifndef GAME_H
#define GAME_H
#include <Game/GameEngine/gameengine.h>
#include <Game/scenes/scenes.h>

class Scene;
class SceneManager;
class MenuScene;
enum class Scenes;

class GUI : public GameObject {
public:
    GUI();

    sf::Vector2f getGUILoc(sf::View* view) {
        return sf::Vector2f(view->getCenter().x - (view->getSize().x / 2), view->getCenter().y - (view->getSize().y / 2));
    }
private:    

};


class Game : public GameEngine{
public:
    static Game* getInstance();
    void run();
    void update() override;
    void game_init() override;

    SceneManager* getSceneManager() {
        return scene_man;
    }
private:
    Game();
    static Game* m_instance;
    sf::RectangleShape* myRect;

    enum class State {MenuState,GameState,PauseState} m_state = State::MenuState;

    void eraseDrawable(sf::Drawable* K);

    SceneManager* scene_man; 

private:
    Game(Game const&);
    Game& operator=(Game const&);

};

Game* getGame();


#endif