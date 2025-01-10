#include <SFML/Graphics.hpp>

#include "Pong.h"
#include "Court.h"
#include "Paddle.h"
#include "BouncingBall.h"
#include "Selection.h"
#include "TennisCourt.h"

#include "util.h"

#include "SuperPong.h"

// class to take ownership of memory of game
// Note: In a real life project, std::unique_ptr would do the job,
//       no user class is required.
class Game
{
public:
    Game(SuperPong* p) : game(p) {}
    ~Game()       {delete game;}
    SuperPong* operator->() const {return game;}
private:
    SuperPong *game;
};


int main()
{
    bool isStarted=false;

    const int width = 1024, height = 736;
    const int frame = 10;

    sf::RenderWindow window(sf::VideoMode(width, height), "EGO PONG!");
    window.setFramerateLimit(50);
    window.setKeyRepeatEnabled(false);

    Selection auswahl = selectMode(window, sf::Vector2f(50, height / 2), sf::Vector2f(5, 5));

    // initialize Game:
    Game    pong(new SuperPong);
    TennisCourt*  court = new TennisCourt(Area(frame,frame,width - 2*frame, height-2*frame));
    Paddle* right = new Paddle( sf::Vector2f(width-frame,height/2),    // position
                                0,                                     // top
                                height,                                // bottom
                                150,                                   // len
                                frame,                                 // width
                                10);                                   // increment
    Paddle* left = new Paddle(  sf::Vector2f(0, height / 2),
                                0,                         // top
                                height,                    // bottom
                                150,                       // len
                                frame,                     // width
                                20,                        // incremwnt
                                Paddle::PaddleType::Left);

    //BouncingBall* ball= new BouncingBall(sf::Vector2f(50, height/2),  // start
    //                                     sf::Vector2f(5,5));          // move vector

    BouncingBall* ball = auswahl.ball;
    bool multiPlayer = (auswahl.numPlayers == 2) ? true : false;


    pong->set(court);  // Pong takes ownership of memory
    pong->set(right);  // Pong takes ownership of memory
    pong->set(ball);   // Pong takes ownership of memory

    if (multiPlayer) {
        pong->set2(left);
    }


    // declare font:
    /* --Lade Schrift aus Datei. */
    sf::Font font;
    if (!font.loadFromFile(FONT))
    {
        return -1;
    }

    bool isRightUp      = false;
    bool isRightDown    = false;
    bool isLeftUp       = false;
    bool isLeftDown     = false;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)  window.close();

            /* --Warte auf Tastendruck. */
            /* --Pruefe den Tastendruck. */
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                if(!isStarted || pong->isGameOver())
                {
                    isStarted=true;
                    ball->reset();
                    pong->setGameOver(false);
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                if (pong->isGameOver())
                {
                    window.close();
                }
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Up)      isRightUp   = true;
                if(event.key.code == sf::Keyboard::Down)    isRightDown = true;
                if(event.key.code == sf::Keyboard::W)       isLeftUp    = true; 
                if(event.key.code == sf::Keyboard::S)       isLeftDown  = true; 
            }
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Up)      isRightUp   = false;
                if(event.key.code == sf::Keyboard::Down)    isRightDown = false;
                if (event.key.code == sf::Keyboard::W)      isLeftUp    = false;
                if (event.key.code == sf::Keyboard::S)      isLeftDown  = false;
            }

        }
        if (isRightUp)                      right->up();
        if (isRightDown)                    right->down();
        if (isLeftUp && multiPlayer)        left->up();
        if (isLeftDown && multiPlayer)      left->down();

        /* --Loesche Bildschirminhalt. */
        window.clear(Mausgrau);
        /* --Ist das Spiel schon gestartet? */
        if (!isStarted || pong->isGameOver())
        {
            /* --Zeichne das Spielfeld. */
            pong->paint(window);
            showText(isStarted ? "GAME OVER\nPRESS E to EXIT\nPRESS S to RESTART" :"PRESS S TO START",font,window);
        }
        else
        {
            /* --Aktualisiere das Spiel. */
            pong->update();
            /* --Zeichne Elemente. */
            pong->paint(window);
        }
        /* --Aktualisiere Inhalt im Fenster. */
        window.display();

    }

    return 0;
}
