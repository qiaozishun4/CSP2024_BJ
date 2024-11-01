#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    string s;
}a[100];
bool cmp(node q,node w){
    return q.s>w.s;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s;
    }
    sort(a+1,a+n+1,cmp);
    int cnt=n;
    for(int i=1;i<=n;i++){
        if(a[i].s==a[i+1].s){
            cnt--;
        }
    }
    cout<<52-cnt;
    return 0;
}
