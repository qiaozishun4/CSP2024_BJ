#include<bits/stdc++.h>
using namespace std;
string s[55],s1[55]={"0","DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DQ","DK","CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CQ","CK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HQ","HK","SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SQ","SK"};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,i,j,ans=52;
    bool f=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
        for(j=1;j<=52;j++)
        {
            if(s[i]==s1[j])
            {
               f=1;
               s1[j]="0";
               break;
            }
        }
        if(f==1)
        {
            f=0;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
