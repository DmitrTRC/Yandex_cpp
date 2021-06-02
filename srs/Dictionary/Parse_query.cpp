//
// Created by Dmitry Morozov on 1/6/21.
//

// TODO Technical task.
/*Задание
        Вернитесь к алгоритму поиска, который обсуждался в начале урока, и который так и не был закончен из-за размышлений о подходящем контейнере.
Возьмите слово из списка поиска и проверьте, что это не стоп-слово.
Если это не стоп-слово, найдите информацию о том, в каких документах оно встречается. Вы уже знаете, что это будет множество из ID.
Добавьте найденные документы в результат поиска.
Напишите реализацию поиска по базе данных. Сигнатура функции поиска должна выглядеть так:
vector<int> FindDocuments(const map<string, set<int>>& word_to_documents,
                          const set<string>& stop_words,
                          const string& query) {
    // напишите тут код функции
}
Требования
        Разные слова могут встречаться в одних и тех же документах. Верните результат поиска без повторов. Не меняйте сигнатуру FindDocuments.
Пример использования
int main() {
    cout << "Stop words : "s;
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read documents
    map<string, set<int>> word_to_documents;
    cout << "Number of documents to add : "s;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        cout << document_id << " : "s;
        AddDocument(word_to_documents, stop_words, document_id, ReadLine());
    }

    cout << "Search request : "s;
    const string query = ReadLine();
    cout << "Search results : "s;
    for (const int document_id : FindDocuments(word_to_documents, stop_words, query)) {
        cout << document_id << ' ';
    }
    cout << endl;
}
Пример ввода с клавиатуры
Stop-words : a the on cat
Number of documents to add : 4
0 : a fat cat sat on a mat and ate a fat rat
1 : little funny fluffy cat
2 : the cat
3 : huge green crocodile
        Search request : funny fat cat
        Пример вывода
        Search results : 0 1
        */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    string s;
    getline(cin, s);
    // функция stoi переводит строку в число типа int
    int result = stoi(s);
    return result;
}

vector<string> SplitIntoWords(const string &text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);

    return words;
}

set<string> ParseStopWords(const string &text) {
    set<string> stop_words;
    for (const string &word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string &text, const set<string> &stop_words) {
    vector<string> words;
    // проходим по всем словам из текста и проверяем, что их нет в списке стоп-слов
    for (const string &word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    // вернём результат без стоп-слов
    return words;
}

void AddDocument(map<string, set<int>> &word_to_documents,
                 const set<string> &stop_words,
                 int document_id,
                 const string &document) {
    // пройдём по всем словам (без стоп-слов) и добавим их в базу данных
    for (const string &word : SplitIntoWordsNoStop(document, stop_words)) {
        word_to_documents[word].insert(document_id);
    }
}

vector<int> FindDocuments(const map<string, set<int>> &word_to_documents,
                          const set<string> &stop_words,
                          const string &query) {
    // напишите тут код функции
}

int main() {
    cout << "Stop words : "s;
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read documents
    map<string, set<int>> word_to_documents;
    cout << "Number of documents to add : "s;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        cout << document_id << " : "s;
        AddDocument(word_to_documents, stop_words, document_id, ReadLine());
    }

    cout << "Search request : "s;
    const string query = ReadLine();
    cout << "Search results : "s;
    for (const int document_id : FindDocuments(word_to_documents, stop_words, query)) {
        cout << document_id << ' ';
    }
    cout << endl;
}