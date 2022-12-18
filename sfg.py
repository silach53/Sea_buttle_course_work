from ctypes import *
import numpy as np

lib = cdll.LoadLibrary(
    "c:\\Users\\User\\Desktop\\Sea_battle_a_build_course\\prj.lab\\UUU\\Debug\\Lamda.dll")
makegame = lib.makegame
fill_board = lib.fill_board
n = lib.с_n();
m = lib.с_m();
rs = lib.с_rs();
    

def bot1_make_a_move(state):
    CB = [0 for x in range(n*m)];
    CB[0]=1
    CB[1]=1
    
    arr = (c_int * len(CB))() 
    print(arr)
    fill_board(state, 1, arr)

if __name__ == "__main__":
    board_statу = makegame()
    print(n)
    #while(True):
    bot1_make_a_move(board_statу)
