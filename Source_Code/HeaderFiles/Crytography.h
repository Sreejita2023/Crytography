#include<bits/stdc++.h>

#include "KeyGenerator.h"
#include "ColorCrytography.h"
#include "ArmstrongCryptograph.h"
using namespace std;

class Cryptography {
public:
    static bool encrypt(const std::string& src, const std::string& trgt) {
        try {
            KeyGenerator kgen(1234);
            ArmstrongCrytograph ac(kgen.getKey());
            ColorCryptograph cc(kgen.getKey());

            std::ifstream fin(src, std::ios::binary);
            std::ofstream fout(trgt, std::ios::binary);

            if (!fin.is_open() || !fout.is_open()) {
                std::cerr << "Error opening files!" << std::endl;
                return false;
            }

            char x;
            int y, z;
            while (fin.get(x)) {
                y = ac.encrypt(static_cast<int>(x));
                z = cc.encrypt(y);
                fout.put(static_cast<char>(z));
            }

            std::cout << "C" << std::endl;
            fin.close();
            fout.close();
            std::cout << "D" << std::endl;
            return true;
        } catch (const std::exception& ex) {
            std::cerr << "Error in encrypt: " << ex.what() << std::endl;
            return false;
        }
    }

    static bool decrypt(const std::string& src, const std::string& trgt) {
        try {
            KeyGenerator kgen(1234);
            ArmstrongCrytograph ac(kgen.getKey());
            ColorCryptograph cc(kgen.getKey());

            std::ifstream fin(src, std::ios::binary);
            std::ofstream fout(trgt, std::ios::binary);

            if (!fin.is_open() || !fout.is_open()) {
                std::cerr << "Error opening files!" << std::endl;
                return false;
            }

            char z;
            int x, y;
            while (fin.get(z)) {
                y = cc.decrypt(static_cast<int>(z));
                x = ac.decrypt(y);
                fout.put(static_cast<char>(x));
            }

            fin.close();
            fout.close();
            return true;
        } catch (const std::exception& ex) {
            std::cerr << "Error in decrypt: " << ex.what() << std::endl;
            return false;
        }
    }
};

