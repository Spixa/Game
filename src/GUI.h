
#include "GameEngine.h"
class GUIObject : public sf::Transformable , public sf::Drawable  { 
private:
    sf::Texture texture;
public: 
    GUIObject();
    virtual ~GUIObject();
    void predraw(sf::RenderWindow* window) {
        setPosition(window->getView().getSize().x - (window->getView().getCenter().x), window->getView().getSize().y - (window->getView().getCenter().y));
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {

    }
    
};

class Text
    : public GUIObject
{   
private:
    sf::Text text;
    sf::Font textFont;
public:
    Text() {

    }
    void loadFromFile(const sf::String& font) {
        if (!textFont.loadFromFile(font)) {
            o("Couldn't load font");
        }
        text.setFont(textFont);
    }
    void make(const sf::String& font, unsigned short fontsize) {
        loadFromFile(font);
        text.setCharacterSize(fontsize);
    }
    void setString(const sf::String to_set) {
        text.setString(to_set);
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform.combine(getTransform());
        target.draw(text,states);
    }



};