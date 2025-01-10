#include "Selection.h"
#include "StrangeBall.h"
#include "CrazyBall.h"
#include "SuperPong.h"
#include <string>
#include <vector>


#include "util.h"

Selection selectMode(sf::RenderWindow& window,
                     const sf::Vector2f& start,
                     const sf::Vector2f& mvec,
                     float radius)
{
    bool isConfigured       = false;

    Selection ret = {new BouncingBall(start, mvec, radius),
                     new Pong,
                     1};

    sf::Font font;
    if (!font.loadFromFile(FONT))
    {
        return ret;
    }

    std::vector<std::string> basemenu;
    basemenu.push_back("*** PONG 2.0 Configuration Menu ***");
    basemenu.push_back("Player         [1] | [2] ");
    basemenu.push_back("Ball     [N] | [S] | [C] ");
    basemenu.push_back("[X] Leave Configuration ");

    std::vector<std::string> menu(basemenu);

    window.setFramerateLimit(50);
    while(!isConfigured)
    {
        sf::Event event;

        std::string mtext = menu[0]+'\n' +
                            menu[1]+'\n' +
                            menu[2]+'\n' +
                            menu[3]+'\n';

        window.clear(sf::Color::Black);
        sf::Text text(mtext,font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        window.draw(text);
        window.display();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
               isConfigured = true;
            }
            if (event.type == sf::Event::KeyPressed)
            {
                // Players:
                if(event.key.code == sf::Keyboard::Numpad1 ||
                   event.key.code == sf::Keyboard::Num1)
                {
                    ret.numPlayers = 1;
                    delete ret.pong;
                    ret.pong = new Pong;
                    menu[1] = basemenu[1] + " --> Single    ";
                }
                if(event.key.code == sf::Keyboard::Numpad2 ||
                   event.key.code == sf::Keyboard::Num2)
                {
                    ret.numPlayers = 2;
                    delete ret.pong;
                    ret.pong = new SuperPong;
                    menu[1] = basemenu[1] + " --> MULTI";
                }
                // Ball:
                if(event.key.code == sf::Keyboard::N)
                {
                    delete ret.ball;
                    ret.ball = new BouncingBall(start, mvec, radius);
                    menu[2] = basemenu[2] + " --> NORMAL";
                }
                if(event.key.code == sf::Keyboard::S)
                {
                    delete ret.ball;
                    ret.ball = new StrangeBall(start, mvec, radius);
                    menu[2] = basemenu[2] + " --> Strange";
                }
                if(event.key.code == sf::Keyboard::C)
                {
                    delete ret.ball;
                    ret.ball = new CrazyBall(start, mvec, radius);
                    menu[2] = basemenu[2] + " --> Crazy";
                }
                if(event.key.code == sf::Keyboard::X)
                {
                    isConfigured   = true;
                    if (ret.ball == nullptr)
                    {
                        ret.ball = new BouncingBall(start, mvec, radius);
                    }
                }
            }
        }
    }
    return ret;
}


