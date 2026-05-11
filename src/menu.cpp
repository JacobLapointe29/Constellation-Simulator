#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <optional>
#include <cmath>
#include "Constallations.h"
#include<string>

enum MenuState {  MONTH_MENU, DAYS_MENU, HOURS_MENU, INCREMINT_PLUS_MENU, INCREMINT_MINUS_MENU, CONSTELLATIONS, FUNFACTS };
enum MonthType { Month_31, Month_30, Month_28 };

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Constellation Explorer", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    //loading in a font for the program to use when writting
    sf::Font font;
    if (!font.openFromFile("assets/TypewritterFont.ttf"))
    {
        std::cerr << "Failed to load TypewritterFont.ttf\n";
        return 1;
    }
   //display live hour
    sf::Text fact(font);
    fact.setCharacterSize(30);
    fact.setFillColor(sf::Color::White);
    fact.setPosition({ 250, 300 });

    sf::Text live_hour(font);
    live_hour.setCharacterSize(16);
    live_hour.setFillColor(sf::Color::White);
    live_hour.setPosition({ 320, 698});

    //month text
    sf::Text month_text(font);
    month_text.setString("Welcome to Our Constellation Exploration Simulator!\nChoose the Month you want to see Constellations on.");
    month_text.setPosition({ 300, 25 });
    month_text.setCharacterSize(24);
    month_text.setFillColor(sf::Color(173, 216, 230));
    month_text.setStyle(sf::Text::Underlined);

    //days text
    sf::Text days_text(font);
    days_text.setString("Choose which day you want to see the Constellations on.");
    days_text.setPosition({ 250, 75 });
    days_text.setCharacterSize(24);
    days_text.setFillColor(sf::Color(173, 216, 230));
    days_text.setStyle(sf::Text::Underlined | sf::Text::Bold);

    //hours text
    sf::Text hours_text(font);
    hours_text.setString("Choose which time of day you want to see the Constellations on.");
    hours_text.setPosition({ 250, 75 });
    hours_text.setCharacterSize(24);
    hours_text.setFillColor(sf::Color(173, 216, 230));
    hours_text.setStyle(sf::Text::Underlined | sf::Text::Bold);

    //loading months menu image
    sf::Texture months_texture;
    if (!months_texture.loadFromFile("assets/Months.png")) {
        std::cerr << "Failed to load Months.png\n";
        return 1;
    }
    sf::Sprite months_sprite(months_texture);
    months_sprite.setPosition({ 375, 150 });

    //Loading all 3 differnt days displays from file
    //31 days   
    sf::Texture texture_31days;
    if (!texture_31days.loadFromFile("assets/31days.png")) {
        std::cerr << "Failed to load 31days.png\n";
        return 1;
    }
    sf::Sprite days_31_sprite(texture_31days);
    days_31_sprite.setPosition({ 375, 150 });

    //loading 30 days  image 
    sf::Texture texture_30days;
    if (!texture_30days.loadFromFile("assets/30days.png")) {
        std::cerr << "Failed to load 30days.png\n";
        return 1;
    }
    sf::Sprite days_30_sprite(texture_30days);
    days_30_sprite.setPosition({ 375, 150 });

    //loading 28 days image
    sf::Texture texture_28days;
    if (!texture_28days.loadFromFile("assets/28days.png")) {
        std::cerr << "Failed to load 28days.png\n";
        return 1;
    }
    sf::Sprite days_28_sprite(texture_28days);
    days_28_sprite.setPosition({ 375, 150 });

    //loading 24 hours image 
    sf::Texture texture_24hours;
    if (!texture_24hours.loadFromFile("assets/24hours.png")) {
        std::cerr << "Failed to load 24hours.png\n";
        return 1;
    }
    sf::Sprite hours_24(texture_24hours);
    hours_24.setPosition({ 375, 150 });
   
    //back to start button
    sf::Texture BacK_button_texture;
    if (!BacK_button_texture.loadFromFile("assets/back_to_start_button.png")) {
        std::cerr << "back_to_start_button.png\n";
        return 1;
    }
    sf::Sprite BacK_button_sprite(BacK_button_texture);
    BacK_button_sprite.setPosition({ 800, 150 });
    
    //buttons for hours
    sf::Texture hour_plus_texture;
    if (!hour_plus_texture.loadFromFile("assets/+hour.png")) {
        std::cerr << "assets/+hour.png\n";
        return 1;
    }
    sf::Sprite hour_plus_sprite(hour_plus_texture);
    hour_plus_sprite.setPosition({ 700, 585 });

    sf::Texture hour_minus_texture;
    if (!hour_minus_texture.loadFromFile("assets/-hour.png")) {
        std::cerr << "-hour.png\n";
        return 1;
    }
    sf::Sprite hour_minus_sprite(hour_minus_texture);
    hour_minus_sprite.setPosition({ 550, 585 });

    sf::Texture Horizon_texture;
    if (!Horizon_texture.loadFromFile("assets/Horizon.png")) {
        std::cerr << "Failed to load Horizon.png\n";
        return 1;
    }
    sf::Sprite Horizon_sprite(Horizon_texture);
    Horizon_sprite.setPosition({0,-25});

    //setting click delay parameters
    sf::Clock clickClock;
    sf::Time delayTime = sf::seconds(0.3);


    MonthType monthtype = Month_28; //declare monthtype as anything so that it is initialized and can change in the first loop and be used in the second 
    MenuState menuState = MONTH_MENU;

    float hour = 0, month = 0, day = 0;
    std::string clickedStar;


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color(0, 0, 50));
        if (menuState == MONTH_MENU)
        {
            window.draw(month_text);
            window.draw(months_sprite);
            window.display();
            
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && clickClock.getElapsedTime() > delayTime)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);

                if (localPosition.x >= 376 && localPosition.y >= 152 && localPosition.x <= 882 && localPosition.y <= 552)
                {
                    // Check which month was clicked
                    if (localPosition.x <= 630)
                    {
                        if (localPosition.y <= 215)
                        {
                            month = 1;
                           
                            monthtype = Month_31;
                        }
                        else if (localPosition.y <= 282)
                        {
                            month = 2;
                            monthtype = Month_28;
                        }
                        else if (localPosition.y <= 349)
                        {
                            month = 3;
                            monthtype = Month_31;
                        }
                        else if (localPosition.y <= 417)
                        {
                            month = 4;
                            monthtype = Month_30;
                        }
                        else if (localPosition.y <= 483)
                        {
                            month = 5;
                            monthtype = Month_31;
                        }
                        else
                        {
                            month = 6;
                            monthtype = Month_30;
                        }
                    }
                    else {
                        if (localPosition.y <= 214)
                        {
                            month = 7;
                            monthtype = Month_31;
                        }
                        else if (localPosition.y <= 282)
                        {
                            month = 8;
                            monthtype = Month_31;
                        }
                        else if (localPosition.y <= 348)
                        {
                            month = 9;
                            monthtype = Month_30;
                        }
                        else if (localPosition.y <= 415)
                        {
                            month = 10;
                            monthtype = Month_31;
                        }
                        else if (localPosition.y <= 481)
                        {
                            month = 11;
                            monthtype = Month_30;
                        }
                        else
                        {
                            month = 12;
                            monthtype = Month_31;
                        }
                    }

                    menuState = DAYS_MENU;
                    clickClock.restart();
                }
            }
        }

        else if (menuState == DAYS_MENU && monthtype == Month_31)
        {
            window.clear(sf::Color(0, 0, 50));
            window.draw(days_text);
            window.draw(days_31_sprite);
            window.display();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && clickClock.getElapsedTime() > delayTime)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);

                if ((localPosition.x >= 384 && localPosition.y >= 159 && localPosition.x <= 578 && localPosition.y <= 492) ||
                    (localPosition.x >= 605 && localPosition.y >= 160 && localPosition.x <= 867 && localPosition.y <= 420))
                {
                    if (localPosition.x >= 387 && localPosition.y >= 161 && localPosition.x <= 435 && localPosition.y <= 205)
                    {
                        day = 1;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 161 && localPosition.x <= 506 && localPosition.y <= 205)
                    {
                        day = 2;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 161 && localPosition.x <= 575 && localPosition.y <= 205)
                    {
                        day = 3;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 161 && localPosition.x <= 648 && localPosition.y <= 205)
                    {
                        day = 4;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 161 && localPosition.x <= 721 && localPosition.y <= 205)
                    {
                        day = 5;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 161 && localPosition.x <= 794 && localPosition.y <= 205)
                    {
                        day = 6;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 161 && localPosition.x <= 867 && localPosition.y <= 205)
                    {
                        day = 7;
                    }
                    if (localPosition.x >= 387 && localPosition.y >= 233 && localPosition.x <= 435 && localPosition.y <= 274)
                    {
                        day = 8;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 233 && localPosition.x <= 506 && localPosition.y <= 274)
                    {
                        day = 9;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 233 && localPosition.x <= 575 && localPosition.y <= 274)
                    {
                        day = 10;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 233 && localPosition.x <= 648 && localPosition.y <= 274)
                    {
                        day = 11;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 233 && localPosition.x <= 721 && localPosition.y <= 274)
                    {
                        day = 12;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 233 && localPosition.x <= 794 && localPosition.y <= 274)
                    {
                        day = 13;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 233 && localPosition.x <= 867 && localPosition.y <= 274)
                    {
                        day = 14;
                    }
                    if (localPosition.x >= 387 && localPosition.y >= 303 && localPosition.x <= 435 && localPosition.y <= 347)
                    {
                        day = 15;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 303 && localPosition.x <= 506 && localPosition.y <= 347)
                    {
                        day = 16;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 303 && localPosition.x <= 575 && localPosition.y <= 347)
                    {
                        day = 17;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 303 && localPosition.x <= 648 && localPosition.y <= 347)
                    {
                        day = 18;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 303 && localPosition.x <= 721 && localPosition.y <= 347)
                    {
                        day = 19;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 303 && localPosition.x <= 794 && localPosition.y <= 347)
                    {
                        day = 20;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 303 && localPosition.x <= 867 && localPosition.y <= 347)
                    {
                        day = 21;
                    }
                    if (localPosition.x >= 387 && localPosition.y >= 377 && localPosition.x <= 435 && localPosition.y <= 420)
                    {
                        day = 22;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 377 && localPosition.x <= 506 && localPosition.y <= 420)
                    {
                        day = 23;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 377 && localPosition.x <= 575 && localPosition.y <= 420)
                    {
                        day = 24;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 377 && localPosition.x <= 648 && localPosition.y <= 420)
                    {
                        day = 25;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 377 && localPosition.x <= 721 && localPosition.y <= 420)
                    {
                        day = 26;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 377 && localPosition.x <= 794 && localPosition.y <= 420)
                    {
                        day = 27;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 377 && localPosition.x <= 867 && localPosition.y <= 420)
                    {
                        day = 28;
                    }
                    if (localPosition.x >= 387 && localPosition.y >= 450 && localPosition.x <= 435 && localPosition.y <= 491)
                    {
                        day = 29;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 450 && localPosition.x <= 506 && localPosition.y <= 491)
                    {
                        day = 30;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 450 && localPosition.x <= 575 && localPosition.y <= 491)
                    {
                        day = 31;
                    }

                    //std::cout << "Day selected at: X = " << localPosition.x << ", Y = " << localPosition.y << "\n";
                    menuState = HOURS_MENU;
                    clickClock.restart();
                }
            }
        }

        else if (menuState == DAYS_MENU && monthtype == Month_30)
        {
            window.clear(sf::Color(0, 0, 50));
            window.draw(days_text);
            window.draw(days_30_sprite);
            window.display();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && clickClock.getElapsedTime() > delayTime)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);

                if ((localPosition.x >= 384 && localPosition.y >= 159 && localPosition.x <= 506 && localPosition.y <= 492) ||
                    (localPosition.x >= 531 && localPosition.y >= 160 && localPosition.x <= 867 && localPosition.y <= 420))
                {
                    if (localPosition.x >= 387 && localPosition.y >= 161 && localPosition.x <= 435 && localPosition.y <= 205)
                    {
                        day = 1;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 161 && localPosition.x <= 506 && localPosition.y <= 205)
                    {
                        day = 2;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 161 && localPosition.x <= 575 && localPosition.y <= 205)
                    {
                        day = 3;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 161 && localPosition.x <= 648 && localPosition.y <= 205)
                    {
                        day = 4;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 161 && localPosition.x <= 721 && localPosition.y <= 205)
                    {
                        day = 5;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 161 && localPosition.x <= 794 && localPosition.y <= 205)
                    {
                        day = 6;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 161 && localPosition.x <= 867 && localPosition.y <= 205)
                    {
                        day = 7;
                    }
                    if (localPosition.x >= 387 && localPosition.y >= 233 && localPosition.x <= 435 && localPosition.y <= 274)
                    {
                        day = 8;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 233 && localPosition.x <= 506 && localPosition.y <= 274)
                    {
                        day = 9;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 233 && localPosition.x <= 575 && localPosition.y <= 274)
                    {
                        day = 10;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 233 && localPosition.x <= 648 && localPosition.y <= 274)
                    {
                        day = 11;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 233 && localPosition.x <= 721 && localPosition.y <= 274)
                    {
                        day = 12;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 233 && localPosition.x <= 794 && localPosition.y <= 274)
                    {
                        day = 13;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 233 && localPosition.x <= 867 && localPosition.y <= 274)
                    {
                        day = 14;
                    }
                    if (localPosition.x >= 387 && localPosition.y >= 303 && localPosition.x <= 435 && localPosition.y <= 347)
                    {
                        day = 15;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 303 && localPosition.x <= 506 && localPosition.y <= 347)
                    {
                        day = 16;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 303 && localPosition.x <= 575 && localPosition.y <= 347)
                    {
                        day = 17;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 303 && localPosition.x <= 648 && localPosition.y <= 347)
                    {
                        day = 18;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 303 && localPosition.x <= 721 && localPosition.y <= 347)
                    {
                        day = 19;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 303 && localPosition.x <= 794 && localPosition.y <= 347)
                    {
                        day = 20;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 303 && localPosition.x <= 867 && localPosition.y <= 347)
                    {
                        day = 21;
                    }
                    if (localPosition.x >= 387 && localPosition.y >= 377 && localPosition.x <= 435 && localPosition.y <= 420)
                    {
                        day = 22;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 377 && localPosition.x <= 506 && localPosition.y <= 420)
                    {
                        day = 23;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 377 && localPosition.x <= 575 && localPosition.y <= 420)
                    {
                        day = 24;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 377 && localPosition.x <= 648 && localPosition.y <= 420)
                    {
                        day = 25;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 377 && localPosition.x <= 721 && localPosition.y <= 420)
                    {
                        day = 26;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 377 && localPosition.x <= 794 && localPosition.y <= 420)
                    {
                        day = 27;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 377 && localPosition.x <= 867 && localPosition.y <= 420)
                    {
                        day = 28;
                    }
                    if (localPosition.x >= 387 && localPosition.y >= 450 && localPosition.x <= 435 && localPosition.y <= 491)
                    {
                        day = 29;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 450 && localPosition.x <= 506 && localPosition.y <= 491)
                    {
                        day = 30;
                    }
                    //std::cout << "Day selected at: X = " << localPosition.x << ", Y = " << localPosition.y << "\n";
                    menuState = HOURS_MENU;
                    clickClock.restart();
                }
            }
        }
        else if (menuState == DAYS_MENU && monthtype == Month_28)
        {
            window.clear(sf::Color(0, 0, 50));
            window.draw(days_text);
            window.draw(days_28_sprite);
            window.display();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && clickClock.getElapsedTime() > delayTime)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);

                if (localPosition.x >= 384 && localPosition.y >= 159 && localPosition.x <= 867 && localPosition.y <= 420)
                {
                    if (localPosition.x >= 387 && localPosition.y >= 161 && localPosition.x <= 435 && localPosition.y <= 205)
                    {
                        day = 1;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 161 && localPosition.x <= 506 && localPosition.y <= 205)
                    {
                        day = 2;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 161 && localPosition.x <= 575 && localPosition.y <= 205)
                    {
                        day = 3;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 161 && localPosition.x <= 648 && localPosition.y <= 205)
                    {
                        day = 4;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 161 && localPosition.x <= 721 && localPosition.y <= 205)
                    {
                        day = 5;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 161 && localPosition.x <= 794 && localPosition.y <= 205)
                    {
                        day = 6;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 161 && localPosition.x <= 867 && localPosition.y <= 205)
                    {
                        day = 7;
                    }
                    if (localPosition.x >= 387 && localPosition.y >= 233 && localPosition.x <= 435 && localPosition.y <= 274)
                    {
                        day = 8;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 233 && localPosition.x <= 506 && localPosition.y <= 274)
                    {
                        day = 9;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 233 && localPosition.x <= 575 && localPosition.y <= 274)
                    {
                        day = 10;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 233 && localPosition.x <= 648 && localPosition.y <= 274)
                    {
                        day = 11;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 233 && localPosition.x <= 721 && localPosition.y <= 274)
                    {
                        day = 12;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 233 && localPosition.x <= 794 && localPosition.y <= 274)
                    {
                        day = 13;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 233 && localPosition.x <= 867 && localPosition.y <= 274)
                    {
                        day = 14;
                    }
                    if (localPosition.x >= 387 && localPosition.y >= 303 && localPosition.x <= 435 && localPosition.y <= 347)
                    {
                        day = 15;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 303 && localPosition.x <= 506 && localPosition.y <= 347)
                    {
                        day = 16;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 303 && localPosition.x <= 575 && localPosition.y <= 347)
                    {
                        day = 17;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 303 && localPosition.x <= 648 && localPosition.y <= 347)
                    {
                        day = 18;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 303 && localPosition.x <= 721 && localPosition.y <= 347)
                    {
                        day = 19;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 303 && localPosition.x <= 794 && localPosition.y <= 347)
                    {
                        day = 20;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 303 && localPosition.x <= 867 && localPosition.y <= 347)
                    {
                        day = 21;
                    }
                    if (localPosition.x >= 387 && localPosition.y >= 377 && localPosition.x <= 435 && localPosition.y <= 420)
                    {
                        day = 22;
                    }
                    if (localPosition.x >= 458 && localPosition.y >= 377 && localPosition.x <= 506 && localPosition.y <= 420)
                    {
                        day = 23;
                    }
                    if (localPosition.x >= 531 && localPosition.y >= 377 && localPosition.x <= 575 && localPosition.y <= 420)
                    {
                        day = 24;
                    }
                    if (localPosition.x >= 605 && localPosition.y >= 377 && localPosition.x <= 648 && localPosition.y <= 420)
                    {
                        day = 25;
                    }
                    if (localPosition.x >= 677 && localPosition.y >= 377 && localPosition.x <= 721 && localPosition.y <= 420)
                    {
                        day = 26;
                    }
                    if (localPosition.x >= 751 && localPosition.y >= 377 && localPosition.x <= 794 && localPosition.y <= 420)
                    {
                        day = 27;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 377 && localPosition.x <= 867 && localPosition.y <= 420)
                    {
                        day = 28;
                    }
                    //std::cout << "Day selected at: X = " << localPosition.x << ", Y = " << localPosition.y << "\n";
                    menuState = HOURS_MENU;
                    clickClock.restart();
                }
            }
        }
        else if (menuState == HOURS_MENU)
        {
            window.clear(sf::Color(0, 0, 50));
            window.draw(days_text);
            window.draw(hours_24);
            window.display();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && clickClock.getElapsedTime() > delayTime)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);

                if (localPosition.x >= 379 && localPosition.y >= 152 && localPosition.x <= 907 && localPosition.y <= 503)
                {
                    // std::cout << "Day selected at: X = " << localPosition.x << ", Y = " << localPosition.y << "\n";
                    if (localPosition.x >= 378 && localPosition.y >= 152 && localPosition.x <= 463 && localPosition.y <= 234)
                    {
                        hour = 1;
                    }
                    if (localPosition.x >= 466 && localPosition.y >= 152 && localPosition.x <= 550 && localPosition.y <= 234)
                    {
                        hour = 2;
                    }
                    if (localPosition.x >= 553 && localPosition.y >= 152 && localPosition.x <= 638 && localPosition.y <= 234)
                    {
                        hour = 3;
                    }
                    if (localPosition.x >= 641 && localPosition.y >= 152 && localPosition.x <= 731 && localPosition.y <= 234)
                    {
                        hour = 4;
                    }
                    if (localPosition.x >= 733 && localPosition.y >= 152 && localPosition.x <= 819 && localPosition.y <= 234)
                    {
                        hour = 5;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 152 && localPosition.x <= 907 && localPosition.y <= 234)
                    {
                        hour = 6;
                    }
                    if (localPosition.x >= 379 && localPosition.y >= 235 && localPosition.x <= 463 && localPosition.y <= 325)
                    {
                        hour = 7;
                    }
                    if (localPosition.x >= 466 && localPosition.y >= 235 && localPosition.x <= 550 && localPosition.y <= 325)
                    {
                        hour = 8;
                    }
                    if (localPosition.x >= 553 && localPosition.y >= 235 && localPosition.x <= 638 && localPosition.y <= 325)
                    {
                        hour = 9;
                    }
                    if (localPosition.x >= 641 && localPosition.y >= 235 && localPosition.x <= 731 && localPosition.y <= 325)
                    {
                        hour = 10;
                    }
                    if (localPosition.x >= 733 && localPosition.y >= 235 && localPosition.x <= 819 && localPosition.y <= 325)
                    {
                        hour = 11;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 235 && localPosition.x <= 907 && localPosition.y <= 325)
                    {
                        hour = 12;
                    }
                    if (localPosition.x >= 379 && localPosition.y >= 326 && localPosition.x <= 463 && localPosition.y <= 416)
                    {
                        hour = 13;
                    }
                    if (localPosition.x >= 466 && localPosition.y >= 326 && localPosition.x <= 550 && localPosition.y <= 416)
                    {
                        hour = 14;
                    }
                    if (localPosition.x >= 553 && localPosition.y >= 326 && localPosition.x <= 638 && localPosition.y <= 416)
                    {
                        hour = 15;
                    }
                    if (localPosition.x >= 641 && localPosition.y >= 326 && localPosition.x <= 731 && localPosition.y <= 416)
                    {
                        hour = 16;
                    }
                    if (localPosition.x >= 733 && localPosition.y >= 326 && localPosition.x <= 819 && localPosition.y <= 416)
                    {
                        hour = 17;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 326 && localPosition.x <= 907 && localPosition.y <= 416)
                    {
                        hour = 18;
                    }
                    if (localPosition.x >= 379 && localPosition.y >= 417 && localPosition.x <= 463 && localPosition.y <= 503)
                    {
                        hour = 19;
                    }
                    if (localPosition.x >= 466 && localPosition.y >= 417 && localPosition.x <= 550 && localPosition.y <= 503)
                    {
                        hour = 20;
                    }
                    if (localPosition.x >= 553 && localPosition.y >= 417 && localPosition.x <= 638 && localPosition.y <= 503)
                    {
                        hour = 21;
                    }
                    if (localPosition.x >= 641 && localPosition.y >= 417 && localPosition.x <= 731 && localPosition.y <= 503)
                    {
                        hour = 22;
                    }
                    if (localPosition.x >= 733 && localPosition.y >= 417 && localPosition.x <= 819 && localPosition.y <= 503)
                    {
                        hour = 23;
                    }
                    if (localPosition.x >= 822 && localPosition.y >= 417 && localPosition.x <= 907 && localPosition.y <= 503)
                    {
                        hour = 24;
                    }

                    menuState = CONSTELLATIONS;
                    clickClock.restart();
                    
                }

            }
        }
        else if (menuState == CONSTELLATIONS)
        {
           
            
            if (hour < 0) hour += 24;
           if (hour >= 24) hour -= 24;
            
            //detect sky color
            if (7 < hour < 17)
            {
                window.clear(sf::Color(173, 216, 230));
            }
            if (hour > 17 || hour<7)
            {
                window.clear(sf::Color(0, 0, 20));

            }
            if(hour == 7 || hour ==17)
                window.clear(sf::Color(0, 0, 120));
            
            window.draw(Horizon_sprite);
            window.draw(hour_minus_sprite);
            window.draw(hour_plus_sprite);

            live_hour.setString("hour: " + std::to_string(static_cast<int>(hour))+":00");
            window.draw(live_hour);



            float orionRotation = TotalRotation(hour, month, day);
            float libraRotation = TotalRotation(hour + (-8.8f), month, day);
            float scorpioRotation = TotalRotation(hour + (-10.8f), month, day);
            float sagittariusRotation = TotalRotation(hour + (-12.3f), month, day);
            float capricornusRotation = TotalRotation(hour + (-15.f), month, day);
            float virgoRotation = TotalRotation(hour + (-7.8f), month, day);
            float aquariusRotation = TotalRotation(hour + (-13.99f), month, day);

            auto orionStars = drawConstellation(window, orionRotation, orionOffsets, orionConnections);
            auto libraStars = drawConstellation(window, libraRotation, libraOffsets, libraConnections);
            auto scorpioStars = drawConstellation(window, scorpioRotation, scorpioOffsets, scorpioConnections);
            auto sagittariusStars = drawConstellation(window, sagittariusRotation, sagitariusOffsets, sagitariusConnections);
            auto capricornusStars = drawConstellation(window, capricornusRotation, capricornusOffsets, capricornusConnections);
            auto virgoStars = drawConstellation(window, virgoRotation, virgoOffsets, virgoConnections);
            auto aquariusStars = drawConstellation(window, aquariusRotation, aquariusOffsets, aquariusConnections);

            
            window.display();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && clickClock.getElapsedTime() > delayTime)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                //std::cout << "Day selected at: X = " << localPosition.x << ", Y = " << localPosition.y << "\n";
                
                if (localPosition.x >= 593 && localPosition.y >= 663 && localPosition.x <= 702 && localPosition.y <= 711)
                {
                    menuState = INCREMINT_MINUS_MENU;
                }
                if (localPosition.x >= 746 && localPosition.y >= 663 && localPosition.x <= 853 && localPosition.y <= 711)
                {
                    menuState = INCREMINT_PLUS_MENU;
                }
                
                auto checkStars = [&](const std::vector<std::pair<sf::Vector2f, std::string>>& stars) 
                {
                    for (const auto& [position, name] : stars)
                    {
                        if (std::hypot(localPosition.x - position.x, localPosition.y - position.y) < 15)
                        {
                            clickedStar = name;
                            menuState = FUNFACTS;
                        }
                    }
                };

                checkStars(orionStars);
                checkStars(libraStars);
                checkStars(scorpioStars);
                checkStars(sagittariusStars);
                checkStars(capricornusStars);
                checkStars(virgoStars);
                checkStars(aquariusStars);

                clickClock.restart();
            }
        }
        if (menuState == INCREMINT_PLUS_MENU)
        {
            hour ++;
            menuState = CONSTELLATIONS;
        }
        
        if (menuState == INCREMINT_MINUS_MENU)
        {
            hour --;
            menuState = CONSTELLATIONS;
        }
        if (menuState == FUNFACTS)
        {
            window.clear(sf::Color(0, 0, 50));
            fact.setString("You clicked on: " + clickedStar);
            window.draw(fact);
            window.draw(BacK_button_sprite);
            window.display();
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && clickClock.getElapsedTime() > delayTime)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                if (localPosition.x >= 796 && localPosition.y >= 148 && localPosition.x <= 1121 && localPosition.y <= 237)
                {
                    menuState = MONTH_MENU;
                    clickClock.restart();
                }
            }
        }
    }

    return 0;
}
