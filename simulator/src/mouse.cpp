#include "mouse.h"

#include <iostream>
using namespace std;

Point pos;

int x;
int y;

void create_mouse() {
  pos.x = 0;
  pos.y = 0;
}

void move_up(Surronding s) {
  if (s.up == 0) {
    pos.y++;
  } else {
    cout << "E: cant move up, wall" << "\n";
  }
}

void move_down(Surronding s) {
  if (s.down == 0) {
    pos.y--;
  } else {
    cout << "E: cant move down, wall" << "\n";
  }
}

void move_right(Surronding s) {
  if (s.right == 0) {
    pos.x++;
  } else {
    cout << "E: cant move right, wall" << "\n";
  }
}

void move_left(Surronding s) {
  if (s.left == 0) {
    pos.x--;
  } else {
    cout << "E: cant move left, wall" << "\n";
  }
}

Point get_pos() { return pos; }