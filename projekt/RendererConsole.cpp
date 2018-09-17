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
    char tmp[COLS+1];
    tmp[COLS] = '\0';
    for(int y=0;y<LINES;y++){
        for(int x=0;x<COLS;x++)
            tmp[0]=((char*)buffer)[y*COLS+x];
        mvprintw(y,0,tmp);
    }
}