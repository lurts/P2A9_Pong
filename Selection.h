#ifndef SELECTION_H
#define SELECTION_H


#include "BouncingBall.h"
#include "Pong.h"

struct Selection
{
    BouncingBall* ball;
    Pong*         pong;

    unsigned int  numPlayers;
};

Selection selectMode(sf::RenderWindow& window,    // window
                     const sf::Vector2f& start,   // start location of ball
                     const sf::Vector2f& mvec,    // move vector of ball
                     float radius =10);           // radius of ball;


#endif // SELECTION_H
