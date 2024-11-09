
help:
	@echo "USE: make simulator"

.PHONY: simulator

simulator:
	cd simulator/src; \
	g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system; \
	./a.out; \
	rm a.out
