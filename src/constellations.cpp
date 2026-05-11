#include "Constallations.h"
#include <cmath>
#include <SFML/Graphics.hpp>


// Now we actually DEFINE the offsets as vectors of Star structs:
const std::vector<Star> orionOffsets = {
    {{852.f, 160.f}, " Saiph\n This Star's Magnitude is 2.05\n Its Absolute Magnitude is -4.44\n Its Distance is 647.14 ± 27.07 ly\n And it Scores a -0.15 on the Color index (B-V)"},
    {{886.f, 49.f}, " Alnitak\n This Star's Magnitude is 1.85\n Its Absolute Magnitude is -5.15\n Its Distance is 817.43 ± 112.99 ly\n And it Scores a -0.09 on the Color index (B-V)"},
    {{904.f, 37.f}, " Alnilam\n This Star's Magnitude is 1.65\n Its Absolute Magnitude is -7.26\n Its Distance is 1976.71 ± 423.58 ly\n And it Scores a -0.19 on the Color index (B-V)"},
    {{921.f, 26.f}, " Mintaka\n This Star's Magnitude is 2.40\n Its Absolute Magnitude is -4.84\n Its Distance is 916.17 ± 128.35 ly\n And it Scores a -0.03 on the Color index (B-V)"},
    {{973.f, 145.f}, " Rigel\n This Star's Magnitude is 0.15\n Its Absolute Magnitude is -6.96\n Its Distance is 862.85 ± 71.21 ly\n And it Scores a -0.03 on the Color index (B-V)"},
    {{852.f, -70.f}},
    {{1010.f, -71.f}}
};
const std::vector<std::pair<int, int>> orionConnections =
{
    {0, 1},{1,2},{2,3},{3,4},{4,0},{1,5},{5,6},{6,3}
};


