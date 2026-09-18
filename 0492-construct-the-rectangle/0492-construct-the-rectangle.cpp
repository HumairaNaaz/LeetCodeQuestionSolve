class Solution {
public:
    vector<int> constructRectangle(int area) {
       for(int W=sqrt(area);W>=1;W--){
        if(area%W==0){
            int L=area/W;
            return {L,W};
        }
       }

        return {};
        
    }
};