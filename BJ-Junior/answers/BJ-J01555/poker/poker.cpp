#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string a[10005];
bool cmp(string a,string b){return a<b;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","W",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}