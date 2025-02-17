// extraction des mots les plus frequents d'un texte (std::map)
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void top_frequent_words(const string& text, unsigned n);
/* we are gonna use
std::vector<std::pair<std::string, int>> sorted_words(freq.begin(), freq.end());
std::sort(sorted_words.begin(), sorted_words.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
*/

int main(){
    string text;
    cout << "Texte : ";
    getline(cin, text);
    
    // since the goal is to find only the top 3
    top_frequent_words(text, 3);
}

void top_frequent_words(const string& text, unsigned n){
    // split the text into words
    istringstream iss(text);
    string word;
    map<string, int> freq;
    while (iss >> word) {
        freq[word]++;
    }

    // sort the words by frequency
    vector<pair<string, int>> sorted_words(freq.begin(), freq.end());
    sort(sorted_words.begin(), sorted_words.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
    // print the n most frequent words

    cout << "Top " << n << " mots les plus frequents : " << endl;
    for (unsigned i = 0; i < n && i < freq.size(); i++) {
        cout << i+1 << ". " << sorted_words[i].first << " -> " << sorted_words[i].second << endl;
    }
}