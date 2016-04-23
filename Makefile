CC = g++ -std=gnu++0x 
LD = g++ -std=gnu++0x
CCFLAG = -Wall -Wno-deprecated -g -c
LDFLAG = -Wall -Wno-deprecated -g

EXECS = Test
#in some case other platform create .exe and will not delete the executable, so I can add extraclean part if needed

all: $(EXECS)

Test: Test.o Signal.o
	$(LD) $(LDFLAG) -o Test Test.o Signal.o

Test.o: Test.h Test.cpp
	$(CC) $(CCFLAG) Test.cpp

Signal.o: Signal.h Signal.cpp
	$(CC) $(CCFLAG) Signal.cpp

clean:
	/bin/rm -f *.o $(EXECS)