typedef struct point_s Point;
struct point_s {
  int x;
  int y;
};

typedef struct surronding_s Surronding;
struct surronding_s {
  int up;
  int down;
  int right;
  int left;
};

void create_mouse();

void move_up(Surronding s);
void move_down(Surronding s);
void move_right(Surronding s);
void move_left(Surronding s);

Point get_pos();