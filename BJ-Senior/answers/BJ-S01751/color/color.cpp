#include<bits/stdc++.h>
using namespace std;
int a[300001],t[1000010],cnt,n;
void f(int n){
    for(int i=1;i<=n;i++){
        t[a[i]]++;
    }
    for(int i=n;i>=1;i--){
        if(t[a[i]]>=2){
            cnt+=a[i];
            t[a[i]]--;
        }
    }
    cout<<cnt<<endl;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        memset(t,0,sizeof t);
        memset(a,0,sizeof a);
        for(int i=1;i<=m;i++){
            cin>>a[i];
        }
        f(m);
    }
    return 0;
}
