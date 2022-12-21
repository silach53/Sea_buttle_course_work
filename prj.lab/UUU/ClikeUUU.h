#ifndef ALEKSEEV_A_R_CLIKEQUEUEP_H
#define ALEKSEEV_A_R_CLIKEQUEUEP_H
#include <stdbool.h>
//#include "UUU/UUU.hpp"
#ifdef __cplusplus
extern "C" {
#endif

	//__declspec(dllexport) const int N = game::n;
	//__declspec(dllexport) const int M = game::m;
	//__declspec(dllexport) const int RS = game::rs;
	__declspec(dllexport) const int N = 10;
	__declspec(dllexport) const int M = 10;
	__declspec(dllexport) const int RS = 2;

	__declspec(dllexport) int с_n();
	__declspec(dllexport) int с_m();
	__declspec(dllexport) int с_rs();

	struct game;
	__declspec(dllexport) struct game* makegame();
	__declspec(dllexport) bool C_fill_board(struct game* g, int bot_id, const	long* X);
	__declspec(dllexport) bool fill_board(struct game* g, int bot_id);
	__declspec(dllexport) bool make_a_move(struct game* g, int bot_id, int i, int j);
	__declspec(dllexport) void print_board(struct game* g);
	__declspec(dllexport) bool end_of_the_game(struct game* g);
	__declspec(dllexport) int who_won(struct game* g);
	__declspec(dllexport) bool b0_feeled(struct game* g);
	__declspec(dllexport) bool b1_feeled(struct game* g);
	__declspec(dllexport) int* ship_roster(struct game* g);


#ifdef __cplusplus
};
#endif

#endif
