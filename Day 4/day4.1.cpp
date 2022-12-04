#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;


int main(){
    map<char,bool> sack1;
    map<int,int> charValues;

    fstream input;

    int totalSum = 0;
    int a,b,c,d;
    input.open("day4.txt",ios::in); //open a file to perform read operation using file object
   
    if (input.is_open()){ //checking whether the file is open
        while(input >> a >> b >> c >> d){    
            cout << a << ":" << b << "," << c << ":" <<d << "---" << totalSum << endl;
            if ((a <= c && b >= d) || (c <= a && d >= b))
                totalSum++;
        }   
        cout << totalSum << endl;
        input.close(); //close the file object.
    }    
}