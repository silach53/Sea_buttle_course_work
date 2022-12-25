#include "UUU/UUU.hpp"
#include "ClikeUUU.h"
#include <vector>
#include <iostream>
#include <iomanip>



extern "C" {
	//game;

	EXPORT int hu_n(game* g) { return g->n; };
	EXPORT int hu_m(game* g) { return g->m; };
	EXPORT int hu_rs(game* g) { return g->rs; };

	EXPORT struct game* makegame() {
		auto p = new game();
		std::cout << std::hex << "makegame() " << p << std::endl;
		return p;
	}
	EXPORT int fill_board(game* g, int bot_id, const long* X) {
		return int(g->fill_board_C(bot_id, X));
	}
	EXPORT int make_a_move(game* g, int bot_id, int i, int j) {
		return g->make_a_move(bot_id, i, j);
	}
	EXPORT void print_board(game* g) {
		g->print_board();
	}
	EXPORT 	int end_of_the_game(game* g) {
		return g->end_of_the_game;
	}
	EXPORT 	int who_won(game* g) {
		return g->who_won;
	}
	EXPORT 	int b0_feeled(game* g) {
		return g->b0_feeled;
	}
	EXPORT 	int b1_feeled(game* g) {
		return g->b1_feeled;
	}
	EXPORT int* C_ship_roster(struct game* g) {
		int* rost = (int*)malloc(hu_rs(g) * sizeof(int));
		for (int i = 0; i < hu_rs(g); ++i) {
			rost[i] = g->ship_roster[i];
		}
		return rost;
	}
	EXPORT  void ship_roster(struct game* g,int* roarter) {
		g->f_in_roster(roarter);
	}
};