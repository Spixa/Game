
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameEngine.h"
#include "utils.h"
class util;

enum class Scenes {
    MainmenuScene
};

class Scene : public GameObject {
public:
    std::vector<sf::Drawable*> scene_objects;
    std::string m_name;
public:
    void bindDrawable(sf::Drawable*);
    void removeDrawable(sf::Drawable*);    

    void start() override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow* window) override; 

    Scene(std::string name);

    virtual void erase_derived();
    void erase();
    std::vector<sf::Drawable*>* getSceneDrawables() { return &scene_objects;}
};


class SceneManager : public GameObject{
public:
    void start() {
        m_scenes.push_back(new Scene("bro"));
        m_currscene = m_scenes[0];
    }
    void update(float deltaTime) override {
        if (!m_currscene) return;
        updateScene(m_currscene,deltaTime);
    }
    void render(sf::RenderWindow* window) override {
        if (!m_currscene) return;
        renderScene(m_currscene,window);
    }

    void nextScene() {

    }
    void previouseScene() {

    }
    Scene* getCurrentScene() { return m_currscene; }

private:
    void startScene(Scene*);
    void renderScene(Scene*, sf::RenderWindow* window);
    void updateScene(Scene*, float deltaTime);
    void eraseScene(Scene*);
protected:
    std::vector<Scene*> m_scenes;
    Scene* m_currscene;
};

