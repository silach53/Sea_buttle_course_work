#ifndef ALEKSEEV_A_R_CLIKEQUEUEP_H
#define ALEKSEEV_A_R_CLIKEQUEUEP_H
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

	int const N = 10;
	int const M = 10;
	int const RS = 10;

	struct game;
	struct game* makegame();
	bool fill_board(struct game* g, int bot_id, int** X);
	bool make_a_move(struct game* g, int bot_id, int i, int j);
	void print_board(struct game* g);
	bool end_of_the_game(struct game* g);
	int who_won(struct game* g);
	bool b0_feeled(struct game* g);
	bool b1_feeled(struct game* g);
	int* ship_roster(struct game* g);

#ifdef __cplusplus
};
#endif

#endif
