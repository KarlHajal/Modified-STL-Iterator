#include <iostream>
#include <string>
#include <libstdc++/unordered_set>
#include <libstdc++/unordered_map>

int main() {
    std::unordered_set<int> set = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    std::cout << std::endl << "unordered_set tests:" << std::endl << std::endl;

    std::cout << "SINGLE PASSES TEST:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "The set contains: ";
        for (auto it = set.begin(); it != set.end(); ++it) {
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }
    std::cout << "The set contains: ";
    for (auto x : set) {
        std::cout << " " << x;
    }
    std::unordered_set<int> set2 = { 1, 2, 3, 4, 5 };
    set2.insert(6);
    set2.emplace(7);
    
    std::cout << std::endl << "SIMULTANEOUS ITERATORS TEST:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        auto it1 = set2.begin();
        auto it2 = set2.begin();

        std::cout << "set2 contains (first iterator): ";
        while(it1 != set2.end()) {
            std::cout << " " << *it1;
            ++it1;
        }
        std::cout << std::endl << "set2 contains (second iterator): ";
        while(it2 != set2.end()) {
            std::cout << " " << *it2;
            ++it2;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "unordered_map test:" << std::endl << std::endl;
    std::unordered_map<int, std::string> map = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"}
    };

    for (int i = 0; i < 5; ++i) {
        std::cout << "The map contains: ";
        for (auto it = map.begin(); it != map.end(); ++it) {
            std::cout << " {" << it->first << " : " << it->second << "}"; 
        }
        std::cout << std::endl;
    }
   
    std::cout << std::endl;

    return 0;
} 
