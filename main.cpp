#include <ncurses.h>

#include "DoublyLinkedList.hpp"
int main() {
  initscr();
  DoublyLinkedList list;
  for (int i = 0; i<10; i++) {
    list.add(i, i);
  }
  list.print();
  refresh();
  getch();
  getch();
  endwin();
  return 0;
}