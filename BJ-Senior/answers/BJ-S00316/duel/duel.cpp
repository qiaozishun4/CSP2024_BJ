#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
queue<int> q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        q.push(a[i]);
        if(!q.empty() && a[i]>q.front()){
            q.pop();
        }
    }
    cout<<q.size()<<endl;
    return 0;
}
