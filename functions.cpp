#include "functions.h"
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
tuple<vector<set<char>>, string> processing(ifstream *file) {
    long long num_items;//кол-во кубиков
    (*file) >> num_items;
    string word;//слово
    (*file) >> word;
    vector<set<char>> cubes(num_items);
    //Читаем матрицу
    string tmp;
    for (long long i = 0; i < num_items; ++i) {
        tmp.clear();
        (*file) >> tmp;
        //избавляемся от повторяющихся букв в кубиках - они не нужны?
        for_each(tmp.begin(),tmp.end(), [&cubes, i](char l){
            cubes[i].insert(l);
        });
    }
    return make_tuple(cubes, word);
}
vector<long long> getPath(vector<long long>& prior, long long dest, long long origin)
{
    vector<long long> ans;
    if(prior[dest] == -1){
        return ans;
    }
    for (int v = dest; v != origin; v = prior[v])  // Проходим по пути из конца в начало
    {
        ans.push_back(v);  // Запоминаем вершину
    }
    ans.push_back(origin);
    reverse(ans.begin(), ans.end());  // Переворачиваем путь
    return ans;
}
vector<long long> BFS(vector<vector<long long>>&_data, long long origin, long long dest){
    queue<long long> queue;
    queue.push(origin);
    vector<bool> visited(_data.size());
    vector<long long>prior(_data.size());
    for (long long i = 0; i < _data.size(); ++i) {
        prior[i] = -1;
    }
    long long current = origin;
    prior[origin] = origin;
    while (!queue.empty() && current != dest) {
        current = queue.front();
        queue.pop();
        if (!visited[current]) {
            visited[current] = true;
            for(long i = 0; i < _data.size(); ++i){
                if(_data[current][i] != 0){
                    queue.push(i);
                    prior[i] = !visited[i] ? current : prior[i];
                }
            }
        }
    }
    return prior;
}
