# Makefile
all:wbs2812b_test.out
CC = gcc
INSTDIR = ./Output
INCLUDE = .
CFLAGS = -O -Wall -ansi
objects = main.o interface/wbs2812bapi.o 
source = main.c interface/wbs2812bapi.c interface/include/wbs2812bapi.h
MYLIB = mylib.a
wbs2812b_test.out: $(MYLIB)
	$(CC) -o wbs2812b_test.out $(MYLIB)

$(MYLIB): $(MYLIB)($(objects))

.SUFFIXES:.c
.c .o:
	$(CC) -c -I$(INCLUDE) $(CFLAGS) $<

#$(objects): %.o: %.c
	#$(CC) -c $(CFLAGS) $< -o $@

clean:
	-rm wbs2812b_test.out *.a

.PHONY: install
install:wbs2812b_test.out
	@if [ -d $(INSTDIR) ];\
	then \
		cp led_test.out $(INSTDIR);\
		chmod a+x $(INSTDIR)/wbs2812b_test.out;\
		chmod og-w $(INSTDIR)/wbs2812b_test.out;\
		echo "Installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) does not exist";\
	fi