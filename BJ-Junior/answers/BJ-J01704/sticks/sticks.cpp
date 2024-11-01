#include<bits/stdc++.h>
using namespace std;
int t,n,a[15000],b[10]={0,1,7,4,2,0,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++) cout<<8;
            continue;
        }
        int cnt=cell(n/7);
        int sum=n-cnt*2;
        bool v=0;
        for(int i=1;i<=cnt;i++) a[i]=1;
        for(int i=cnt;i>=1&&sum>0;i--){
            if(a[i]==1&&sum==4){
                a[i]==4;
                v=1;
            }
            if(sum>=5){
                sum-=5;
                a[i]=8;
            }else{
                for(int j=1;j<=sum;j++){
                    if(a[i]==1) a[i]=7;
                    else if(a[i]==7) a[i]=4;
                    else if(a[i]==4) a[i]=2;
                    else if(a[i]==2) a[i]=0;
                    sum--;
                }
            }
        }
        if(v) cout<<1;
        for(int i=1;i<=cnt;i++) cout<<a[i];
        cout<<endl;
    }
    return 0;
}
//174208
