#ifndef EXO
    #define EXO 8
#endif

#if EXO == 1
    //  Manipulation d’un tableau C 1D
    #include <iostream>

    int main(){
        // make a table of size 5
        int table[10] = {10,20,30,40,50};
        long int Sum = 0;

        // show the elements using a for loop
        std::cout << "Elements: ";
        for(int i = 0; i < 5; i++){
            std::cout << table[i] << " ";
            // sum using += operator
            Sum += table[i];
        }
        std::cout << std::endl;

        // show the sum of the elements
        std::cout << "Somme = " << Sum << std::endl;
    
        return 0;
    }

#elif EXO == 2
    // Tableau C 2D (Stockage Matriciel)
    #include <iostream>

    int main(){
        int Matrix[3][3] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

        int sum = 0;

        std::cout << "Matrices" << std::endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                std::cout << Matrix[i][j] << " ";
                if (i == j) sum += Matrix[i][j];
            }
            std::cout << std::endl;
        }

        std::cout << "Somme diagonale = " << sum << std::endl;
    }

#elif EXO == 3
    // Utilisation de std::array
    #include <iostream> 
    #include <array>
    
    int main(){
        // let's define an array
        std::array<int, 5> myArray = {1, 2, 3, 4, 5};
        // let's print the array
        std::cout << "Original: ";
        for(int i = 0; i < myArray.size(); i++){
            std::cout << myArray[i] << " ";
        }
        std::cout << std::endl;

        // let's reverse the array
        int left = 0;
        int right = myArray.size() - 1;
        while (left < right) {
            // Swap elements at indices left and right
            int temp = myArray[left];
            myArray[left] = myArray[right];
            myArray[right] = temp;
    
            // Move the pointers towards the center
            left++;
            right--;
        }
    

        // let's print the reversed array
        std::cout << "Reversed: ";
        // using an iterator
        for(auto it = myArray.begin(); it != myArray.end(); it++){
            std::cout << *it << " ";
        }

        return 0;
    }

#elif EXO == 4
    // Utilisation de std::vector
    #include <iostream>
    #include <vector>
    #include <string>

    int main() {
        std::vector<int> myVector; // Vector to store numbers

        std::string inputLine;
        std::cout << "Enter numbers separated by spaces or commas: ";
        std::getline(std::cin, inputLine); // Read full input
        // another approach is to use std::cin after using is.unsetf(ios_base::skipws)
        // the rest of the logic stays the same
        
        std::string current_number = "";
        
        for (size_t i = 0; i < inputLine.length(); i++) {
            char c = inputLine[i];

            // If character is a digit, add to current_number
            if (c >= '0' && c <= '9') {
                current_number += c;
            } 
            // If character is a space or comma, process the current number
            else if (c == ' ' || c == ',') {
                if (!current_number.empty()) { // If we have a valid number
                    myVector.push_back(std::stoi(current_number)); // Convert and store it
                    current_number = ""; // Reset for the next number
                }
            } 
            else {
                std::cout << "Error: Invalid input character '" << c << "'" << std::endl;
                return 1; // Exit with error
            }
        }

        // Add the last number if any
        if (!current_number.empty()) {
            myVector.push_back(std::stoi(current_number));
        }

        // Print the vector
        std::cout << "Double: ";
        for (int num : myVector) {
            std::cout << num * 2 << " ";
        }
        std::cout << std::endl;

        return 0;
    }



#elif EXO == 5
    // Utilisation de std::list (Liste Chaînée)
    #include <iostream>
    # include <list>

    int main(){
        // let's define a list
        std::list<int> myList = {10, 20, 30, 40, 50};

        // let's add elements to the end of the list
        myList.push_back(60);

        // let's add elements to the beginning of the list
        myList.push_front(0);

        // let's print the list
        std::cout << "Apres insertion: ";
        for(auto it = myList.begin(); it != myList.end(); it++){
            std::cout << *it << " ";
        }

        return 0;
    }

