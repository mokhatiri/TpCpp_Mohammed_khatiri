// Trier les mots par longueur (std::multimap)
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

void sort_by_length(const string& text);
/*
using std::multimap<int, string> word_map;
*/

int main(){
    string text;
    cout << "Phrase : ";
    getline(cin, text);
    sort_by_length(text);
}

void sort_by_length(const string& text){
    //sorting the words by length
    // according to the web, multimap is a sorted container according to the first key
    multimap<int, string> word_map;
    string word;
    stringstream ss(text);

    while(ss >> word){
        // feed every word into the map
        word_map.insert(pair<int, string>(word.length(), word));
    }
    // print the map
    for(auto it = word_map.begin(); it != word_map.end(); it++){
        cout << it->second << " ";
    }
}