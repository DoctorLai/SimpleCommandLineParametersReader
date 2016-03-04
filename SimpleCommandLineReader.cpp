/*
    Author: https://helloacm.com
    Free to Use, donation is appreciated:  https://helloacm.com/out/paypal
*/
#include <map>
#include <vector>
#include <algorithm>
#include "SimpleCommandLineReader.h"

using namespace std;

SimpleCommandLineReader::SimpleCommandLineReader(int argc, const char** argv): SimpleCommandLineReader(argc, argv, false)  {

};

SimpleCommandLineReader::SimpleCommandLineReader(int argc, const char** argv, bool sensitive) : _caseSensitive(sensitive) {
    // argv[0] can be skipped
    for (int i = 1; i < argc; i ++) {
        process(argv[i]);
    }
};

void SimpleCommandLineReader::process(const string& arg) {
    
    auto sepPos = arg.find(SepChar);
    if(sepPos != string::npos) {
        auto key = arg.substr(0, sepPos);
        _dict[uniformString(key)] = arg.substr(sepPos + 1);
    }
}

const string& SimpleCommandLineReader::Get(const string& key) const {
    try {
        return _dict.at(uniformString(key));
    } catch (out_of_range&) {
        throw runtime_error("No such value");
    }
}

string SimpleCommandLineReader::Get(const string& key, const string& default_value) const noexcept {
    try {
        return Get(key);
    }
    catch(out_of_range&) {
        return default_value;
    }
}