const std::vector<Star> libraOffsets = {
    {{619.f, 253.f}, " 46-Lib\n This Star's Magnitude is 4.10\n Its Absolute Magnitude is 1.01\n Its Distance is 168.47 ± 1.30 ly\n And it Scores a 1.01 on the Color index (B-V)"},
    {{681.f, 227.f}, " Zubenelhakrabi\n This Star's Magnitude is 3.90\n Its Absolute Magnitude is 0.40\n Its Distance is 163.16 ± 1.30 ly\n And it Scores a 1.01 on the Color index (B-V)"},
    {{748.f, 153.f}, " Zubeneschamali\n This Star's Magnitude is 2.60\n Its Absolute Magnitude is -1.17\n Its Distance is 185.11 ± 1.67 ly\n And it Scores a -0.06 on the Color index (B-V)"},
    {{777.f, 381.f}, " Brachium\n This Star's Magnitude is 3.25\n Its Absolute Magnitude is -1.48\n Its Distance is 288.38 ± 6.24 ly\n And it Scores a 1.67 on the Color index (B-V)"},
    {{832.f, 235.f}, " Zubenelgenubi\n This Star's Magnitude is 2.75\n Its Absolute Magnitude is 0.92\n Its Distance is 75.80 ± 0.33 ly\n And it Scores a 0.16 on the Color index (B-V)"}
};
const std::vector<std::pair<int, int>> libraConnections = {
    {0, 1},
    {2, 4},
    {4, 3},
    {1, 3},
    {1,2}
};
//done scorpio names only
const std::vector<Star> scorpioOffsets = {

    {{634.f, 565.f}, " Girtab\n This Star's Magnitude is 2.95\n Its Absolute Magnitude is -5.91\n Its Distance is 1929.92 ± 157.33 ly\n And it Scores a 0.51 on the Color index (B-V)"},
    {{647.f, 548.f}, " Mula\n This Star's Magnitude is 2.35\n Its Absolute Magnitude is -3.50\n Its Distance is 483.19 ± 11.87 ly\n And it Scores a -0.19 on the Color index (B-V)"},
    {{660.f, 605.f}, " Sagras\n This Star's Magnitude is 1.85\n Its Absolute Magnitude is -2.76\n Its Distance is 272.02 ± 30.07 ly\n And it Scores a 0.41 on the Color index (B-V)"},
    {{673.f, 522.f}, " Shaula\n This Star's Magnitude is 1.60\n Its Absolute Magnitude is -4.62\n Its Distance is 571.20 ± 66.32 ly\n And it Scores a -0.22 on the Color index (B-V)"},
    {{726.f, 613.f}, " (BAA) Sco\n This Star's Magnitude is 3.30\n Its Absolute Magnitude is 1.54\n Its Distance is 73.48 ± 0.26 ly\n And it Scores a 0.44 on the Color index (B-V)"},
    {{772.f, 605.f}, " (Zeta) Sco\n This Star's Magnitude is 4.70\n Its Absolute Magnitude is -6.04\n Its Distance is 4593.75 ± 1167.74 ly\n And it Scores a 0.35 on the Color index (B-V)"},
    {{789.f, 547.f}, " Xamidimura\n This Star's Magnitude is 3.00\n Its Absolute Magnitude is -4.14\n Its Distance is 874.41 ± 135.82 ly\n And it Scores a -0.19 on the Color index (B-V)"},
    {{802.f, 492.f}, " Larawag\n This Star's Magnitude is 2.25\n Its Absolute Magnitude is 0.80\n Its Distance is 63.71 ± 0.27 ly\n And it Scores a 1.14 on the Color index (B-V)"},
    {{858.f, 414.f}, " Paikauhale\n This Star's Magnitude is 2.80\n Its Absolute Magnitude is -3.01\n Its Distance is 474.06 ± 33.91 ly\n And it Scores a -0.22 on the Color index (B-V)"},
    {{881.f, 393.f}, " Antares\n This Star's Magnitude is 1.65\n Its Absolute Magnitude is -5.10\n Its Distance is 553.75 ± 80.37 ly\n And it Scores a 1.86 on the Color index (B-V)"},
    {{978.f, 331.f}, " Acrab\n This Star's Magnitude is 2.60\n Its Absolute Magnitude is -3.46\n Its Distance is 530.34 ± 59.69 ly\n And it Scores a -0.06 on the Color index (B-V)"},
    {{980.f, 407.f}, " Fang\n This Star's Magnitude is 2.85\n Its Absolute Magnitude is -3.42\n Its Distance is 585.56 ± 60.35 ly\n And it Scores a -0.19 on the Color index (B-V)"},
    {{988.f, 356.f}, " Dschubba\n This Star's Magnitude is 2.35\n Its Absolute Magnitude is -3.10\n Its Distance is 401.67 ± 39.68 ly\n And it Scores a -0.03 on the Color index (B-V)"}
};
const std::vector<std::pair<int, int>> scorpioConnections = {
    {0,1},{0,2},{1,3},{2,4},{4,5},{5,6},{6,7},{7,8},{8,9},{9,10},{9,11},{9,12}

};

