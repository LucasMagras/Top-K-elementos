#ifndef READ_HPP
#define READ_HPP

#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <locale>

#define k 20

using namespace std;

struct Item {
    string palavra;
    int frequencia;

    Item(string str, int freq) : palavra(str), frequencia(freq) {}

    bool operator<(Item other) const {
        return frequencia > other.frequencia;
    }
};

void leitura();
string ConverterAcentuadasParaMinusculas(string num);
bool CaracterEstranho(string word);
#endif