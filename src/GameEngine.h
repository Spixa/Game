#include <SFML/Graphics.hpp>
class Property
{
public:
	Property();
	Property(bool bool_value);
	Property(int int_value);
	Property(const std::string& string_value);
	Property(float float_value);
	Property(const Property& property);
	Property& operator=(const Property& property);
	Property(Property&& property);
	Property& operator=(Property&& property);
	~Property();
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
	enum class Type { NoInit, Bool, Int, Float, String } m_type;
};



class GameObject {
public:
    GameObject();
    virtual ~GameObject();
    void setName(const std::string& name);
	const std::string& getName() const;
	void setProperty(const std::string& name, const Property& property);
	Property getProperty(const std::string& name) const;
    virtual void start();
	virtual void update(int delta_time);
	virtual void events(const sf::Event& event) {};
	void enable();
	void disable();
	bool isEnabled() const;
	void hide();
	void show();
	bool isVisible() const;
    
    void turnOff();
    void turnOn();

	virtual void draw(sf::RenderWindow* window);
	const Vector& getPosition() const;
	void setPosition(const Vector& point);
	void setPosition(float x, float y);
	void move(const Vector& point);
	void setSize(const Vector& size);
protected:
	virtual void onPropertySet(const std::string& name);
	virtual void onPropertyGet(const std::string& name) const;
	virtual void onActivated() {};
	virtual void onPositionChanged(const Vector& new_pos, const Vector& old_pos) {};
private:
	std::string m_name;
	bool m_started = false;
	std::map<std::string, Property> m_properties;
	bool m_enable;
	bool m_visible;
	Vector m_pos, m_size;
};


class Game {
private:
    

protected:
    void virtual init();
    void virtual update(float deltaTime);

public:
    Game(const std::string& name, const sf::Vector2u resolution);
    ~Game();
    void run();
    
    sf::Vector2u resolution() const;
};