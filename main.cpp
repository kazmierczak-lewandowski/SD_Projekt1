#include "ArrayList.hpp"
#include "Collection.hpp"

#include <ncurses.h>

#include <array>
#include <memory>
#include <string>
#include <vector>

void menuLoop(const std::vector<std::string>& choices, int &highlight) {
  int choice = 0;
  while (choice != 10) {
    for (int i = 0; i < choices.size(); i++) {
      if (i == highlight) {
        attron(A_REVERSE);
      }
      mvprintw(i, 0, "%s", choices[i].c_str());
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
      if (highlight != choices.size() - 1)
        highlight++;
      break;
    }
    default:
      break;
    }
  }
}
long getInput(const std::string& message) {
  clear();
  int input = 0;
  long result = 0;
  while (input != 10) {
    printw("%s", message.c_str());
    scanw("%d", &input);
    if ((input < '0' || input >'9') && input != 10) {
      printw("Niepoprawny wybor. Sprobuj ponownie.\n");
      continue;
    }
    result += input - '0';
  }
  return result;
}
int main() {
  initscr();
  keypad(stdscr, true);
  std::unique_ptr<Collection> collection = nullptr;
  std::vector<std::string> CHOICES{"1. ArrayList", "2. LinkedList",
    "3. DoublyLinkedList", "4. Wyjdz"};
  int highlight = 0;
  menuLoop(CHOICES, highlight);
  switch (highlight) {
    case 0: {
      collection = std::make_unique<ArrayList>();
      break;
    }
    case 1: {
      //collection = std::make_unique<LinkedList>()
      break;
    }
    case 2: {
      //collection = std::make_unique<DoublyLinkedList>()
      break;
    }
    case 3: {
      endwin();
      return 0;
    }
    default:
      break;

  }
  CHOICES = {"1. Dane z pliku", "2. Losowe dane",
    "3. Wypisz", "4. Wyszukaj", "5. Dodaj", "6. Usun", "7. Wyjdz"};
  do {
    clear();
    menuLoop(CHOICES, highlight);
      switch (highlight) {
        case 0: {
          // collection->loadFromFile();
          break;
        }
        case 1: {
          // collection->generateRandomData();
          break;
        }
        case 2: {
          collection->print();
          break;
        }
        case 3: {
          const long res = collection->get(
              static_cast<int>(getInput("Podaj element do wyszukania: ")));
          clear();
          if (res == -1) {
            printw("Nie znaleziono elementu\n");
          }
          else {
            printw("Znaleziono element na pozycji %ld\n", res);
          }
          break;
        }
        case 4: {
          // collection->add();
          break;
        }
        case 5: {
          collection->remove(
            static_cast<int>(getInput("Podaj indeks do usuniecia: ")));
          break;
        }
        default:
          break;
      }
  } while (highlight == 7);
  endwin();
  return 0;
}
