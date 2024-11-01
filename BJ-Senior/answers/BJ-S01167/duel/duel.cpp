#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int a[MAXN];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        if(!pq.empty() && -pq.top() < a[i]) pq.pop();
        pq.push(-a[i]);
    }
    cout<<pq.size()<<endl;
    return 0;
}