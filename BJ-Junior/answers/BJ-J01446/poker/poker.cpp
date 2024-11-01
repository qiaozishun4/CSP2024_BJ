#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n,sum=0,v[100000];
    cin>>n;
    map<string,long long>t;
    string a[n+5],b[60]={"DA","CA","HA","SA","D2","C2","H2","S2","D3","C3","H3","S3","D4","C4","H4","S4",
    "D5","C5","H5","S5","D6","C6","H6","S6","D7","C7","H7","S7","D8","C8","H8","S8","D9","C9","H9","S9","DT",
    "CT","HT","ST","DJ",
"CJ","HJ","SJ","DQ","CQ","HQ","SQ","DK","CK","HK","SK"};
    for(int i=0;i<=51;i++){
        t[b[i]]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    for(int i=0;i<=51;i++){
        if(t[b[i]]>=1){
            sum++;
        }
    }
    if(sum==52)cout<<0;
    else cout<<52-sum;
    return 0;
}
