#pragma once
#include<bits/stdc++.h>

using namespace std;
class KeyGenerator {
    array<int, 4> armstrongNumbers = { 153, 370, 371, 407 };
    array<int, 24> baseTable = { 1234, 1243, 1324, 1342, 1423, 1432, 2134, 2143, 2314, 2341, 2413, 2431, 3124,
            3142, 3214, 3241, 3412, 3421, 4123, 4132, 4213, 4231, 4312, 4321 };

    string key, numericKey;

public:
    KeyGenerator(string k) {
        
        key = k;
        numericKey = "";
    }
    string getNumericKey() {
        if (numericKey == "")
            generateNumericKey();

        return numericKey;
    }

    void generateNumericKey() {// key: How old is my computer?
        int tot = 0;
        int l, i;
        l = key.length();
        for (i = 0; i < l; i++) {// add the ASCII of characters of key

            tot += key[i];
        }
        // example : tot = 2141

        int permutation = baseTable[tot % (baseTable.size())];
        // example : permutation = baseTable[5] = 1432

        string temp = "";
        cout << "*" << permutation << '\n';
        while (permutation > 0) {
            temp = to_string(armstrongNumbers[permutation % 10 - 1]) + temp;
            permutation /= 10;
        }
        // numericKey = partA+partB
        numericKey = temp + to_string(tot);
    }

    void display() {
        cout << "key : " << key << "\n";
        cout << "numeric key : " << numericKey << "\n";
    }
};


