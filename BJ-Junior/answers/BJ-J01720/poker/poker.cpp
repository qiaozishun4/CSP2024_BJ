#include <bits/stdc++.h>
#define int long long
using namespace std;
int abc[101];
int d[100001],c[100001],h[100001],s[100001];
signed main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    abc['A']=1;
    abc['2']=2;
    abc['3']=3;
    abc['4']=4;
    abc['5']=5;
    abc['6']=6;
    abc['7']=7;
    abc['8']=8;
    abc['9']=9;
    abc['T']=10;
    abc['J']=11;
    abc['Q']=12;
    abc['K']=13;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        if(a[0]=='D'){
            d[abc[a[1]]]=1;
        }else if(a[0]=='C'){
            c[abc[a[1]]]=1;
        }else if(a[0]=='H'){
            h[abc[a[1]]]=1;
        }else {
            s[abc[a[1]]]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=13;i++){
        if(!d[i]) ans++;
        if(!c[i]) ans++;
        if(!h[i]) ans++;
        if(!s[i]) ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
