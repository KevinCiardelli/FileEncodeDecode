all: encode decode

encode:
	gcc -Wall -Werror -std=c99 encode.c -o encode -lm
decode:
	gcc -Wall -Werror -std=c99 decode.c -o decode -lm

clean:
	rm *.c -f output
