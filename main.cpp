#include "Analysis.hpp"
#include "ArrayList.hpp"
#include "Collection.hpp"
#include "DoublyLinkedList.hpp"
#include "LinkedList.hpp"

#include <memory>
#include <ncurses.h>
#include <string>
#include <vector>

void menuLoop(const std::vector<std::string> &choices, int &highlight) {
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
long getInput(const std::string &message) {
  clear();
  int input = 0;
  while (true) {
    printw("%s", message.c_str());
    scanw("%d", &input);
    if (input < 1) {
      printw("Niepoprawny wybor. Sprobuj ponownie.\n");
      continue;
    }
    return input;
  }
}
int main() {
  initscr();
  keypad(stdscr, true);
  curs_set(0);
  std::unique_ptr<Collection> collection = nullptr;
  std::vector<std::string> CHOICES{"1. ArrayList", "2. LinkedList",
                                   "3. DoublyLinkedList", "4. Testy",
                                   "5. Wyjdz"};
  int highlight = 0;
  menuLoop(CHOICES, highlight);
  switch (highlight) {
  case 0: {
    collection = std::make_unique<ArrayList>();
    break;
  }
  case 1: {
    collection = std::make_unique<LinkedList>();
    break;
  }
  case 2: {
    collection = std::make_unique<DoublyLinkedList>();
    break;
  }
  case 3: {
    Analysis::analyze(100000, 10000000);
    break;
  }
  case 4: {
    endwin();
    return 0;
  }
  default:
    break;
  }
  CHOICES = {"1. Dane z pliku numbers.txt",
             "2. Losowe dane",
             "3. Wypisz",
             "4. Wyszukaj",
             "5. Dodaj",
             "6. Usun",
             "7. Wyjdz"};
  do {
    highlight = 0;
    clear();
    menuLoop(CHOICES, highlight);
    switch (highlight) {
    case 0: {
      Collection::fillFromFile(*collection, "numbers.txt");
      clear();
      printw("Wypelniono danymi z pliku\n");
      getch();
      break;
    }
    case 1: {
      Collection::fillWithRandom(*collection, getInput("Podaj rozmiar: "));
      clear();
      printw("Wypelniono losowymi danymi\n");
      getch();
      break;
    }
    case 2: {
      collection->print();
      getch();
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
      getch();
      break;
    }
    case 4: {
      collection->add(static_cast<int>(getInput("Podaj element do dodania: ")));
      clear();
      printw("Dodano element\n");
      getch();
      break;
    }
    case 5: {
      collection->remove(
          static_cast<int>(getInput("Podaj indeks do usuniecia: ")));
      clear();
      printw("Usunieto element\n");
      getch();
      break;
    }
    default:
      break;
    }
  } while (highlight != 6);
  endwin();
  return 0;
}