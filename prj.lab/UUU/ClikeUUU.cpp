#include "UUU/UUU.hpp"
#include "ClikeUUU.h"
#include <vector>

extern "C" {
	//game;

	__declspec(dllexport) int hu_n() { return game::n; };
	__declspec(dllexport) int hu_m() { return game::m; };
	__declspec(dllexport) int hu_rs() { return game::rs; };

	__declspec(dllexport) struct game* makegame() {
		return new game();
	}
	int C_fill_board(game* g, int bot_id, const long* X) {
		return int(g->fill_board_C(bot_id, X));
	}	
	__declspec(dllexport) int fill_board(game* g, int bot_id) {
		return g->fill_board_f(bot_id);
	}
	__declspec(dllexport) int make_a_move(game* g, int bot_id, int i, int j) {
		return g->make_a_move(bot_id, i, j);
	}
	__declspec(dllexport) void print_board(game* g) {
		g->print_board();
	}
	__declspec(dllexport) 	int end_of_the_game(game* g) {
		return g->end_of_the_game;
	}
	__declspec(dllexport) 	int who_won(game* g) {
		return g->who_won;
	}
	__declspec(dllexport) 	int b0_feeled(game* g) {
		return g->b0_feeled;
	}
	__declspec(dllexport) 	int b1_feeled(game* g) {
		return g->b1_feeled;
	}
	int* C_ship_roster(game* g) {
		int* rost = (int*)malloc(hu_rs() * sizeof(int));
		for (int i = 0; i < hu_rs(); ++i) {
			rost[i] = g->ship_roster[i];
		}
		return rost;
	}
	void ship_roster(game* g) {
		g->f_in_roster();
	}
};