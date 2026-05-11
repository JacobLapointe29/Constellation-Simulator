# Constellation Explorer (C++ / SFML)

An interactive application that allows users to explore constellations based on selected date and time.
Built as a C++ project using SFML to simulate constellation visibility based on user-selected time and date.

## Features

* Select month, day, and hour
* Dynamic sky color based on time of day
* Interactive constellation rendering
* Clickable stars with information display

## Technologies

* C++
* SFML (Simple and Fast Multimedia Library)

## How to Run

1. Download SFML: https://www.sfml-dev.org/download.php
2. Open the project in Visual Studio
3. Configure SFML:

   * Add include directory: `SFML/include`
   * Add library directory: `SFML/lib`
4. Link libraries:

   * sfml-graphics.lib
   * sfml-window.lib
   * sfml-system.lib
5. Copy SFML `.dll` files into your build folder (`x64/Debug`)
6. Run the program

## Assets

All images and fonts are stored in the `assets/` folder and loaded using relative paths.

## Notes

This project demonstrates event handling, state-based UI, and rendering using SFML.

## Preview

![App Preview](assets/images/preview.png)