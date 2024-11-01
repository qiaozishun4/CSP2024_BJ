#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,k,q,cnt;
struct node{
    int l,r,p;
};
struct li{
    int r,len,num;
};
vector<int> en[N],be[N];
vector<node> a;
bool bfs(int r1,int c){
    queue<li> qu;
    for(auto i:be[1]){
        qu.push({1,2,i});
    }
    //cout<<r1<<" "<<c<<endl;
    while(!qu.empty()){
        li t1=qu.front();
        qu.pop();
        if(t1.r==r1&&a[t1.num].r==c){
            return true;
        }
        //cout<<t1.r<<" "<<a[t1.num].l<<" "<<a[t1.num].r<<endl;
        for(auto i:be[a[t1.num].r]){
            if(a[i].p==a[t1.num].p){
                int tlen=t1.len+1;
                if(tlen<=k){
                    qu.push({t1.r,tlen,i});
                }
            }else{
                int tr=t1.r+1;
                if(tr<=r1){
                    qu.push({tr,t1.len,i});
                }
            }
        }
    }
    return false;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        a.clear();
        for(int i=0;i<N;i++){
            en[i].clear();
            be[i].clear();
        }
        scanf("%d%d%d",&n,&k,&q);
        cnt=0;
        for(int i=1;i<=n;i++){
            int l,t1,t2;
            scanf("%d%d",&l,&t1);
            for(int j=2;j<=l;j++){
                scanf("%d",&t2);
                a.push_back({t1,t2,i});
                be[t1].push_back(cnt);
                en[t2].push_back(cnt);
                cnt++;
                t1=t2;
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            scanf("%d%d",&r,&c);
            cout<<bfs(r,c)<<endl;
        }
    }
    return 0;
}
