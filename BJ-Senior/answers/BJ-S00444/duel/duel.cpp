#include <bits/stdc++.h>
using namespace std;
int n,r[100005],rmin=1e5+1,rmax=0;
queue <int> q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        r[t]++;
        rmin=min(rmin,t);
        rmax=max(rmax,t);
    }
    q.push(rmin);
    for(int i=rmin+1;i<=rmax;i++){
        int rcnt=r[i];
        while(q.size() && rcnt!=0){
            if(r[q.front()]==rcnt){
                r[q.front()]=0;
                rcnt=0;
                q.pop();
            }else if(r[q.front()]<rcnt){
                rcnt-=r[q.front()];
                r[q.front()]=0;
                q.pop();
            }else if(r[q.front()]>rcnt){
                r[q.front()]-=rcnt;
                rcnt=0;
            }
        }
        q.push(i);
    }
    int cnt=0;
    for(int i=rmin;i<=rmax;i++){
        cnt+=r[i];
    }
    cout<<cnt;
    return 0;
}
