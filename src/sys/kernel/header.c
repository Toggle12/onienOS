char *vidmem = (char*)0xb8000; 

void printString(const char* str) {
    unsigned int i = 0, j = 0;

    while (str[j] != '\0') {
        vidmem[i] = str[j];
        vidmem[i+1] = 0x07;
        ++j;
        i = i + 2;
    }
}

void clearScreen() {
    unsigned int j = 0;
    
    while (j < 80 * 25 * 2) {
        vidmem[j] = 'x';
        vidmem[j+1] = 0x07;
        j = j + 2;
    }

    j = 0;
}

void OSmain(void) {
    clearScreen();
    printString("x");
}