public class Solution {
    public int StrStr(string haystack, string needle) {
        
        if(needle.Length == 0){
            return 0;
        }
        for(int i = 0 ; i< haystack.Length ; i++){
            if(haystack[i] == needle[0]){
                bool isValid = true;
                
                if(haystack.Length - i < needle.Length){
                    isValid = false;
                }
                else{
                    for(int j = 0, k = i ; j< needle.Length && k < haystack.Length ; j++, k++){
                        if(haystack[k] != needle[j]){
                            isValid = false;
                            break;
                        }
                    }  
                }
                
                
                if(isValid == true){
                    return i;
                }
            }
        }
        
        return -1;
    }
}