#include "../HEADERFILES/ArmstrongCryptograph.h"
#include "../HEADERFILES/ColorCrytography.h"
#include "../HEADERFILES/KeyGenerator.h"
#include <bits/stdc++.h>

using namespace std;
int main() {
    string data = "This is an very important statement.";
    string key = "How old is my computer?";
    KeyGenerator kGen(key);
    string nK = kGen.getNumericKey();
    //DEBUG
    kGen.display();
    ArmstrongManager aMgr(nK);
    ColorManager cMgr(nK);

    string encData = "";
    int temp;
    
    for (int i = 0; i < data.length(); i++) {
        temp = aMgr.encrypt(data[i]);
        temp = cMgr.encrypt(temp);
        encData = encData + (char)temp;
    }

    string decData = "";
    for (int i = 0; i < encData.length(); i++) {
        temp = cMgr.decrypt(encData[i]);
        temp = aMgr.decrypt(temp);

        decData = decData + (char)temp;
    }

    cout << "data: " << data << "  " << data.length() << "\n";
    cout << "enc data: " << encData << "  " << encData.length() << "\n";
    cout << "dec data: " << decData << "  " << decData.length() << "\n";

}