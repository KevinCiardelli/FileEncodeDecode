/*
author: Kevin Ciardelli -ciardelk@bc.eduuthor: Kevin Ciardelli -ciardelk@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIT_SIZE 8
#define ARRAY_SIZE 7

int encode(unsigned char input, int * indices) {
    int i,j,k;
    int count = 0;
    int count2 = 0;
    int a[BIT_SIZE];
    for(i = 0; i < BIT_SIZE; i++) {
        if((input >> i) & 1) {
            a[ARRAY_SIZE - i] = 1;
            count++;
        }
        else {
            a[ARRAY_SIZE - i] = 0;
        }
    }

    int c[count];

    for(j = ARRAY_SIZE; j >=  0; j--) {
        if(a[j] == 1) {
            c[count2] = ARRAY_SIZE - j;
            count2++;
        }
    }
    for(k = 0; k < count; k++) {
        indices[k] = (c[k]+count) % BIT_SIZE;
    }
    return count;
}

void read_and_encode_file(char * in_file, char * out_file) {
    FILE * input_file;
    FILE * output_file;
    int ch;
    input_file = fopen(in_file, "r");
    output_file = fopen(out_file, "w");

    while ((ch = fgetc(input_file)) != EOF) {
        int a[BIT_SIZE]; 
        int b, c;
        b = encode(ch, a);
        fprintf(output_file,"%d", b);
        for(c = 0; c < b; c++) {
            fprintf(output_file, "%d", a[c]);
        }
    }
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char * argv[]) {
    if(NULL == argv[1] || NULL == argv[2]) {
        printf("Please enter input and output file names as command-line arguments.\n");
        exit(EXIT_FAILURE);
    }
    read_and_encode_file(argv[1], argv[2]);
    return EXIT_SUCCESS;
}
