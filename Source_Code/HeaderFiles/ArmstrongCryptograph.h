#pragma once
#include<bits/stdc++.h>
using namespace std;
class ArmstrongCrytograph{
private:
    int encIndex;
    int decIndex;
    vector<int>key;

 public:
    ArmstrongCrytograph(string k){
        int i,l;
        l=k.length();
 
        key.resize(l);
        for(int i=0;i<l;i++){
            key[i]=static_cast<int>(k[i]-'0');
        }
    }
    int encrypt(int x){
        int temp=x^key[encIndex];
        encIndex = (encIndex + 1) % key.size();
        return temp;
    }
    int decrypt(int x){
        int temp=x^key[decIndex];
        decIndex = (decIndex + 1) % key.size();
        return temp;
    }
};
