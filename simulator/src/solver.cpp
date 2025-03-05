#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "structs.h"
using namespace std;

int next_solver_move(Surronding surronding) {
  if (surronding.right == 0) {
    return 2; // turn right
  } else if (surronding.up == 0) {
    return 0; // forward
  } else if (surronding.left == 0) {
    return 3; // left
  } else if (surronding.down == 0) {
    return 1; // back
  }
  return 99;
}