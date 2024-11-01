#include<bits/stdc++.h>
using namespace std;
int poker[100][100];//poker[花色][点数];
int main()
{
    int ans=0;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char flower,number;
        cin>>flower>>number;
        poker[flower][number]++;
    }
    for(int i=1;i<=4;i++)
    {
        char flower;
        switch(i)
        {
            case 1:flower='D';break;
            case 2:flower='C';break;
            case 3:flower='H';break;
            case 4:flower='S';break;
        }
        for(char c='2';c<='9';c++)
        {
            if(poker[flower][c]==0)ans++;
        }
        if(poker[flower]['A']==0)ans++;
        if(poker[flower]['T']==0)ans++;
        if(poker[flower]['J']==0)ans++;
        if(poker[flower]['Q']==0)ans++;
        if(poker[flower]['K']==0)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
