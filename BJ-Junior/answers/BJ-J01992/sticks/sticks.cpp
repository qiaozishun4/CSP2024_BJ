#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
int f[7]={8,10,1,7,20,2,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>x;
        if(x==4||x==1){
            cout<<-1<<endl;
            continue;
        }
        cout<<f[x%7];
        for(int i=1;i<x/7;i++)cout<<"8";
        if(x%7!=0&&x%7!=4&&x%7!=1&&x/7>=1)cout<<"8";
        cout<<endl;
    }
    return 0;
}
