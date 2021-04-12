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

void print_line(struct color c, int length) {
	printf("  ");
	set_ansi(c.ansi);
	set_8bit(c.xterm);
	set_24bit(c.r, c.g, c.b);
	for (int i = 0; i < length; i++) {
		printf(" ");
	}
	reset_colors();
	printf("\n");
}

int main() {
	puts("");

	// red
	struct color red = { .ansi = 41, .xterm = 160, .r = 228, .g = 3, .b = 3 };
	print_line(red, 17);
	// orange
	struct color orange = { .ansi = 101, .xterm = 208, .r = 255, .g = 140, .b = 0 };
	print_line(orange, 17);
	// yellow
	struct color yellow = { .ansi = 103, .xterm = 226, .r = 255, .g = 237, .b = 0 };
	print_line(yellow, 17);
	// green
	struct color green = { .ansi = 42, .xterm = 28, .r = 0, .g = 128, .b = 38 };
	print_line(green, 17);
	// blue
	struct color blue = { .ansi = 104, .xterm = 27, .r = 0, .g = 77, .b = 255 };
	print_line(blue, 17);
	// purple
	struct color purple = { .ansi = 45, .xterm = 90, .r = 117, .g = 7, .b = 135 };
	print_line(purple, 17);

	puts("");

	return 0;
}
