//Write program to find GCD of any two numbers a and b by Generalized Euclidean Algorithm. Demonstrate by giving as input two numbers a & b and value of n and show output GCD(a, b).

#include <iostream>
using namespace std;

int main(){

    int a;
    cout << "enter the devidend" << endl;
    cin >> a;

    int b;
    cout << "enter the divisor" << endl;
    cin >> b;


int x = a;
int y = b;


while (y != 0){

    int temp = x %y ;

    x = y;
    y = temp;   

};

    cout << "The GCD is: " << x << endl;
    return 0;


}