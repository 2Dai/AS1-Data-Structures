CC=c99
CFLAGS=-g -Wall -pedantic
# -ansi 
#
GENERES =	\
	lca.h	\
	th.h	\
	exemple-lca.c \
	exemple-th.c	\
	interpreteur-lca.c \
	interpreteur-th.c \
    performance-lca.c \
    performance-th.c \

EXE =	\
	exemple-lca-iterative	\
	exemple-lca-recursive	\
	exemple-th	\
	interpreteur-lca-iterative	\
	interpreteur-lca-recursive	\
	interpreteur-th	\
	test-lca-iterative \
	test-lca-recursive \
	test-th \
    performance-lca-iterative \
    performance-lca-recursive \
    performance-th \

all:: ${GENERES} $(EXE)

test-lca-iterative: test-lca.o lca-iterative.o seatest.o
	$(CC) $(LDFLAGS) -o $@ $^

test-lca-recursive: test-lca.o lca-recursive.o seatest.o	
	$(CC) $(LDFLAGS) -o $@ $^

test-th: test-th.o seatest.o th.o fonctions-hachage.o lca-iterative.o
	$(CC) $(LDFLAGS) -o $@ $^

interpreteur-lca-iterative: interpreteur-lca.o lca-iterative.o
	$(CC) $(LDFLAGS) -o $@ $^

interpreteur-lca-recursive: interpreteur-lca.o lca-recursive.o
	$(CC) $(LDFLAGS) -o $@ $^

interpreteur-th: interpreteur-th.o lca-iterative.o th.o fonctions-hachage.o
	$(CC) $(LDFLAGS) -o $@ $^

exemple-lca-iterative: exemple-lca.o lca-iterative.o seatest.o
	$(CC) $(LDFLAGS) -o $@ $^

exemple-lca-recursive: exemple-lca.o lca-recursive.o seatest.o
	$(CC) $(LDFLAGS) -o $@ $^

exemple-th: exemple-th.o th.o fonctions-hachage.o lca-iterative.o seatest.o
	$(CC) $(LDFLAGS) -o $@ $^

performance-lca-iterative: performance-lca.o lca-iterative.o
	$(CC) $(LDFLAGS) -pg -o $@ $^

performance-lca-recursive: performance-lca.o lca-recursive.o
	$(CC) $(LDFLAGS) -pg -o $@ $^

performance-th: performance-th.o lca-iterative.o th.o fonctions-hachage.o
	$(CC) $(LDFLAGS) -pg -o $@ $^

lca.h: sda.h
	cat $< | sed -e s/sda/lca/g -e s/SDA/LCA/g > $@

th.h: sda.h
	cat $< | sed -e s/sda/th/g -e s/SDA/TH/g > $@

%-lca.c: %-sda.c
	cat $< | sed -e s/sda/lca/g -e s/SDA/LCA/g > $@

%-th.c: %-sda.c
	cat $< | sed -e s/sda/th/g -e s/SDA/TH/g > $@


th.o: th.h th.c lca.h

seatest.o : seatest.c seatest.h

lca-iterative.o: lca-specifique.h lca.h lca-iterative.c

lca-recursive.o: lca.h lca-recursive.c

exemple-lca.o: lca.h exemple-lca.c seatest.h

exemple-th.o: th.h exemple-th.c seatest.h

fonctions-hachage.o: fonctions-hachage.h fonctions-hachage.c

test-lca.o: lca.h test-lca.c seatest.h

test-th.o: th.h test-th.c fonctions-hachage.h seatest.h

interpreteur-th.o: th.h lca.h fonctions-hachage.h interpreteur-th.c

interpreteur-lca.o: lca.h interpreteur-lca.c

performance-lca.o: performance-lca.c lca.h

performance-th.o: performance-th.c th.h lca.h

clean::
	rm -f *.o
	rm -f ${GENERES}
	rm -f $(EXE) a.out gmon.out
