/*
    Author: https://helloacm.com
    Free to Use, donation is appreciated:  https://helloacm.com/out/paypal
*/

#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class SimpleCommandLineReader {
public:
    SimpleCommandLineReader(int, char**);
    SimpleCommandLineReader(int, char**, bool);
    string Get(string);
    string Get(string, string);

private:
    const char SepChar = '=';
    vector<string> _args;
    map<string, string> _dict;
    bool _caseSensitive = false;
    void process(void);
};

