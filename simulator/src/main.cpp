#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "debug.h"
#include "mouse.h"
#include "solver.h"
#include "structs.h"
#include "window.h"

using namespace std;

//                        row col
int maze_matrix_horizontal[17][16] = {};

int maze_matrix_vertical[16][17] = {};

Surronding calculate_surronding(Mouse_Position pos,
                                int maze_matrix_horizontal[17][16],
                                int maze_matrix_vertical[16][17]) {
  Surronding s_pre_direction;
  Surronding s_post_direction;

  s_pre_direction.up = maze_matrix_horizontal[15 - pos.y][pos.x];
  s_pre_direction.down = maze_matrix_horizontal[16 - pos.y][pos.x];
  s_pre_direction.right = maze_matrix_vertical[15 - pos.y][pos.x + 1];
  s_pre_direction.left = maze_matrix_vertical[15 - pos.y][pos.x];

  if (pos.directon == 0) {
    s_post_direction = s_pre_direction;
  } else if (pos.directon == 1) {
    s_post_direction.up = s_pre_direction.down;
    s_post_direction.down = s_pre_direction.up;
    s_post_direction.right = s_pre_direction.left;
    s_post_direction.left = s_pre_direction.right;
  } else if (pos.directon == 2) {
    s_post_direction.up = s_pre_direction.right;
    s_post_direction.down = s_pre_direction.left;
    s_post_direction.right = s_pre_direction.down;
    s_post_direction.left = s_pre_direction.up;
  } else if (pos.directon == 3) {
    s_post_direction.up = s_pre_direction.left;
    s_post_direction.down = s_pre_direction.right;
    s_post_direction.right = s_pre_direction.up;
    s_post_direction.left = s_pre_direction.down;
  }

  return s_post_direction;
}

Surronding calculate_surronding_pre_direction(
    Mouse_Position pos, int maze_matrix_horizontal[17][16],
    int maze_matrix_vertical[16][17]) {
  Surronding s_pre_direction;

  s_pre_direction.up = maze_matrix_horizontal[15 - pos.y][pos.x];
  s_pre_direction.down = maze_matrix_horizontal[16 - pos.y][pos.x];
  s_pre_direction.right = maze_matrix_vertical[15 - pos.y][pos.x + 1];
  s_pre_direction.left = maze_matrix_vertical[15 - pos.y][pos.x];

  return s_pre_direction;
}

int counteract_rotation(int direction, int next_move) {
  if (direction == 0) {
    return next_move;
  } else if (direction == 1) {
    if (next_move == 0) {
      return 1;
    } else if (next_move == 1) {
      return 0;
    } else if (next_move == 2) {
      return 3;
    } else if (next_move == 3) {
      return 2;
    }
  } else if (direction == 2) {
    if (next_move == 0) {
      return 2;
    } else if (next_move == 1) {
      return 3;
    } else if (next_move == 2) {
      return 1;
    } else if (next_move == 3) {
      return 0;
    }
  } else if (direction == 3) {
    if (next_move == 0) {
      return 3;
    } else if (next_move == 1) {
      return 2;
    } else if (next_move == 2) {
      return 0;
    } else if (next_move == 3) {
      return 1;
    }
  }
  return 99;
}

int main() {
  // Create a window
  maze_from_file(maze_matrix_horizontal, maze_matrix_vertical);
  // Mouse mouse = create_mouse();
  create_mouse();

  // Main loop
  while (get_window_open()) {
    window_event();

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
    Mouse_Position mouse_position = mouse_get_pos();
    draw_background();
    draw_maze(maze_matrix_horizontal, maze_matrix_vertical);
    draw_mouse(mouse_position);
    if (mouse_position.x == 7) {
      if (mouse_position.y == 8) {
        std::this_thread::sleep_for(std::chrono::microseconds(100000 * 1000));
      }
    }

    Surronding s = calculate_surronding(mouse_position, maze_matrix_horizontal,
                                        maze_matrix_vertical);
    Surronding s_no_rotation = calculate_surronding_pre_direction(
        mouse_position, maze_matrix_horizontal, maze_matrix_vertical);

    print_surronding(s);

    int next_move = next_solver_move(s);
    // counteract rotation
    next_move = counteract_rotation(mouse_position.directon, next_move);

    if (next_move == 0) {
      move_up(s_no_rotation);
    } else if (next_move == 1) {
      move_down(s_no_rotation);
    } else if (next_move == 2) {
      move_right(s_no_rotation);
    } else if (next_move == 3) {
      move_left(s_no_rotation);
    }

    // print_horizontal_matrix(maze_matrix_horizontal);
    // print_vertical_matrix(maze_matrix_vertical);

    // Display the contents of the window
    window_display();
    std::this_thread::sleep_for(std::chrono::microseconds(100 * 1000));
  }

  return 0;
}