const std::vector<Star> sagitariusOffsets =
{
    {{397.f, 402.f}, " Terebellum IV\n This Star's Magnitude is 4.40\n Its Absolute Magnitude is -1.29\n Its Distance is 448.63 ± 10.84 ly\n And it Scores a 1.64 on the Color index (B-V)"},
    {{422.f, 509.f}, " ISO 11\n This Star's Magnitude is 4.35\n  Its Absolute Magnitude is -1.66 \nIts Distance is 518.53 ± 16.75 ly\n And it Scores a -0.15 on the Color index (B-V)"},
    {{449.f, 602.f}, " l Sgr\n This Star's Magnitude is 4.10\n  Its Absolute Magnitude is 0.37\nIts Distance is 181.80 ± 2.10 ly\n And it Scores a 1.07 on the Color index (B-V)"},
    {{477.f, 350.f}, " h1 Sgr - 51 Sgr\nThis Star's Magnitude is 5.60\n Its Absolute Magnitude is 1.02\n Its Distance is 268.66 ± 2.23 ly\n And it Scores a 1.02 on the Color index (B-V)"},
    {{518.f, 251.f }, " p1 Sgr \n This Star's Magnitude is 3.90\n  Its Absolute Magnitude is 0.95\nIts Distance is 126.96 ± 0.93 ly\n And it Scores a 0.22 on the Color index (B-V)" },
    {{532.f, 575.f}, " Rukbat (Alrami)\nThis Star's Magnitude is 3.95\n Its Absolute Magnitude is 0.22\n Its Distance is 181.80 ± 2.20 ly\n And it Scores a -0.09 on the Color index (B-V)"},
    {{538.f, 634.f}, " Arkab Posterior\n This Star's Magnitude is 4.25\n  Its Absolute Magnitude is 0.35\nIts Distance is 134.17 ± 1.04 ly\n And it Scores a 1.18 on the Color index (B-V)"},
    {{571.f, 387.f}," Namalsadirah II\n This Star's Magnitude is 3.30\n Its Absolute Magnitude is 0.53\n Its Distance is 116.99 ± 2.97 ly\n And it Scores a 1.17 on the Color index (B-V)"},
    {{587.f, 420.f}," Ascella\n This Star's Magnitude is 3.25\n Its Absolute Magnitude is 1.07\n Its Distance is 89.09 ± 2.07 ly\n And it Scores a 0.00 on the Color index (B-V)"},
    {{600.f, 295.f},  " 37 Sgr\n This Star's Magnitude is 3.50\n  Its Absolute Magnitude is -1.75\nIts Distance is 365.24 ± 20.46 ly\n And it Scores a 1.14 on the Color index (B-V)"},
    {{609.f, 367.f}," Nunki ( Sadira )\n This Star's Magnitude is 2.05\n Its Absolute Magnitude is -2.17\n Its Distance is 227.76 ± 4.52 ly\n And it Scores a -0.12 on the Color index (B-V)"},
    {{630.f, 378.f},  " Namalsidrah I\n This Star's Magnitude is 3.15\n Its Absolute Magnitude is -1.18\n Its Distance is 239.29 ± 3.29 ly\n And it Scores a -1.18 on the Color index (B-V)"},
    {{630.f, 378.f}, " Namalsidrah I\n This Star's Magnitude is 3.15\n Its Absolute Magnitude is -1.18\n Its Distance is 239.29 ± 3.29 ly\n And it Scores a -1.18 on the Color index (B-V)"},
    {{696.f, 358.f}, " Kaus Borealis\n This Star's Magnitude is 2.80\n  Its Absolute Magnitude is 0.90\nIts Distance is 78.18 ± 0.30 ly\n And it Scores a 1.01 on the Color index (B-V)"},
    {{700.f, 485.f}, " Kaus Australis\n This Star's Magnitude is 1.75\n Its Absolute Magnitude is -1.46\n Its Distance is 143.30 ± 1.50 ly\n And it Scores a -0.03 on the Color index (B-V)"},
    {{714.f, 418.f}, " Kaus Media\n This Star's Magnitude is 2.70\n Its Absolute Magnitude is -2.44\n Its Distance is 347.71 ± 6.55 ly\n And it Scores a 1.39 on the Color index (B-V)"},
    {{715.f, 520.f}, " Hamalwarid \n This Star's Magnitude is 3.10\n  Its Absolute Magnitude is 1.58\nIts Distance is 145.93 ± 1.55 ly\n And it Scores a 1.58 on the Color index (B-V)"},
    {{745.f, 299.f}, " Al Thalimain\n This Star's Magnitude is 3.80\n  Its Absolute Magnitude is -11.43\nIts Distance is 36239.60 ly\n And it Scores a 0.19 on the Color index (B-V)"},
    {{760.f, 433.f}, " Al Nasl\n This Star's Magnitude is 2.95\n Its Absolute Magnitude is 0.59\n Its Distance is 96.87 ± 0.52 ly\n And it Scores a 0.98 on the Color index (B-V)"},
    {{820.f, 403.f}, " 2 Sgr - 3 Sgr\n This Star's Magnitude is 4.50\n Its Absolute Magnitude is -2.82\n Its Distance is 950.89 ± 52.89 ly\n And it Scores a 0.60 on the Color index (B-V)"},
    {{571.f, 317.f}, " 39 Sgr\n This Star's Magnitude is 3.75\n  Its Absolute Magnitude is 0.55\nIts Distance is 142.05 ± 1.47 ly\n And it Scores a 1.01 on the Color index (B-V)"}
};

