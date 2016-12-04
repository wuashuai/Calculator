//
//  Calculator.cpp
//  Calculator
//
//  Created by Zhenchuan Pang on 12/3/16.
//  Copyright © 2016 wuzhongru. All rights reserved.
//

#include "Calculator.mm"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Calculator{
    
public:
    Calculator();
    ~Calculator();
    const char* numPadPress(char *s);
    bool check(string current);
    string reverse(string current);
    void clearAll();
    void clear();
    string calculate(string x, string y, string op);
    int getOne();
    
private:
    string preValue;
    string current;
    string op;
    double pos;
    string show;
};

Calculator::Calculator() {
    preValue = "";
    current = "";
    op = "";
    pos = 1;
    show = "0";
}

static Calculator cal;

Calculator::~Calculator(){}

int Calculator::getOne(){
    return 1;
}
const char* Calculator::numPadPress(char *s) {
    string keyValue(s);
    if(s == "+" || s == "-" || s == "*" || s == "/"){
        if(pos == 0){
            current = preValue;
        }
        if(pos != 0 && preValue.length() > 0 && current.length() > 0){
            current = calculate(preValue, current, op);
        }
        op = keyValue;
        preValue = current;
        show = preValue;
        current = "";
        pos = 1;
        if(preValue == "error"){
            clear();
        }
    }else if(s == "AC"){
        clearAll();
    }else if(s == "+/-"){
        if(pos == 1) {
            current = reverse(current);
            show = current;
        }else{
            preValue = reverse(preValue);
            show = preValue;
        }
    }else if(s == "%"){
        string y = "100";
        op = "/";
        if(pos == 0){
            preValue = calculate(preValue, y, op);
            show = preValue;
        }else{
            current = calculate(current, y, op);
            show = current;
        }
    }else if(s == "="){
        preValue = calculate(preValue, current, op);
        pos = 0;
        show = preValue;
        if(preValue == "error"){
            clear();
        }
    }else if(s == "."){
        if(current == "0" || pos == 0){
            current = "0.";
            pos = 1;
        }
        if(!check(current)) {
            current += keyValue;
        }
        show = current;
    }else{
        if (pos == 0){
            op = "";
            pos = 1;
            preValue = "";
            current = keyValue;
        }else if(current == "0"){
            current = keyValue;
        }else{
            current += keyValue;
        }
        show = current;
    }
    const char* res = show.c_str();
    return res;
}

bool Calculator::check(string current){
    
    if(current.find('.') != string::npos)
        return true;
    return false;
}

string Calculator::reverse(string current){
    string re = "-1";
    return calculate(current, re, "*");
}


void Calculator::clearAll(){
    preValue = "";
    current = "";
    op = "";
    pos = 1;
    show = "0";
}

void Calculator::clear(){
    preValue = "";
    current = "";
    op = "";
    pos = 1;
}

string Calculator::calculate(string x, string y, string op){
    double res = 0.0;
    int alt =  0;
    
    double a = 0.0;
    double b = 0.0;
    
    if(x != "." && x != ""){
        a = atof(x.c_str());
    }
    if(y != "." && y != ""){
        b = atof(y.c_str());
    }
    
    switch(op[0]){
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            if(b == 0) {
                return "error";
            }
            res = a / b;
            break;
        default:
            res = a + b;
    }
    alt = (int)res;
    if (alt == res){
        return alt + "";
    }
    
    ostringstream strs;
    strs << res;
    string str = strs.str();
    return str;
    //    return res + "";
}
