// Detection de palindrome (string , reverse)
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(const string& text);

int main(){
    string text;
    cout << "Entrez un mot : ";
    getline(cin, text);
    string confirmation;
    confirmation = is_palindrome(text) ? "est un" : "n'est pas un";
    cout << text << " " << confirmation << " palindrome" << endl;
}

bool is_palindrome(const string& text){
    string text_reverse = text;
    reverse(text_reverse.begin(), text_reverse.end());
    return text == text_reverse;
}