const std::vector<std::pair<int, int>> sagitariusConnections = {
    {0, 1}, {1, 2}, {2, 6}, {2, 5}, {0, 3}, {3, 8}, {8, 7}, {9, 10}, {12, 11},
{11, 8}, {12, 15}, {15, 14}, {14, 8}, {11, 10}, {10, 7}, {12, 13},
{13, 15}, {13, 17}, {15, 18}, {18, 14}, {14, 16}, {18, 19},{20,4}, {20,9}
};
const std::vector<Star> capricornusOffsets = {
    {{638.f, 225.f}, " Deneb Algedi\n This Star's Magnitude is 2.85\n Its Absolute Magnitude is 0.19\n Its Distance is 38.70 ± 0.09 ly\n And it Scores a 0.19 on the Color index (B-V)"},
    {{663.f, 234.f}, " Nashira\n This Star's Magnitude is 3.65\n Its Absolute Magnitude is 0.24\n Its Distance is 157.03 ± 5.26 ly\n And it Scores a 0.32 on the Color index (B-V)"},
    {{703.f, 316.f}, " 34 Cap\n This Star's Magnitude is 3.75\n Its Absolute Magnitude is -1.61\n Its Distance is 385.53 ± 9.34 ly\n And it Scores a 1.01 on the Color index (B-V)"},
    {{722.f, 239.f}, " 32 Cap\n This Star's Magnitude is 4.25\n Its Absolute Magnitude is 0.35\n Its Distance is 196.72 ± 3.15 ly\n And it Scores a 0.89 on the Color index (B-V)"},
    {{777.f, 248.f}, " 23 Cap\n This Star's Magnitude is 4.05\n Its Absolute Magnitude is 0.57\n Its Distance is 162.19 ± 2.23 ly\n And it Scores a 0.00 on the Color index (B-V)"},
    {{809.f, 389.f}, " 18 Cap\n This Star's Magnitude is 4.10\n Its Absolute Magnitude is -3.42\n Its Distance is 1038.71 ± 109.79 ly\n And it Scores a 1.64 on the Color index (B-V)"},
    {{832.f, 370.f}, " 16 Cap\n This Star's Magnitude is 4.10\n Its Absolute Magnitude is 3.27\n Its Distance is 47.87 ± 0.19 ly\n And it Scores a 0.41 on the Color index (B-V)"},
    {{935.f, 230.f}, " Dabih Major\n This Star's Magnitude is 3.05\n Its Absolute Magnitude is -3.11\n Its Distance is 555.63 ± 44.90 ly\n And it Scores a 0.79 on the Color index (B-V)"},
    {{952.f, 201.f}, " Algedi\n This Star's Magnitude is 3.55\n Its Absolute Magnitude is 0.99\n Its Distance is 105.83 ± 0.65 ly\n And it Scores a 0.89 on the Color index (B-V)"}


};
const std::vector<std::pair<int, int>> capricornusConnections = {
    {0,1},{1,3},{3,4},{3,2},{2,4},{4,5},{4,7},{7,6},{7,8}
};


