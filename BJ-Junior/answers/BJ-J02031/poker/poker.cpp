#include<stdio.h>
#include<string.h>
int le2num(char a)
{
    if(a>='2'&&a<='9')return a-'0';
    if(a=='A')return 1;
    if(a=='T')return 10;
    if(a=='J')return 11;
    if(a=='Q')return 12;
    if(a=='K')return 13;
    return -1;
}
int h2num(char a)
{
    if(a=='D') return 0;
    if(a=='C') return 1;
    if(a=='H') return 2;
    if(a=='S') return 3;
    return -1;
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int tab[100];
    memset(tab,0x00,sizeof(tab));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char tmp[10];
        scanf("%s",tmp);
        int idx=h2num(tmp[0])*13+le2num(tmp[1])-1;
        tab[idx]=1;
    }
    int cnt=0;
    for(int i=0;i<52;i++)
    {
        if(tab[i]==0)
        {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
