#include <bits/stdc++.h>
using namespace std;
bool pai[4][14];
long long n,l=0,li,ans=0,i,j;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(pai,0,sizeof(pai));
    string cmp;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>cmp;
        if(cmp[1]>='A'&&cmp[1]<='Z')
        {
            if(cmp[1]=='A')l=1;
            else if(cmp[1]=='T')l=10;
            else if(cmp[1]=='J')l=11;
            else if(cmp[1]=='Q')l=12;
            else if(cmp[1]=='K')l=13;
        }
        else
            l=int(cmp[1]-48);
        if(cmp[0]=='D')li=0;
        else if(cmp[0]=='H')li=1;
        else if(cmp[0]=='C')li=2;
        else if(cmp[0]=='S')li=3;
        pai[li][l]=true;
    }
    for(i=0;i<4;++i)
        for(j=1;j<14;++j)
            if(pai[i][j]==false)ans++;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
