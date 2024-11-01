#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t,n,a[8]={0,0,1,7,4,2,6,8},w,shu;
queue <int>ans;
int main(){
    freopen("sticks1.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;

    while(t--){
        cin>>n;
        if(n<2)cout<<-1<<endl;
        else if(n<=7)cout<<a[n]<<endl;
        else if(n%7==0){
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
        }
        else if(n%7==1){
            cout<<1<<0;
            for(int i=1;i<=n/7-1;i++)cout<<8;
            cout<<endl;
        }
        else{
            w=2;
            while(n>w*7){
                    w++;
            }
            while(n){
                cout<<a[n-(w-1)*7];
                n-=n-(w-1)*7;
                w--;
            }
            cout<<endl;

        }
    }
    return 0;
}


