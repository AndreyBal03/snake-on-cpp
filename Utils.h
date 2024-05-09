#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

void dimensions(int *WIDTH, int *HEIGHT)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    *HEIGHT = w.ws_row;
    *WIDTH = w.ws_col;
}
