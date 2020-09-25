#include <iostream>
#include <string>
#include <tuple>
#include "functions.h"
using namespace std;
int main(int argc, char* argv[]) {
    ifstream file;
    ofstream answer;
    //file.open("../maxFlowTests/test1.in", ios_base::in);
    file.open(argv[1], ios_base::in);
    answer.open("./answer.out", ios_base::out);
    vector<set<char>>cubes; string word;
    tie(cubes, word) = processing(&file);
    vector<vector<int>> f(2 + cubes.size() + word.size());
    vector<vector<long long int>> c(2 + cubes.size() + word.size());
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
    vector<long long> prior = move(BFS(c, 0, 1));
    vector<long long> way = move(getPath(prior, 1, 0));
    while (!way.empty()){
        long long prev_point = 0, min_flow = 0;
        for(const auto el : way){
            if(c[prev_point][el] < min_flow || min_flow == 0){
                min_flow = c[prev_point][el];
            }
            prev_point = el;
        }
        for(int i = 0; i < way.size() - 1; ++i){
            long long a = way[i], b = way[i+1];
            f[a][b] += min_flow;
            f[b][a] -= min_flow;
            c[a][b] -= min_flow;
            c[b][a] += min_flow;
        }
        prior = move(BFS(c, 0, 1));
        way = move(getPath(prior, 1, 0));
        min_flow = 0;
    }
    long long res = 0;
    for (const auto e: f[0]){
        res += e;
    }
    if(res == word.size()){
        answer << "YES";
    }
    else{
        answer << "NO";
    }
    file.close();
    answer.close();
    return 0;
}
