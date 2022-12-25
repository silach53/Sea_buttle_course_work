from sea import *

def bot0_make_a_move(state):
    my_board =  [ [0 for x in range(sea.m)] for x in range(sea.n)]
    my_board[0][0]=1
    my_board[1][1]=1
    sea.fill_board(state, 0, my_board)

def bot1_make_a_move(state):
    my_board =  [ [0 for x in range(sea.m)] for x in range(sea.n)]
    my_board[0][0]=1
    my_board[1][1]=1
    sea.fill_board(state, 1, my_board)

if __name__ == "__main__":
    #print(help(sea))
    board_statу = sea.makegame()
    print('ship roster')
    print(ship_roster)
    bot0_make_a_move(board_statу)
    
    #sea.fill_board(board_statу,0,my_board)
    sea.print_board(board_statу)

     
