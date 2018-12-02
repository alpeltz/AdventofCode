#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;


void readFile(istream &is, vector<string> &file){
    string input;
    while(cin >> input){
        file.push_back(input);
    }
}

int main(){
    string input;
    int total=0;
    set<int> frequencies;
    frequencies.insert(0);
    vector<string> file;
    readFile(cin, file);
    int fileSize = file.size()-1;
    int index = 0;
    while(true){
        string operation = file[index].substr(0,1);
        int freq = stoi(file[index].substr(1,string::npos));
        if(operation == "+"){
            total += freq;
            if(frequencies.find(total) != frequencies.end()){
                cout << "Duplicate found: " << total;
                return false;
            }
            else{
                frequencies.insert(total);
            }
        }
        else if(operation == "-"){
            total-= freq;
            if(frequencies.find(total) != frequencies.end()){
                cout << "Duplicate found: " << total;
                return false;
            }
            else{
                frequencies.insert(total);
            }
        }
        else{
            cout << "Not an operation. Total is: " << total;
            return 0;
        }
        if(index == fileSize){
            index = 0;
        }
        else{index++;}
    
    }

}