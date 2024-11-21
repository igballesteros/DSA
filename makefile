linkedLists: linkedLists.o functions.o
	g++ linkedLists.o functions.o -o linkedLists

linkedLists.o: linkedLists.cpp
	g++ -c linkedLists.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

clean:
	rm *.o linkedLists