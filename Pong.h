#ifndef PONG_H
#define PONG_H


// Forward Definition:
class Court;
class Paddle;
class BouncingBall;
namespace sf
{
class RenderWindow;
}


class Pong
{
public:
    Pong();
    Pong(const Pong&) = default;
    Pong& operator=(const Pong&) = default;
     ~Pong();
    /* --Aktualisiere das Spielfeld. */
    void update();
    /* --Zeichne das Spielfeld. */
    void paint(sf::RenderWindow& window);
    /* --Setze Paddle etc. */
    void set(Paddle* p);

    void set(Court* c)
    {
        _court=c;
    }
    void set(BouncingBall* b)
    {
        _ball=b;
    }
    /* --Prueft, ob Spiel beendet ist. */
    bool isGameOver() const
    {
        return done;
    }

    void setGameOver(bool gameOver = true)
    {
        done = gameOver;
    }


protected:
    /* --Ball. */
    BouncingBall* _ball = nullptr;
    /* --Spielfeld. */
    Court* _court = nullptr;
    /* --Schlaeger. */
    Paddle* _paddle = nullptr;

    bool done = false; /* --Ist das Spiel vorbei? */
};


#endif // PONG_H
