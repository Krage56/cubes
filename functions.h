//
// Created by krage56 on 25.09.2020.
//

#ifndef CUBES_FUNCTIONS_H
#define CUBES_FUNCTIONS_H
#include <vector>
#include <fstream>
#include <set>
using namespace std;
vector<long long> getPath(vector<long long>& prior, long long dest, long long origin);
vector<long long> BFS(vector<vector<long long>>&_data, long long origin, long long dest);
tuple<vector<set<char>>, string> processing(ifstream *file);
#endif //CUBES_FUNCTIONS_H
