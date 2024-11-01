#include <iostream>
using namespace std;
#define N 100005
int a[N];
int inp[N];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>inp[i];
        a[inp[i]]++;
    }
    int p=0,small=0;//is first exist.
    for(int i=1;i<N;i++)
    {
        if(p==0 && a[i])
        {
            p=1;
            small+=a[i];
            continue;
        }
        if(a[i])
        {
            if(a[i]>=small)
            {
                small=a[i];
            }
            else
            {
                ;//small=small-a[i];
            }
        }
    }
    cout<<small;
    return 0;
}