const std::vector<Star> virgoOffsets =
{
    {{650.f, 80.f}, " Rijl al Awwa\n This Star's Magnitude is 3.85\n Its Absolute Magnitude is 2.54\n Its Distance is 59.59 ± 0.22 ly\n And it Scores a 0.38 on the Color index (B-V)"},
    {{748.f, 88.f},  " Syrma\n This Star's Magnitude is 4.05\n Its Absolute Magnitude is 2.31\n Its Distance is 72.53 ± 0.31 ly\n And it Scores a 0.51 on the Color index (B-V)"},
    {{757.f, 151.f}, " Algafar I\n This Star's Magnitude is 4.15\n Its Absolute Magnitude is -0.31\n Its Distance is 254.81 ± 4.88 ly\n And it Scores a 1.33 on the Color index (B-V)"},
    {{907.f, 20.f}, " Heze\n This Star's Magnitude is 3.35\n Its Absolute Magnitude is 1.58\n Its Distance is 73.52 ± 0.82 ly\n And it Scores a 0.10 on the Color index (B-V)"},
    {{925.f, 180.f}, " Spica\n This Star's Magnitude is 0.95\n Its Absolute Magnitude is -3.47\n Its Distance is 249.74 ± 12.70 ly\n And it Scores a -0.25 on the Color index (B-V)"},
    {{1068.f, -21.f}, " Minelauva\n This Star's Magnitude is 3.35\n Its Absolute Magnitude is -0.57\n Its Distance is 198.39 ± 2.62 ly\n And it Scores a 1.58 on the Color index (B-V)"},
    {{1110.f, 57.f}, " Porrima\n This Star's Magnitude is 3.40\n Its Absolute Magnitude is 3.04\n Its Distance is 38.58 ± 0.27 ly\n And it Scores a 0.32 on the Color index (B-V)"},
    {{1197.f, 57.f}, " Zaniah\n This Star's Magnitude is 3.85\n Its Absolute Magnitude is -0.63\n Its Distance is 257.02 ± 8.65 ly\n And it Scores a 0.04 on the Color index (B-V)"},
    {{650.f,-80.f}},
    {{800.f, -50.f}}

};
const std::vector<std::pair<int, int>> virgoConnections = {
    {0,1},{1,2},{2,4},{4,3},{4,6},{6,7}, {3,5}, {5,6},{3,8},{8,9}
};

const std::vector<Star> aquariusOffsets = {
    {{100.f, 170.f}, " 91 Aqr\n This Star's Magnitude is 4.20\n Its Absolute Magnitude is 0.98\n Its Distance is 143.74 ± 1.65 ly\n And it Scores a 1.11 on the Color index (B-V)"},
    {{112.f, 346.f}, " b1 Aqr\n This Star's Magnitude is 3.95\n Its Absolute Magnitude is 0.45\n Its Distance is 163.40 ± 1.86 ly\n And it Scores a 1.07 on the Color index (B-V)"},
    {{163.f, 349.f}, " c2 Aqr\n This Star's Magnitude is 3.65\n Its Absolute Magnitude is -0.95\n Its Distance is 270.67 ± 4.85 ly\n And it Scores a 1.20 on the Color index (B-V)"},
    {{186.f, 132.f}, " Hydor\n This Star's Magnitude is 3.70\n Its Absolute Magnitude is -1.16\n Its Distance is 305.39 ± 15.40 ly\n And it Scores a 1.64 on the Color index (B-V)"},
    {{211.f, 222.f}, " 71 Aqr\n This Star's Magnitude is 4.05\n Its Absolute Magnitude is -0.89\n Its Distance is 317.58 ± 8.72 ly\n And it Scores a 1.58 on the Color index (B-V)"},
    {{236.f, 10.f}, " 62 Aqr\n This Star's Magnitude is 4.00\n Its Absolute Magnitude is 0.44\n Its Distance is 167.86 ± 2.13 ly\n And it Scores a -0.09 on the Color index (B-V)"},
    {{262.f, 5.f}, " Sadaltager\n This Star's Magnitude is 4.10\n Its Absolute Magnitude is 1.59\n Its Distance is 103.44 ± 3.97 ly\n And it Scores a 0.41 on the Color index (B-V)"},
    {{292.f, 25.f}, " Sadachbia\n This Star's Magnitude is 3.85\n Its Absolute Magnitude is 0.95\n Its Distance is 123.97 ± 3.49 ly\n And it Scores a -0.06 on the Color index (B-V)"},
    {{320.f, 118.f}, " 43 Aqr\n This Star's Magnitude is 4.15\n Its Absolute Magnitude is 0.35\n Its Distance is 187.45 ± 2.45 ly\n And it Scores a 0.98 on the Color index (B-V)"},
    {{352.f, 4.f}, " Sadalmeik\n This Star's Magnitude is 2.95\n Its Absolute Magnitude is -3.08\n Its Distance is 523.53 ± 15.49 ly\n And it Scores a 0.98 on the Color index (B-V)"},
    {{365.f, 205.f}, " 33 Aqr\n This Star's Magnitude is 4.25\n Its Absolute Magnitude is 0.60\n Its Distance is 175.16 ± 2.05 ly\n And it Scores a 0.-0.06 on the Color index (B-V)"},
    {{484.f, 75.f}, " Sadalsuud\n This Star's Magnitude is 2.90\n Its Absolute Magnitude is -3.18\n Its Distance is 537.33 ± 18.79 ly\n And it Scores a 0.82 on the Color index (B-V)"},
    {{641.f, 130.f}, "2 Aqr\n This Star's Magnitude is 3.75\n Its Absolute Magnitude is -0.27\n Its Distance is 207.74 ± 2.74 ly\n And it Scores a 0.00 on the Color index (B-V)"}
};
const std::vector<std::pair<int, int>> aquariusConnections = {
    {0,1},{0,3},{3,5},{5,6},{6,7},{7,9},{9,11},{11,12},{9,8},{8,10},{8,4},{4,2}
};


