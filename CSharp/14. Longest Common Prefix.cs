public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        Trie root = new Trie();
        int result = 0;
        foreach(var x in strs){
            result = Math.Max(result, InsertIntoTrie(x, ref root, strs.Length));
        }
        
        return strs[0].Substring(0,result);
    }
    
    private int InsertIntoTrie(string s, ref Trie root, int totalStr){
        int maxVal = 0;
        
        Trie cur = root;
        for(int i = 0 ; i < s.Length ; i++){
            int numericVal = s[i] - 'a';
            if(cur.next[numericVal] == null){
                cur.next[numericVal] = new Trie();
            }
            cur.next[numericVal].Counter++;
            
            if(cur.next[numericVal].Counter == totalStr){
                maxVal = i+1;
            }
            
            cur = cur.next[numericVal];
        }
        return maxVal;
    }
}


public class Trie
{
    public int Counter { get; set; }
    public Trie[] next;
    public Trie()
    {
        Counter = 0;
        next = new Trie[26];
    }
}