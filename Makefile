CC = g++
LD = g++
CCFLAG = -Wall -Wno-deprecated -g -c
LDFLAG = -Wall -Wno-deprecated -g

EXECS = main
#in some case other platform create .exe and will not delete the executable, so I can add extraclean part if needed

all: $(EXECS)

main: Signal.o 
	$(LD) $(LDFLAG) -o main signal.o
	
Signal.o: Signal.h Signal.cpp
	$(CC) $(CCFLAG) Signal.cpp

clean:
	/bin/rm -f *.o $(EXECS)
