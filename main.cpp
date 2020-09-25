#include <iostream>
#include <string>
#include <tuple>
#include "functions.h"
using namespace std;
int main() {
    ifstream file;
    ofstream answer;
    file.open("../cubesTests/test1.in", ios_base::in);
    vector<set<char>>cubes; string word;
    tie(cubes, word) = processing(&file);
    vector<vector<int>>c(2 + cubes.size() + word.size()), f(2 + cubes.size() + word.size());
    for(long long i = 0; i < f.size(); ++i){
        for (long long j = 0; j < f.size(); ++j){
            f[i].push_back(0);
            c[i].push_back(0);
        }
    }
    for(long long i = 0; i < word.size(); ++i){
        c[0][i+2] = 1;
        for(long long j = 0; j < cubes.size(); ++j){
            if(cubes[j].find(word[i]) != cubes[j].end()){
                c[i+2][word.size() + 2 + j] = 1;
            }
            c[word.size() + 2 + j][1] = 1;
        }
    }

    file.close();
    return 0;
}
