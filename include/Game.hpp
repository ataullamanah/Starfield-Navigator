#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Asteroid.hpp"
#include "Resource.hpp"
#include "Starfield.hpp"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();
    void spawnAsteroids();
    void spawnResources();
    void checkCollisions();

    sf::RenderWindow window;
    Player player;
    std::vector<Asteroid> asteroids;
    std::vector<Resource> resources;
    Starfield starfield;
    sf::Font font;
    sf::Text scoreText;
    sf::Text gameOverText;
    int score;
    bool isGameOver;
    bool isPaused;
    sf::Clock clock;
};

#endif
