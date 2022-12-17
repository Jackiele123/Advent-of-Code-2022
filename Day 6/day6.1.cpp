#include <iostream>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

const int PACKET_SIZE = 14; // 4 for part 1 and 14 for part 2

int main(){
    fstream input;
    
    string data;
    int left = 0;
    int duplicate = false;

    input.open("day6.txt",ios::in); //open a file to perform read operation using file object   
   
    if (input.is_open()){ //checking whether the file is open
         while(getline(input,data)){
            while(left < data.size() - PACKET_SIZE){
                for (int i = 0; i < PACKET_SIZE;i++){
                    for(int j = i+1; j < PACKET_SIZE;j++){
                        if (data[left+i] == data[left+j])
                            duplicate = true;
                    }
                }
                if(!duplicate){
                    cout << left + PACKET_SIZE << endl;   
                    return EXIT_SUCCESS;
                }
                left++;
                duplicate = false;
            }
        }
        input.close(); //close the file object.
    }
}