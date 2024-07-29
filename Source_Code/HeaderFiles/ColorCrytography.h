#pragma once
#include<bits/stdc++.h>
using namespace std;
class ColorCryptograph
{
private:
    vector<vector<vector<int>>> map;
    int sequence[11] = {0, 1, 2, 2, 1, 0, 0, 1, 1, 2, 0};
    int encIndex, decIndex;

public:
    ColorCryptograph(string key)
    {
        int r = stoi(key.substr(0, 2));
        int g = stoi(key.substr(2, 2));
        int b = stoi(key.substr(4));

        int i, j, k;
        int n;
        int bands[] = {r, g, b};

        map.resize(3, vector<vector<int>>(16, vector<int>(16)));

        encIndex = 0;
        decIndex = 0;


        for (i = 0; i < map.size(); i++)
        {
            n = bands[i];
            for (j = 0; j < map[i].size(); j++)
            {
                for (k = 0; k <map[i][j].size(); k++)
                {
                    map[i][j][k] = n;
                    n = (n + 1) % 256;
                }
            }
        }

        encIndex = 0;
        decIndex = 0;
    }

    int encrypt(int data)
    {
        //break the data into nibbles
        int r = data >> 4; 
        //r=data/16
        int c = data & 0xF; //AND with 1111

        int result = map[sequence[encIndex]][r][c];
        encIndex = (encIndex + 1) % (sizeof(sequence) / sizeof(sequence[0]));
        return result;
    }

    int decrypt(int encData)
    {
        int temp = (encData - map[sequence[decIndex]][0][0] + 256) % 256;
        int r = temp / 16;
        int c = temp % 16;
        decIndex = (decIndex + 1) % (sizeof(sequence) / sizeof(sequence[0]));
        return (r << 4) | c;
    }
};
