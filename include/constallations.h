
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// Define a Star struct to hold a position and a name
struct Star
{
    sf::Vector2f offset;
    std::string name;
};

// Extern declarations for each constellation
extern const std::vector<Star> orionOffsets;
extern const std::vector<Star> libraOffsets;
extern const std::vector<Star> scorpioOffsets;
extern const std::vector<Star> sagitariusOffsets;
extern const std::vector<Star> capricornusOffsets;
extern const std::vector<Star> virgoOffsets;
extern const std::vector<Star> aquariusOffsets;

extern const std::vector<std::pair<int, int>> orionConnections;
extern const std::vector<std::pair<int, int>> libraConnections;
extern const std::vector<std::pair<int, int>> scorpioConnections;
extern const std::vector<std::pair<int, int>> sagitariusConnections;
extern const std::vector<std::pair<int, int>> capricornusConnections;
extern const std::vector<std::pair<int, int>> virgoConnections;
extern const std::vector<std::pair<int, int>> aquariusConnections;

// Function declarations
std::vector<std::pair<sf::Vector2f, std::string>> drawConstellation(sf::RenderWindow& window, float rotationAngle, const std::vector<Star>& offsets,
    const std::vector<std::pair<int, int>>& connections);
float TotalRotation(float hour, int month, int day);
