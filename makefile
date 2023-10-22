test-set:
	clang -o prog ./HashSetTests.c ./HashSet.c ./Utils.c
	./prog
	[ ! -e ./prog ] || rm ./prog

test-map: 
	clang -o prog ./HashMapTests.c ./HashMap.c ./Utils.c 
	./prog
	[ ! -e ./prog ] || rm ./prog

test-arr-list: 
	clang -o prog ./ArrayListTests.c ./ArrayList.c ./Utils.c
	./prog
	[ ! -e ./prog ] || rm ./prog

clean:
	[ ! -e ./prog ] || rm ./prog

tests:
	make test-set
	make test-map
	make test-arr-list