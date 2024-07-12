# Makefile
all:led_test.out
CC = gcc
INSTDIR = ./Output
INCLUDE = .
CFLAGS = -O -Wall -ansi
objects = main.o interface/colorledApi.o 
source = main.c interface/colorledApi.c interface/include/colorledApi.h
MYLIB = mylib.a
led_test.out: $(MYLIB)
	$(CC) -o led_test.out $(MYLIB)

$(MYLIB): $(MYLIB)($(objects))

.SUFFIXES:.c
.c .o:
	$(CC) -c -I$(INCLUDE) $(CFLAGS) $<

#$(objects): %.o: %.c
	#$(CC) -c $(CFLAGS) $< -o $@

clean:
	-rm led_test.out *.a

.PHONY: install
install:led_test.out
	@if [ -d $(INSTDIR) ];\
	then \
		cp led_test.out $(INSTDIR);\
		chmod a+x $(INSTDIR)/led_test.out;\
		chmod og-w $(INSTDIR)/led_test.out;\
		echo "Installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) does not exist";\
	fi