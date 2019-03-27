#include <stdio.h>
#include <stdlib.h>		// for random numbers
#include "screen.h"
#include <time.h>

int main(){
	srand(time(NULL));
	int dec[COL], i;		// 80-pieces of sound decibel
	for (i = 0; i < COL; i++) dec[i] = rand()%70 + 30;
	clearScreen();
	setColors(RED, bg(YELLOW));
	barChart(dec);
	resetColors();
	getchar();
}
