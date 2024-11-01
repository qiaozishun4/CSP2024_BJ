#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string pok[60]={"114514","DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
bool vis[60];
int ans=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        for(int j=1;j<=53;j++)
        {
            if(a==pok[j]&&vis[j]==0)
            {
                ans++;
                vis[j]=1;
            }
        }
    }
    cout<<52-ans;
    return 0;
}
