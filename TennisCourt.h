//
// Created by lars on 11.01.24.
//

#ifndef PONGPONG_TENNISCOURT_H
#define PONGPONG_TENNISCOURT_H

#include <SFML/Graphics.hpp>
#include "Court.h"

class TennisCourt: public Court
{
public:
    TennisCourt(Area a):Court(a){};

    void paint(sf::RenderWindow& window);





};

#endif //PONGPONG_TENNISCOURT_H
