#include <bits/stdc++.h>
using namespace std;
int x[15]={0,-1,1,7,4,2,6,8,10,0,23,20};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==1||n==0){cout<<-1<<endl;continue;}
        else{
            int k = (n+5)%7+2;
            if((k==3||k==4)&&n>4)
                k+=7;
            if(k==10&&n>10){k+=7;cout<<200;}
            else cout<<x[k];
            n-=k;
            for(int i = 1;i<=n/7;i++)
                cout<<8;
            cout<<endl;
        }
    }
}
