#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Micromouse Simulator");

    // Set a default background color
    sf::Color backgroundColor(100, 149, 237); // Cornflower Blue

    // Create a simple button (rectangle shape)
    sf::RectangleShape button(sf::Vector2f(200, 50));
    button.setFillColor(sf::Color::Green);
    button.setPosition(300, 275); // Position it in the center of the window

    // Create a text label for the button
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        return -1; // Ensure you have a font available
    }

    sf::Text text("Click Me", font, 24);
    text.setFillColor(sf::Color::White);
    text.setPosition(350, 290); // Center text in the button

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Check for mouse click events
            if (event.type == sf::Event::MouseButtonPressed) {
                if (button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    // Change background color when the button is clicked
                    backgroundColor = sf::Color(rand() % 256, rand() % 256, rand() % 256); // Random color
                }
            }
        }

        // Clear the window with the current background color
        window.clear(backgroundColor);

        // Draw the button and its text
        window.draw(button);
        window.draw(text);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
