#include <ncurses.h>
#include "./Renderer.h"
#include "./RendererConsole.h"

RendererConsole::RendererConsole() {
  // Init terminal
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
}

RendererConsole::~RendererConsole() {
    endwin();
}

void RendererConsole::drawFrame() {
    
}