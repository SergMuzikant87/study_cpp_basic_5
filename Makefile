CC := g++
FLAGS := -Wall -O2 -std=c++11 -g

all:
	@echo "Compile programm"
	$(CC) $(FLAGS) dz_5_1.cpp -o dz_5_1
	$(CC) $(FLAGS) dz_5_2.cpp -o dz_5_2
	$(CC) $(FLAGS) dz_5_3.cpp -o dz_5_3
	$(CC) $(FLAGS) dz_5_4.cpp -o dz_5_4
