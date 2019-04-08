// this file contains screen function, thay are used to display
// some levels of a PUTTY screen as a bar chart
#include <stdio.h>
#include "screen.h"

void barChart(int db[]){
	int i, j;
	for (i = 0; i < COL; i++){	// for 80 column
		for (j = 0; j < db[i]/3; j++){
			if (j > 20) setColors(GREEN, bg(BLACK));
			else setColors(RED, bg(BLACK));
			printf("\033[%d;%dH", 35 - j, i + 1);
#ifdef UNICODE		// conditional compilation
			printf("%s", BAR);
#else
			printf("%c", '*');
#endif
		}
	}
	// this part is for finding peak
	int peakCount = 0;
	i = 0; j = 0;
	while (i < COL){
		if (db[i] > 80){
			j = i;
			while (db[j] > 80 && j < COL - 1) j++;	// find the peak end point
			int maxPivot = j;	// the end point
			for (int k = i; k <= j; k++)
				if (db[k] > db[maxPivot]) maxPivot = k;	// find the peak point
			int notSmaller = 0, notBigger = 0;
			for (int k = i; k < maxPivot; k++)	// from beginning to peak
				if (db[k] > db[k + 1]) notBigger++;
			for (int k = maxPivot + 1; k <= j; k++)	// from peak to end
				if (db[k] > db[k - 1]) notSmaller++;
			if (notBigger == 0 && notSmaller == 0) peakCount++;
			i = j;
		}
		i++;
	}
	printf("\033[1;61H");
	setColors(RED, bg(WHITE));
	printf("Peak: %d\n", peakCount);
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
