# Basic Makefile (Q1)

#app-main: point.o app-main.o
#	clang++ point.o app-main.o -o app-main

#point.o: point.cpp point.h
#	clang++ -c point.cpp

#app-main.o: app-main.cpp point.h
#	clang++ -c app-main.cpp


app: date.o app.o client.o
	g++ -o date.o app.o client.o

date.o:	Date.cpp	Date.h
	g++ -c Date.cpp

app.o:	app.cpp
	g++ -c app.cpp

client.o: Client.h Client.cpp
	g++ -c Client.cpp

