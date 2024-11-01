#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5;
int n,a[maxn],pass,j;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&(a[i]));
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        for(;j<n;j++)
        {
            if(a[j]>a[i])
            {
                pass++;
                j++;
                break;
            }
        }
        if(j==n)
        {
            break;
        }
    }
    printf("%d",n-pass);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
