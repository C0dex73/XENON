ifeq (run,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif

all: ./bin/assembler

./bin/assembler: ./bin/assembler.o
	g++ -o ./bin/assembler ./bin/assembler.o -W

./bin/assembler.o: ./src/assembler.cpp ./src/paths.h
	g++ -o ./bin/assembler.o -c ./src/assembler.cpp -W

.PHONY: clean mrproper

clean:
	rm -rf bin/*.o

reset: clean
	rm -rf bin/*

run:
	./bin/assembler $(RUN_ARGS)