// advanced search using regex (std::regex)
// verifier si une phrase contient une adresse mail
#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool contains_email(const string& text);

int main()
{
    // getting an input phrase
    string phrase;
    cout << "Enter a phrase: ";
    getline(cin, phrase);
    // regex 
    contains_email(phrase);
}

bool contains_email(const string& text){
    // regex
    // from (a-z or A-Z or numbers or ._%+-) or more of this characters 
    // ,and then @ 
    // ,and then again (from a-z and A-Z and numbers and .-) or more of this characters 
    // ,and then . 
    // ,and then (from a-z or A-Z) 2 or more of this characters // since the domain name is at least 2 characters
    std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    std::smatch match;

    if (std::regex_search(text, match, pattern)) {
        std::cout << "Found email: " << match.str() << "\n";
        return true;
    } else {
        std::cout << "No email found\n";
        return false;
    }
}