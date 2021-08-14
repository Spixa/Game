#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "includes.h"

#define INVALID "invalid"
#define o(x) std::cout << "Game Logs > "<< x << std::endl
#define out_(x) std::cout << "Game Logs > "<< x
#define outl(x) std::cout << "Game Logs > "<< x << std::endl


class Var {
public:
    Var();
	Var(bool bool_value);
	Var(int int_value);
	Var(const std::string& string_value);
	Var(float float_value);
	Var(const Var& Var);
	Var& operator=(const Var& Var);
	Var(Var&& Var);
	Var& operator=(Var&& Var);
	~Var();
	bool asBool() const;
	int asInt() const;
	float asFloat() const;
	const std::string& asString() const;
	bool isValid() const;

    
private:
	union
	{
		int int_data;
		float float_data;
		std::string* string_data;
		bool bool_data;
	};
    enum class Type {None,Int,String,Float,Bool} m_type;
};

class GameObject {
public:
    std::string m_name;
    enum class Type {Management,Ingame} m_type;
    std::map<std::string, Var> objectVars;
    sf::Vector2f objectPosition;

    GameObject();
    GameObject(std::string name,const Type&);

    void setName(const std::string&);

    void setPosition(const sf::Vector2f& pos) {
        objectPosition = pos;
    }

    const sf::Vector2f& getPosition() const {
        return objectPosition;
    };

    void setVar(const std::string&, const Var&);

    virtual void start();
    virtual void update(float deltaTime);
    virtual void render(sf::RenderWindow* window);
protected: // Events
    void onVarSet(const std::string&);
};



class TextureManager : public GameObject { 
private:
    const std::string res_path = "res/";

public:
    TextureManager();
    void start() override;
    std::string grab(std::string);
    std::map<std::string,std::string> getResources() { return resources; }

private:
    std::map<std::string,std::string> resources;
};



class GameEngine {
public:
    // used to iterate to run update() and start() functions
    std::vector<GameObject*> objs_stack;

    // Individual objects
    TextureManager* m_textureman;


    sf::RenderWindow* window;
    sf::View* view;
    sf::Vector2u window_size;
    sf::String window_title;

    std::vector<sf::Drawable*> render_stack;    
    sf::Clock deltaTimeClock;
    float deltaTime;
public:
    bool running = true;

    std::vector<sf::Drawable*>& getRenderStack() { return render_stack; }
    void pushToRenderStack  (sf::Drawable*  ); 

    GameEngine();
    GameEngine(sf::String,sf::Vector2u);
    void init();
    virtual void game_init();
    ~GameEngine();

    void loop();
    void render();
    void update_base();
    float getDeltaTime();
    virtual void update();
    void update_view() {
        view->setSize((float) window->getSize().x,(float) window->getSize().y);
    }
    TextureManager* getTextureManager() { return m_textureman; }
    void setCenter(sf::Vector2u loc) { view->setCenter(loc.x,loc.y); }

    void pushObject(GameObject*);
};

#endif