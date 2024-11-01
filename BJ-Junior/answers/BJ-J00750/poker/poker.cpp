#include<iostream>
#include<cstring>
using namespace std;
string a[105];
int ans=0;
int main(){
    int n,t;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
            t=0;
        cin>>a[i];
        for(int j=1;j<i;j++){
            if(a[i]==a[j]) t=1;
        }
        if(t==0) ans++;
    }
    cout<<52-ans;
return 0;
}

