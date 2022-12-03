#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;


int main(){
    map<char,bool> sack1;
    map<int,int> charValues;

    for (int i = 0; i < 26; i++)
        charValues[int('a')+i] = i+1;
    for (int i = 0; i < 26; i++)
        charValues[int('A')+i] = i+27;

    fstream input;
    
    string data;
    int totalSum = 0;
    input.open("day3.txt",ios::in); //open a file to perform read operation using file object
   
   if (input.is_open()){ //checking whether the file is open
    while(input >> data){
        for(int i = 0; i < data.size()/2; i++)
            sack1[data[i]] = true;
        for(int i = data.size()/2; i < data.size(); i++)
            if (sack1.count(data[i])){
                totalSum += charValues[int(data[i])];
                cout << charValues[int(data[i])] << ":" << data[i] << endl;
                break;
            }
        sack1.clear();
    }
    cout << totalSum << endl;
      input.close(); //close the file object.
   }

}