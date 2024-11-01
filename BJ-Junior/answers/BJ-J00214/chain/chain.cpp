#include<bits/stdc++.h>
using namespace std;
int T;
inline bool cmp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
    return a.first.first<b.first.first;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        int n,k,q,maxx=0;
        scanf("%d%d%d",&n,&k,&q);
        vector<int>v[n+5];
        for(register int i=1;i<=n;++i){
            int l;
            scanf("%d",&l);
            for(register int j=1;j<=l;++j){
                int x;
                scanf("%d",&x);
                v[i].push_back(x);
                maxx=max(maxx,x);
            }
        }
        vector<pair<int,int> >s[maxx+5];
        for(register int i=1;i<=n;++i){
            for(register int j=0;j^v[i].size();++j){
                s[v[i][j]].push_back({i,j});
            }
        }
        //
        queue<pair<int,int> >p;
        for(register int i=0;i^s[1].size();++i)p.push(s[1][i]);
        vector<pair<pair<int,int>,int> >qa;
        int maxr=0;
        for(register int i=1;i<=q;++i){
            int r,c;
            scanf("%d%d",&r,&c);
            maxr=max(maxr,r);
            qa.push_back({{r,c},i});
        }
        sort(qa.begin(),qa.end());
        int top=0;
        bitset<100010>ans;
        for(register int idx=1;idx<=maxr;++idx){
            bitset<200010>b;
            queue<pair<int,int> >q2;
            while(!p.empty()){
                int x=p.front().first,y=p.front().second;
                p.pop();
                for(int i=y+1;i<min(y+k,(int)v[x].size());++i){
                    b[v[x][i]]=1;
                    for(int j=0;j^s[v[x][i]].size();++j){
                        if(s[v[x][i]][j].first^x)q2.push(s[v[x][i]][j]);
                    }
                }
            }
            p=q2;
            while(qa[top].first.first==idx&&top^qa.size()){
                if(b[qa[top].first.second])ans[qa[top].second]=1;
                ++top;
            }
        }
        for(register int i=1;i<=q;++i)cout<<ans[i]<<"\n";
    }
    return 0;
}
