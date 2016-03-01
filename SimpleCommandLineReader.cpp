/*
    Author: https://helloacm.com
    Free to Use, donation is appreciated:  https://helloacm.com/out/paypal
*/
#include <map>
#include <vector>
#include <algorithm>
#include "SimpleCommandLineReader.h"

using namespace std;

SimpleCommandLineReader::SimpleCommandLineReader(int argc, char** argv): SimpleCommandLineReader(argc, argv, false)  {

};

SimpleCommandLineReader::SimpleCommandLineReader(int argc, char** argv, bool sensitive){
    _caseSensitive = sensitive;
    for (int i = 0; i < argc; i ++) {
        string cur(argv[i]);
        _args.push_back(cur);
    }
    process();
};

void SimpleCommandLineReader::process(void) {
    for (int i = 0; i < _args.size(); i ++) {
        string cur = _args[i];
        string key = "";
        string val = "";
        for (int j = 0; j < cur.length(); j ++) {
            if (cur[j] == SepChar) {
                key = cur.substr(0, j);
                val = cur.substr(j + 1);
                break;
            }
        }
        if (!_caseSensitive) {
            std::transform(key.begin(), key.end(), key.begin(), ::tolower);
        }
        _dict[key] = val;
    }
}

string SimpleCommandLineReader::Get(string key) {
    return Get(key, "");
}

string SimpleCommandLineReader::Get(string key, string default_value) {
    if (!_caseSensitive) {
        std::transform(key.begin(), key.end(), key.begin(), ::tolower);
    }
    if (_dict.count(key) > 0) {
        return _dict[key];
    }
    return default_value;
}

