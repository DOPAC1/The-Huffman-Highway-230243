#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;


double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double mod(double x, double y);
double sin_func(double x);
double cos_func(double x);
double tan_func(double x);
double ln_func(double x);
double exp_func(double x);

double calculate(const string& operation, double x, double y = 0) {
    if (operation == "+") return add(x, y);
    else if (operation == "-") return subtract(x, y);
    else if (operation == "*") return multiply(x, y);
    else if (operation == "/") return divide(x, y);
    else if (operation == "%") return mod(x, y);
    else if (operation == "sin") return sin_func(x);
    else if (operation == "cos") return cos_func(x);
    else if (operation == "tan") return tan_func(x);
    else if (operation == "ln") return ln_func(x);
    else if (operation == "exp") return exp_func(x);
    throw invalid_argument("Unknown operation: " + operation);
}

double add(double x, double y) { return x + y; }
double subtract(double x, double y) { return x - y; }
double multiply(double x, double y) { return x * y; }
double divide(double x, double y) { 
    if (y == 0) throw invalid_argument("Division by zero"); 
    return x / y; 
}
double mod(double x, double y) { return fmod(x, y); }
double sin_func(double x) { return sin(x); }
double cos_func(double x) { return cos(x); }
double tan_func(double x) { return tan(x); }
double ln_func(double x) { 
    if (x <= 0) throw invalid_argument("ln(x) is undefined for x <= 0"); 
    return log(x); 
}
double exp_func(double x) { return exp(x); }

int main() {
    string input;
    cout << "Enter expression: ";
    getline(cin, input);
    istringstream iss(input);

    string operation;
    double x, y;
    
    iss >> operation >> x;
    if (operation == "+" || operation == "-" || operation == "*" || operation == "/" || operation == "%") {
        iss >> y;
    }

    try {
        double result = calculate(operation, x, y);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
