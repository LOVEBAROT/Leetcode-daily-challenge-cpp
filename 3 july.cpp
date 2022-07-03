//Today problem = 376. Wiggle Subsequence

class solution{
	public:
	int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1; //if n == 1 return 1.
        int total = 0;
        int pdiff = nums[1] - nums[0];  // take previous difference
        if(pdiff == 0)
            total = 1; //if previous difference is 0 then add 1 to total.
        else
            total = 2; // if previous difference is  not 0 then add 2 to total.
        for(int i = 2;i < n;i++)
        {
            int cdiff = nums[i] - nums[i-1]; //current difference
            if((pdiff >= 0 and cdiff < 0) or (pdiff <= 0 and cdiff > 0)) // check for positive or negative sequence
            {
                total++; 
                pdiff = cdiff; //make previous difference = current difference
            }
        }
        return total;
    }
};