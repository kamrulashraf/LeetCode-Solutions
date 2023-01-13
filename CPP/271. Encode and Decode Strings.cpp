class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for(auto &x : strs){
            res += to_string(x.size()) + '#';
            res += x;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        string count, temp;
        int i = 0;
        for(int i = 0 ; i< s.size() ; i++){
            if(s[i] == '#'){
                int tot = stoi(count);
                i++;
                for(int j = 0 ; j< tot ; j++){
                    int idx = i+j;
                    temp += s[idx];
                }

                res.push_back(temp);
                count.clear();
                temp.clear();
                i = i+tot-1;
                continue;
            }
            count += s[i];
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));