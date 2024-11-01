#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,r[N],cnt=0,pl=0,num[N],x,y;
queue<pair<int,int> >v;
queue<int>q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(register int i=1;i<=n;i++){
        cin>>r[i];
        num[r[i]]++;
    }
    for(register int i=1;i<=1e5;i++){
        while(num[i]--){
            v.push(make_pair(i,0));
        }
    }
    for(register int i=1;i<=n;i++){
        x=v.front().first;
        y=v.front().second;
        v.pop();
        if(v.front().first>x){
            v.front().second=1;
        }
        if(!q.empty() && x>q.front() && y==0){
            q.pop();
        }
        if(x==v.front().first || i==n){
            q.push(x);
        }
    }
    cout<<q.size();
    return 0;
}
