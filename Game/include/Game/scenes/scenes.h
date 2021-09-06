#ifndef SCENES_H
#define SCENES_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <Game/GameEngine/gameengine.h>
#include <Game/utils/utils.h>
#include <Game/gui/GUI.h>
#include <Game/realm/realm.h>
enum class Scenes {
    MainmenuScene
};

class Scene : public GameObject {
public:
    std::vector<GUIObject*> scene_objects;
    std::vector<GameObject*> game_objs;
    std::string m_name;
public:
    void bindGUIObject(GUIObject*);
    void removeGUIObject(GUIObject*);    

    void bindGameObject(GameObject*);
    void removeGameObject(GameObject*);

    void start() override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow* window) override; 

    // Constructor takes a name
    Scene(std::string name);

    virtual void updateScene(float deltaTime) {}   
    
    virtual void erase_derived();
    void erase();
    std::vector<GUIObject*>* getSceneGUIObjects()   { return &scene_objects;}
    std::vector<GameObject*>* getSceneGameObjects() { return &game_objs;    }
};

/////////////////////////////////
class MenuScene
    : public Scene {
public:
    MenuScene();
    void erase_derived() override;
    void updateScene(float deltaTime) override; 
protected:
    Text* someText;
    gui::RichButton* button;
    gui::RichButton* quit_btn;
    sf::Clock clock;
    sf::Font font;
};
/////////////////////////////////
class GameScene 
    : public Scene {
public:
    GameScene();
    void erase_derived() override;
    void updateScene(float deltaTime) override;
private:
    Realm m_realm;
};
//////////////////////////////////
class SceneManager : public GameObject{
public:
    void start() {
        m_currscene = m_scenes[0];
        m_scene_index = 0;
    }   
    void update(float deltaTime) override {
        if (!m_currscene) {
            outl("Note: invalid scene update.");
            return;
        }
        updateScene(m_currscene,deltaTime);
    }
    void render(sf::RenderWindow* window) override {
        if (!m_currscene) {
            outl("Note: invalid scene update.");
            return;
        }
        renderScene(m_currscene,window);
    }
    void nextScene() {
        m_scene_index++;
        // Scene is out of bounds. Index was not allocated by the vector
        if (m_scenes.size() <= m_scene_index) {
            outl("Error: scene " << std::to_string(m_scene_index) << " is out of bounds.\nperhaps its not yet to be pushed on the vector");
            m_scene_index--;
            return;
        }
        outl("Erasing...");
        m_currscene->erase();
        outl("Erased.");

        outl("Loading new scene... (" << m_scene_index << ")");
        m_currscene = m_scenes[m_scene_index];
        outl("Loaded " << m_currscene->m_name);
    }
    void previouseScene() {
        if (m_scene_index - 1 < 0) {
            outl("Error: scene " << std::to_string(m_scene_index - 1) << " is negative. cannot load.");
            return;
        }
        m_currscene->erase();
        m_scene_index--;
        m_currscene = m_scenes[m_scene_index];
    }
    Scene* getCurrentScene() { return m_currscene; }
    ~SceneManager() {
        for (auto x : m_scenes) {
            delete(x);
        }
        delete(m_currscene);
    }

    void pushScene(Scene*);
private:
    void startScene(Scene*);
    void renderScene(Scene*, sf::RenderWindow* window);
    void updateScene(Scene*, float deltaTime);
    void eraseScene(Scene*);
protected:
    std::vector<Scene*> m_scenes;
    Scene* m_currscene;
    int m_scene_index=0;
    
    friend TileMap;
};


#endif