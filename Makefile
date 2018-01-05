MapProgram.exe: ParkClass.o ColorClass.o PixelLocationClass.o MapClass.o main.o
	g++ -g -Wall ParkClass.o ColorClass.o PixelLocationClass.o MapClass.o main.o -o MapProgram.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o

MapClass.o: MapClass.cpp MapClass.h
	g++ -c MapClass.cpp -o MapClass.o

PixelLocationClass.o: PixelLocationClass.cpp PixelLocationClass.h
	g++ -c PixelLocationClass.cpp -o PixelLocationClass.o

ColorClass.o: ColorClass.cpp ColorClass.h
	g++ -c ColorClass.cpp -o ColorClass.o

ParkClass.o: ParkClass.cpp ParkClass.h
	g++ -c ParkClass.cpp -o ParkClass.o

clean:
	rm -rf *.o *~ *.exe