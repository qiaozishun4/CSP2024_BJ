#include<bits/stdc++.h>
using namespace std;
string a,b;
long long ans=0,n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a;
        if(a==b){
            ans++;
        }
        b=a;
    }
    cout<<52-n+ans<<endl;
    return 0;
}
