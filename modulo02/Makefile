all: produtor_consumidor

run: produtor_consumidor
	./bin/produtor_consumidor

produtor_consumidor:
	gcc -Wall -o ./bin/produtor_consumidor -pthread ./src/produtor_consumidor.c ./src/buffer.c ./src/fila.c ./src/opcoes.c ./src/msleep.c

buffer_test:
	gcc -Wall -o ./bin/buffer_test ./src/buffer_test.c ./src/buffer.c ./src/fila.c
	./bin/buffer_test

clean:
	rm -rf ./bin/*