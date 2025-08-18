//Write program to find GCD of any two numbers a and b by Generalized Euclidean Algorithm. Demonstrate by giving as input two numbers a & b and value of n and show output GCD(a, b) and value of s & t.

#include <iostream>
using namespace std;

int main(){

    int a;
    cout << "enter the devidend" << endl;
    cin >> a;

    int b;
    cout << "enter the divisor" << endl;
    cin >> b;


int r1 = a;
int r2 = b;
int s1 = 1;
int s2 = 0;
int t1 = 0;
int t2 = 1;


while (r2 != 0){

    int r = r1 %r2 ;

    r1 = r2;
    r2 = r;   

    int s = s1 - int(r1 / r2) * s2;

s1 = s2;
s2 = s;

    int t = t1 - int(r1 / r2) * t2;

t1 = t2;
t2 = t;

};

    cout << "The GCD is: " <<r1 << endl;
    cout << "The s is: " <<s1 << endl;
    cout << "The t is: " <<t1 << endl;

    return 0;


}
