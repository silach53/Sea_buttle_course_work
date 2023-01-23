#ifndef ALEKSEEV_A_R_QUEUEP_H
#define ALEKSEEV_A_R_QUEUEP_H
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#ifdef __cplusplus
/// <summary>
/// 
/// </summary>
struct game {
public:
	/// <summary>
	/// Эта переменная отвечает за заполненность доски первого игрока
	/// </summary>
	bool b0_feeled = false;
	/// <summary>
	///  Эта переменная отвечает за заполненность доски второго игрока
	/// </summary>
	bool b1_feeled = false;
	/// <summary>
	///  Эта переменная отвечает за то чей сейчас ход
	/// </summary>
	int  whos_tern = 0;
	/// <summary>
	/// Эта переменная нужна чтобы узнавать закончилась игра или нет
	/// </summary>
	bool end_of_the_game = false;
	/// <summary>
	/// Эта переменаня нужна чтобы узнавать кто победитель
	/// </summary>
	int	 who_won = -1;
	/// <summary>
	/// Эта переменная отвечает за высотоу поля
	/// </summary>
	int  n;
	/// <summary>
	/// Эта переменная отвечает за ширину поля
	/// </summary>
	int	 m;
	/// <summary>
	/// Эта переменная отвечает за размер ростера короблей (сколько всего их будет на поле)
	/// </summary>
	int	 rs;
	/// <summary>
	/// Это набор длин короблей присутствующих на поле
	/// </summary>
	std::vector<int> ship_roster;
	/// <summary>
	/// Эта статичное поле которое используется агентом делающим детерминированные действия
	/// </summary>
	const std::vector<std::vector<int>> CB;
	/// <summary>
	/// Функция отвечает за заполнение достки 
	/// </summary>
	/// <param name="bot_id">Отвечает за то чью досту заполняем</param>
	/// <param name="X">Передаем массив являющийся заполненной доской</param>
	/// <returns>Возвращает 1 если все прошло хорошо и операция выполнена, ноль в ином случае</returns>
	bool fill_board(int bot_id, std::vector<std::vector<int>>& X);
	/// <summary>
	/// Функция аналогичная fill_board, просто принимает массив из C
	/// </summary>
	/// <param name="bot_id"></param>
	/// <param name="X"></param>
	/// <returns></returns>
	int fill_board_C(int bot_id, const long* X);
	/// <summary>
	/// Функция отвечает за выполнение хода
	/// </summary>
	/// <param name="bot_id">Передается параметр того, кто делает ход</param>
	/// <param name="i">id по вертикали</param>
	/// <param name="j">id горизонтали </param>
	/// <returns>Возвращает 1 если все прошло хорошо и операция выполнена, ноль в ином случае</returns>
	bool make_a_move(int bot_id, int i, int j);
	/// <summary>
	/// Функция печатающая состояние доски в файл
	/// </summary>
	void print_board();
	/// <summary>
	/// Конструктор состояния игры
	/// </summary>
	game();
	/// <summary>
	/// Узнавание ростера короблей, созданное для библиотеки C
	/// </summary>
	/// <param name="roarter"></param>
	void f_in_roster(int* roarter);
private:
	/// <summary>
	/// Метод, использующийся для получения названия магазина, в котором представлен товар, из ссылки на этот товар
	/// </summary>
	/// <param name="temp">Ссылка на товар</param>
	/// <returns>Имя магазина, в случае если поддерживается его парсинг, иначе - пустую строку</returns>
	std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> board;
	/// <summary>
	/// 
	/// </summary>
	/// <param name="bot_id"></param>
	/// <returns></returns>
	bool             chek_bot(int bot_id);
	/// <summary>
	/// 
	/// </summary>
	void             pass_tern();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="v"></param>
	/// <param name="g"></param>
	/// <param name="used"></param>
	/// <param name="counter"></param>
	/// <param name="num"></param>
	/// <param name="otvet"></param>
	/// <param name="co"></param>
	void             dfs(std::pair<int, int> v, const std::vector<std::vector<int>>& g,
		std::map<std::pair<int, int>, int>& used, std::vector<int> counter, int& num,
		std::map<std::pair<int, int>, int>& otvet, int& co);
	std::vector<int> DFS(const std::vector < std::vector<int>>& X);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="X"></param>
	/// <returns></returns>
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
