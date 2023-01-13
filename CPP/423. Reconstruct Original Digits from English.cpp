class Solution {
public:
    string originalDigits(string s) {
        vector < pair<int , string> >  numbers;
        numbers.push_back(make_pair(0, "zero"));
        numbers.push_back(make_pair(2, "two"));
        numbers.push_back(make_pair(4, "four"));
        numbers.push_back(make_pair(6, "six"));
        numbers.push_back(make_pair(7, "seven"));
        numbers.push_back(make_pair(8, "eight"));
        numbers.push_back(make_pair(1, "one"));
        numbers.push_back(make_pair(3, "three"));
        numbers.push_back(make_pair(5, "five"));
        numbers.push_back(make_pair(9, "nine"));
        
        map<char, int> counter;
        map <int, int> resCount;
        for(int i = 0 ; i< s.size() ; i++){
            counter[s[i]]++;
        }
        
        for(int i = 0 ; i< numbers.size() ; i++){
            int minValue = 999999;
            for(int j = 0 ; j< numbers[i].second.size() ; j++){
                minValue = min(minValue, counter[numbers[i].second[j]]);
            }
            
            for(int j = 0 ;j < numbers[i].second.size() ; j++){
                counter[numbers[i].second[j]] -= minValue;
            }
            resCount[numbers[i].first] = minValue;
        }
        
        string result;
        for(int i = 0 ; i <= 9 ; i++){
            for(int j = 0 ;j < resCount[i] ; j++){
                result += (char) (i+48);
            }
        }
        
        return result;

    }
};