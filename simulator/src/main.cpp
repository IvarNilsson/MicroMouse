#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>

using namespace std;

int maze_square_width = 100;
int maze_wall_width = 10;

int maze_width = (maze_square_width + maze_wall_width) * 16 + maze_wall_width;

int window_width = maze_width + 400;
int window_height = maze_width;

int maze_matrix_horizontal[17][16] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 0, -for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 1, -for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 2, -for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 3, -for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 4, -for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 5, -for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 6, -for my formatter
    1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1,  // row 7, -for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 8, -for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 9, -for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 10, for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 11, for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 12, for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 13, for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 14, for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 15, for my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1   // row 16, for my formatter
};
//  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15

int maze_matrix_vertical[16][17] = {
    0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 0, r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 1, r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 2, r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 3, r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 4, r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 5, r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 6, r my formatter
    1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 7, r my formatter
    1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 8, r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 9, r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 10,r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 11,r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 12,r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 13,r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 14,r my formatter
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // row 15,r my formatter
};
//  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16

sf::RenderWindow window(sf::VideoMode(window_width, window_height),
                        "Micromouse Simulator");

sf::Color maze_area_gray(100, 100, 100);
sf::Color control_panel_gray(200, 200, 200);
sf::Color maze_wall_red(100, 0, 0);

void draw_background() {
  sf::RectangleShape maze_area(sf::Vector2f(maze_width, maze_width));
  sf::RectangleShape control_panel(
      sf::Vector2f(window_width - maze_width, window_height));
  maze_area.setPosition(0, 0);
  control_panel.setPosition(maze_width, 0);
  maze_area.setFillColor(sf::Color::Green);

  maze_area.setFillColor(maze_area_gray);
  control_panel.setFillColor(control_panel_gray);

  window.draw(maze_area);
  window.draw(control_panel);
}

void maze_from_file() {
  ifstream f("/home/ivar/Projects/MicroMouse/simulator/src/save_maze_1.txt");

  if (!f.is_open()) {
    printf("Error opening the file!");
    return;
  }

  string s;
  int row = 1;
  while (getline(f, s)) {
    // cout << s << endl;

    for (int i = 0; i < s.size(); i++) {
      if (row % 2 == 1 && (i - 2) % 4 == 0) {
        if (s[i] == '-') {
          // printf("-");
          cout << i << "- ";
          // cout << "r" << row << ",c" << i << "    ";
          maze_matrix_horizontal[(row - 1) / 2][(i - 2) / 4] = 1;
          // cout << "r" << ((row - 1) / 2) << ",c" << (i - 2) / 4 << "   ";
        } else {
          cout << i << "  ";

          // printf(" ");
          maze_matrix_horizontal[(row - 1) / 2][(i - 2) / 4] = 0;
        }

      } else if (row % 2 == 0 && i % 4 == 0) {
        if (s[i] == 'I') {
          // cout << "I";
          // cout << i << "| ";
          cout << "r" << row << ",c" << i << "    ";
          maze_matrix_vertical[(row / 2) - 1][i / 4] = 1;
        } else {
          // printf(" ");
          // cout << i << "  ";
          maze_matrix_vertical[(row / 2) - 1][i / 4] = 0;
        }
      }
    }
    printf("\n");
    row++;
  }

  for (int r = 0; r < 17; r++) {
    for (int c = 0; c < 16; c++) {
      cout << maze_matrix_horizontal[r][c];
    }
    printf("\n");
  }

  printf("\n");
  printf("\n");

  for (int r = 0; r < 16; r++) {
    for (int c = 0; c < 17; c++) {
      cout << maze_matrix_vertical[r][c];
    }
    printf("\n");
  }

  f.close();
}

