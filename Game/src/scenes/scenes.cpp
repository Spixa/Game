#include <Game/scenes/scenes.h>
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

void Scene::bindGameObject(GameObject* g) {
    if (g->m_type != GameObject::Type::Ingame) {
        outl("Error: Did not bind " << m_name << ".obj." << g->m_name << "\nPerhaps its not an In-game object.");
        return;
    }
    game_objs.push_back(g);
}

void Scene::removeGameObject(GameObject* g) {
    int index = util::getIndex(game_objs, g);
    if (index <= game_objs.size()) {
        game_objs.erase(game_objs.begin() + index);
    }
}

void Scene::start() {
    for (auto x : game_objs) {
        x->start();
    }
}

void Scene::render(sf::RenderWindow* window) {
    for (auto x : scene_objects) {
        x->predraw(window);
        window->draw(*x);
    }

    for (auto x : game_objs) {
        x->render(window);
    }
}

void Scene::update(float deltaTime) {
    for (auto x : game_objs) {
        x->update(deltaTime);
    }
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

MenuScene::MenuScene() : Scene("menu_scene"), clock() {
    if (!font.loadFromFile("res/fonts/common_font.ttf")) {
        outl("sus");
    }
    someText = new Text();
    someText->make("res/fonts/common_font.ttf", 24);
    someText->setString("bromandude");
    bindGUIObject(someText);


    button = new gui::RichButton("Play", font, {75,50}, gui::style::clean);
    quit_btn = new gui::RichButton("Quit", font, {75,150}, gui::style::cancel);

    bindGUIObject(button);
    bindGUIObject(quit_btn);
}

void MenuScene::erase_derived() {
    
}
void MenuScene::updateScene(float deltaTime) {

    button->update(getGame()->evnt, *getGame()->window);
    quit_btn->update(getGame()->evnt, *getGame()->window);
    if (button->getState() == gui::state::clicked) {
        getGame()->getSceneManager()->nextScene();
    }
    if (quit_btn->getState() == gui::state::hovered) {
        quit_btn->setText("Quit?");
    } else {
        quit_btn->setText("Quit");
    }
    if (quit_btn->getState() == gui::state::clicked) {
        exit(0);
    }
}
////////////////////////////////////////////////

GameScene::GameScene() : Scene("game_scene"), m_realm() {
    
    bindGameObject(&m_realm);
}

void GameScene::erase_derived() {

}

void GameScene::updateScene(float deltaTime) {

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

void SceneManager::pushScene(Scene* scene) {
    m_scenes.push_back(scene);
}