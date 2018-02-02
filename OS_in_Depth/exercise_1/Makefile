cc = gcc
ccflags = -g -I.

all:	server interface

server: server.o db.o window.o
	$(cc) ${ccflags} ${LDflags} server.o db.o window.o \
		-o server

server.o:	server.c window.h db.h
	$(cc) server.c -c ${ccflags}

db.o:	db.c db.h
	$(cc) db.c -c ${ccflags}

window.o:	window.c window.h
	$(cc) window.c -c ${ccflags}

interface:	interface.c
	${cc} -o interface interface.c -O

clean:
	/bin/rm -f *.o server interface
