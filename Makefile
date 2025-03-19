default:
	echo "Building..........."
	rm -rf ./bin
	rm -rf ./build
	mkdir -p ./bin
	mkdir -p ./build
	gcc -Wall -c ./src/main.c -o ./build/main.o
	gcc -Wall -c ./src/networking/server.c -o ./build/server.o
	gcc -Wall -c ./src/networking/request.c -o ./build/request.o
	gcc -Wall -c ./src/networking/response.c -o ./build/response.o
	ar rcs ./build/main.a ./build/main.o ./build/server.o ./build/request.o ./build/response.o 
	gcc ./build/main.a -o ./bin/main.out
	echo "Running.........."
	./bin/main.out
