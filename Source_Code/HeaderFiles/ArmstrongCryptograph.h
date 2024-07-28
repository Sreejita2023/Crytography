#pragma once
#include<bits/stdc++.h>
using namespace std;
class ArmstrongManager {
    string numericKey;
    int enc_index, dec_index;
public:
    ArmstrongManager(string nK) {
        numericKey = nK;
        enc_index = -1;
        dec_index = -1;
    }

    int encrypt(int data) {
        // cout<<data<<"$$4"<<"\n";
        try {
            return data ^ numericKey[++enc_index];
        }
        catch (int ex) {
            enc_index = -1;
            return data ^ numericKey[++enc_index];
        }
    }


    int decrypt(int data)
    {
        try
        {
            return data ^ numericKey[++dec_index];
        }
        catch (int ex)
        {
            dec_index = -1;
            return data ^ numericKey[++dec_index];
        }
    }
};
