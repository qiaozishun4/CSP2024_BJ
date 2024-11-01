#include <bits/stdc++.h>
using namespace std;
int n,ans,k[205];
bool f[10][20];
string s;
void init() {
    k['D']=1;
    k['C']=2;
    k['H']=3;
    k['S']=4;
    k['A']=1;
    for (int i=2;i<=9;i++)
        k[i+48]=i;
    k['T']=10;
    k['J']=11;
    k['Q']=12;
    k['K']=13;
    return;
}
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    init();
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        cin>>s;
        f[k[s[0]]][k[s[1]]]=true;
    }
    for (int i=1;i<=4;i++)
        for (int j=1;j<=13;j++)
            if (!f[i][j])
                ans++;
    printf("%d",ans);
    return 0;
}
