# Makefile
all:adxl485_test.out
CC = gcc
INSTDIR = ./Output
INCLUDE = .
CFLAGS = -O -Wall -ansi
objects = main.o interface/adxl485api.o 
source = main.c interface/adxl485api.c interface/include/adxl485api.h
MYLIB = mylib.a
adxl485_test.out: $(MYLIB)
	$(CC) -o adxl485_test.out $(MYLIB)

$(MYLIB): $(MYLIB)($(objects))

.SUFFIXES:.c
.c .o:
	$(CC) -c -I$(INCLUDE) $(CFLAGS) $<

#$(objects): %.o: %.c
	#$(CC) -c $(CFLAGS) $< -o $@

clean:
	-rm adxl485_test.out *.a

.PHONY: install
install:adxl485_test.out
	@if [ -d $(INSTDIR) ];\
	then \
		cp adxl485_test.out $(INSTDIR);\
		chmod a+x $(INSTDIR)/adxl485_test.out;\
		chmod og-w $(INSTDIR)/adxl485_test.out;\
		echo "Installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) does not exist";\
	fi