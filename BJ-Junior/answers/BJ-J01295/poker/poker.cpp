#include <bits/stdc++.h>
using namespace std;
short n,card_num,sum;
char cc[60],cp[60];
int main(){freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>cc[i]>>cp[i];
    card_num=n;
    for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)if(cp[i]==cp[j]&&cc[i]==cc[j])card_num--;
    sum=52-card_num;
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;}