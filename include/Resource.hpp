#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <SFML/Graphics.hpp>

class Resource {
public:
    Resource(sf::Vector2f position);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::CircleShape shape;
};

#endif
