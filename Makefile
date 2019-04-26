EXECS = Simulation #testAnimator
OBJS = VehicleBase.o Simulation.o Section.o TrafficLight.o Lane.o Intersection.o Roadways.o Animator.o#ParameterParser.o#testAnimator.o Animator.o VehicleBase.o

#### use next two lines for Mac
#CC = clang++
#CCFLAGS = -std=c++11 -stdlib=libc++

#### use next two lines for mathcs* machines:
CC = g++
CCFLAGS = -std=c++11 -Wall -Wno-deprecated -Werror=return-type -g

all: $(EXECS)

Simulation: $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

%.o: %.cpp *.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS)
