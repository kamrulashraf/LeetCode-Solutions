public class Solution
    {
        public string LongestPalindrome(string s)
        {
            var dp = new Boolean[1005, 1005];
            string ret = "";

            for (int i = 0; i < s.Length; i++)
            {
                dp[i, i] = true;
                
                if(dp[i,i]){
                    if(ret.Length == 0){
                        ret += s[i];
                    }
                }
                if (i + 1 != s.Length)
                {
                    dp[i, i + 1] = s[i] == s[i + 1] ? true : false;
                    if(dp[i, i+1]){
                        if(ret.Length == 1){
                            ret = s.Substring(i,2);
                        }
                    }
                }
            }

            for (int i = 3; i <= s.Length; i++)
            {
                for (int j = 0; j + i <= s.Length; j++)
                {
                    int nxtIdx = j + i - 1;
                    dp[j, nxtIdx] = dp[j + 1, nxtIdx - 1] && s[j] == s[nxtIdx] ? true : false;
                    if (dp[j, nxtIdx])
                    {
                        ret = s.Substring(j, i);
                    }
                }
            }

            return ret;
        }
    }

    public class Solution1
    {
        private int start;
        private int maxLen;
        public string LongestPalindrome(string s)
        {
            InitMaxAndIndex();
            
            for(int i = 0 ; i< s.Length ; i++){
                int left, right;
                
                left = i;
                right = i+1;
                GetMaxLen(ref s, left, right, ref start, ref maxLen);
                
                left = i-1;
                right = i+1;
                GetMaxLen(ref s, left, right,ref start,ref maxLen);
            }
            
            return s.Substring(start, maxLen);
            
        }
    
        private void InitMaxAndIndex(){
            start = 0;
            maxLen = 1;
        }
    
        private void GetMaxLen(ref string s, int left, int right, ref int start, ref int maxLen){
            while(left >= 0 && right < s.Length && s[left] == s[right]){
                int len = right-left+1;
                if(len > maxLen){
                    maxLen = len;
                    start = left;
                }
                left--;
                right++;
            }
        }
    }