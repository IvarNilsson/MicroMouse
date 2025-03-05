#ifndef STRUCTS_H
#define STRUCTS_H

// typedef struct point_s Point;
struct Mouse_Position {
  int x;
  int y;
  int directon;
};

// typedef struct surronding_s Surronding;
struct Surronding {
  int up;
  int down;
  int right;
  int left;
};

#endif  // STRUCTS_H
