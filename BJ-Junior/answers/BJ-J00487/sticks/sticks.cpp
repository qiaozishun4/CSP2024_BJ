#include<bits/stdc++.h>
using namespace std;

long long t;
long long a[10005];



int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long ans=0;
cin>>t;
for(long long i=1;i<=t;i++){
    cin>>a[i];
    if(a[i]==2) a[i]=1;
    else if(a[i]==5) a[i]=2;
    else if(a[i]==4) a[i]=4;
    else if(a[i]==6) a[i]=6;
    else if(a[i]==3) a[i]=7;
    else if(a[i]==7) a[i]=8;
    
    else {
            cout<<"-1";
    continue;
    }
    ans=a[i];

    cout<<ans;



}
return 0;
}


