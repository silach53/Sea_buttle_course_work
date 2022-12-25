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
	

	

	

	struct game;

	

	__declspec(dllexport) struct game* makegame();
	__declspec(dllexport) int fill_board(struct game* g, int bot_id, const	long* X);
	__declspec(dllexport) int make_a_move(struct game* g, int bot_id, int i, int j);
	__declspec(dllexport) void print_board(struct game* g);
	__declspec(dllexport) int end_of_the_game(struct game* g);
	__declspec(dllexport) int who_won(struct game* g);
	__declspec(dllexport) int b0_feeled(struct game* g);
	__declspec(dllexport) int b1_feeled(struct game* g);
	__declspec(dllexport) int* C_ship_roster(struct game* g);
	__declspec(dllexport) void ship_roster(struct game* g,int* roarter);
	__declspec(dllexport) int hu_n();
	__declspec(dllexport) int hu_m();
	__declspec(dllexport) int hu_rs();

#ifdef __cplusplus
};
#endif

#endif
