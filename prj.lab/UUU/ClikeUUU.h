#ifndef ALEKSEEV_A_R_CLIKEQUEUEP_H
#define ALEKSEEV_A_R_CLIKEQUEUEP_H
#include <stdbool.h>
//#include "UUU/UUU.hpp"
#ifdef __cplusplus

#if defined(_MSC_VER)
	//  Microsoft 
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
	//  GCC
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#else
	//  do nothing and hope for the best?
#define EXPORT
#define IMPORT
#pragma warning Unknown dynamic link import/export semantics.
#endif

extern "C" {
#endif
	struct game;
	EXPORT struct game* makegame();
	EXPORT int fill_board(struct game* g, int bot_id, const	long* X);
	EXPORT int make_a_move(struct game* g, int bot_id, int i, int j);
	EXPORT void print_board(struct game* g);
	EXPORT int end_of_the_game(struct game* g);
	EXPORT int who_won(struct game* g);
	EXPORT int b0_feeled(struct game* g);
	EXPORT int b1_feeled(struct game* g);
	EXPORT int* C_ship_roster(struct game* g);
	EXPORT void ship_roster(struct game* g,int* roarter);
	EXPORT int hu_n(game* g);
	EXPORT int hu_m(game* g);
	EXPORT int hu_rs(game* g);

#ifdef __cplusplus
};
#endif

#endif
