//https://leetcode.com/problems/push-dominoes/description/

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n= dominoes.length();
        vector<int> indices(n+2);
        vector<char> symbols(n+2);
        int len = 0;
        indices[len]  =-1;
        symbols[len]= 'L';
        len++;
        for(int i=0;i<n;i++){
            if(dominoes[i]!='.'){
                indices[len] = i;
                symbols[len++] = dominoes[i];
            }
        }
        symbols[len] = 'R';
        indices[len] = n;
        len++;
        for(int i=0;i<len;i++) cout<<symbols[i]<<" ";
        string ans = dominoes;
        for(int k=-1;k<len;k++){
            int i = indices[k], j = indices[k+1];
            char x = symbols[k], y = symbols[k+1];
            
            if(x==y){
                for(int a = i+1;a<j;a++)
                    ans[a] = x;
            }else if(x>y){ //i.e. R....L
                for(int a=i+1;a<j;a++)
                ans[a] = (a-i==j-a)?'.':a-i<j-a?'R':'L';
            }
            
        }
        
        return ans;
        
    }
};
