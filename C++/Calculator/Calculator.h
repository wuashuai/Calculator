#define CALCULATOR_H
#include <iostream>
#include <string>

using namespace std;

class Calculator{

	public:
		Calculator();
        ~Calculator();
		double numPadPressed(string s);
		bool check(string current);
		string reverse(string current);
		void clearAll();
        void clear();
		string calculate(string x, string y, string op);
		
	private:
		string preValue;
    	string current;
    	string op;
    	double pos;
    	double show;
};