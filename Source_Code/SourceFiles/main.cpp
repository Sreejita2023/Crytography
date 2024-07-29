#include<bits/stdc++.h>
#include"../HeaderFiles/Crytography.h"
using namespace std;
int main() {
    Cryptography cr;
    try {
        string srcFile, trgtFile;
        int ch;

        while (true) {
            cout << "1. Encrypt" << endl;
            cout << "2. Decrypt" << endl;
            cout << "3. Exit" << endl;

            cin >> ch;

            if (ch == 1) {
                cout << "Enter the absolute path of the file to encrypt: ";
                cin >> srcFile;
                cout << "Enter the absolute path of the target file: ";
                cin >> trgtFile;

                if (cr.encrypt(srcFile, trgtFile))
                    cout << "Encryption Successful" << endl;
                else
                    cout << "Encryption Failed" << endl;
            } else if (ch == 2) {
                cout << "Enter the absolute path of the file to decrypt: ";
                cin >> srcFile;
                cout << "Enter the absolute path of the target file: ";
                cin >> trgtFile;

                if (cr.decrypt(srcFile, trgtFile))
                    cout << "Decryption Successful" << endl;
                else
                    cout << "Decryption Failed" << endl;
            } else if (ch == 3) {
                break;
            } else {
                cout << "Wrong Choice" << endl;
            }
        }
    } catch (const exception& ex) {
        cerr << "Error in decrypt: " << ex.what() << endl;
    }

    return 0;
}

