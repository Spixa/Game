#include "scenes.h"
Scene::Scene(std::string name) : m_name(name), GameObject(std::string("SceneManager.scene." + name), GameObject::Type::Ingame) {

}

void Scene::bindGUIObject(GUIObject* d) {
    scene_objects.push_back(d);
}

void Scene::removeGUIObject(GUIObject* d) {
    int index = util::getIndex(scene_objects,d); 
    if (index <= scene_objects.size()) {
        scene_objects.erase(scene_objects.begin() + index);
    }
}

void Scene::start() {

}

void Scene::render(sf::RenderWindow* window) {
    for (auto x : scene_objects) {
        x->predraw(window);
        window->draw(*x);
    }
}

void Scene::update(float deltaTime) {
    updateScene(deltaTime);
}

void Scene::erase() {
    for (auto x : scene_objects) {
        removeGUIObject(x);
    }
}

void Scene::erase_derived() {
    o("Undefined behaviour while erasing scene: " << m_name);
}
/////////////////////////////////////////////

MenuScene::MenuScene() : Scene("menu_scene") {
    if (!font.loadFromFile("res/fonts/common_font.ttf")) {
        outl("sus");
    }
    someText = new Text();
    someText->make("res/fonts/common_font.ttf", 24);
    someText->setString("bromandude");
    bindGUIObject(someText);

}

void MenuScene::erase_derived() {
    
}
void MenuScene::updateScene(float deltaTime) {
    
}


////////////////////////////////////////////

void SceneManager::startScene(Scene* s) {
    s->start();
}

void SceneManager::eraseScene(Scene* s) {
    s->erase();
}

void SceneManager::updateScene(Scene* s, float deltaTime) {
    s->update(deltaTime);
}

void SceneManager::renderScene(Scene* s, sf::RenderWindow* window) {
    s->render(window);
}