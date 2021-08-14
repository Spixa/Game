#include "scenes.h"
Scene::Scene(std::string name) : m_name(name), GameObject(std::string("SceneManager.scene." + name), GameObject::Type::Ingame) {

}

void Scene::bindDrawable(sf::Drawable* d) {
    scene_objects.push_back(d);
}

void Scene::removeDrawable(sf::Drawable* d) {
    int index = util::getIndex(scene_objects,d); 
    if (index <= scene_objects.size()) {
        scene_objects.erase(scene_objects.begin() + index);
    }
}

void Scene::start() {

}

void Scene::render(sf::RenderWindow* window) {
    for (auto x : scene_objects) {
        window->draw(*x);
    }
}

void Scene::update(float deltaTime) {
    updateScene(deltaTime);
}

void Scene::erase() {
    for (auto x : scene_objects) {
        removeDrawable(x);
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
    
    text_gamename = new sf::Text("Sus Imposter Aewouga LMFAO",font,24);
    bindDrawable(text_gamename);
    text_gamename->setPosition(10,20);

}

void MenuScene::erase_derived() {
    
}
void MenuScene::updateScene(float deltaTime) {
    text_gamename->setString("delta time: " + util::to_str<float>(deltaTime));
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