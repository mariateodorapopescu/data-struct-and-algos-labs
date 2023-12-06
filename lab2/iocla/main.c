#include <stdio.h>
#include <stdlib.h>

int main() {
	int **ptr_dublu = malloc(sizeof(*ptr_dublu) * 2);
	ptr_dublu[0] = malloc(sizeof(**ptr_dublu) * 2);
	ptr_dublu[1] = malloc(sizeof(int) * 2);

	ptr_dublu[0][0] = 100;
	ptr_dublu[0][1] = 200;
	ptr_dublu[1][0] = 300;
	ptr_dublu[1][1] = 400;

	printf("%d %d\n", ptr_dublu[0][0], ptr_dublu[1][0]);

	printf("%d\n", *(ptr_dublu + 1));
	//printf("0X%X\n", ptr_dublu[1]);
}
