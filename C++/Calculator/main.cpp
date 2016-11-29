#include <iostream>
#include <string>
#include "Calculator.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
    string input[8];
    input[0] = "6";
    input[1] = "+";
    input[2] ="1";
    input[3] =".";
    input[4] ="6";
    input[5] ="=";
    input[6] ="+/-";
    input[7] ="AC";
    Calculator c;

    for(int i = 0 ; i < 8; i++){
        string cur = input[i];
        cout << i << "    " << c.numPadPressed(cur) << endl;
    }

}