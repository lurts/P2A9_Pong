//
// Created by lars on 11.01.24.
//

#include "TennisCourt.h"

#include <SFML/Graphics.hpp>
#include <vector>

// 1024 x 736

void TennisCourt::paint(sf::RenderWindow& window)
{
    Court::paint(window);

    float dicke = 6;
    sf::VertexArray m(sf::Quads, 24);
    //obere horizontale Linie
    m[0].position = sf::Vector2f(10, area().height * 0.12);
    m[1].position = sf::Vector2f(area().width + 10, area().height * 0.12);
    m[2].position = sf::Vector2f(area().width + 10, area().height * 0.12 + dicke);
    m[3].position = sf::Vector2f(10, area().height * 0.12 + dicke);
    //untere horizontale Linie
    m[4].position = sf::Vector2f(10, area().height * 0.88);
    m[5].position = sf::Vector2f(area().width + 10, area().height * 0.88);
    m[6].position = sf::Vector2f(area().width + 10, area().height * 0.88 + dicke);
    m[7].position = sf::Vector2f(10, area().height * 0.88 + dicke);
    //linke vertikale Linie
    m[8].position = sf::Vector2f(area().width * 0.23, area().height * 0.12);
    m[9].position = sf::Vector2f(area().width * 0.23 + dicke, area().height * 0.12);
    m[10].position = sf::Vector2f(area().width * 0.23 + dicke, area().height * 0.88);
    m[11].position = sf::Vector2f(area().width * 0.23, area().height * 0.88);
    //rechte vertikale Linie
    m[12].position = sf::Vector2f(area().width * 0.77, area().height * 0.12);
    m[13].position = sf::Vector2f(area().width * 0.77 + dicke, area().height * 0.12);
    m[14].position = sf::Vector2f(area().width * 0.77 + dicke, area().height * 0.88);
    m[15].position = sf::Vector2f(area().width * 0.77, area().height * 0.88);
    //mittlere horizontale Linie
    m[16].position = sf::Vector2f(area().width * 0.23, area().height * 0.5);
    m[17].position = sf::Vector2f(area().width * 0.77, area().height * 0.5);
    m[18].position = sf::Vector2f(area().width * 0.77, area().height * 0.5 + dicke);
    m[19].position = sf::Vector2f(area().width * 0.23, area().height * 0.5 + dicke);
    //mittlere vertikale Linie
    m[20].position = sf::Vector2f(area().width * 0.5, 0);
    m[21].position = sf::Vector2f(area().width * 0.5 + dicke*2, 0);
    m[22].position = sf::Vector2f(area().width * 0.5 + dicke*2, area().height + 10);
    m[23].position = sf::Vector2f(area().width * 0.5, area().height + 10);
    m[20].color = sf::Color::Black;
    m[21].color = sf::Color::Black;
    m[22].color = sf::Color::Black;
    m[23].color = sf::Color::Black;

    window.draw(m);
}