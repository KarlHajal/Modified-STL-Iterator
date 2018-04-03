 # Modified STL Iterator
Modification to the libstdc++ C++ STL library that allows unordered_map or unordered_set iterators to explore container elements in a different order every run.

The purpose of this modification is to detect wrong assumptions regarding the iteration order of certain STL containers such as unordered_map and unordered_set, since any given order the elements are placed in is not guaranteed and might differ from one implementation to the other.

Here's an example showing the result:
```c++
#include <iostream>
#include <libstdc++/unordered_set>
int main() {

 	std::cout << std::endl << "unordered_set test:" << std::endl;    
	std::unordered_set<int> set = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i < 5; ++i) {
		std::cout << "The set contains: ";
		for (auto it = set.begin(); it != set.end(); ++it) {
			std::cout << " " << *it;
		}
		std::cout << std::endl;
	}
    
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

    return 0;
}
```

Output:
```
unordered_set test:
The set contains:  5 3 7 6 4 10 9 8 1 2
The set contains:  6 10 5 8 3 1 4 2 7 9
The set contains:  2 9 7 4 1 10 3 8 6 5
The set contains:  10 9 8 1 7 3 6 4 2 5
The set contains:  7 1 3 5 2 9 6 8 4 10

unordered_map test:
The map contains:  {4 : four} {1 : one} {6 : six} {5 : five} {2 : two} {7 : seven} {3 : three}
The map contains:  {2 : two} {1 : one} {7 : seven} {6 : six} {5 : five} {4 : four} {3 : three}
The map contains:  {7 : seven} {4 : four} {1 : one} {5 : five} {3 : three} {6 : six} {2 : two}
The map contains:  {5 : five} {1 : one} {7 : seven} {4 : four} {6 : six} {2 : two} {3 : three}
The map contains:  {2 : two} {7 : seven} {1 : one} {3 : three} {6 : six} {5 : five} {4 : four}

```

To try it out, you can build the project from the command line using either:
```
make TEST=file_name
./bin/file_name
```
Or
```
make run TEST=file_name
```
where file_name.cpp is a file in the ./test directory.
