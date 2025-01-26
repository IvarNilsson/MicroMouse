#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "mouse.h"

using namespace std;

typedef struct point_s Point;

int maze_square_width = 100;
int maze_wall_width = 10;

int maze_width = (maze_square_width + maze_wall_width) * 16 + maze_wall_width;

int window_width = maze_width + 400;
int window_height = maze_width;

//                        row col
int maze_matrix_horizontal[17][16] = {};

int maze_matrix_vertical[16][17] = {};

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
          maze_matrix_horizontal[(row - 1) / 2][(i - 2) / 4] = 1;
        } else {
          maze_matrix_horizontal[(row - 1) / 2][(i - 2) / 4] = 0;
        }

      } else if (row % 2 == 0 && i % 4 == 0) {
        if (s[i] == 'I') {
          maze_matrix_vertical[(row / 2) - 1][i / 4] = 1;
        } else {
          maze_matrix_vertical[(row / 2) - 1][i / 4] = 0;
        }
      }
    }
    row++;
  }

  f.close();
}

void maze_to_file() {
  ofstream f("/home/ivar/Projects/MicroMouse/simulator/src/maze_to_file.txt");

  if (!f.is_open()) {
    printf("Error opening the file!");
    return;
  }

  for (int row = 0; row < 33; row++) {
    for (int col = 0; col < 65; col++) {
      // ---
      if (row % 2 == 0 && (col - 2) % 4 == 0) {
        if (maze_matrix_horizontal[row / 2][(col - 2) / 4] == 1) {
          f << "---";
        } else {
          f << "   ";
        }

        // I
      } else if (row % 2 == 1 && (col) % 4 == 0) {
        if (maze_matrix_vertical[row / 2][col / 4] == 1) {
          f << "I";
        } else {
          f << " ";
        }

        // +
      } else if (row % 2 == 0 && col % 4 == 0) {
        f << "+";

        // " "
      } else if (row % 2 == 1) {
        f << " ";
      }
    }
    f << "\n";
  }

  f.close();
}

void draw_maze() {
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
        // add a outline?
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
        // add a outline?
      }
    }
  }
}

void draw_mouse(Point pos) {
  int mouse_size = 100;
  sf::RectangleShape mouse(sf::Vector2f(mouse_size, mouse_size));
  mouse.setFillColor(sf::Color::Blue);
  int zero_y = (maze_wall_width + maze_square_width) * 15 + maze_wall_width;
  int zero_x = maze_wall_width;
  int mouse_x = zero_x + (maze_wall_width + maze_square_width) * pos.x;
  int mouse_y = zero_y + (maze_wall_width + maze_square_width) * pos.y * -1;
  mouse.setPosition(mouse_x, mouse_y);  // this is wrong
  window.draw(mouse);
}

Surronding calculate_surronding(Point pos, int maze_matrix_horizontal[17][16],
                                int maze_matrix_vertical[16][17]) {
  Surronding s;

  cout << maze_matrix_horizontal;

  // up
  s.up = maze_matrix_horizontal[15 - pos.y][pos.x];
  s.down = maze_matrix_horizontal[16 - pos.y][pos.x];
  s.left = maze_matrix_vertical[15 - pos.y][pos.x];
  s.right = maze_matrix_vertical[15 - pos.y][pos.x + 1];

  return s;
}

void print_horizontal_matrix(int maze_matrix_horizontal[17][16]) {
  cout << "Printing maze_matrix_horizontal" << endl;
  for (int row = 0; row < 17; row++) {
    for (int col = 0; col < 16; col++) {
      cout << maze_matrix_horizontal[row][col] << " ";
    }
    cout << endl;
  }
}

void print_vertical_matrix(int maze_matrix_vertical[16][17]) {
  cout << endl << "Printing maze_matrix_vertical" << endl;
  for (int row = 0; row < 16; row++) {
    for (int col = 0; col < 17; col++) {
      cout << maze_matrix_vertical[row][col] << " ";
    }
    cout << endl;
  }
}

void print_surronding(Surronding s) {
  cout << endl;
  cout << "       up   " << endl;
  cout << "       " << s.up << "   " << endl;
  cout << "left " << s.left << "   " << s.right << " rihgt" << endl;
  cout << "       " << s.down << "   " << endl;
  cout << "      down   " << endl << endl;
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
  // maze_to_file();
  // Mouse mouse = create_mouse();
  create_mouse();

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
    draw_mouse(get_pos());

    Surronding s;
    s = calculate_surronding(get_pos(), maze_matrix_horizontal,
                             maze_matrix_vertical);
    print_surronding(s);
    move_up(s);

    // print_horizontal_matrix(maze_matrix_horizontal);
    // print_vertical_matrix(maze_matrix_vertical);

    // Display the contents of the window
    window.display();
    sleep(1);
  }

  return 0;
}
