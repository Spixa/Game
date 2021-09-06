#ifndef PLAYER_H
#define PLAYER_H

#include <Game/entities/entity.h>

class Player 
    : public Entity
{
public:
    Player();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif