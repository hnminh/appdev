// this file contains screen function, thay are used to display
// some levels of a PUTTY screen as a bar chart
#include <stdio.h>
#include "screen.h"

void barChart(int db[]){
	int i, j;
	for (i = 0; i < COL; i++){	// for 80 column
		for (j = 0; j < db[i]/3; j++){
			printf("\033[%d;%dH", 35 - j, i + 1);
#ifdef UNICODE		// conditional compilation
			printf("%s", BAR);
#else
			printf("%c", '*');
#endif
		}
	}
}

void clearScreen(void){
	printf("\033[2J");
	fflush(stdout);	// for remote terminal (such as PUTTY)
}

void setColors(short bg, short fg){
	printf("\033[%d;%d;1m", bg, fg);
	fflush(stdout);
}

void resetColors(void){
	printf("\033[0m");
	fflush(stdout);
}
