#include<bits/stdc++.h>
using namespace std;
int n,r[100001];
queue<int>q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>r[i];
    sort(r+1,r+n+1);
    q.push(r[1]);
    for(int i=2;i<=n;++i){
        int x=q.front();
        if(r[i]>x) q.pop();
        q.push(r[i]);
    }
    cout<<q.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
