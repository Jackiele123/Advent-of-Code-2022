#include <iostream>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <sstream>

using namespace std;


int main(){
    map<int,stack<char>> stacks;
    stack<char> sort;
    
    fstream stack;
    fstream moves;
    
    string data;
    int quantity;
    int from;
    int to;
    string temp;
    
    
    stack.open("day5.txt",ios::in); //open a file to perform read operation using file object
    moves.open("moves.txt",ios::in); //open a file to perform read operation using file object
   
    if (stack.is_open()){ //checking whether the file is open
        while(getline(stack,data)){
            for (int i = 0; i < 9;i++){
                if (data[1+(i*4)] != ' '){
                    stacks[i].push(data[1+(i*4)]);
                }
            }
        }
        stack.close(); //close the file object.
    }
    if (moves.is_open()){ //checking whether the file is open
        while(moves >> temp >> quantity >> temp >> from >> temp >> to){
            for (int i = 0; i < quantity; i++){
                sort.push(stacks[from-1].top());
                stacks[from-1].pop();
            }
            while(!sort.empty()){
                stacks[to-1].push(sort.top());
                sort.pop();
            }
        }
        moves.close(); //close the file object.
    }
    for (int i = 0; i < 9;i++){
        cout << stacks[i].top();
    }
}
