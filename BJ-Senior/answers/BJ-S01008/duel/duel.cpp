#include<bits/stdc++.h>
using namespace std;
int n,r,duelvhead;
vector<pair<int,bool>>v;
int mybinsearch(int l,int r,int k){
    while(l<r){
        int mid=(l+r)>>1;
        if(v[mid].first>k&&!v[mid].second)r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    freopen("duel.in","r",stdin),freopen("duel.out","w",stdout),scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&r),v.push_back({r,0});
    sort(v.begin(),v.begin()+n);
    while(duelvhead<n){
        int mbsres=mybinsearch(duelvhead+1,n-1,v[duelvhead].first);
        if(v[mbsres].second||v[mbsres].first<=v[duelvhead].first){
            bool flag=1;
            for(int i=duelvhead+1;i<n;i++)if(!v[i].second){
                flag=0,v[i].second=1;
                break;
            }
            if(flag)break;
        }else v[mbsres].second=1,duelvhead++;
    }
    cout<<n-duelvhead<<'\n';
    return 0;
}