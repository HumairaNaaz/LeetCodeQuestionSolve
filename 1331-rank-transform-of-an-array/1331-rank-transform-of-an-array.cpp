class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
         vector<int> temp=arr; //copy 

        sort(temp.begin(),temp.end());
        int rank=1;
        map<int,int> mp;

        for(int x:temp){
            if(mp.find(x)==mp.end()){
                mp[x]=rank;
                rank++;
            }
        }

        for(int i=0;i<n;i++){
            arr[i]=mp[arr[i]];
        }
        return  arr;

    }
};