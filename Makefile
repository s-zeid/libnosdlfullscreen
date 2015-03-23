all: libnosdlfullscreen.so

32: libnosdlfullscreen32.so
64: libnosdlfullscreen.so

libnosdlfullscreen.so: libnosdlfullscreen-native.so
	mv $^ $@

libnosdlfullscreen%.so: nosdlfullscreen.c
	$(CC) $(CFLAGS) -Wall -fPIC -DPIC -c nosdlfullscreen.c \
	 $(if $(filter 32,$*),-m$*,)
	$(LD) $(LDFLAGS) -ldl -shared -o $@ nosdlfullscreen.o \
	 $(if $(filter 32,$*),-m elf_i386,)
	rm -f nosdlfullscreen.o

.PHONY: clean

clean:
	rm -f libnosdlfullscreen*.so*
