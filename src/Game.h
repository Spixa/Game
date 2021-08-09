#ifndef GAME_h
#define GAME_H

#include "gameengine.h"

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
};

class util {
public:
    static int getIndex(std::vector<sf::Drawable*> v, sf::Drawable* K)
    {
        auto it = find(v.begin(), v.end(), K);
    
        // If element was found
        if (it != v.end())
        {
        
            // calculating the index
            // of K
            int index = it - v.begin();
            return index;
        }
        else {
            // If the element is not
            // present in the vector
            return -1;
        }
    }

};

Game& getGame();

#endif