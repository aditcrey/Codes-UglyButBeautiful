class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n,vector<int> (n));
        if(n==0) return ans;
        int l =0,r=n-1,t=0,b=n-1;
        int i=1;
        while(i<=n*n && l<=r && t<=b){
            for(int j=l;j<=r;j++)
            {
                ans[t][j]  = i;
                i++;
            }
            t++;
            
            for(int j=t;j<=b;j++)
            {
                ans[j][r]  = i;
                i++;
            }
            r--;
            
            if(t<=b)
            for(int j=r;j>=l;j--)
            {
                ans[b][j]  = i;
                i++;
            }
            b--;
            
            if(l<=r)
            for(int j=b;j>=t;j--)
            {
                ans[j][l]  = i;
                i++;
            }
            l++;
        }
        return ans;
    }
};
