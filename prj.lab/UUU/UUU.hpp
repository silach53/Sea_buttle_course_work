#ifndef ALEKSEEV_A_R_QUEUEP_H
#define ALEKSEEV_A_R_QUEUEP_H
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
/*
Пришло грустное осознание, что я не в ту сторону писал прогу
Было привычно написать цикл игры и которого будут дергаться, боты и запрашиваьт их делать ход
но теперь стало очевидно, чтобы не думать как Дернуть бота, нужно просто дать боту возможность
узнать нужную ему текущую инфорамцию и сделать ход

- ход 1 создать поле
- ход 2 сделать ход

0 -> нет коробля, и в поле еще не стреляли
1 -> есть корабль и в поле еще не стреляли
2 -> нет коробля, и в поле еще не стреляли
3 -> есть корабль и в поле уже стреляли
*/
#ifdef __cplusplus
struct game {
public:
	bool                   b0_feeled = false;
	bool                   b1_feeled = false;
	int                    whos_tern = 0;
	bool                   end_of_the_game = false;
	int					   who_won = -1;
	static const int			   n = 10;
	static const int			   m = 10;
	static const int			   rs = 2;
	std::vector<int> ship_roster;
	const std::vector<std::vector<int>> CB;

	bool fill_board(int bot_id, std::vector<std::vector<int>>& X);
	bool fill_board_C(int bot_id, const long* X);
	bool fill_board_f(int bot_id);
	bool make_a_move(int bot_id, int i, int j);
	void print_board();
	game();
private:
	std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> board;
	bool             chek_bot(int bot_id);
	void             pass_tern();
	void             dfs(std::pair<int, int> v, const std::vector<std::vector<int>>& g,
		std::map<std::pair<int, int>, int>& used, std::vector<int> counter, int& num,
		std::map<std::pair<int, int>, int>& otvet, int& co);
	std::vector<int> DFS(const std::vector < std::vector<int>>& X);
	std::vector < std::vector<int>> X_to_Y(const long* X) {
		std::vector < std::vector<int>> Y(n, std::vector <int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				Y[i][j] = X[n * i + j];
		return Y;
	}
};

#endif


#endif