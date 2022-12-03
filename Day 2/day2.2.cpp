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
    map<char,int> win;
    win['A'] = GAME::PAPER;
    win['B'] = GAME::SCISSOR;
    win['C'] = GAME::ROCK;

    map<char,int> loss;
    loss['A'] = GAME::SCISSOR;
    loss['B'] = GAME::ROCK;
    loss['C'] = GAME::PAPER;

    map<char,int> draw;
    draw['A'] = GAME::ROCK;
    draw['B'] = GAME::PAPER;
    draw['C'] = GAME::SCISSOR;

    fstream input;
    
    char data1;
    char data2;

    int totalScore = 0;
    int score = 0;

    input.open("day2.txt",ios::in); //open a file to perform read operation using file object
   
   if (input.is_open()){ //checking whether the file is open
    while(input >> data1 >> data2){ //read data from file object and put it into string.
    if (data2 == 'X')
        score += loss[data1];
    else if (data2 == 'Y')
        score += (draw[data1] + DRAW);
    else
        score += (win[data1] + WIN);

        totalScore += score;
        score = 0;
      }
      cout << totalScore << endl;
      input.close(); //close the file object.
   }

}