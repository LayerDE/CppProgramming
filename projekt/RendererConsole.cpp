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
  buffer = new char[COLS*LINES];
  permanentBuffer = new char[COLS*LINES];
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

void RendererConsole::prepareBridge(float x1, float y1, float x2, float y2){

}
void RendererConsole::prepareDoubleBridge(float x1, float y1, float x2, float y2){

}
void RendererConsole::prepareIsland(float x1, float y1, int maxBridges){
    
}