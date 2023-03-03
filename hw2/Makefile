F = -std=c++11
P = simple_main coins_main coin_menu letter_count word_count

all: $P

simple_main: Coins.h simple_main.cpp
	g++ $F simple_main.cpp -o simple_main

coins_main: Coins.h coins_main.cpp
	g++ $F coins_main.cpp -o coins_main

coin_menu: Coins.h coin_menu.cpp
	g++ $F coin_menu.cpp -o coin_menu

letter_count: letter_count.cpp
	g++ $F letter_count.cpp -o letter_count

word_count: word_count.cpp
	g++ $F word_count.cpp -o word_count

clean:
	/bin/rm -f $P