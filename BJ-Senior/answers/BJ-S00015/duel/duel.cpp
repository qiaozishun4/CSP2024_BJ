#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int r[maxn],cnt[maxn];
queue<int >a;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        cnt[r[i]]++;
    }
    for(int i=1;i<=maxn;i++){
        if((cnt[i])!=0)
            a.push(cnt[i]);
    }
    while(!a.empty()){
        int s=a.front();
        a.pop();
        if(s<=a.front()){
            ans=a.front();
        }
        else{
            ans=s;
            a.front()=s;
        }
    }
    cout<<ans;
    return 0;
}
