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

