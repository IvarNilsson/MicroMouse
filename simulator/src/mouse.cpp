#include <iostream>

#include "structs.h"

using namespace std;

Mouse_Position pos;

void create_mouse() {
  pos.x = 0;
  pos.y = 0;
  pos.directon = 0;
}

void move_up(Surronding s) {
  if (s.up == 0) {
    pos.y++;
    pos.directon = 0;
  } else {
    cout << "E: cant move up, wall" << "\n";
  }
}

void move_down(Surronding s) {
  if (s.down == 0) {
    pos.y--;
    pos.directon = 1;
  } else {
    cout << "E: cant move down, wall" << "\n";
  }
}

void move_right(Surronding s) {
  if (s.right == 0) {
    pos.x++;
    pos.directon = 2;
  } else {
    cout << "E: cant move right, wall" << "\n";
  }
}

void move_left(Surronding s) {
  if (s.left == 0) {
    pos.x--;
    pos.directon = 3;
  } else {
    cout << "E: cant move left, wall" << "\n";
  }
}

Mouse_Position mouse_get_pos() { return pos; }