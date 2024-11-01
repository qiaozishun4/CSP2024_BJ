#include<bits/stdc++.h>
using namespace std;
string a[60];
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
    long long n,cnt=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i];
             if(a[i]==a[n]){
             cnt+=1;
             }
        }
if(cnt==0){
    ans=52-n;
}else{
    if(n==1){
   ans=52-(n+1-cnt);
    }

    ans=52-(n+1-cnt-1);
}
cout<<ans<<endl;
    return 0;
}

