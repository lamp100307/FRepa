#ifndef UNTITLED_INTERPRETATOR_H
#define UNTITLED_INTERPRETATOR_H

#include<iostream>
#include<string>
#include <map>
using namespace std;

class interpretator {
protected:
    static map<string, string> variables;

    static void execute(const string &command);

public:
    static void start(const string &file);

    static bool is_doc;
    static bool is_if;
};
#endif //UNTITLED_INTERPRETATOR_H
