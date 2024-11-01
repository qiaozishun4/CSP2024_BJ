#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[20];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    a[1]=-1;
    a[2]=1;
    a[3]=7;
    a[4]=4;
    a[5]=2;
    a[6]=6;
    a[7]=8;
    a[8]=10;
    a[9]=18;
    a[10]=22;
    a[11]=20;
    a[12]=28;
    a[13]=68;
    a[14]=88;
    a[15]=108;
    a[16]=188;
    while(t--){
        cin>>n;
        if(n<=16)cout<<a[n]<<endl;
        else{
            string s="";
            while(n>16){
                n-=7;
                s=s+'8';
            }
            cout<<a[n]<<s<<endl;
        }
    }
}
