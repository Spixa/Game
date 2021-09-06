#ifndef GUI_H
#define GUI_H

#include <Game/GameEngine/gameengine.h>


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
namespace gui {
    namespace style {
        enum
        {
            none = 0,
            save = 1,
            cancel = 2,
            clean = 3,
        };
    };

    namespace state
    {
        enum
        {
            normal = 0,
            hovered = 1,
            clicked = 2
        };
    };

class RichButton
    : public GUIObject
{
public:
    // Default constructor
    RichButton();

    // All in one setup
    //      Sets up the button in a singular constructor
    RichButton(sf::String, sf::Font&, sf::Vector2f, sf::Uint8 style);

    ~RichButton();

public:  // Functions
        void setColorTextNormal(sf::Color text){m_textNormal = text;};
        void setColorTextHover(sf::Color text){m_textHover = text;};
        void setColorTextClicked(sf::Color text){m_textClicked = text;};
        void setColorNormal(sf::Color bgNormal){m_bgNormal = bgNormal;};
        void setColorHover(sf::Color bgHover){m_bgHover = bgHover;};
        void setColorClicked(sf::Color bgClicked){m_bgClicked = bgClicked;};
        void setBorderColor(sf::Color border){m_border = border;};
        void setBorderThickness(float t){m_borderThickness = t;};
        void setBorderRadius(float r){m_borderRadius = r;};
        void setPosition(sf::Vector2f position){m_position = position;};
        void setSize(unsigned int size);
        void setText(std::string s)
        {
            m_text.setString(s);
            m_shadow = m_text;
        };
        
        // Definition in .cpp file
        void setStyle(sf::Uint8 style);
        void setFont(sf::Font& font);

        sf::Vector2f getPosition(){return m_position;};
        sf::Vector2f getDimensions(){return sf::Vector2f(m_button.getGlobalBounds().width, m_button.getGlobalBounds().height);};
        sf::Uint8 getState(){return m_state;};

        void update(sf::Event& e, sf::RenderWindow& window);
public: // Inherited abstract functions
    // From GUIObject -> sf::Drawable 
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
private:
    
    sf::Color m_bgNormal;
    sf::Color m_bgHover;
    sf::Color m_bgClicked;
    sf::Color m_textNormal;
    sf::Color m_textHover;
    sf::Color m_textClicked;
    sf::Color m_border;

    float m_borderThickness;
    float m_borderRadius;

    sf::Vector2f m_size;
    sf::Vector2f m_position;
    sf::Uint8 m_style;
    sf::Uint8 m_state;

    sf::ConvexShape m_button;
    sf::Font m_font;
    unsigned int m_fontSize;
    sf::Text m_text;
    sf::Text m_shadow;
};


};


#endif