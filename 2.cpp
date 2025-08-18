//Write program to find Multiplicative Inverse of b in Zp, p prime by Generalized Euclidean Algorithm by giving input as b and p and output as Multiplicative Inverse of b.

#include <iostream>
using namespace std;

int multiinverse(int b, int p) {
    int t1 = 0, t2 = 1;
    int r1 = p, r2 = b;

    while (r2 != 0) {
        int q = r1 / r2;
        int r = r1 % r2;
        int t = t1 - q * t2;

        r1 = r2;
        r2 = r;
        t1 = t2;
        t2 = t;
    }

    if (r1 == 1)
        return (t1 + p) % p;
    else
        return -1;
}

int main() {
    int b, p;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter prime p: ";
    cin >> p;


    int inverse = multiinverse(b, p);
    if (inverse == -1)
        cout << "inverse does not exist." << endl;
    else
        cout << "inverse of " << b << " % " << p << " is: " << inverse << endl;

    return 0;
}
