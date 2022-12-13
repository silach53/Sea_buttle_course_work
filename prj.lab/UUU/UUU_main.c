#include <UUU/ClikeUUU.h>
#include <stdio.h>

const int CB[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

void random_board(int* Y[10][10] ,int roster[2]) {
	int n = N, m = M;
	int X[10][10];

	//Заполняет доску 

	//Кораблики не должны стоять рядом - но попробуем на это забить
	int i, j, or;
	for (int t = 0; t < RS; ++t) {
		int x = roster[t];
		i = rand() % (n-x);
		j = rand() % (m-x);
		or = rand() % 2;

		if (or == 0) {
			for (int k = 0; k < x; ++k)
				X[i+k][j] = 1;
		}
		else {
			for (int k = 0; k < x; ++k)
				X[i][j+k] = 1;
		}
	}

	Y = X;
}
//Random bot
void bot0_make_a_move(struct game* state) {
	if (b0_feeled(state) == false) {
		int X[10][10];
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) X[i][j] = 0;
		while (!fill_board(state,0, X)) {
			random_board(X,ship_roster(state));
			//state.print_board();
		}
		return;
	}
	int i=0, j=0;//заполнить случайными 
	while (!make_a_move(state,0, i, j)) {
		i = rand() % N;
		j = rand() % M;
	}
}

//Deterministic bot
void bot1_make_a_move(struct game* state) {
	if (b1_feeled(state) == false) {
		if (!fill_board(state,1, CB))
			printf("You made your board incorrecly\n");
		return;
	}
	//Детерминированно перебираем достку 
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (make_a_move(state,1, i, j))
				return;

}

int main() {
	struct game* board_statу = makegame();
	
	srand(time(NULL));

	while (true) {
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