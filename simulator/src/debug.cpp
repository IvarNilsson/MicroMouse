#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "structs.h"

using namespace std;

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
