#include "interpretator.h"
#include "interLibrary/documentation.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

map<string, string> interpretator::variables;
bool interpretator::is_doc = false;
bool interpretator::is_if = false;
string commands[3]{"console", "var", "println"};

void interpretator::execute(const string &command) {
    documentation::execute_documentation(command);
    setlocale(LC_ALL, "ru");
    if (interpretator::is_doc == true) {
    } else if (command.starts_with("console")) {
        const string second = command.substr(command.find('.'), command.length());
        const string word = second.substr(1, second.find('(') - 1);
        if (word == "out") {
            const string var = second.substr(second.find('(') + 1, second.find(')') - 5);
            const string text = second.substr(second.find('(') + 2, second.find(')') - 7);
            if (variables.find(var) != variables.end()) {
                cout << variables[var] << endl;
            } else {
                cout << text << endl;
            }
        } else if (word == "eout") {
            const string var = second.substr(second.find('(') + 1, second.find(')') - 6);
            const string text = second.substr(second.find('(') + 2, second.find(')') - 8);
            if (variables.find(var) != variables.end()) {
                cerr << variables[var] << endl;
            } else {
                cerr << text << endl;
            }
        } else if (word == "newline") {
            cout << endl;
        } else {
            cout << "Invalid Command: " << word << endl;
        }
    } else if (command.starts_with("var")) {
        const size_t twoPoints = command.find(':');
        const size_t equal = command.find('=');
        const string type = command.substr(4, twoPoints - 4);
        string name = command.substr(twoPoints + 2, equal - 10);
        string value = command.substr(equal + 2, command.length());
        if (type == "int") {
            if (isdigit(value[0])) {
                variables[name] = value;
            } else {
                cerr << "non int type: " << name << " = " << value << endl;
            }
        } else if (type == "float") {
            if (isdigit(value[0])) {
                variables[name] = value;
            } else {
                cerr << "non float type: " << name << " = " << value << endl;
            }
        } else if (type == "string") {
            if (command.find('"') != command.npos) {
                name = command.substr(twoPoints + 2, equal - 12);
                variables[name] = command.substr(command.find('"'), command.length());
            } else {
                cerr << "non string type: " << name << " = " << value << endl;
            }
        } else if (type == "bool") {
            if (value == "true" or value == "false") {
                variables[name] = value;
            } else {
                cerr << "non bool type: " << name << " = " << value << endl;
            }
        } else if (type == "input") {
            if (command.find('"') != command.npos) {
                name = command.substr(twoPoints + 2, equal - 12);
                cout << command.substr(command.find('"') + 1, command.length() - 20);
                getline(std::cin, value);
                if (value.empty()) {
                    cerr << "wrong input" << endl;
                } else {
                    variables[name] = value;
                }
            } else {
                name = command.substr(twoPoints + 2, equal - 12);
                getline(std::cin, value);
                if (value.empty()) {
                    cerr << "wrong input" << endl;
                } else {
                    variables[name] = value;
                }
            }
        }
    } else if (command.starts_with("println")) {
        string text = command.substr(9, command[-1] + 4);
        cout << text << endl;
    } else if (command.starts_with("") or command.starts_with("//")) {
    } else {
        cout << "command not execute {}", command;
    }
}

void interpretator::start(const string &file) {
    ifstream files;
    files.open(file);
    if (files.is_open()) {
        string line;
        while (getline(files, line)) {
            execute(line);
        }
        files.close();
    } else {
        cerr << "Не удалось открыть файл: " << file << endl;
    }
}
