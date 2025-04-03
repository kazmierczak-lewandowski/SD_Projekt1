#include <ncurses.h>

#include <array>
#include <string>

int main() {
  initscr();
  const std::array<std::string, 4> CHOICES{"1. ArrayList", "2. LinkedList", "3. DoublyLinkedList", "4. Exit"};
  keypad(stdscr, true);
  int choice = 0;
  int highlight = 0;
  while (choice != 10) {
    for (int i = 0; i < CHOICES.size(); i++) {
      if (i == highlight) {
        attron(A_REVERSE);
      }
      mvprintw(i, 0, "%s", CHOICES[i].c_str());
      attroff(A_REVERSE);
    }
    choice = getch();

    switch (choice) {
      case KEY_UP: {
        if (highlight != 0)
          highlight--;
        break;
      }
      case KEY_DOWN: {
        if (highlight != 3)
          highlight++;
        break;
      }
      default:
        break;
    }
  }
  printw("Your choice: %s\n", CHOICES[highlight].c_str());
  getch();
  endwin();
  return 0;
}
