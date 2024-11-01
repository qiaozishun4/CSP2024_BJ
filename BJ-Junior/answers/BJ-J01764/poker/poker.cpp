#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt;
string s[100010];
string q[101]={"SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK","DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK"};
bool mp[100010];
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<52;j++){
            if(s[i]==q[j]){
                mp[j]=1;
            }
        }
    }
    for(int i=0;i<52;i++){
        if(!mp[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
