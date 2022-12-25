from sea import *
from random import randint as rand

n = sea.n
m = sea.m
roster = sea.ship_roster()

def random_board():
    X = [[0 for x in range(m)] for y in range(n)]
    #Заполняет доску 	
    #Кораблики не должны стоять рядом - но попробуем на это забить
    for t in range(sea.rs):
            x = roster[t]
            i = rand(0,n - x - 1)
            j = rand(0,m - x - 1)
            ror = rand(0,1)
            if (ror == 0):
                for k in range(x):
                    X[i + k][j] = 1
            else:
                for k in range(x):
                    X[i][j + k] = 1;
    return X

#Random bot
def bot0_make_a_move(state):
    if (sea.b0_feeled(state) == 0):
        X = [[0 for x in range(m)] for y in range(n)]
        while (not sea.fill_board(state, 0, X)):
            X = random_board()
        return

    i,j = -1,-1#заполнить случайными 
    while (not sea.make_a_move(state, 0, i, j)):
        i = rand(0,n-1)
        j = rand(0,m-1)

#Deterministic bot
def bot1_make_a_move(state):
    CB = [[0 for x in range(m)] for y in range(n)]
    CB[5][5] = 1
    CB[8][3] = 1
    if (sea.b1_feeled(state) == 0):
        if (not sea.fill_board(state, 1, CB)):
            print("You made your board incorrecly\n")
        return

    #Детерминированно перебираем достку
    for i in range(n):
        for j in range(m):
            if (sea.make_a_move(state, 1, i, j)):
                return

if __name__ == "__main__":
    board_statу = sea.makegame()
    while (True):
        bot0_make_a_move(board_statу)
        if (sea.end_of_the_game(board_statу)):
            break
        bot1_make_a_move(board_statу)
        if (sea.end_of_the_game(board_statу)):
            break
        sea.print_board(board_statу)

    sea.print_board(board_statу)
    print(f"Player:  {sea.who_won(board_statу)} won the game")	

