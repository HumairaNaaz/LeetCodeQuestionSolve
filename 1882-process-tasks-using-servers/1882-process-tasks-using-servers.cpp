class Solution {
public:
    typedef pair<int,int> P; //wt,idx
    typedef tuple<long,int,int> T; //finshTym,wt,idx

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();

        //free Server(wt,idx)
        priority_queue<P,vector<P>, greater<P>> freeServer;

        //Busy Serser{finishTym,wt,idx}
        priority_queue<T,vector<T>, greater<T>> busyServer;

        for(int i=0;i<n;i++){
            freeServer.push({servers[i],i});
        }

        vector<int> result(m);

        for(int i=0;i<m;i++){
            //BusyServer->Free server
            while(!busyServer.empty() && get<0>(busyServer.top())<=i){
                auto [fnshTym,wt,idx]=busyServer.top();
                busyServer.pop();
                freeServer.push({wt,idx});
            }
            if(freeServer.empty()){
                auto [fnshTym,wt,idx]=busyServer.top();
                busyServer.pop();
                result[i]=idx;
                busyServer.push({fnshTym+tasks[i],wt,idx});
            }else{
                auto [wt,idx]=freeServer.top();
                freeServer.pop();
                result[i]=idx;
                busyServer.push({i+tasks[i],wt,idx});
            }
        }
 
        return result;
    }
};