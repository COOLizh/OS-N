#include <curses.h>

#ifdef __linux__
#endif

#define ESC 27

int main() {
    int symbol = -1;
    initscr();
    while(symbol != ESC) {
        noecho();
        symbol = getchar();
        cbreak();
        if(symbol >= 48 && symbol <= 57) {
            printf("%c%c", symbol, symbol);
        } else {
            printf("%c", symbol);
        }

    }
    return 0;
}