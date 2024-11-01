#include<bits/stdc++.h>
using namespace std;
int n,s,x,y,z;
int sz[100005];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sz[i];
    }
    sort(sz+1,sz+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(sz[i]>sz[i-1]){
            z=max(x,y);
            y=x;
            x=0;
        }
        x++;
    }
    cout<<max(x,y);
    return 0;
}
