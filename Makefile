all:  compile link

test:  compile link clean

r: compile link clean run
go:	
	g++ *.cpp -lsfml-graphics -lsfml-window -lsfml-system -o main
	main.exe
compile: 
	g++ -c *.cpp
link: 
	g++ *.o -o main -lsfml-graphics -lsfml-window -lsfml-system
clean:
	del *.o	
run: 
	main.exe




