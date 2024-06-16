#include "stdio.h"

struct car {
  char *name;
  float price;
  int speed;
};

struct car new_car(char *name, float price, int speed) {
  struct car x = {.name=name, .price=price, .speed=speed};
  return x;
}

void set_price(struct car* car, float price) {
    car->price = price;
}

int main(void) {
  struct car saturn = new_car("Saturn SL/2", 16000.99, 175);
  set_price(&saturn, 1000.0);
  printf("Speed:\t%f\n", saturn.price);
}
