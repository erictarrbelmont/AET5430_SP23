//
//  main.cpp
//  HelloWorld
//
//  Created by Eric Tarr on 1/12/23.
//

#include <iostream>

// function [out] = myFunction(input)

// C++ data types:
// numbers:
// Integers: "int"
// "float" : 32-bit decimal number
// "double" : 64-bit decimal numbers

// void function: doesn't return an output variable


using namespace std;

// Declare functions before they are used (Forward declare)
// Global scope
float myFunction(float x);

int main() {
    
    // Creating a variable:
    int x; // "declare" a new int variable
    x = 10; // "define" the variable
    
    float y = 4.5, z = -9.9;
    
    cout << "Hello, World!\n";
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    
    // Creating arrays
    static const int size = 5;
    
    float array[size] = {10.f,5.f,3.f,2.f,1.f}; // "declare"
    
    
    // Conditional
    if (x > 5){
        cout << "Cool!" << endl;
    }
    else if (x < 0){
        cout << "Nice!" << endl;
    }
    else {
        cout << "Wow!" << endl;
    }
    
    
    
    // Loops
    for (int n = 0; n < 5 ; ++n){
        float q = array[n];
        float w = myFunction(q);
        cout << w << endl;
    }
    
    
    return 0;
}


float myFunction(float x){
    float y = x + 100.f;
    return y;
}
