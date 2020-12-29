class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret;
        int len;
        string lenstr;
        /* how about string of which length of length is longger than UINT_MAX? */
        for (auto const &str : strs){
            string lenmeta(32, '0');
            lenstr = to_string(str.length());
            lenmeta.replace((32 - lenstr.length()), lenstr.length(), lenstr);
            ret += lenmeta + str;
        }
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int j=0;
        int len = s.length();
        
        vector<string> ret;
        int curlen;

        while (j < len){
            /* for each token */
            curlen = stoi(s.substr(j, 32));
            ret.push_back(s.substr(j+32, curlen));
            j += (32 + curlen);
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));