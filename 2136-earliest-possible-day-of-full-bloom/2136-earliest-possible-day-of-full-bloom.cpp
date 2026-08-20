class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>> vec(n);

        for(int i=0;i<n;i++){ //{plantTime[i],growTime[i]}
           vec[i]={plantTime[i],growTime[i]};
        }

        //sort growtime in descending
        auto lambda = [](pair<int,int>& p1, pair<int,int>& p2){
            return p1.second>p2.second;
        };
        sort(vec.begin(),vec.end(),lambda);

        int maxBloomDay=0;
        int prevPlantDay=0;

        for(int i=0;i<n;i++){
            int currPlantDay=vec[i].first;
            int currGrowDay=vec[i].second;

            prevPlantDay +=currPlantDay;
            int currPlantBloomTime=prevPlantDay+currGrowDay;
            maxBloomDay=max(maxBloomDay,currPlantBloomTime);
        }
        return maxBloomDay;
        
    }
};