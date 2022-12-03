#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

const int WIN = 6;
const int DRAW = 3;

enum GAME {ROCK = 1, PAPER = 2, SCISSOR =3};

int main(){
    map<char,int> weapon;
    weapon['A'] = GAME::ROCK;
    weapon['B'] = GAME::PAPER;
    weapon['C'] = GAME::SCISSOR;
    weapon['X'] = GAME::ROCK;
    weapon['Y'] = GAME::PAPER;
    weapon['Z'] = GAME::SCISSOR;

    map<int,int> result;
    result[GAME::ROCK] = GAME::PAPER;
    result[GAME::PAPER] = GAME::SCISSOR;
    result[GAME::SCISSOR] = GAME::ROCK;

    fstream input;
    
    char data1;
    char data2;

    int totalScore = 0;
    int score = 0;

    input.open("day2.txt",ios::in); //open a file to perform read operation using file object
   
   if (input.is_open()){ //checking whether the file is open
      while(input >> data1 >> data2){ //read data from file object and put it into string.
        score += weapon[data2];
        if(result[weapon[data1]] == weapon[data2])
            score += WIN;
        else if(weapon[data1] == weapon[data2])
            score += DRAW;
        else{}

        totalScore += score;
        score = 0;
      }
      cout << totalScore << endl;
      input.close(); //close the file object.
   }

}