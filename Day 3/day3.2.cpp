#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;


int main(){
    map<char,bool> sack1;
    map<char,bool> sack2;
    map<int,int> charValues;

    for (int i = 0; i < 26; i++)
        charValues[int('a')+i] = i+1;
    for (int i = 0; i < 26; i++)
        charValues[int('A')+i] = i+27;

    fstream input;
    
    string data1;
    string data2;
    string data3;
    int totalSum = 0;
    input.open("day3.txt",ios::in); //open a file to perform read operation using file object
   
   if (input.is_open()){ //checking whether the file is open
    while(input >> data1 >> data2 >> data3){
        for(int i = 0; i < data1.size(); i++)
             sack1[data1[i]] = true;
        for(int i = 0; i < data2.size(); i++)
             sack2[data2[i]] = true;
        for(int i = 0; i < data3.size(); i++){
            if(sack1.count(data3[i]) && sack2.count(data3[i])){
                totalSum += charValues[data3[i]];
                break;
            }
        }
        sack1.clear();
        sack2.clear();
    }
    cout << totalSum << endl;
      input.close(); //close the file object.
   }

}