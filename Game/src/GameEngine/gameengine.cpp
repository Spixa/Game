#include <Game/GameEngine/gameengine.h>
Var::Var()
{
    m_type = Type::None;
}

Var::~Var()
{
	if (m_type == Type::String)
		delete string_data;
}

Var::Var(const Var& Var)
{
	m_type = Var.m_type;
	switch (m_type)
	{
		case(Type::Float):
		{
			float_data = Var.float_data;
			break;
		}
		case(Type::Int):
		{
			int_data = Var.int_data;
			break;
		}
		case(Type::Bool):
		{
			bool_data = Var.bool_data;
			break;
		}
		case(Type::String):
		{
			string_data = new std::string(*Var.string_data);
			break;
		}
		default:break;
	}
}

Var& Var::operator=(const Var& Var)
{
	m_type = Var.m_type;
	switch (m_type)
	{
		case(Type::Float):
		{
			float_data = Var.float_data;
			break;
		}
		case(Type::Int):
		{
			int_data = Var.int_data;
			break;
		}
		case(Type::Bool):
		{
			bool_data = Var.bool_data;
			break;
		}
		case(Type::String):
		{
			string_data = new std::string(*Var.string_data);
			break;
		}
		default:break;
	}
	return *this;
}

Var::Var(Var&& Var)
{
	m_type = Var.m_type;
	switch (m_type)
	{
	case(Type::Float):
	{
		float_data = Var.float_data;
		break;
	}
	case(Type::Int):
	{
		int_data = Var.int_data;
		break;
	}
	case(Type::Bool):
	{
		bool_data = Var.bool_data;
		break;
	}
	case(Type::String):
	{
		string_data = Var.string_data;
		Var.string_data = nullptr;
		break;
	}
	default:break;
	}
}

Var& Var::operator=(Var&& Var)
{
	m_type = Var.m_type;
	switch (m_type)
	{
	case(Type::Float):
	{
		float_data = Var.float_data;
		break;
	}
	case(Type::Int):
	{
		int_data = Var.int_data;
		break;
	}
	case(Type::Bool):
	{
		bool_data = Var.bool_data;
		break;
	}
	case(Type::String):
	{
		string_data = Var.string_data;
		Var.string_data = nullptr;
		break;
	}
	default:break;
	}
	return *this;
}

Var::Var(bool bool_value)
{
    m_type = Type::Bool;
    bool_data = bool_value;
}

Var::Var(int int_value)
{
    m_type = Type::Int;
    int_data = int_value;
}

Var::Var(const std::string& string_value)
{
    m_type = Type::String;
    string_data = new std::string(string_value);
}

Var::Var(float float_value)
{
    m_type = Type::Float;
    float_data = float_value;
}

bool Var::asBool() const
{
    assert(m_type == Type::Bool);
    return bool_data;
}
int Var::asInt() const
{
    assert(m_type == Type::Int);
    return int_data;
}
float Var::asFloat() const
{
    assert(m_type == Type::Float);
    return float_data;
}
const std::string& Var::asString() const
{
    assert(m_type == Type::String);
    return *string_data;
}
bool Var::isValid() const
{
    return m_type != Type::None;
}

void GameObject::setName(const std::string& name) {
	m_name = name;
}

void GameObject::start() {

}

void GameObject::update(float deltaTime) {

}

void GameObject::render(sf::RenderWindow*) {

}


GameObject::GameObject() {
    m_name = "unknown_obj";
    m_type = Type::Management;
}
GameObject::GameObject(std::string name,const Type& type) : m_name(name), m_type(type) {
	o("Made " << m_name);
}
void GameObject::setVar(const std::string& var_name,const Var& var) {
    objectVars[var_name] = var;
    onVarSet(var_name);
}
void GameObject::onVarSet(const std::string& v) {
    if (v == "x") {
        setPosition({objectVars["x"].asFloat(),getPosition().y});
    } else
    if (v == "y") {
        setPosition({getPosition().y,objectVars["y"].asFloat()});
    } else
    if (v == "name") {
        setName(objectVars["name"].asString());
    }
}


TextureManager::TextureManager() : GameObject("Texture Manager",Type::Management) {
	
	resources["player"] = "entity/player/player.png";
	resources["tiles"] = "tiles/tiles.png";
	resources["common_font"] = "font/common_font.ttf";
	resources["bad"] = "bad/loc/place";

}

void TextureManager::start() {
		
}


std::string TextureManager::grab(std::string to_get) {
	
	if(resources.find(to_get) != resources.end()) {
		return res_path + resources[to_get];
	}
	return resources["bad"];
	
}

/*	 GAME 	ENGINE	*/

GameEngine::GameEngine() {
	init();
}


GameEngine::GameEngine(sf::String title, sf::Vector2u size) : window_title(title), window_size(size) {
	outl(std::to_string(window_size.x) << " - " << std::to_string(window_size.y));
	window = new sf::RenderWindow(sf::VideoMode(window_size.x , window_size.y),title,sf::Style::Close | sf::Style::Resize);
	view = new sf::View();
	window->setView(*view);
	view->setSize(window->getSize().x,window->getSize().y);
	
}
void GameEngine::init() {
	

	m_textureman = new TextureManager();
	pushObject(m_textureman);

	for (auto x : objs_stack) {
		x->start();
	}
	game_init();

	loop();
	
}

void GameEngine::game_init() {

}

GameEngine::~GameEngine() {

}

void GameEngine::pushToRenderStack(sf::Drawable* to_push) {
	render_stack.push_back(to_push);
}

void GameEngine::loop() {
	while (running) {
		render();
		update_base();
		update();
		deltaTime = getDeltaTime();		
	}


}

void GameEngine::update() {

}

void GameEngine::render() {
	window->clear();

	for (auto x : render_stack)
		window->draw(*x);
	for (auto x : objs_stack)
		x->render(window);
	
	window->display();
}



void GameEngine::update_base() {
	for (auto x : objs_stack) {
		x->update(deltaTime);
	}	
	delete(view);
	view = new sf::View(sf::FloatRect(0.f, 0.0f, window->getSize().x, window->getSize().y));
	window->setView(*view);

	while (window->pollEvent(evnt)) {
		switch (evnt.type) {
			case sf::Event::Closed:
				window->close();
				exit(0);
		}
	}
	update_view();

}

float GameEngine::getDeltaTime() {
	return deltaTimeClock.restart().asSeconds();
}

void GameEngine::pushObject(GameObject* to_push) {
	objs_stack.push_back(to_push);
	to_push->start();
}