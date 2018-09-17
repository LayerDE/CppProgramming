// Copyright [year] <Copyright Owner>
#include <ncurses.h>
#include <math.h>
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
  for (int x = 0; x < COLS * LINES; x++)
    ((char*)buffer)[x] = ((char*)permanentBuffer)[x] = ' ';
}

RendererConsole::~RendererConsole() {
    endwin();
}

void RendererConsole::drawFrame() {
    char tmp[COLS + 1];
    tmp[COLS] = '\0';
    for (int y = 0; y < LINES; y++) {
        for (int x = 0; x < COLS; x++)
            tmp[0] = ((char*)buffer)[y * COLS + x];
        mvprintw(y, 0, tmp);
    }
}

void RendererConsole::prepareBridge(float x1, float y1,
  float x2, float y2) {
    if (abs(x1 - x2) < abs(y1 - y2))
        drawBridgeVert(x1 < x2 ? x1 : x2 , y1 < y2 ? y1 : y2,
          sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
    else
        drawBridgeHor(x1 < x2 ? x1 : x2, y1 < y2 ? y1 : y2,
          sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}
void RendererConsole::prepareDoubleBridge(float x1, float y1,
  float x2, float y2) {
    if (abs(x1 - x2) < abs(y1 - y2))
        draw2BridgeVert(x1 < x2 ? x1 : x2, y1 < y2 ? y1 : y2,
          sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
    else
        draw2BridgeHor(x1 < x2 ? x1 : x2, y1 < y2 ? y1 : y2,
          sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}
void RendererConsole::drawBridgeVert(int x, int y, int len) {
    for (int z = 0; z < len; z++)
        ((char*)buffer)[(y + z) * COLS + x] = '|';
}
void RendererConsole::drawBridgeHor(int x, int y, int len) {
    for (int z = 0; z < len; z++)
        ((char*)buffer)[y * COLS + x + z] = '-';
}
void RendererConsole::draw2BridgeVert(int x, int y, int len) {
    for (int z = 0; z < len; z++)
        ((char*)buffer)[(y + z) * COLS + x] = 'H';
}
void RendererConsole::draw2BridgeHor(int x, int y, int len) {
    for (int z = 0; z < len; z++)
        ((char*)buffer)[y * COLS + x + z] = '=';
}

void RendererConsole::prepareIsland(float x1, float y1, int maxBridges) {
    ((char*)buffer)[(int)y1*COLS+(int)x1]='0'+maxBridges;
}
