#include "Starfield.hpp"
#include <random>

Starfield::Starfield() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> posDist(0, 800);
    std::uniform_real_distribution<float> speedDist(50, 200);
    
    for (int i = 0; i < 100; ++i) {
        sf::CircleShape star(2.0f);
        star.setPosition(posDist(gen), posDist(gen));
        star.setFillColor(sf::Color::White);
        stars.push_back(star);
        velocities.emplace_back(0, speedDist(gen));
    }
}

void Starfield::update(float deltaTime) {
    for (size_t i = 0; i < stars.size(); ++i) {
        stars[i].move(velocities[i] * deltaTime);
        if (stars[i].getPosition().y > 600) {
            stars[i].setPosition(stars[i].getPosition().x, 0);
        }
    }
}

void Starfield::render(sf::RenderWindow& window) {
    for (const auto& star : stars) {
        window.draw(star);
    }
}
