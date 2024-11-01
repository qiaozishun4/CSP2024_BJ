#include<bits/stdc++.h>
#include<queue>
using namespace std;
int n,m[200000];
queue <int> q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }
    sort(m+1,m+n+1);
    q.push(1);
    for(int i=2;i<=n;i++){
        if(m[q.front()]<m[i]){
            q.pop();
        }
        q.push(i);
    }
    cout<<q.size()<<endl;
    return 0;
}
