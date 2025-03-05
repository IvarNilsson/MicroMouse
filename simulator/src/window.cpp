#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "structs.h"

using namespace std;

// Sizes:
int maze_square_width = 100;
int maze_wall_width = 10;

int maze_width = (maze_square_width + maze_wall_width) * 16 + maze_wall_width;

int window_width = maze_width + 400;
int window_height = maze_width;
// end sizes

sf::RenderWindow window(sf::VideoMode(window_width, window_height),
                        "Micromouse Simulator");

bool get_window_open() { return window.isOpen(); }

void window_event() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void window_display() { window.display(); }

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

void maze_from_file(int maze_matrix_horizontal[17][16],
                    int maze_matrix_vertical[16][17]) {
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

void maze_to_file(int maze_matrix_horizontal[17][16],
                  int maze_matrix_vertical[16][17]) {
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

void draw_maze(int maze_matrix_horizontal[17][16],
               int maze_matrix_vertical[16][17]) {
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

void draw_mouse(Mouse_Position pos) {
  // position (blue square)
  int mouse_size = 100;
  sf::RectangleShape mouse(sf::Vector2f(mouse_size, mouse_size));
  mouse.setFillColor(sf::Color::Blue);
  int zero_y = (maze_wall_width + maze_square_width) * 15 + maze_wall_width;
  int zero_x = maze_wall_width;
  int mouse_x = zero_x + (maze_wall_width + maze_square_width) * pos.x;
  int mouse_y = zero_y + (maze_wall_width + maze_square_width) * pos.y * -1;
  mouse.setPosition(mouse_x, mouse_y);
  window.draw(mouse);

  // direction (red small square)
  int direction_marker_size = 20;
  sf::RectangleShape direction_marker(
      sf::Vector2f(direction_marker_size, direction_marker_size));
  direction_marker.setFillColor(sf::Color::Red);

  int pos_offset = mouse_size / 2 - direction_marker_size / 2;
  if (pos.directon == 0) {
    direction_marker.setPosition(mouse_x + pos_offset, mouse_y);
  } else if (pos.directon == 1) {
    direction_marker.setPosition(mouse_x + pos_offset,
                                 mouse_y + mouse_size - direction_marker_size);
  } else if (pos.directon == 2) {
    direction_marker.setPosition(mouse_x + mouse_size - direction_marker_size,
                                 mouse_y + pos_offset);
  } else if (pos.directon == 3) {
    direction_marker.setPosition(mouse_x, mouse_y + pos_offset);
  }
  window.draw(direction_marker);
}
