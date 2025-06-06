#include "Player.hpp"
#include <cmath>

Player::Player() : speed(200.0f), rotationSpeed(180.0f) {
    shape.setPointCount(3);
    shape.setPoint(0, sf::Vector2f(0, -20));
    shape.setPoint(1, sf::Vector2f(-15, 20));
    shape.setPoint(2, sf::Vector2f(15, 20));
    shape.setOrigin(0, 0);
    shape.setPosition(400, 500);
    shape.setFillColor(sf::Color::White);
}

void Player::update(float deltaTime) {
    sf::Vector2f position = shape.getPosition();
    position += velocity * deltaTime;
    
    if (position.x < 0) position.x = 0;
    if (position.x > 800) position.x = 800;
    if (position.y < 0) position.y = 0;
    if (position.y > 600) position.y = 600;
    
    shape.setPosition(position);
    velocity *= 0.95f; // Friction
}

void Player::render(sf::RenderWindow& window) {
    window.draw(shape);
}

void Player::handleInput() {
    float rotation = shape.getRotation();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        shape.rotate(-rotationSpeed * 0.016f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        shape.rotate(rotationSpeed * 0.016f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        float rad = rotation * 3.14159f / 180.0f;
        velocity += sf::Vector2f(std::cos(rad), std::sin(rad)) * speed * 0.016f;
    }
}

sf::FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();
}

sf::Vector2f Player::getPosition() const {
    return shape.getPosition();
}
