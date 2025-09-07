#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void findPosition(char keyMatrix[5][5], char ch, int& row, int& col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyMatrix[i][j] == ch) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

void encryptPair(char keyMatrix[5][5], char a, char b, char& out1, char& out2) {
    int row1, col1, row2, col2;
    findPosition(keyMatrix, a, row1, col1);
    findPosition(keyMatrix, b, row2, col2);
    
    if (row1 == row2) {
        out1 = keyMatrix[row1][(col1 + 1) % 5];
        out2 = keyMatrix[row2][(col2 + 1) % 5];
    }
    else if (col1 == col2) {
        out1 = keyMatrix[(row1 + 1) % 5][col1];
        out2 = keyMatrix[(row2 + 1) % 5][col2];
    }
    else {
        out1 = keyMatrix[row1][col2];
        out2 = keyMatrix[row2][col1];
    }
}

void decryptPair(char keyMatrix[5][5], char a, char b, char& out1, char& out2) {
    int row1, col1, row2, col2;
    findPosition(keyMatrix, a, row1, col1);
    findPosition(keyMatrix, b, row2, col2);
    
    if (row1 == row2) {
        out1 = keyMatrix[row1][(col1 + 4) % 5];
        out2 = keyMatrix[row2][(col2 + 4) % 5];
    }
    else if (col1 == col2) {
        out1 = keyMatrix[(row1 + 4) % 5][col1];
        out2 = keyMatrix[(row2 + 4) % 5][col2];
    }
    else {
        out1 = keyMatrix[row1][col2];
        out2 = keyMatrix[row2][col1];
    }
}

string prepareText(string text, bool isEncrypt) {
    string cleanedText;
    for (char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            cleanedText += c;
        }
    }
    
    string preparedText;
    if (isEncrypt) {
        size_t i = 0;
        while (i < cleanedText.length()) {
            preparedText += cleanedText[i];
            i++;
            if (i == cleanedText.length()) {
                preparedText += 'X';
            } else if (preparedText.back() == cleanedText[i]) {
                preparedText += 'X';
            } else {
                preparedText += cleanedText[i];
                i++;
            }
        }
    } else {
        preparedText = cleanedText;
        if (preparedText.length() % 2 != 0) {
            preparedText += 'X';
        }
    }
    
    return preparedText;
}

string encryptPlayfair(string plaintext, char keyMatrix[5][5]) {
    string cleanedText = prepareText(plaintext, true);
    
    string ciphertext;
    for (size_t i = 0; i < cleanedText.length(); i += 2) {
        char out1, out2;
        encryptPair(keyMatrix, cleanedText[i], cleanedText[i + 1], out1, out2);
        ciphertext += out1;
        ciphertext += out2;
    }
    
    return ciphertext;
}

string decryptPlayfair(string ciphertext, char keyMatrix[5][5]) {
    string cleanedText = prepareText(ciphertext, false);
    
    string plaintext;
    for (size_t i = 0; i < cleanedText.length(); i += 2) {
        char out1, out2;
        decryptPair(keyMatrix, cleanedText[i], cleanedText[i + 1], out1, out2);
        plaintext += out1;
        plaintext += out2;
    }
    
    if (!plaintext.empty() && plaintext.back() == 'X') {
        plaintext.pop_back();
    }
    
    return plaintext;
}

int main() {
    char keyMatrix[5][5] = {
        {'R', 'U', 'S', 'H', 'B'},
        {'L', 'A', 'Z', 'E', 'C'},
        {'D', 'F', 'G', 'I', 'K'},
        {'M', 'N', 'O', 'P', 'Q'},
        {'T', 'V', 'W', 'X', 'Y'}
    };
    
    string mode, text;
    
    cout << "Enter mode (encrypt or decrypt): ";
    getline(cin, mode);
    
    if (mode == "encrypt") {
        cout << "Enter the plaintext: ";
    } else if (mode == "decrypt") {
        cout << "Enter the ciphertext: ";
    } else {
        cout << "Invalid mode. Please enter 'encrypt' or 'decrypt'." << endl;
        return 1;
    }
    
    getline(cin, text);
    
    string result;
    if (mode == "encrypt") {
        result = encryptPlayfair(text, keyMatrix);
        cout << "Encrypted ciphertext: " << result << endl;
    } else if (mode == "decrypt") {
        result = decryptPlayfair(text, keyMatrix);
        cout << "Decrypted plaintext: " << result << endl;
    }
    
    return 0;
}