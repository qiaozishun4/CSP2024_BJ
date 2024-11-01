#include<iostream>
using namespace std;

int R[100005];
int nR[100005];

void sort(int l,int r)
{
    if(l==r)return;

    int m=(l+r)/2;
    sort(l,m);
    sort(m+1,r);

    int n=l,l2=l,l3=(l+r)/2+1;

    while(1)
    {
        if((R[l2]<R[l3]||l3>r)&&l2<=m)
        {
            nR[n]=R[l2];
            n++;
            l2++;
        }
        else if(l3<=r)
        {
            nR[n]=R[l3];
            n++;
            l3++;
        }
        else break;
    }

    for(int i=l;i<=r;i++)
    {
        R[i]=nR[i];
    }
    return;
}

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n;
    cin>>n;

    R[0]=0;

    for(int i=1;i<=n;i++)
    {
        cin>>R[i];
    }

    sort(1,n);

    int first=1;
    int ans=n;

    for(int i=1;i<=n;i++)
    {
        if(R[i]>R[first])
        {
            first++;
            ans--;
        }
    }

    cout<<ans;

    return 0;
}
