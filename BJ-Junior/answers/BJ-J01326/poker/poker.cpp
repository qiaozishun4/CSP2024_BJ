#include <bits/stdc++.h>
using namespace std;

int n,t[114],temp,ans;
char a,b;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a >> b;
        temp=0;
        if(a=='C')temp+=13;
        else if(a=='H')temp+=26;
        else if(a=='S')temp+=39;
        if(b=='A')temp+=1;
        else if(b=='T')temp+=10;
        else if(b=='J')temp+=11;
        else if(b=='Q')temp+=12;
        else if(b=='K')temp+=13;
        else temp+=b-'0';
        t[temp]++;
    }
    for(int i=1;i<=52;i++)if(!t[i])ans++;

    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}