#elif EXO == 6
    // Utilisation de std::set (Éléments Uniques)
    #include <iostream>
    #include <set>

    int main(){
        // let's define a set
        std::set<int> mySet;

        // let's insert 5, 10, 15, 20
        mySet.insert(5);
        mySet.insert(10);
        mySet.insert(15);
        mySet.insert(20);

        // print
        std::cout << "Original: ";
        for(auto it = mySet.begin(); it != mySet.end(); it++){
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        // let's try inserting 10 again
        mySet.insert(10);
        
        // print
        std::cout << "Apres insertion de 10: ";
        for(auto it = mySet.begin(); it != mySet.end(); it++){
            std::cout << *it << " ";
        }

        return 0;
    }

#elif EXO == 7
    // Utilisation de std::map (Paires Clé-Valeur)
    #include <iostream>
    #include <map>

    int main(){
        // let's define a map
        std::map<std::string, int> Students_notes = {
            {"John",85},{"Alice",90},{"Bob",78}
        };

        // let's print the map
        for(auto it = Students_notes.begin(); it != Students_notes.end(); it++){
            std::cout << it->first << " : " << it->second << std::endl;
        }

        return 0;
    }
#elif EXO == 8
    // Compteur de mots avec std::unordered_map
    #include <iostream>
    #include <string>
    #include <unordered_map>

    int main(){
        // let's define a map
        std::unordered_map<std::string, int> word_count;
        // let's define a string
        std::string sentence = "pomme banane pomme orange banane banane";

        // we split the sentence into words
        // throught the " " between words
        std::string word = "";
        for (char c : sentence){
            if(c == ' '){
                // if the word is not empty, we add it to the map
                if(word != ""){
                    // update the word count
                    word_count[word]++;
                    // a good thing in cpp is that this syntax isn't wrong even if the key doesn't exist yet
                    
                    // reset the word
                    word = "";
                }
            }
            else{
                // as long as we don't encounter a space, we add the character to the word
                word += c;
            }
        }
        // if the word is not empty, we add it to the map
        if(word != ""){
            word_count[word]++;
        }

        // print the map
        for(auto it = word_count.begin(); it != word_count.end(); it++){
            std::cout << it->first << " : " << it->second << std::endl;
        }

        return 0;
    }

#elif EXO == 9
    // Trier un std::vector
    #include <iostream>
    #include <vector>
    #include <algorithm>

    int main(){
        // let's define a vector
        std::vector<int> myVector = {30,10,50,20,40};
        // print Original
        std::cout << "Original: ";
        for(auto it = myVector.begin(); it != myVector.end(); it++){
            std::cout << *it << " ";
        }

        // using std::sort
        std::sort(myVector.begin(), myVector.end());
        // print Sorted
        std::cout << "\nTrie: ";
        for(auto it = myVector.begin(); it != myVector.end(); it++){
            std::cout << *it << " ";
        }

        return 0;
    }

#elif EXO == 10
    // Trouver la Plus Longue Séquence Consécutive dans un std::set
    #include <iostream>
    #include <set>

    int main(){
        // let's define a set
        std::set<int> mySet = {100, 4, 200, 1, 3, 2};
        // we store only the sarting iterator of the sequence
        auto start = mySet.begin();
        auto curr = mySet.begin();
        auto curr_start = mySet.begin();

        int count = 1;
        int current_count = 1;
        int current_element = *curr;
        // the set when accesed is sorted by default

        // let's start at the beginning
        // if the next element is the same as the current one + 1
        // then we increment the current_count and we update the current_element
        // else we reset the current_count and we update the current_element and iterator curr_start 

        bool Truth = true;
        
        while(curr != mySet.end()){
            current_element = *curr;
            curr++;
            if(current_element + 1 == *curr){
                current_count++;
                if (current_count > count){
                    count = current_count;
                    start = curr_start;
                }
            }
            else{
                current_count = 1;
                curr_start = curr;
            }
        }


        // print the result from the start iterator
        std::cout << "Plus longue sequence: ";
        std::cout << count <<" (";
        for(auto it = start; count > 0; it++ , count--){
            std::cout << *it;
            if(count > 1) std::cout << ", ";
        }
        std::cout << ")" << std::endl;
    }
#elif EXO == 11
    // Implémentation d’un Cache LRU (Least Recently Used)
    #include <iostream>
    #include <list> // to store the elements by order of use
    # include <unordered_map> // to assure fast access to the elements O(1)

    // we won't be defining a class we are goin to be making functions only
    // implement get(key, ...) and put(key, value, ...) and display(lru)
    // we are giong to pass lru and cashe as parameters for put and get
    
    // return 0 for successful, other for failed or other cases (each return value signifies a certain type of result)
    std::pair<int,std::pair<int,int>> put(std::unordered_map<int, std::list<std::pair<int, int>>::iterator>& cache,std::list<std::pair<int,int>>& lru,int capacity,int key,int value){
        // if no deletion return the inputed value and 0 
        // if deletion return the deleted value and 1
        // if error return -1 and wanted inputed value
        std::pair<int,std::pair<int,int>> result = std::make_pair(0,std::make_pair(key,value));

        // check if the element is already in the hash map
        if(cache.find(key) != cache.end()){
            // if it is, we update the value
            cache[key]->second = value;
            // and we move the element to the front of the list
            auto position = cache[key];
            // then remove
            lru.erase(position);
        }
        // if it is not, we add it to the front of the list
        else{
            // if the list is full, we remove the last element
            if(lru.size() == capacity){
                // remove the last element
                // and return at as a value
                result.first = 1;
                result.second.first = lru.back().first;
                result.second.second = lru.back().second;

                cache.erase(lru.back().first);
                lru.pop_back();
            }
        }

        // add the new element to the front of the list
        lru.push_front({key, value});
        // add the new element to the hash map
        cache[key] = lru.begin();

        return result;
    } 

    int get(std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache, std::list<std::pair<int,int>>& lru,int capacity,int key){
        // check if the element is already in the hash map
        if(cache.find(key) != cache.end()){
            // if it is, we update the position
            auto position = cache[key];
            // first copy to a temp
            auto temp = *position;
            // then remove
            lru.erase(position);
            // add the new element to the front of the list
            lru.push_front(temp);
            // add the new element to the hash map
            cache[key] = lru.begin();

            return temp.second;
        }
        else{
            return -1;
        }
    }

    void display(std::list<std::pair<int,int>> lru){
        for(auto it = lru.begin(); it != lru.end(); it++){
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
        std::cout << std::endl;
    }

    int main(){
        // let's define a cache
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
        std::list<std::pair<int,int>> lru;
        int capacity = 2;
        // let's add elements to the cache
        put(cache, lru, capacity, 1, 10);
        put(cache, lru, capacity, 2, 20);
        // print the cache
        std::cout << "Etat de cache: ";
        // without a display function
        display(lru);

        // access to key 1   
        std::cout << "Access a la cle 1 : " << get(cache, lru, capacity, 1) << std::endl;
    
        // new state of cache
        std::cout << "Etat de cache: ";
        display(lru);

        // add a new element
        std::pair<int,int> to_add = std::make_pair(3, 30);
        std::pair<int,int> deleted = put(cache, lru, capacity, to_add.first, to_add.second).second;

        // print the deleted element
        std::cout << "Ajout de (" << to_add.first << "," << to_add.second << "), suppression de (" << deleted.first << "," << deleted.second << ")" << std::endl;
        
        // print the cache
        std::cout << "Etat de cache: ";
        display(lru);
    }

#else
    // throw an error if the EXO variable is not in the range of the defined EXO
    #error "EXO variable is not in the range of the defined EXOs"

#endif