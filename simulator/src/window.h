#include "structs.h"

bool get_window_open();

void window_event();

void window_display();

void draw_background();

void maze_from_file(int maze_matrix_horizontal[17][16],
                    int maze_matrix_vertical[16][17]);

void maze_to_file(int maze_matrix_horizontal[17][16],
                  int maze_matrix_vertical[16][17]);

void draw_maze(int maze_matrix_horizontal[17][16],
               int maze_matrix_vertical[16][17]);

void draw_mouse(Mouse_Position pos);
