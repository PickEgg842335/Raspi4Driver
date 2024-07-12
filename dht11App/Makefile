# Makefile
all:hello_pract.out
CC = gcc
INSTDIR = ./Output
INCLUDE = .
CFLAGS = -O -Wall -ansi
objects = main.o interface/dht11Api.o 
source = main.c interface/dht11Api.c interface/include/dht11Api.h.h
MYLIB = mylib.a
hello_pract.out: $(MYLIB)
	$(CC) -o dht11test.out $(MYLIB)

$(MYLIB): $(MYLIB)($(objects))

.SUFFIXES:.c
.c .o:
	$(CC) -c -I$(INCLUDE) $(CFLAGS) $<

#$(objects): %.o: %.c
	#$(CC) -c $(CFLAGS) $< -o $@

clean:
	-rm dht11test.out *.a

.PHONY: install
install:dht11test.out
	@if [ -d $(INSTDIR) ];\
	then \
		cp dht11test.out $(INSTDIR);\
		chmod a+x $(INSTDIR)/dht11test.out;\
		chmod og-w $(INSTDIR)/dht11test.out;\
		echo "Installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) does not exist";\
	fi