#include<bits/stdc++.h>
using namespace std;
#define int long long
int num[]={6,2,5,5,4,5,6,3,7,6};
void slv(int n){
    int cnt=0;
    if(n==1){
        cout<<"-1"<<endl;
        return;
    }
    for(int i=1;i<10;i++){
        if(num[i]==n){
            cout<<i<<endl;
            return;
        }
    }
    if(n%7==0){
        for(int i=1;i<=n/7;i++){
            cout<<"8";
        }
        cout<<endl;
        return;
    }
    int l=ceil(n*1.0/7);
    switch(n%7){
case 1:cout<<"10";
for(int i=1;i<=l-2;i++){
    cout<<"8";
}
cout<<endl;
return;
break;
case 2:
    cout<<"18";
    for(int i=1;i<=l-2;i++)cout<<"8";
    cout<<endl;
    return;
    break;
case 3:
    cout<<"22";
    for(int i=1;i<=l-2;i++)cout<<"8";
    cout<<endl;
    return;
    break;
case 4:
    cout<<"20";
    for(int i=1;i<=l-2;i++)cout<<"8";
    cout<<endl;
    return;
    break;
case 5:
    cout<<"28";
    for(int i=1;i<=l-2;i++)cout<<"8";
    cout<<endl;
    return;
    break;
case 6:
    cout<<"68";
    for(int i=1;i<=l-2;i++)cout<<"8";
    cout<<endl;
    return;
    break;
    }
}
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
   int t;
   cin>>t;
   int n;
   while(t--){
    cin>>n;
    slv(n);
   }

}
