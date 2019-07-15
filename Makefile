SH=/bin/sh
CC=gcc
INSTDIR=/usr/local
INSTLIB=${INSTDIR}/lib
INSTINC=${INSTDIR}/include

libsimu1.a : libsimu1.o
	rm -f libsimu1.a
	ar qv libsimu1.a libsimu1.o

libsimu1.o : libsimu1.c libsimu1.h
	${CC} -c libsimu1.c

demo : demo.c libsimu1.h libsimu1.a
	${CC} demo.c libsimu1.a -o demo -lm
	./demo

clean :
	rm -f *.a *.o demo demo.exe

install :
	cp -i libsimu1.a ${INSTLIB}/libsimu1.a
	cp -i libsimu1.h ${INSTINC}/libsimu1.h

uninstall :
	(cd ${INSTLIB} ; rm -f libsimu1.a)
	(cd ${INSTINC} ; rm -f libsimu1.h)
