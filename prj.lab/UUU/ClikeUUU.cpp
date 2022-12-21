#include "UUU/UUU.hpp"
#include "ClikeUUU.h"
#include <vector>

extern "C" {
	//game;

	__declspec(dllexport) int с_n() { return N; };
	__declspec(dllexport) int с_m() { return M; };
	__declspec(dllexport) int с_rs() { return RS; };

	__declspec(dllexport) struct game* makegame() {
		return new game();
	}
	__declspec(dllexport) bool C_fill_board(game* g, int bot_id, const long* X) {
		return g->fill_board_C(bot_id, X);
	}	
	__declspec(dllexport) bool fill_board(game* g, int bot_id) {
		return g->fill_board_f(bot_id);
	}
	__declspec(dllexport) bool make_a_move(game* g, int bot_id, int i, int j) {
		return g->make_a_move(bot_id, i, j);
	}
	__declspec(dllexport) void print_board(game* g) {
		g->print_board();
	}
	__declspec(dllexport) 	bool end_of_the_game(game* g) {
		return g->end_of_the_game;
	}
	__declspec(dllexport) 	int who_won(game* g) {
		return g->who_won;
	}
	__declspec(dllexport) 	bool b0_feeled(game* g) {
		return g->b0_feeled;
	}
	__declspec(dllexport) 	bool b1_feeled(game* g) {
		return g->b1_feeled;
	}
	__declspec(dllexport) 	int* ship_roster(game* g) {
		int* rost = (int*)malloc(RS * sizeof(int));
		for (int i = 0; i < RS; ++i) {
			rost[i] = g->ship_roster[i];
			//std::cout << rost[i] << " ";
		}
		//std::cout << "\n\n";
		return rost;
	}
};