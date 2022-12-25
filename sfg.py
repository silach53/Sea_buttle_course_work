from ctypes import *
import numpy as np

class sea():
    lib             = cdll.LoadLibrary("c:\\Users\\User\\Desktop\\Sea_battle_a_build_course\\prj.lab\\UUU\\Debug\\Lamda.dll")
    makegame        = lib.makegame
    lib.makegame.restype = c_void_p
    fill_board_c      = lib.fill_board
    make_a_move     = lib.make_a_move     #(struct game* g, int bot_id, int i, int j);
    print_board     = lib.print_board     #(struct game* g);
    end_of_the_game = lib.end_of_the_game #(struct game* g);
    who_won         = lib.who_won         #(struct game* g);
    b0_feeled       = lib.b0_feeled       #(struct game* g);
    b1_feeled       = lib.b1_feeled       #(struct game* g);
    ship_roster_f   = lib.ship_roster     #(struct game* g,int* x);
    n               = lib.hu_n();
    m               = lib.hu_m();
    rs              = lib.hu_rs();
    
    def fill_board(state,bot_id,mas):
        #convert into c like array
        arr=[]
        for x in mas:
            for y in x: arr.append(y)  
        arr_c = (c_int * (sea.n*sea.m))(*arr)
        sea.fill_board_c(state,bot_id,arr_c)
        
    def ship_roster(state):
        arr = [0 for x in range(sea.rs)]
        arr_c = (c_int * (sea.rs))(*arr)
        sea.ship_roster_f(board_statу,arr_c)

        result = []
        for x in arr_c:
            result.append(int(x))
        return result

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
    board_statу = c_void_p(sea.makegame())
    print('ship roster')
    print(sea.ship_roster(board_statу))
    
    #bot0_make_a_move(board_statу)
    
    #sea.fill_board(board_statу,0,my_board)
    #sea.print_board(board_statу)
    
