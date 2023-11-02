# Generated with github.com/da0x/mmpp
# Binary:
grab: .obj .obj/main.o
	g++ -std=c++20 .obj/main.o -o grab

.obj:
	mkdir .obj

.obj/main.o: ./main.cpp
	g++ -std=c++20 -o .obj/main.o -c ./main.cpp

run: grab
	./grab

clean:
	rm -rfv .obj

install:
	sudo cp -v grab /usr/local/bin/

uninstall:
	sudo rm -v /usr/local/bin/grab
