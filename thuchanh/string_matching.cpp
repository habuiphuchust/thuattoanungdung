#include <iostream>
#include <string>
using namespace std;
int countOccurrences(const std::string& mainString, const std::string& searchString) {
    int count = 0;
    size_t pos = 0;

    while ((pos = mainString.find(searchString, pos)) != std::string::npos) {
        count++;
        pos += searchString.length();
    }

    return count;
}

int main() {
    string mainString;
    string searchString;
    getline(cin, searchString) ;
    getline(cin, mainString);
    int occurrences = countOccurrences(mainString, searchString);
    cout << occurrences;

    return 0;
}
