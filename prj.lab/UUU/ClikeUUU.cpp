#include "UUU/UUU.hpp"
#include "ClikeUUU.h"
#include <vector>

extern "C" {
	game;
	struct game* makegame() {
		return new game();
	}
	bool fill_board(game* g, int bot_id, const int* X) {
		return g->fill_board_C(bot_id, X);
	}
	bool make_a_move(game* g, int bot_id, int i, int j) {
		return g->make_a_move(bot_id, i, j);
	}
	void print_board(game* g) {
		g->print_board();
	}
	bool end_of_the_game(game* g) {
		return g->end_of_the_game;
	}
	int who_won(game* g) {
		return g->who_won;
	}
	bool b0_feeled(game* g) {
		return g->b0_feeled;
	}
	bool b1_feeled(game* g) {
		return g->b1_feeled;
	}
	int* ship_roster(game* g) {
		int rost[RS];
		for (int i = 0; i < RS; ++i) {
			rost[i] = g->ship_roster[i];
			std::cout << rost[i] << " ";
		}
		std::cout << "\n\n";
		return rost;
	}
};