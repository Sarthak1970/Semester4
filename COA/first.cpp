#include<iostream>
#include<string>
using namespace std;

bool ANDGATE(string &s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')
        return 0;
    }
    return 1;
}

int main(){
    string s;
    cout<<"Enter a binary string :";
    getline(cin,s);
    cout<<ANDGATE(s);
}