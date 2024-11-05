#include "../SFML-2.3.2/include/SFML/Graphics.hpp"

#include "../include/Parabola.h"

// Global variables
const int g_iWIDTH = 600;
const int g_iHEIGHT = 600;
float fCenterX = g_iWIDTH / 2;
float fCenterY = g_iHEIGHT / 2;
int leftBound = - (g_iWIDTH / 2);
int rightBound = g_iWIDTH / 2;

// F - draw function
bool isReleasedF = true;
// D - draw derivative
bool isReleasedD = false;
// D - draw antiderivative
bool isReleasedA = false;

// This values can be changed
float pointPerLine = 50;
float fScale = 2;
float deltaX = 0.1;
int n = 4000; // `n` equal parts for [a, b] (for integration)

int quantityLines = (rightBound - leftBound) * pointPerLine + 1;

void drawAxis(sf::RenderWindow& window) {
    sf::RectangleShape AxisX(sf::Vector2f(g_iWIDTH, 1));
    AxisX.setFillColor(sf::Color::Black);
    AxisX.setPosition(0, fCenterY);
    
    sf::RectangleShape AxisY(sf::Vector2f(1, g_iHEIGHT));
    AxisY.setFillColor(sf::Color::Black);
    AxisY.setPosition(fCenterX, 0);
    
    sf::RectangleShape arrow[4];
    for (int i = 0; i < 4; i++){
        arrow[i].setSize(sf::Vector2f(1.5, 10));
        arrow[i].setFillColor(sf::Color::Black);
        
        if (i < 2)
            arrow[i].setPosition(fCenterX, 0);
        else
            arrow[i].setPosition(g_iWIDTH, fCenterY);
    }
    
    arrow[0].setRotation(15);
    arrow[1].setRotation(-15);
    arrow[2].setRotation(60);
    arrow[3].setRotation(-240);
    
    window.draw(AxisX);
    window.draw(AxisY);
    for (int i = 0; i < 4; i++) {
        window.draw(arrow[i]);
    }
}


int main(int, char const**)
{
    // Example function
    Parabola parabola;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(g_iWIDTH, g_iHEIGHT), "Graphics");
    
    // thickness and color for function (parabola)
    sf::CircleShape func(1.f);
    func.setFillColor(sf::Color::Blue);
    // thickness and color for derivative of function (parabola)
    sf::CircleShape derivative(1.f);
    derivative.setFillColor(sf::Color::Red);
    // thickness and color for antiderivative of function (parabola)
    sf::CircleShape antiderivative(1.f);
    antiderivative.setFillColor(sf::Color::Green);
    
    // Start the app loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            // Draw antiderivarive ?
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A){
                if (isReleasedA)
                    isReleasedA = false;
                else
                    isReleasedA = true;
            }
            // Draw derivative ?
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D){
                if (isReleasedD)
                    isReleasedD = false;
                else
                    isReleasedD = true;
            }
            // Draw function (default - true) ?
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F){
                if (isReleasedF)
                    isReleasedF = false;
                else
                    isReleasedF = true;
            }
        }
        
        // Clear screen
        window.clear(sf::Color::White);
        drawAxis(window);
        
        // draw function
        if(isReleasedF) {
            for (float xi = 0; xi < quantityLines; xi++)
            {
                float func_x = (leftBound + xi/pointPerLine) * fScale;
                float func_y = parabola.GetY(func_x) * fScale;
                func.setPosition(fCenterX + func_x - 0.5f,
                                 fCenterY - func_y - 0.5f);
                window.draw(func);
            }
        }
        
        // draw derivative
        if(isReleasedD) {
            for (float xi = 0; xi < quantityLines; xi++)
            {
                float func_x = (leftBound + xi/pointPerLine) * fScale;
                float func_y = parabola.GetDerivativeY(func_x, deltaX) * fScale;
                derivative.setPosition(fCenterX + func_x - 0.5f,
                                       fCenterY - func_y - 0.5f);
                window.draw(derivative);
            }
        }
        
        // draw antiderivative
        if (isReleasedA) {
            for (int xi = 0; xi < quantityLines; xi++)
            {
                float func_x = (leftBound + xi / pointPerLine) * fScale;
                float dx = func_x/n;
                float y = parabola.GetAntiderivativeY(0, func_x, dx) * fScale;
                antiderivative.setPosition(fCenterX + func_x - 0.5f,
                                           fCenterY - y - 0.5f);
                window.draw(antiderivative);
            }
        }

        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}
