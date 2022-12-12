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

class game {
public:
	bool                   b1_feeled       = false;
	bool                   b2_feeled       = false;
	int                    whos_tern       = 0;
	bool                   end_of_the_game = false;
	int					   who_won         = -1;
	const int			   n               = 10;
	const int			   m               = 10;
	const std::vector<int> ship_roster     = { 1,1 };
	
	bool fill_board(int bot_id, std::vector < std::vector<int>> X);
	bool make_a_move(int bot_id, int i, int j);
	void print_board();
	game();
private:
	
	std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> board;
	bool             chek_bot(int bot_id);
	void             pass_tern();
	void             dfs(std::pair<int, int> v, const std::vector<std::vector<int>>& g,
		std::map<std::pair<int, int>, int>& used,std::vector<int> counter, int& num,
		std::map<std::pair<int, int>, int>& otvet,int& co);
	std::vector<int> DFS(const std::vector < std::vector<int>>& X);
};



