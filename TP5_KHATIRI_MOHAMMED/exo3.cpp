// Compression de texte (encodage RLE)
#include <iostream>
#include <string>

using namespace std;

string encode_rle(const string& text);

int main(){
    // ask for a string
    string text;
    cout << "Texte (one word) : ";
    cin >> text;
    cout << "Encode : \"" << encode_rle(text) <<"\""<< endl;
}

string encode_rle(const string& text){
    string result;
    int count = 1;

    for (int i = 0; i < text.length(); i++) {
        // if the next character is the same as the current one, increment the count
        if (text[i] == text[i + 1]) {
            count++;
        }
        // if the next character is different, add the count and the character to the result
        else {
            // trandform count to string first
            result += text[i] + to_string(count);
        }
    }

    // return the result
    return result;
}
