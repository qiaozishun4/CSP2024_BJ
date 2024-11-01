#include<bits/stdc++.h>
using namespace std;
int n,ans,maxx=0,cnt=1;
int a[200005];
int b[200005];
int c[200005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
        maxx=max(maxx,a[i]);
    }
    for(int i=1;i<=maxx;i++){
        if(b[i]!=0){
            c[cnt]=b[i];
            cnt++;
        }
    }
    cnt=cnt-1;
    maxx=0;
    for(int i=1;i<=cnt;i++){
        maxx=max(maxx,c[i]);
    }
    cout<<maxx<<endl;
    return 0;
}
