#include <bits/stdc++.h>
using namespace std;
char a[200];
char k[4][100];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    n*=2;
    for(int i=1;i<=n;i+=2)
    {
        scanf("%s",&a[i]);
    }
    //printf("%s\n",a[1]);
    int s=0;
    for(int i=1;i<=n;i+=2)
    {
        //printf("xun %d\n",i);
        if(a[i]=='D')
        {
            //printf("k[1][%d]\n",a[i+1]);
            if(k[1][a[i+1]]==0)
            {
                k[1][a[i+1]]=1;
                s++;
                //printf("s=%d\n",s);
            }
        }
        else if(a[i]=='C')
        {
            //printf("k[2][%d]\n",a[i+1]);
            if(k[2][a[i+1]]==0)
            {
                k[2][a[i+1]]=1;
                s++;
                //printf("s=%d\n",s);
            }
        }
        else if(a[i]=='H')
        {
            //printf("k[3][%d]\n",a[i+1]);
            if(k[3][a[i+1]]==0)
            {
                k[3][a[i+1]]=1;
                s++;
                //printf("s=%d\n",s);
            }
        }
        else if(a[i]=='S')
        {
            //printf("k[4][%d]\n",a[i+1]);
            if(k[4][a[i+1]]==0)
            {
                k[4][a[i+1]]=1;
                s++;
                //printf("s=%d\n",s);
            }
        }
    }
    s=52-s;
    printf("%d",s);
}
