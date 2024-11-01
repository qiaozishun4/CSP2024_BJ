#include<bits/stdc++.h>
using namespace std;
int a[100005];
queue<int> q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    q.push(a[1]);
    for(int i=2;i<=n;i++){
        if(a[i]>q.front()){
            q.pop();
        }
        q.push(a[i]);
    }
    cout<<q.size();
    return 0;
}
