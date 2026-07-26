class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();

        vector<int> LeftCloseR(n);
        vector<int> RightCloseL(n);

        //Move left to right to find LeftCloseR
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                LeftCloseR[i]=i;  //R pushes starts from me
            }
            else if(dominoes[i]=='.'){
               LeftCloseR[i]=i>0 ? LeftCloseR[i-1] : -1;
            }
            else{
                LeftCloseR[i]=-1;
            }
        }

         //Move right to left to find RightCloseL
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                RightCloseL[i]=i; //R pushes starts from me
            }
            else if(dominoes[i]=='.'){
               RightCloseL[i]=i<n-1 ? RightCloseL[i+1] : -1;
            }
            else{
                RightCloseL[i]=-1;
            }
        }

        string ans(n,' ');
        for(int i=0;i<n;i++){
            int distLeftR=abs(i-LeftCloseR[i]);
            int distRightL=abs(i-RightCloseL[i]);

            if(RightCloseL[i]==LeftCloseR[i]){
                ans[i]='.';
            }
            else if(RightCloseL[i]==-1){
                ans[i]='R';
            }
            else if(LeftCloseR[i]==-1){
                ans[i]='L';
            }
            else if(distLeftR==distRightL){
                ans[i]='.';
            }
            else{
                ans[i]=distRightL<distLeftR ?'L':'R';
            }
        }
        return ans;
        
    }
};