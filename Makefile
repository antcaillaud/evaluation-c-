CPP = g++
RM=rm -f
%.o:%.cpp
	$(CPP) -o $@ -c $<

eval : sommets.o  arete.o matrice.o liste.o lire.o main.o 
	$(CPP) $^ -o $@

sommets.o : sommets.cpp sommets.h
arete.o : arete.cpp arete.h sommets.h
matrice.o : matrice.cpp matrice.h arete.h sommets.h
liste.o : liste.cpp liste.h matrice.h arete.h sommets.h
lire.o : lire.cpp lire.h sommets.h arete.h
main.o : main.cpp sommets.h arete.h matrice.h liste.h lire.h

clean:
	$(RM) *.o eval

.PHONY: clean