#include <iostream>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <sstream>

using namespace std;


int main(){
    stack<map<string,int>> storage;
    map<string,int> folders;
    
    fstream input;
    
    string data;
    
    input.open("day7.txt",ios::in); //open a file to perform read operation using file object
   
    if (input.is_open()){ //checking whether the file is open
        while(getline(input,data)){
            for (int i = 0; i < 9;i++){
                if (data[1+(i*4)] != ' '){
                    stacks[i].push(data[1+(i*4)]);
                }
            }
        }
        input.close(); //close the file object.
    }
}