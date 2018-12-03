#include <string>
#include <iostream>
#include <set>

using namespace std;

bool find2(const string &str, const char &c){
    size_t found = str.find(c);
    size_t found2 = str.find(c,found +1);
    size_t found3 = str.find(c,found2 +1);
    if(found3 != string::npos){
        return false;
    }
    return(found2 != string::npos);
}

bool find3(const string &str, const char &c){
    size_t found = str.find(c);
    size_t found2 = str.find(c,found +1);
    size_t found3 = str.find(c,found2 +1);
    size_t found4 = str.find(c, found3 +1);
    if(found4 != string::npos){
        return false;
    }
    return(found2 != string::npos && found3 != string::npos);
}

bool compare(const string &str, const string &str2, int &index){
    const char * cstr = str.c_str();
    const char * cstr2 = str2.c_str();
    const char *t1;
    const char *t2;
    int countDif = 0;
    for(t1 = cstr,t2 = cstr2; *t1 != 0 && *t2 != 0; t1++,t2++){
        if(*t1 != *t2){
            countDif++;
            index = t1-cstr;
        }

    }
    return (countDif ==1);
}
int main(){

    const char *alph = "abcdefghijklmnopqrstuvwxyz";
    string input;
    int doubleCount = 0;
    int tripleCount = 0;
    bool foundDouble = false;
    bool foundTriple = false;
    set<string> id;
    while(cin >> input){
    id.insert(input);
    for(const char *temp = alph; temp - alph <= 26; temp++){
        if((foundTriple == false) && find3(input,*temp)){
            tripleCount++;
            foundTriple = true;
        }
        else if((foundDouble == false) && find2(input,*temp)){
            doubleCount++;
            foundDouble = true;
        }
    }

    foundDouble = false;
    foundTriple = false;
    }

    int checkSum = doubleCount * tripleCount;
    std::cout<< checkSum;

    int index = 0;
    string common;
    bool similar = false;
    
    size_t idx = index;
    for(auto iter = id.begin();iter !=id.end();iter++){
        for(auto iter2 = iter;iter2 != id.end();iter2++){
            similar = compare(*iter,*iter2, index);
            if(similar){
                common = *iter;
                idx = index;
            }
        }
    }
    
    size_t len =1;

    common.erase(idx,len);

    cout<< "common letters: " << common;


}