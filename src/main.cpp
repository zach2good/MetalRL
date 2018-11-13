#include "BearLibTerminal.h"

int main()
{
    terminal_open();

    // Printing text
    terminal_print(1, 1, "Hello, world!");
    terminal_refresh();

    // Wait until user close the window
    while (terminal_read() != TK_CLOSE);

    terminal_close();
}