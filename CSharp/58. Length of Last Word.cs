public class Solution {
    public int LengthOfLastWord(string s) {
        s = s.Trim();
        int index = s.LastIndexOf(' ');
        return s.Length - index-1;
    }
}