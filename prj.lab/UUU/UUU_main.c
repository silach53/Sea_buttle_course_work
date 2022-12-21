#include <UUU/ClikeUUU.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N;
int M;
int RS;

void random_board(int* X, int* roster) {
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) X[i * N + j] = 0;
	//Заполняет доску 
	int n = N, m = M;
	//Кораблики не должны стоять рядом - но попробуем на это забить
	int i, j, or ;
	for (int t = 0; t < RS; ++t) {
		int x = roster[t];
		i = rand() % (n - x);
		j = rand() % (m - x);
		or = rand() % 2;

		if (or == 0) {
			for (int k = 0; k < x; ++k)
				X[(i + k) * N + j] = 1;
		}
		else {
			for (int k = 0; k < x; ++k)
				X[i * N + (j + k)] = 1;
		}
	}
}

void small_print(const int* X) {
	printf("smallprint\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			printf("%d", X[i * N + j]);
		printf("\n");
	}
}

//Random bot
void bot0_make_a_move(struct game* state) {
	if (b0_feeled(state) == 0) {
		//Штука для бота
		int* X = (int*)malloc(N * M * sizeof(int));
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) X[i * N + j] = 0;
		//small_print(X);
		while (!C_fill_board(state, 0, X)) {
			random_board(X, C_ship_roster(state));
			//small_print(X);
		}
		return;
	}

	int i = 0, j = 0;//заполнить случайными 
	while (!make_a_move(state, 0, i, j)) {
		i = rand() % N;
		j = rand() % M;
	}
}

//Deterministic bot
void bot1_make_a_move(struct game* state) {
	int* CB = (int*)malloc(N * M * sizeof(int));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			CB[i * N + j] = 0;

	CB[5 * N + 5] = 1;
	CB[8 * N + 3] = 1;


	if (b1_feeled(state) == 0) {
		if (!C_fill_board(state, 1, CB))
			printf("You made your board incorrecly\n");
		return;
	}
	//Детерминированно перебираем достку 
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (make_a_move(state, 1, i, j))
				return;

}

int main() {

	struct game* board_statу = makegame();
	


	N = hu_n();
	M = hu_m();
	RS = hu_rs();
	

	srand(time(NULL));

	while (1) {
		bot0_make_a_move(board_statу);
		if (end_of_the_game(board_statу)) {
			break;
		}

		bot1_make_a_move(board_statу);

		if (end_of_the_game(board_statу)) {
			break;
		}

		print_board(board_statу);
	}

	print_board(board_statу);
	printf("Player:  %d won the game", who_won(board_statу));
}