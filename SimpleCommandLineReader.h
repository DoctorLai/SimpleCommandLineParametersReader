/*
    Author: https://helloacm.com
    Free to Use, donation is appreciated:  https://helloacm.com/out/paypal
*/

#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class SimpleCommandLineReader {
public:
    SimpleCommandLineReader(int, const char**);
    SimpleCommandLineReader(int, const char**, bool);
    const string& Get(const string&) const;
    string Get(const string&, const string&) const noexcept;

private:
    const char SepChar = '=';
    map<string, string> _dict;
    bool _caseSensitive = false;
    
    void process(const string& arg);
    
    string uniformString(const string& val) const
    {
        string result(val);
        if(!_caseSensitive) {
            std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        }
        return result;
    }
};

