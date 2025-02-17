// Frequence des mots dans un texte (std::unordered_map, std::istringstream)
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

void word_frequency(const string& text);

int main(){
    string text;
    cout << "Entrez une phrase : ";
    getline(cin, text);
    word_frequency(text);
}

void word_frequency(const string& text){
    // loop throught the text, split the words and count them using the map
    unordered_map<string, int> word_count;
    istringstream iss(text);
    string word;

    // this basically passes the last string using the stream to word untill the end of the stream
    while (iss >> word) {
        word_count[word]++;
    }

    // print the result
    for (const auto& pair : word_count) {
        cout << pair.first << " -> " << pair.second << endl;
    }
}