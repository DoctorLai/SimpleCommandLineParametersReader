# SimpleCommandLineParametersReader
A Very Simple C#/C++ Command Line Parameters Reader

# How to Use (C#)?
    var param = new SimpleCommandLineParametersReader(args);
    var input = param.Get("Input");  // suppose you have command line parameter "Input=InputFile"

# How to Use (C++)?
    int main(int argc, char** argv) {
        SimpleCommandLineReader param(argc, argv);
        cout << param.Get("key1") << endl;
        cout << param.Get("key2", "default_value_key2") << endl;
        cout << param.Get("key3", "default_value_key3") << endl;
        return 0;
    }
    
Just remember, less is more!
