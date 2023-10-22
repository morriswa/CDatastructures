tests:
	clang -o prog ./HashTable.c
	./prog

test-map: 
	clang -o prog ./HashMapTests.c ./HashMap.c
	./prog

clean:
	[ ! -e ./prog ] || rm ./prog