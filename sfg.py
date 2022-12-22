from ctypes import *
import numpy as np

class sea():
    lib             = cdll.LoadLibrary("c:\\Users\\User\\Desktop\\Sea_battle_a_build_course\\prj.lab\\UUU\\Debug\\Lamda.dll")
    makegame        = lib.makegame
    fill_board_cpp  = lib.fill_board
    make_a_move     = lib.make_a_move     #(struct game* g, int bot_id, int i, int j);
    print_board     = lib.print_board     #(struct game* g);
    end_of_the_game = lib.end_of_the_game #(struct game* g);
    who_won         = lib.who_won         #(struct game* g);
    b0_feeled       = lib.b0_feeled       #(struct game* g);
    b1_feeled       = lib.b1_feeled       #(struct game* g);
    ship_roster_f   = lib.ship_roster     #(struct game* g);
    n               = lib.hu_n();
    m               = lib.hu_m();
    rs              = lib.hu_rs();
    
    def fill_board(state,bot_id,mas):
        s = ""
        for x in mas:
            for y in x:
                s+=y+' '
            s+='\n'
        with open("board.txt",'r') as f:
            f.write(s)
        fill_board_cpp(state,bot_id)    
    def ship_roster(state):
        sea.ship_roster_f(state)
        with open('roaster.txt','r') as f:
            x = f.read()
        print(x)
    

def bot1_make_a_move(state):
    CB = [0 for x in range(n*m)];
    CB[0]=1
    CB[1]=1
    fill_board(state, 1, CB)

if __name__ == "__main__":
    #распечатать в в плюсах в файлик адрес этой гадости и возможно подключить стайп в питоне
    #print()
    board_statу = c_void_p(sea.makegame())
    #with open(r'C:\Users\User\Desktop\Sea_battle_a_build_course\prj.lab\UUU\x.txt','r') as f:
    #        x = f.read()
    print(x)
    #board_statу = c_int(int(x,16))
    board_statу = c_int(int(x,16))
    print(type(board_statу))
    #print(hex(board_statу))
    #while(True):
    #bot1_make_a_move(board_statу)
    sea.ship_roster(board_statу)
    
