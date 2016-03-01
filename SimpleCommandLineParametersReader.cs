/*
    Author: https://helloacm.com
    Free to Use, donation is appreciated:  https://helloacm.com/out/paypal
*/
using System;
using System.Collections.Generic;

namespace CommandLineParametersReader
{
    public class SimpleCommandLineParametersReader
    {       
        private readonly char SepChar = '=';
        private string[] _args { get; }
        private Dictionary<string, string> _dict { get; }

        public bool CaseSensitive { get; set; }

        public CommandLineParametersReader(string[] args, bool isCaseSesnive = false)
        {
            if (args == null)
            {
                throw new Exception("args should not be null");
            }
            _args = args;
            CaseSensitive = isCaseSesnive;
            _dict = new Dictionary<string, string>();
            Process();            
        }

        // Process Arguments into KeyPairs
        private void Process()
        {
            foreach (var arg in _args)
            {
                var s = arg.Trim();
                var ss = s.Split(new []{ SepChar }, 2, StringSplitOptions.RemoveEmptyEntries);
                if (ss.Length <= 0) continue;
                var key = ss[0];
                if (CaseSensitive)
                {
                    key = key.ToLower();
                }
                var val = ss[1];
                _dict[key] = val;
            }
        }

        // Return the Key
        public string Get(string key)
        {
            if (CaseSensitive) { key = key.ToLower(); }
            return _dict.ContainsKey(key) ? _dict[key] : "";
        }

        // Return the Key with a default value
        public string Get(string key, string defaultvalue)
        {
            if (CaseSensitive) { key = key.ToLower();}
            return _dict.ContainsKey(key) ? _dict[key] : defaultvalue;
        }
    }
}
