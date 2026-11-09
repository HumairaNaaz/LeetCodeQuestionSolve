class Solution {
public:
    typedef pair<int,int> p; //{finishTym,serverId}
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_server;
        for(int i=0;i<k;i++){
            available_server.insert(i); 
        }

        priority_queue<p,vector<p>, greater<p>> busyServer;

        vector<int> cntReq(k,0);

        //Total Req=n
         for(int i=0;i<arrival.size();i++){
            int time=arrival[i];

            while(!busyServer.empty() && busyServer.top().first <=time){
                int server=busyServer.top().second;

                busyServer.pop();
                available_server.insert(server);

            }
            int target=i%k;
            auto it=available_server.lower_bound(target);

            if(it==available_server.end()){
                it=available_server.begin();
            }
            if(available_server.empty()){
                continue; //np server avail ,drop the current req
            }

            int targetServer=*it;
            available_server.erase(it);

            busyServer.push({time+load[i],targetServer});
            cntReq[targetServer]++;
         }
         int maxNoOfReq=*max_element(begin(cntReq),end(cntReq));
         vector<int> result;

         for(int i=0;i<k;i++){
            if(cntReq[i]==maxNoOfReq){
                result.push_back(i);
            }
         }
         return result;      
    }
};