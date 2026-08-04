class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minElement= *min_element(nums.begin(),nums.end());
        int maxElement= *max_element(nums.begin(),nums.end());

        unordered_set<int> st(nums.begin(),nums.end());

        vector<int> missingElement;

        for(int i=minElement;i<=maxElement;i++){
          
           if(st.find(i)==st.end()){
              missingElement.push_back(i);
           }
        }   
        return missingElement;     
    }
};