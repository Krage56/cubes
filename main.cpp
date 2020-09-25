#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    unordered_map<char, int> word;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for_each(alphabet.begin(), alphabet.end(), [&word](const char l){word.insert({l,0});});
    //for_each(word.begin(), word.end(), [](auto k){cout << k.second << " ";});

    return 0;
}
