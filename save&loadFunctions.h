#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>

using namespace std;
using namespace sf;

void save(int savedGrid[][9]){
    ofstream savedgame("saved game.txt",ios::out);
    
if(savedgame.is_open()){
         for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
               savedgame<<savedGrid[i][j];
               savedgame<<endl;
            }
         }   
        }
        savedgame.close();
    }


   
