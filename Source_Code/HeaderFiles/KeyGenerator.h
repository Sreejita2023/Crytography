#pragma once
#include<bits/stdc++.h>
using namespace std;
class KeyGenerator {
public:
    static vector<string> allPermutations;
    static string armstrongDigits;

    string userKey;

    KeyGenerator(int uid) {
        int i = uid % allPermutations.size();
        userKey = allPermutations[i];
    }

    string getKey() {
        return userKey;
    }

private:
    static void getPermutations(const string &set, const string &sol) {
        if (set.length() == 1) {
            allPermutations.push_back(sol + set);
        } else {
            for (size_t i = 0; i < set.length(); ++i) {
                char currentDigit = set[i];
                string restOfTheDigits = set.substr(0, i) + set.substr(i + 1);
                getPermutations(restOfTheDigits, sol + currentDigit);
            }
        }
    }

    static bool static_init() {
        getPermutations(armstrongDigits, "");
        return true;
    }

    static bool initialized;
};

// Initialize static members
vector<string> KeyGenerator::allPermutations;
string KeyGenerator::armstrongDigits = "153704";
bool KeyGenerator::initialized = KeyGenerator::static_init();

