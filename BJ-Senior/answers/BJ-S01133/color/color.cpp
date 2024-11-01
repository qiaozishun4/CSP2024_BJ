#include<bits/stdc++.h>
using namespace std;
struct qaq{
    int x,y;
};
int dp(qaq a[],int n,int c){
    if(n==1) return 0;
    for(int i=n-2;i>=0;i--){
        if(a[i].x==a[n-1].x){
            for(int j=i+1;j<n-1;j++) a[j].y=(!c);
            for(int j=0;j<i;j++) a[j].y=(!c);
            return(dp(a,n-1,!c)+a[n-1].x);

        }
    }
    return(dp(a,n-1,c));
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        qaq a[n];
        for(int i=0;i<n;i++){
            cin>>a[i].x;
            a[i].y=1;
        }
        cout<<dp(a,n,1)<<endl;;
    }
    return 0;
}