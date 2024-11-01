#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM
int t,n;
int st[15]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
void work(){
    int d=n%7+7;
    if(d==7)d=14;
    if(n<=7){
        cout<<st[n]<<endl;
        return ;
    }
    cout<<st[d];
    for(int i=1;i<=(n-1)/7-1;i++)cout<<8;
    cout<<endl;
    return ;
}
void init(){
    cin>>t;
    while(t--){
        cin>>n;
        work();
    }
    return ;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    init();
    return 0;
}