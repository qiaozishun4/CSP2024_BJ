#include<bits/stdc++.h>
using namespace std;

queue<int>q;
int a[100001];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    q.push(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]>q.front())q.pop();
        q.push(a[i]);
    }
    cout<<q.size()<<endl;
    return 0;
}
