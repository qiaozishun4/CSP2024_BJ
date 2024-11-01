
#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int a[1000001];
        a[1]=-1,a[2]=1,a[3]=7,a[4]=4,a[5]=2,a[6]=6,a[7]=8,a[8]=16,a[9]=18,a[10]=46;
        a[11]=26,a[12]=28,a[13]=56 ,a[14]=88 ,a[15]=156,a[16]=188,a[17]=1156,a[18]=208;
        if(n%7==0){
            int t=n/=7;
            for(int i=1;i<=t;i++){
                cout<<8;
            }
            cout<<endl;
        }else if((n-1)%7==0&&n!=1){
            int t=(n-1)/7-1;
            cout<<16;
            for(int i=1;i<=t;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n<=18){
            cout<<a[n]<<endl;
        }else cout<<-1<<endl;
    }



return 0;
}
