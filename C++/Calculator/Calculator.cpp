#include "Calculator.h"
#include <iostream>
#include <string>

using namespace std;

Calculator::Calculator() {
    preValue = "";
    current = "";
    op = "";
    pos = 1;
    show = "0";
}

Calculator::~Calculator(){}

double Calculator::numPadPressed(string s) {
    switch (s) {
        case "+" : case "-" : case "*" : case "/" :
            if(pos == 0){
                current = preValue;
            }
            if(pos != 0 && !preValue && !current){
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
            break;
        
        case "AC": 
        	clearAll();
        	break;
        
        case "+/-":
            if(pos == 1) {
                current = reverse(current);
                show = current;
            }
            else{
                preValue = reverse(preValue);
                show = preValue;
            }
        	break;
        case "%%":
            double y = 100;
            op = "/";
            if(pos == 0){
                preValue = calculate(preValue, y, op);
                show = preValue;
            }else{
                current = calculate(current, y, op);
                show = current;
            }
        	break;
        case "=":
            preValue = calculate(preValue, current, op);
            pos = 0;
            show = preValue;
            if(preValue == "error"){
                clear();
            }
        	break;
        case ".":
            if(current == "0" || pos == 0){
                current = "0.";
                pos = 1;
            }
            if(current) {
                current += keyValue;
            }
            show = current;
            break;
        default :
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
}
    
bool Calculator::check(string current){
    return current.find(".");
    
}

string Calculator::reverse(string current){
    int re = "-1";
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
        a = stod(x);
    }
    if(y != "." && y != ""){
        b = stod(y);
    }

    switch(op){
        case "+": 
        	res = a + b;
        	break;
        case "-": 
        	res = a - b;
        	break;
        case "*": 
        	res = a * b;
        	break;
        case "/":
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
    return res + "";
}
    

