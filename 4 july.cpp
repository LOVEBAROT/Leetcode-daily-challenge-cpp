// 135. Candy (Hard)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int MinCandy = 0;
        vector <int>TotCandy(n,1);
        for(int i=1;i<n;i++)
        {
             if(ratings[i]>ratings[i-1])
			    TotCandy[i]=TotCandy[i-1]+1;
        }
        for(int i=n-1;i>0;i--)
        {
             if(ratings[i-1]>ratings[i])
			    TotCandy[i-1]=max(TotCandy[i]+1,TotCandy[i-1]);
        }
        for(int i=0;i < n;i++)
        {
            MinCandy += TotCandy[i];
        }
        return MinCandy;
    }
};