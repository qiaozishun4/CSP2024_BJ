#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    int ao[100000];
    scanf("%d",&n);
    int add=n;
    for(int i=0;i<n;i++)
    {
        cin>>ao[i];
    }
    for(int i=0;i<n;i++)
    {
        int bit=0;
        for(int j=0;j<n;j++)
        {
            if(ao[j]<ao[i])
            {
                bit=ao[i];
                ao[i]=ao[j];
                ao[j]=bit;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(ao[n/2]>ao[i])
        {
            add--;
        }
        if(ao[n/2]<ao[i])
        {
            add--;
        }
    }
    printf("%d",add);
    return 0;
}
