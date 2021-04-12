#include <stdio.h>

void set_ansi(int fg) {
	printf("\033[%d;%dm", fg, fg - 10);
}

void set_8bit(int color) {
	// foreground
	//printf("\033[38;5;%dm", color);
	// background
	printf("\033[48;5;%dm", color);
}

void set_24bit(int r, int g, int b) {
	// foreground
	printf("\033[38;2;%d;%d;%dm", r, g, b);
	// background
	//printf("\033[48;2;%d;%d;%dm", r, g, b);
}

void reset_colors() {
	printf("\033[0m");
}

int main() {
	puts("");
	// red
	printf("  ");
	set_ansi(41);
	set_8bit(160);
	set_24bit(228, 3, 3);
	printf("                 ");
	reset_colors();
	printf("\n");
	// orange
	printf("  ");
	set_ansi(101);
	set_8bit(208);
	set_24bit(255, 140, 0);
	printf("                 ");
	reset_colors();
	printf("\n");
	// yellow
	printf("  ");
	set_ansi(103);
	set_8bit(226);
	set_24bit(255, 237, 0);
	printf("                 ");
	reset_colors();
	printf("\n");
	// green
	printf("  ");
	set_ansi(42);
	set_8bit(28);
	set_24bit(0, 128, 38);
	printf("                 ");
	reset_colors();
	printf("\n");
	// blue
	printf("  ");
	set_ansi(104);
	set_8bit(27);
	set_24bit(0, 77, 255);
	printf("                 ");
	reset_colors();
	printf("\n");
	// purple
	printf("  ");
	set_ansi(45);
	set_8bit(90);
	set_24bit(117, 7, 135);
	printf("                 ");
	reset_colors();
	printf("\n");

	puts("");

	return 0;
}

