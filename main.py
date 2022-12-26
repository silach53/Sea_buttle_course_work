from sea import *
from random import randint as rand
from random import seed

board_statу = sea.makegame()
n = sea.n(board_statу)
m = sea.m(board_statу)
rs = sea.rs(board_statу)
roster = sea.ship_roster()
print(roster)
with open('print_board.txt','w') as f:
    f.write('b_random  |b_const\n')

def random_board(rando = 0):
    if(rando):
        seed(rando)
    
    X = [[0 for x in range(m)] for y in range(n)]
    #Заполняет доску 	
    #Кораблики не должны стоять рядом - но попробуем на это забить
    for t in range(rs):
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
            print(sea.fill_board(state, 0, X))
        return

    i,j = -1,-1#заполнить случайными 
    while (not sea.make_a_move(state, 0, i, j)):
        i = rand(0,n-1)
        j = rand(0,m-1)

#Deterministic bot
def bot1_make_a_move(state):
    if (sea.b1_feeled(state) == 0):
        X = [[0 for x in range(m)] for y in range(n)]
        rando = 2344111
        while (not sea.fill_board(state, 1, X)):
            X = random_board(rando)
            rando+=1
        return
        
    #Детерминированно перебираем достку
    for i in range(n):
        for j in range(m):
            if (sea.make_a_move(state, 1, i, j)):
                return

if __name__ == "__main__":
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