std::vector<std::pair<sf::Vector2f, std::string>> drawConstellation(sf::RenderWindow& window, float rotationAngle, const std::vector<Star>& offsets,
    const std::vector<std::pair<int, int>>& connections)
{
    sf::Vector2f celestialPole(625.f, 3700.f); // Center of rotation
    sf::Vector2f referencePoint(0.f, 0.f);      // Starting reference

    std::vector<sf::Vector2f> rotatedPositions;
    std::vector<std::pair<sf::Vector2f, std::string>> finalStars; // Store final rotated star positions and names
    std::vector<sf::CircleShape> stars;        // Circle shapes for drawing

    // Rotate each star
    sf::Angle rotateBy = sf::degrees(rotationAngle);
    float rad = rotateBy.asRadians();
    float cosA = std::cos(rad);
    float sinA = std::sin(rad);
    // Create the stars
    for (const auto& starInfo : offsets) {
        sf::CircleShape star(3.f);
        star.setPosition(referencePoint + starInfo.offset);
        stars.push_back(star);
        finalStars.push_back({ sf::Vector2f(0.f, 0.f), starInfo.name }); // Initialize position, will update later
    }

    for (size_t i = 0; i < stars.size(); ++i) {
        sf::Vector2f offset = stars[i].getPosition() - celestialPole;

        sf::Vector2f rotatedOffset;
        rotatedOffset.x = offset.x * cosA - offset.y * sinA;
        rotatedOffset.y = offset.x * sinA + offset.y * cosA;

        sf::Vector2f finalPosition = celestialPole + rotatedOffset;
        stars[i].setPosition(finalPosition);
        finalStars[i].first = finalPosition; // Update the rotated position
        rotatedPositions.push_back(finalPosition);
    }
    // Draw lines between stars
    for (const auto& connection : connections) {
        int idx1 = connection.first;
        int idx2 = connection.second;

        sf::Vertex line[] =
        {
            sf::Vertex(rotatedPositions[idx1], sf::Color::White),
            sf::Vertex(rotatedPositions[idx2], sf::Color::White)
        };
        window.draw(line, 2, sf::PrimitiveType::Lines);
    }
    // Draw all stars
    for (const auto& star : stars) {
        window.draw(star);
    }

    return finalStars; // Return the vector of pairs
}

float TotalRotation(float hour, int month, int day)
{
    float tothours = (hour)+((month - 1) * 2.f) + ((day - 1) * 0.055f);
    float adjustedHour = std::fmod(tothours, 24.f);

    if (adjustedHour <= 12.f)
        return adjustedHour * 3.65f;
    else
        return (adjustedHour - 24.f) * 3.48f;
}
