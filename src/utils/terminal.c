
#include "terminal.h"
// char terminal_buffer[8192];


int getTerminalWidth() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO console_info;

    if (GetConsoleScreenBufferInfo(hConsole, &console_info)) {
        return console_info.dwSize.X;
    } else {
        return -1;
    }
}

void centralizarTexto(const char *texto) {
    int larguraLinha = getTerminalWidth();

    int posicaoInicial = (larguraLinha - strlen(texto)) / 2;

    for (int i = 0; i < posicaoInicial; i++) {
        printf(" ");
    }

    printf("%s", texto);
}



void configureTerminal()
{
    // setvbuf(stdout, terminal_buffer, _IOFBF, sizeof(terminal_buffer));

#ifdef __WIN32
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;

    GetConsoleMode(handle, &mode);
    mode |= TERMINAL_PROCESSING;

    SetConsoleMode(handle, mode);
#endif
}