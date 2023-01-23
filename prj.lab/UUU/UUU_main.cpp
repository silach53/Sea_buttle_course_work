#include <UUU/UUU.hpp>
std::vector<std::vector<int>> CB = {
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

void random_board(std::vector<std::vector<int>>& Y,std::vector<int> roster) {
	int n = Y.size(), m = Y[0].size();
	std::vector<std::vector<int>> X(n, std::vector<int>(m));

	//Заполняет доску 

	//Кораблики не должны стоять рядом - но попробуем на это забить
	int i, j, qor;
	for (auto x : roster) {
		i = rand() % (n-x);
		j = rand() % (m-x);
		qor = rand() % 2;

		if (qor == 0) {
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
void bot0_make_a_move(game& state) {
	if (state.b0_feeled == false) {
		std::vector<std::vector<int>> X(state.n, std::vector<int>(state.m));
		while (!state.fill_board(0, X)) {
			random_board(X,state.ship_roster);
			//state.print_board();
		}
		return;
	}
	int i=0, j=0;//заполнить случайными 
	while (!state.make_a_move(0, i, j)) {
		i = rand() % state.n;
		j = rand() % state.m;
	}
}

//Deterministic bot
void bot1_make_a_move(game& state) {
	if (state.b1_feeled == false) {
		std::vector<std::vector<int>> TMP;
		TMP = CB;
		if (!state.fill_board(1, TMP))
			std::cout << "You made your board incorrecly";
		return;
	}
	//Детерминированно перебираем достку 
	for (int i = 0; i < state.n; ++i)
		for (int j = 0; j < state.m; ++j)
			if (state.make_a_move(1, i, j))
				return;

}

int main() {
	game board_statу;
	

	srand(time(NULL));

	while (true) {
		bot0_make_a_move(board_statу);

		if (board_statу.end_of_the_game) {
			break;
		}

		bot1_make_a_move(board_statу);
		
		if (board_statу.end_of_the_game) {
			break;
		}

		board_statу.print_board();
	}

	board_statу.print_board();
	std::cout << "Player: " << board_statу.who_won << " won the game";
}
