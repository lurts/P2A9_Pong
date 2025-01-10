
#include <SFML/Graphics.hpp>

void showText(const sf::String& t,const sf::Font&  font,sf::RenderWindow& window)
{
    sf::Text text(t,font);
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Blue);
    window.draw(text);
}

