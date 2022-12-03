#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int main(){
   fstream input;
   int sum = 0;
   int highestNum = 0;

   vector<int> allNums;
   vector<int>::iterator it;

   input.open("input.txt",ios::in); //open a file to perform read operation using file object
   if (input.is_open()){ //checking whether the file is open
      string data;
      while(getline(input, data)){ //read data from file object and put it into string.
        if (data.empty()){
          allNums.push_back(sum);
          sum = 0;
        }
        else{
            istringstream temp(data);
            int num;
            temp >> num;
            sum += num;
        }
      }
      sort(allNums.begin(), allNums.end());
      int size = allNums.size() - 1;
      for (int i = 0; i < 3; i++)
      {
        cout << allNums[size - i] << endl;
        highestNum += allNums[size - i];
        allNums.pop_back(); 
      }
      cout << highestNum << endl;
      input.close(); //close the file object.
   }
}