default:
	echo "hello world"

run:
	rm -rf ./bin
	mkdir -p ./bin
	gcc ./networking/test.c ./networking/server.c -o ./bin/test
	./bin/test
