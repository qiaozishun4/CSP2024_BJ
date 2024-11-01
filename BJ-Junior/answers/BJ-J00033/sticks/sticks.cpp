#include<bits/stdc++.h>
using namespace std;
int t,n,a[]={6,2,5,5,4,5,6,3,7,6},b[100010];
int main(){
   freopen("sticks.in","r",stdin);
   freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        memset(b,0,sizeof(b));
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            continue;
        }
        if(n%7==1){
            cout<<10;
            for(int i=2;i<=n/7;i++) cout<<8;
            continue;
        }
        int m=n/7;
        int y=n%7;
        for(int i=1;i<=9;i++){
            if(a[i]>=y&&a[i]<=n){
                cout<<i;
                n-=a[i];
                break;
            }
        }
        if(n==0){
            cout<<endl;
            continue;
        }
        //cout<<1;
        int o=n/m,cnt;
        int p=n%m;
        for(int i=0;i<=9;i++){
            if(a[i]==o){
                for(int j=1;j<=m;j++){
                    b[j]=i;
                }
                cnt=a[i];
                break;
            }
        }
        int e=p/(7-cnt);
        for(int i=1;i<=e-1;i++){
            b[m-i+1]=7;
            p-=(7-cnt);
        }
        for(int i=0;i<=9;i++){
            if(a[i]==cnt+p)
            b[m-e+1]=i;
        }
        //cout<<1;
        for(int i=1;i<=m;i++) cout<<b[i];
        cout<<endl;
    }
   fclose(stdin);
   fclose(stdout);
    return 0;
}

