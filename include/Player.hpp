#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    void handleInput();
    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition() const;

private:
    sf::ConvexShape shape;
    float speed;
    float rotationSpeed;
    sf::Vector2f velocity;
};

#endif