void draw_maze() {
  // maze eges (big square with hole in it)
  // sf::RectangleShape edge_horizontal(sf::Vector2f(maze_width,
  // maze_wall_width)); sf::RectangleShape
  // edge_vertical(sf::Vector2f(maze_wall_width, maze_width));
  // edge_horizontal.setFillColor(maze_wall_red);
  // edge_vertical.setFillColor(maze_wall_red);
  // window.draw(edge_horizontal);
  // window.draw(edge_vertical);
  // edge_horizontal.setPosition(0, maze_width - maze_wall_width);
  // edge_vertical.setPosition(maze_width - maze_wall_width, 0);
  // window.draw(edge_horizontal);
  // window.draw(edge_vertical);

  // maze corners
  sf::RectangleShape maze_corner(
      sf::Vector2f(maze_wall_width, maze_wall_width));
  maze_corner.setFillColor(sf::Color::White);
  for (int row = 0; row < 17; row++) {
    for (int col = 0; col < 17; col++) {
      maze_corner.setPosition(col * (maze_square_width + maze_wall_width),
                              row * (maze_square_width + maze_wall_width));
      window.draw(maze_corner);
      if (row == 8 && col == 8) {
        maze_corner.setFillColor(sf::Color::Green);
        window.draw(maze_corner);
        maze_corner.setFillColor(sf::Color::White);
      }
    }
  }

  // horizontal walls
  sf::RectangleShape wall_horizontal(
      sf::Vector2f(maze_square_width, maze_wall_width));
  // sf::RectangleShape no_wall(sf::Vector2f(maze_square_width,
  // maze_wall_width));
  wall_horizontal.setFillColor(maze_wall_red);
  // no_wall.setFillColor(maze_area_gray);
  // no_wall.setOutlineColor(maze_wall_red);

  for (int row = 0; row < 17; row++) {
    for (int col = 0; col < 16; col++) {
      if (maze_matrix_horizontal[row][col] == 1) {
        wall_horizontal.setPosition(
            col * (maze_square_width + maze_wall_width) + maze_wall_width,
            (row) * (maze_square_width + maze_wall_width));
        window.draw(wall_horizontal);
      } else {
      }
    }
  }

  // vertical walls
  sf::RectangleShape wall_vertical(
      sf::Vector2f(maze_wall_width, maze_square_width));
  wall_vertical.setFillColor(maze_wall_red);

  for (int row = 0; row < 16; row++) {
    for (int col = 0; col < 17; col++) {
      if (maze_matrix_vertical[row][col] == 1) {
        wall_vertical.setPosition(
            (col) * (maze_square_width + maze_wall_width),
            row * (maze_square_width + maze_wall_width) + maze_wall_width);
        window.draw(wall_vertical);
      } else {
      }
    }
  }
}

int main() {
  // Create a window

  /*
    // Set a default background color
    sf::Color backgroundColor(100, 149, 237);  // Cornflower Blue

    // Create a simple button (rectangle shape)
    sf::RectangleShape button(sf::Vector2f(200, 50));
    button.setFillColor(sf::Color::Green);
    button.setPosition(300, 275);  // Position it in the center of the window

    // Create a text label for the button
    sf::Font font;
    if (!font.loadFromFile(
            "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
      return -1;  // Ensure you have a font available
    }

    sf::Text text("btn", font, 24);
    text.setFillColor(sf::Color::White);
    text.setPosition(350, 290);  // Center text in the button
  */

  maze_from_file();

  // Main loop
  while (window.isOpen()) {
    /*
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Check for mouse click events
      if (event.type == sf::Event::MouseButtonPressed) {
        if (button.getGlobalBounds().contains(event.mouseButton.x,
                                              event.mouseButton.y)) {
          // Change background color when the button is clicked
          backgroundColor = sf::Color(rand() % 256, rand() % 256,
                                      rand() % 256);  // Random color
        }
      }
    }


    // Clear the window with the current background color
    window.clear(backgroundColor);

    // Draw the button and its text
    window.draw(button);
    window.draw(text);

    // sf::Text line("btn", font, 24);

    */

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    draw_background();
    draw_maze();

    // Display the contents of the window
    window.display();
  }

  return 0;
}
