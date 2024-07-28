#pragma once
#include <bits/stdc++.h>
#include "ByteManager.h"
using namespace std;
class ColorManager
{
    int *rgb;
    int enc_index, dec_index;

public:
    ColorManager(string nK)
    {
        rgb = new int[3];
        enc_index = dec_index = -1;

        int partB = stoi(nK.substr(12));                 // int(nK[12:])
        rgb[0] = (stoi(nK.substr(0, 4)) + partB) % 256;  // int(nK[0:4])
        rgb[1] = (stoi(nK.substr(4, 8)) + partB) % 256;  // int(nK[4:8])
        rgb[2] = (stoi(nK.substr(8, 12)) + partB) % 256; // int(nK[8:12])
    }

    int encrypt(int data)
    {
        int nibbles[2];
        ByteManager b;
        b.byteToNibble(data, nibbles);
        enc_index = (enc_index + 1) % 3; // 3 is size of rgb array
        return (rgb[enc_index] + nibbles[0] * 16 + nibbles[1]) % 256;
    }

    int decrypt(int data)
    {
        int temp;
        int nibbles[2];
        dec_index = (dec_index + 1) % 3;
        temp = (data - rgb[dec_index] + 256) % 256;

        nibbles[0] = temp / 16;
        nibbles[1] = temp % 16;
        ByteManager b;
        return b.nibblesToByte(nibbles);
    }
};