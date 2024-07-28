#pragma once
class ByteManager {
public:
    static void byteToNibble(int x, int arr[]) {
        // 104 --->[0110,1000]
        arr[0] = (x & 255) >> 4;// higher nibble
        arr[1] = x & 15;// lower nibble
    }

    static int nibblesToByte(int nibbles[]) {
        // [0110,1000] ---> 104
        return ((nibbles[0] & 15) << 4) | (nibbles[1] & 15);
    }
};

