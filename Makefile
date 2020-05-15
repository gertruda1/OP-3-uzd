main: funkcijos_vektorius.o funkcijos_list.o funkcijos_deque.o
	g++ -o test UnitTest.cpp funkcijos_vektorius.o funkcijos_list.o funkcijos_deque.o
funkcijos_vektorius:
	g++ -c funkcijos_vektorius.cpp
funkcijos_list:
	g++ -c funkcijos_list.cpp
funkcijos_deque:
	g++ -c funkcijos_deque.cpp

clean:
	del *.o main