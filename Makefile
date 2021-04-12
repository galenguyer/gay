CC=gcc

CFLAGS=-Wall -Wextra -Werror -pedantic -fstack-protector-all -pedantic -std=c99
SANITY_FLAGS=-Wfloat-equal -Wshadow -Wpointer-arith

PREFIX ?= /usr

SOURCE=gay.c

OUTPUT=gay

ALL: $(OUTPUT)

debug: CFLAGS += -g -O0
debug: $(OUTPUT)

release: CFLAGS += -static -O3
release: $(OUTPUT)

$(OUTPUT): Makefile $(SOURCE)
	$(CC) $(CFLAGS) $(SANITY_FLAGS) $(SOURCE) -o $(OUTPUT)

install: $(OUTPUT)
	install -Dm755 "gay"   "$(PREFIX)/bin/gay"
	install -Dm644 "LICENSE"    "$(PREFIX)/share/licenses/gay/LICENSE"
	#install -Dm644 "gay.8" "$(PREFIX)/share/man/man8/gay.8.gz"

uninstall:
	rm -f "$(PREFIX)/bin/gay"
	rm -f "$(PREFIX)/share/licenses/gay/LICENSE"
	#rm -f "$(PREFIX)/share/man/man8/gay.8.gz"

#gay: gay.c
#	gcc -ggdb -o $@ -std=c99 -Wall $<

.PHONY:watch
watch: gay
	while true; do \
		clear; \
		(make gay && ./gay) || true; \
		inotifywait -qe modify ./gay.c; \
	done
