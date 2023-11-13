
#include "terminal.h"
// char terminal_buffer[8192];

// void resizeTerminal(){
//     HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

//     SetConsoleTitle("Whatsapp Motors Manager");

//     SMALL_RECT windowSize = {0, 0, 80, 32};
//     SetConsoleWindowInfo(wHnd, 1, &windowSize);

//     COORD bufferSize = {79, 31};
//     SetConsoleScreenBufferSize(wHnd, bufferSize);
// }

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
    // resizeTerminal();

#ifdef __WIN32
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;

    GetConsoleMode(handle, &mode);
    mode |= TERMINAL_PROCESSING;

    SetConsoleMode(handle, mode);
#endif

}