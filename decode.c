#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BIT_SIZE 8

char decode(const int count, const int bits[]) {
    int i, x;
    int holder;
    int a[count];
    char b = '\0';

    for(i = 0; i < count; i++) {
        if(bits[i] < count) {
             a[i] = (bits[i] + BIT_SIZE - count) % BIT_SIZE;
        }
        else {
             a[i] = (bits[i] - count);
        }
    }
    for(x = 0; x < count; x++) {
        holder = a[x];
        b |= (1 << holder);
    }
    return b;
}

void read_and_decode_file(const char * file_name) {
    FILE * input_file;
    int ch;
    input_file = fopen(file_name, "r");

    while(fscanf (input_file, "%1i", &ch) != EOF) {
        int count = ch;
        int x;
        int bits[ch];
        for(x = 0; x < count; x++) {
            fscanf (input_file, "%1i", &ch);
            bits[x] = ch;
        }
        printf("%c", decode(count, bits));
    }
    fclose(input_file);
}

int main(int argc, char * argv[]) {
    read_and_decode_file(argv[1]);
    return EXIT_SUCCESS;
}
