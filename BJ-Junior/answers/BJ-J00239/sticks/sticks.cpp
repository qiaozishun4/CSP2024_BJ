#include<bits/stdc++.h>
using namespace std;
int f[20];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    int n;
    f[1]=-1;
    f[2]=1;
    f[3]=7;
    f[4]=4;
    f[5]=2;
    f[6]=6;
    f[7]=8;
    f[8]=10;
    f[9]=18;
    f[10]=22;
    f[11]=20;
    f[12]=28;
    f[13]=80;
    f[17]=2068;
    for(int w=1;w<=t;w++){
        cin>>n;
        if(n<=13){
            cout<<f[n];
        }
        else if(n==17){
            cout<<f[17];
        }
        else{
            if(n%7==3){
                cout<<f[17];
                for(int i=1;i<n/7-1;i++){
                    cout<<8;
                }
            }
            else{
                    cout<<f[n%7+7];
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            }
        }
        cout<<endl;
    }
    return 0;
}
