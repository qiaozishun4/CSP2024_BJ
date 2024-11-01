#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main(){
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
long long n;
long long sum=0;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]%7==0){
        sum=1;
    }else{
        sum=0;
    }
}
for(int i=1;i<=n;i++){
if(sum==1){
        cout<<"-1"<<endl;
    }else{
        cout<<a[i]<<endl;
    }
}
    return 0;
}

