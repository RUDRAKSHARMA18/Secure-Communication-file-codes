//Write Program to Encrypt and Decrypt by Affine Cipher (7, 1) the message 'Cryptography is easy subject'. Take Input Message and Key (7, 1) and Output ciphertext.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}


int modInverse(int a, int m) {
    int t1 = 0, t2 = 1;
    int r1 = m, r2 = a;

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
        return (t1 + m) % m;
    else
        return -1;
}


string encrypt(string text, int a, int b) {

    string result = "";
    for (char c : text) {
        char upper = toupper(c);
            result += (((a * (upper - 65) + b) % 26) + 65); 
    }
    return result;
}


string decrypt(string cipher, int a, int b) {

    string result = "";
    int inv = modInverse(a, 26);

    for (char c : cipher) {
            char upper = toupper(c);
            int temp = (inv * (((upper - 65) - b + 26) % 26)) % 26;  
            char decrypted = (temp + 65);  
            result += tolower(decrypted);
    }
    return result;
}


int main() {
    int choice;
    string message;
    int a, b;

    cout << "Affine Cipher Program\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

if (choice == 1 or choice == 2){

    bool valid_a = false;
    while (!valid_a) {
        cout << "Enter key a: ";
        cin >> a;
        if (gcd(a, 26) == 1) {
            valid_a = true;
        } else {
            cout << "Inverse doesn't exist for a= " << a << ".\nEnter another value.\n";
        }
    }

    cout << "Enter key b: ";
    cin >> b;
    cin.ignore(); 
}

    switch (choice) {
        
        case 1:{
            cout << "Enter plaintext: ";
            getline(cin, message);
            string ciphertext = encrypt(message, a, b);
            cout << "Key: (" << a << ", " << b << ")\n";
            cout << "Ciphertext: " << ciphertext << "\n";
            break;}

        case 2:{
            cout << "Enter ciphertext: ";
            getline(cin, message);
            string plaintext = decrypt(message, a, b);
            cout << "Key: (" << a << ", " << b << ")\n";
            cout << "Plaintext: " << plaintext << "\n";
            break;}

        default:
            cout << "Invalid choice.\n";
    }

    return 0;
}