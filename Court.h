#ifndef COURT_H
#define COURT_H

#include <SFML/Graphics.hpp>   // required for attribute _field



using Area = sf::Rect<float>;

class BouncingBall;

class Court {
public:
/* --Spielfeldraender. */
  enum class Edge { None, Top, Left, Right, Bottom };

  Court(Area field);
   ~Court() = default;
/* --Zeichne das Spielfeld. */
  virtual void paint(sf::RenderWindow& window);
/* --Gibt Spielfeldbegrenzung zurueck. */
  Area area() const { return _field; }
/* --Prueft, ob es eine Kollision gibt. */
  Edge hasCollision(const BouncingBall& ball,sf::Vector2f& point) const;



protected:
Area _field;
};
#endif // COURT_H
