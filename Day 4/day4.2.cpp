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
            if ( (a >= c && a <=d) || (c >= a && c <=b) || (b <=d && b >=c) || (d <=b && d >=a))
                totalSum++;
        }   
        cout << totalSum << endl;
        input.close(); //close the file object.
    }    
}