CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = pi_orig pi_simd
all: $(EXEC)

SRCS_common = main.c

pi_orig: $(SRCS_common) pi_orig.c pi_orig.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

pi_simd: $(SRCS_common) pi_simd.c pi_simd.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

clean:
	$(RM) $(EXEC) *.o
