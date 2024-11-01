#include<bits/stdc++.h>
using namespace std;
int n;
int k[100005];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        if(k[i]%7!=0) flag=false;
    }
    if(flag==false){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i]/7;j++) cout<<8;
        cout<<endl;
    }
    return 0;
}
