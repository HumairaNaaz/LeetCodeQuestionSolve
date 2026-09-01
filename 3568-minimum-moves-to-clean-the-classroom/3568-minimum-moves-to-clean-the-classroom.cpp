class Solution {
public:
    using VB=vector<bool>;
    using VVB=vector<VB>;
    using VVVB=vector<VVB>;
    using VVVVB=vector<VVVB>;
    vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};

    struct state{
        int row;
        int col;
        int energyleft;
        int collcetedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();
        int maxEnergy=energy;
        int litterBit[20][20];
        int litterCount=0;
        int startR=0;
        int startC=0;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                litterBit[r][c]=-1;

                if(classroom[r][c]=='S'){
                    startR=r;
                    startC=c;
                }
                else if(classroom[r][c]=='L'){
                  litterBit[r][c]=litterCount;
                  litterCount++;
                }
            }
        }

        int allcollected=(1<<litterCount)-1;
        if(litterCount==0) return 0;

        VVVVB visited(m,VVVB(n,VVB(maxEnergy+1,VB(1<<litterCount,false))));
        queue<state> que;
        que.push({startR,startC,maxEnergy,0});
        visited[startR][startC][maxEnergy][0]=true;

        int moves=0;

        while(!que.empty()){
            int currSize=que.size();
            while(currSize--){
                state curr=que.front();
                que.pop();

                if(curr.collcetedMask==allcollected){
                    return moves;
                }
                if(curr.energyleft==0){
                    continue;
                }

                for(auto &dir:direction){
                    int nextrow=curr.row+dir[0];
                    int nextcol=curr.col+dir[1];

                    if(nextrow<0 || nextrow>=m || nextcol<0 || nextcol>=n){
                        continue;
                    }

                    int nextMask=curr.collcetedMask;
                    char cell=classroom[nextrow][nextcol];
                    if(cell=='X'){
                        continue;
                    }
                    int nextEnergy=curr.energyleft-1;

                    if(cell=='R'){
                        nextEnergy=maxEnergy;
                    }
                    else if(cell=='L'){
                        nextMask |=(1<<litterBit[nextrow][nextcol]);
                    }
                    if(!visited[nextrow][nextcol][nextEnergy][nextMask]){
                        visited[nextrow][nextcol][nextEnergy][nextMask]=true;
                        que.push({nextrow,nextcol,nextEnergy,nextMask});
                    }
                }
            }
            moves++;
        }
        return -1;
        
    }
};