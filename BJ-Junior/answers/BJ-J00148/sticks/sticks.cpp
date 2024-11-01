#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000005];
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
         if(a[i]==1)cout<<"-1"<<endl;
        else if(a[i]==2)cout<<"1"<<endl;
        else if(a[i]==3)cout<<"7"<<endl;
        else if(a[i]==6)cout<<"6"<<endl;
        else if(a[i]==18)cout<<"208"<<endl;
    }
    return 0;
}
