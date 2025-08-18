// Write program to encrypt and decrypt by Ceaser Cipher the Plaintext Message ' It is good to be talkative' by taking input the plain message and Output the ciphertext formed along with its Cryptanalysis

#include <iostream>
#include <string>
#include <cctype>
using namespace std;


string encrypt(string text, int shift) {
    string result = "";

    for (char c : text) {
        char upper = toupper(c);
        result += char((upper - 65 + shift) % 26 + 65);
    }
    return result;
}


string decrypt(string text, int shift) {
    string result = "";

    for (char c : text) {
        char upper = toupper(c);
        result += char((upper - 65 - shift + 26) % 26 + 65);
    }
    return result;
}




int main() {

cout << "Enter 1 for Encryption or 2 for Decryption: ";
int choice;
cin >> choice;
cin.ignore(); 

switch (choice) {
    case 1: {
        string plain;
        cout << "Enter the plaintext: ";
        getline(cin, plain);

        int key;
        cout << "Enter the key: ";
        cin >> key;

        string cip = encrypt(plain, key);
        cout << "Ciphertext: " << cip << endl;
        break;



    }
    case 2: {
        string cip;
        cout << "Enter the ciphertext: ";
        getline(cin, cip);

        int key;
        cout << "Enter the key: ";
        cin >> key;

        string dec = decrypt(cip, key);
        cout << "Decrypted Text: " << dec << endl;
        break;
    }

    default:
        cout << "Invalid choice!" << endl;


}

return 0;
}







