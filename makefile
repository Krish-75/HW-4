main.o passengers.o drivers.o rides.o economy.o basic.o group.o luxury.o

a.out : main.o passengers.o drivers.o rides.o passenger.o driver.o ride.o
	g++ main.o passengers.o drivers.o rides.o passenger.o driver.o ride.o -o a.out

main.o : main.cpp passengers.h drivers.h rides.h
	g++ -Wall -c main.cpp

rides.o : rides.cpp rides.h ride.h
	g++ -Wall -c rides.cpp

passengers.o : passengers.cpp passengers.h passenger.h
	g++ -Wall -c passengers.cpp

drivers.o : drivers.cpp drivers.h driver.h
	g++ -Wall -c drivers.cpp

ride.o : ride.cpp ride.h driver.h passenger.h economy.o basic.o group.o luxury.o
	g++ -Wall -c ride.cpp

passenger.o : passenger.cpp passenger.h 
	g++ -Wall -c passenger.cpp

driver.o : driver.cpp driver.h economy.o basic.o group.o luxury.o
	g++ -Wall -c driver.cpp

economy.o : economy.cpp economy.h
	g++ -Wall -c economy.cpp

basic.o : basic.cpp basic.h
	g++ -Wall -c basic.cpp

group.o : group.cpp group.h
	g++ -Wall -c group.cpp

luxury.o : luxury.cpp luxury.h
	g++ -Wall -c luxury.cpp

clean :
	rm *.o a.out