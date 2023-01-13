class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0;
        if(nums1.size() < nums2.size()){
            swap(nums1, nums2);
        }
        
        int totNums = nums1.size() + nums2.size();
        if(totNums%2 == 0){
            res += searchValue(totNums/2, nums1, nums2);
            res += searchValue(totNums/2-1, nums1, nums2);
            res/= 2.0;
        }   
        else{
            res += searchValue(totNums/2, nums1, nums2);
        }
        
        
        return res;
        
    }
    
    double searchValue(int medianindx, vector<int>&nums1,vector<int>& nums2){
        for(int i = -1 ; i< (int) nums1.size() ; i++){
            int alternateValue = medianindx - i - 1;
            pair<int, bool> res = isValid(i, alternateValue, nums1, nums2);
            if(res.second){
                return res.first;
            }
        }
        
        return 0;
    }
    
    
    pair<int, bool> isValid(int index1, int index2, vector<int> &nums1, vector<int>&nums2){
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(index1 >= size1 || index2 >= size2){
            return make_pair(0, false);
        }
        
        if(index1 < 0){
            if( (size1 > 0 && nums1[0] >= nums2[index2]) || size1 == 0){
                return make_pair(nums2[index2], true);
            }
            else{
                return make_pair(0, false);
            }
            
        }
        
        if(index2 < 0){
            if( (size2 > 0 && nums2[0] >= nums1[index1]) || size2 == 0){
                return make_pair(nums1[index1], true);    
            }
            else{
                return make_pair(0, false);
            }
        }
        
        
        if(nums1[index1] <= nums2[index2]){
            if(nums1.size() - 1 == index1){
                return make_pair(nums2[index2], true);
            }
            else if(nums1[index1+1] >= nums2[index2]){
                return make_pair(nums2[index2], true);
            }
        }
        else{
            if(nums2.size()-1 == index2){
                return make_pair(nums1[index1], true);
            }
            else if(nums2[index2+1] >= nums1[index1]){
                return make_pair(nums1[index1], true);
            }
        }
        
        return make_pair(0, false);
    }
};


class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> mergeArray;
        mergeFunction(nums1, nums2, mergeArray);
        int size = mergeArray.size();
        if(size%2==0){
            return (mergeArray[size/2] + mergeArray[size/2-1]) / 2.0;
        }
        else{
            return mergeArray[size/2];
        }
    }
    
    void mergeFunction(vector<int>& nums1, vector<int>& nums2, vector<int>& mergeArray){
        int left = 0;
        int right = 0;
        while(left < nums1.size() || right < nums2.size()){
            if(left >= nums1.size()){
                mergeArray.push_back(nums2[right++]);
            }
            else if(right >= nums2.size()){
                mergeArray.push_back(nums1[left++]);
            }
            else{
                if(nums1[left] < nums2[right]){
                    mergeArray.push_back(nums1[left++]);
                }
                else{
                    mergeArray.push_back(nums2[right++]);
                }
            }
        }
    }
};


class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0){
            swap(nums1,nums2);
        }
        int target = (nums1.size() + nums2.size()) / 2 + 1;
        double res = findMedian(nums1,nums2, target);
        if( (nums1.size()+nums2.size())%2 == 0){
            res += findMedian(nums1,nums2, target-1);
            res /= 2.0;
        }

        return res;

    }




    int findMedian(vector<int>& nums1, vector<int>& nums2, int target){
        int b = 0;
        int e = nums1.size();

        int res = -1;
        while(b <= e){
            int m = (b+e)/2;
            bool right = isGoRight(nums1, nums2, m, target);
            bool left = isGoLeft(nums1, nums2, m, target);
            if(!right && !left){
                res = max( m-1 >= 0 ? nums1[m-1] : INT_MIN, target-m-1 >= 0 ? nums2[target-m-1] : INT_MIN);
                break;
            }
            else if(right){
                b = m + 1;
            }
            else{
                e = m;
            }
        }

        return res;
    }

    bool isGoRight(vector<int>& nums1, vector<int>& nums2, int takenEl, int target){
            int index = takenEl - 1;
            int index2 = target-takenEl - 1;

            int firstA, firstB;
            int secondA;

            if(index + 1 < nums1.size()){
                firstB = nums1[index+1];
            }
            else{
                firstB = INT_MAX;
            }

            if(index2 < 0){
                secondA = INT_MIN;
            }
            else{
                if(index2 < nums2.size())
                    secondA = nums2[index2];
                else
                    secondA = INT_MAX;
            }

            if(firstB < secondA){
                return true;
            }
            else{
                return false;
            }

        }

    bool isGoLeft(vector<int>& nums1, vector<int>& nums2, int takenEl, int target){
        int index = takenEl - 1;
        int index2 = target-takenEl - 1;

        int first, second;
        if(index < 0){
            first = INT_MIN;
        }
        else{
            first = nums1[index];
        }

        if(index2 + 1 < 0){
            second = INT_MIN;
        }
        else if(index2 + 1 >= nums2.size()){
            second = INT_MAX;
        }
        else{
            second  = nums2[index2+1];
        }

        if(second < first){
            return true;
        }
        else{
            return false;
        }
    }
};