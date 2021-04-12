gay: gay.c
	gcc -ggdb -o $@ -std=c99 -Wall $<

.PHONY:watch
watch: gay
	while true; do \
		clear; \
		(make gay && ./gay) || true; \
		inotifywait -qe modify ./gay.c; \
	done
