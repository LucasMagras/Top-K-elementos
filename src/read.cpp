#include "read.hpp"

void leitura() 
{
    string dataFileName("dataset/DomCasmurro.txt");
    string dataFileName2("dataset/Semana_Machado_Assis.txt");
    string StopWords("dataset/stopwords.txt");
    string word, line;

    unordered_map<string, int> frequencia; // hash que armazena a palavra e a freq que ela aparece
    priority_queue<Item> heap; // heap de tamanho k
    unordered_set<string> excludedWords; // hash que armazena as stop words lida do arq

    ifstream dataFile(dataFileName);
    ifstream dataFile2(dataFileName2);
    ifstream StopWordsFile(StopWords);

    if (!dataFile.is_open() || !dataFile2.is_open() || !StopWordsFile.is_open()) {
        cout << "NAO FOI POSSIVEL ABRIR OS ARQUIVOS !!! " << endl;
    }

    while (getline(dataFile, line)) { //leitura do primeiro arq
        stringstream ss(line);
        string token;
        while (ss >> token) {
            token.erase(remove_if(token.begin(), token.end(), ::ispunct), token.end());  // remove sinais de pontuação do token
            transform(token.begin(), token.end(), token.begin(), ::tolower); // transforma para letras minusculas
            token = ConverterAcentuadasParaMinusculas(token); // transforma os caracteres acentuados para minusculos
            if (!token.empty() && CaracterEstranho(token)){ // evita adicionar espaços vazios na hash e trata o travecao
                frequencia[token]++;
            }
        }
    }

    while (getline(dataFile2, line)) { //leitura do segundo arq
        stringstream ss(line);
        string token;
        while (ss >> token) {
            token.erase(remove_if(token.begin(), token.end(), ::ispunct), token.end()); 
            transform(token.begin(), token.end(), token.begin(), ::tolower); 
            token = ConverterAcentuadasParaMinusculas(token); 
            if (!token.empty() && CaracterEstranho(token)) { 
                frequencia[token]++;
            }
        }
    }
    
    while (getline(StopWordsFile, line)) { // excluindo as stop words da hash
        stringstream ss(line);
        string token;
        while (ss >> token) {
            frequencia.erase(token);
        }
    }


    for (const auto& pair : frequencia) { // preenche a heap com os primeiros k elementos da hash
        if (heap.size() < k) {
            heap.push(Item(pair.first, pair.second));
        } else if (pair.second > heap.top().frequencia) {
            heap.pop();
            heap.push(Item(pair.first, pair.second));
        }
    }

    cout << endl << "PRINTANDO OS PRIMEIROS " << k << " ELEMENTOS DA HEAP"<<endl<<endl;
    while (!heap.empty()) {
        cout << "Palavra: " << heap.top().palavra << " - Frequência: " << heap.top().frequencia << endl;
        heap.pop();
    }
}

string ConverterAcentuadasParaMinusculas(string num) {
    string maiuscula = "ÁÀÃÉÈÍÌÓÒÚÙ";
    string minuscula = "áàãéèíìóòúù";

    for (size_t i = 0; i < maiuscula.size(); i++) {
        replace(num.begin(), num.end(), maiuscula[i], minuscula[i]);
    }
    return num;
}

bool CaracterEstranho(string word) { // se o caractere estiver na lista de inválidos, retorne falso
    static unordered_set<char> invalidChars = {static_cast<char>(0xE2), static_cast<char>(0x80), static_cast<char>(0x94)}; // sequencia de bytes do travesao
    
    for (char c : word) {
        if (invalidChars.find(c) != invalidChars.end()) {
            return false; 
        }
    }
    return true;
}
