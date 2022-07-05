//128. Longest Consecutive Sequence (medium)


// time complexcity = O(n).
// space complexcity = O(n) because of set.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s2(nums.begin(), nums.end());
        int longest = 0;
        for(auto x:s2)
        {
            //check if its start of sequence
            if(s2.find(x-1) == s2.end()) //check element is not present in the set then its not the start of sequence
            {
                int length = 0;
                while(s2.find(x + length) != s2.end()) //if element present in ths set then its start of sequence and length incremented by 1.
                {
                    length +=1;
                }
                longest = max(length,longest);
            }
        }     
        return longest;
    }
};