#include <UUU/UUU.hpp>
#include <vector>
#include <map> 
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

game::game() {
	std::ifstream fin("config.txt");
	fin >> n >> m;
	
	std::string s;
	getline(fin, s); getline(fin, s);
	fin.close();

	//replace(s.begin(),s.end()," ", "");
	for(int i =0; i < s.size(); i+=2)
		ship_roster.push_back(s[i]-'0');
	sort(ship_roster.begin(), ship_roster.end());

	rs = ship_roster.size();
	
	std::vector<std::vector<int>> XXX(n, std::vector<int>(m, 0));
	board = { XXX,XXX };
	
	/*std::ofstream fin("x.txt");
	fin << (this);
	fin.close();*/

}

bool game::chek_bot(int bot_id) {
	if (bot_id < 0 || bot_id>1)
		return false;
	return (bot_id == whos_tern);

}
void game::pass_tern() {
	whos_tern = (whos_tern + 1) % 2;

	int flag_1 = 0;
	int flag_11 = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (board.first[i][j] == 1)
				flag_1++;
			if (board.first[i][j] == 3)
				flag_11++;
		}

	int flag_2 = 0;
	int flag_22 = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (board.second[i][j] == 1)
				flag_2++;
			if (board.second[i][j] == 3)
				flag_22++;
		}

	if (((flag_1 == 0) && (flag_11 > 0) || ((flag_2 == 0) && (flag_22 > 0)))) {
		if (flag_1 != 0)
			who_won = 0;
		else
			who_won = 1;
		end_of_the_game = true;
	}
}


//void game::print_board() {
//	std::ofstream fin("print_board.txt");
//	fin << "was print board";
//	fin.close();
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < 2 * m + 1; ++j) {
//			if (j < m)
//				std::cout << board.first[i][j];
//			if (j == m)
//				std::cout << "|";
//			if (j > m)
//				std::cout << board.second[i][j - m - 1];
//		}
//		std::cout << "\n";
//	}
//	for (int j = 0; j < 2 * m + 1; ++j)
//		std::cout << "-";
//	std::cout << "\n";
//}

void game::print_board() {
	std::ofstream fout("print_board.txt", std::ios::app);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2 * m + 1; ++j) {
			if (j < m)
				fout << board.first[i][j];
			if (j == m)
				fout << "|";
			if (j > m)
				fout << board.second[i][j - m - 1];
		}
		fout << "\n";
	}
	for (int j = 0; j < 2 * m + 1; ++j)
		fout << "-";
	fout << "\n";
	fout.close();
}

int game::fill_board_C(int bot_id, const long* Y) {
	std::vector<std::vector<int>> X = X_to_Y(Y);
	return 	 fill_board(bot_id, X);
}

bool game::fill_board(int bot_id, std::vector < std::vector<int>>& X) {
	if (!chek_bot(bot_id))
		return false;

	//Chek the board
	if (X.size() != n)
		return false;

	if (X.size() == n) {
		for (auto x : X)
			if (x.size() != m)
				return false;
	}

	//We need to ckek the sizes and number of ships
	if (DFS(X) != ship_roster)
		return false;

	if (bot_id == 0) {
		board.first = X;
		b0_feeled = true;
	}
	else {
		board.second = X;
		b1_feeled = true;
	}

	pass_tern();

	return true;
}

bool game::make_a_move(int bot_id, int i, int j) {
	if (!chek_bot(bot_id) && !(b0_feeled) && !(b1_feeled))
		return false;


	if (i > n || i < 0 || j<0 || i>m)
		return false;


	if (bot_id == 0) {
		int& cceil = board.second[i][j];

		if (cceil == 2 || cceil == 3)
			return false;

		if (cceil == 0)
			cceil = 2;
		else
			cceil = 3;
	}
	else {
		int& cceil = board.first[i][j];

		if (cceil == 2 || cceil == 3)
			return false;

		if (cceil == 0)
			cceil = 2;
		else
			cceil = 3;
	}

	pass_tern();
	return true;
}


void game::dfs(std::pair<int, int> v, const std::vector<std::vector<int>>& g,
	std::map<std::pair<int, int>, int>& used,
	std::vector<int> counter, int& num,
	std::map<std::pair<int, int>, int>& otvet,
	int& co) {

	counter[num]++;
	otvet[v] = num;
	used[v] = 1;

	std::vector< std::pair<int, int>> potential_moves;
	if (v.first - 1 >= 0)  potential_moves.push_back({ v.first - 1, v.second });
	if (v.second - 1 >= 0) potential_moves.push_back({ v.first, v.second - 1 });
	if (v.first + 1 < n)   potential_moves.push_back({ v.first + 1, v.second });
	if (v.second + 1 < m)  potential_moves.push_back({ v.first, v.second + 1 });

	for (auto to : potential_moves)
		if ((!used[to]) && (used[to] != -1) && (g[to.first][to.second] == 1))
			dfs(to, g, used, counter, num, otvet, co);
	used[v] = -1;
}

std::vector<int> game::DFS(const std::vector < std::vector<int>>& X) {
	std::map<std::pair<int, int>, int> used;
	std::vector<int> counter(n * m);
	int num = 0;
	std::map<std::pair<int, int>, int> otvet;
	int co = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (!used[{i, j}] && X[i][j] == 1) {
				dfs({ i,j }, X, used, counter, num, otvet, co);
				num++;
			}
		}

	std::vector<int> ans;
	for (auto x : otvet) {
		ans.push_back(x.second);
	}

	std::map<int, int> transfrom;
	for (auto x : ans)
		transfrom[x]++;
	ans = {};
	for (auto x : transfrom)
		ans.push_back(x.second);

	sort(ans.begin(), ans.end());
	return ans;
}

void game::f_in_roster(int* roarter) {
	for (int i = 0; i < ship_roster.size(); ++i)
		roarter[i]= ship_roster[i];
}