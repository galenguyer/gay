#include <stdio.h>

struct color {
	int ansi;
	int xterm;
	int r;
	int g;
	int b;
};

void set_ansi(int fg) {
	printf("\033[%d;%dm", fg, fg - 10);
}

void set_8bit(int color) {
	// foreground
	printf("\033[38;5;%dm", color);
	// background
	printf("\033[48;5;%dm", color);
}

void set_24bit(int r, int g, int b) {
	// foreground
	printf("\033[38;2;%d;%d;%dm", r, g, b);
	// background
	printf("\033[48;2;%d;%d;%dm", r, g, b);
}

void reset_colors() {
	printf("\033[0m");
}

int main() {
	puts("");

	// red
	struct color red = { .ansi = 41, .xterm = 160, .r = 288, .g = 3, .b = 3 };
	printf("  ");
	set_ansi(red.ansi);
	set_8bit(red.xterm);
	set_24bit(red.r, red.g, red.b);
	printf("                 ");
	reset_colors();
	printf("\n");
	// orange
	struct color orange = { .ansi = 101, .xterm = 208, .r = 255, .g = 140, .b = 0 };
	printf("  ");
	set_ansi(orange.ansi);
	set_8bit(orange.xterm);
	set_24bit(orange.r, orange.g, orange.b);
	printf("                 ");
	reset_colors();
	printf("\n");
	// yellow
	struct color yellow = { .ansi = 103, .xterm = 226, .r = 255, .g = 237, .b = 0 };
	printf("  ");
	set_ansi(yellow.ansi);
	set_8bit(yellow.xterm);
	set_24bit(yellow.r, yellow.g, yellow.b);
	printf("                 ");
	reset_colors();
	printf("\n");
	// green
	struct color green = { .ansi = 42, .xterm = 28, .r = 0, .g = 128, .b = 38 };
	printf("  ");
	set_ansi(green.ansi);
	set_8bit(green.xterm);
	set_24bit(green.r, green.g, green.b);
	printf("                 ");
	reset_colors();
	printf("\n");
	// blue
	struct color blue = { .ansi = 104, .xterm = 27, .r = 0, .g = 77, .b = 255 };
	printf("  ");
	set_ansi(blue.ansi);
	set_8bit(blue.xterm);
	set_24bit(blue.r, blue.g, blue.b);
	printf("                 ");
	reset_colors();
	printf("\n");
	// purple
	struct color purple = { .ansi = 45, .xterm = 90, .r = 117, .g = 7, .b = 135 };
	printf("  ");
	set_ansi(purple.ansi);
	set_8bit(purple.xterm);
	set_24bit(purple.r, purple.g, purple.b);
	printf("                 ");
	reset_colors();
	printf("\n");

	puts("");

	return 0;
}
