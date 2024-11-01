#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n,m,a[100005],c[100005];
    cin>>n>>m;
    int cnt=0;
    for(int i = 0 ; i <n ; i++)
    {
        cin>>a[i];
        cnt+=a[i];
    }
    for(int j = 0 ; j < m ; j++)
    {
        cin>>c[j];
    }
    int T;
    int kx=1,k=0;
    while(k<n)
    {
        k++;
        kx*=2;
    }
    int g[20][20];
    for(int i = 0 ; i < k ; i++)
    {
        for(int j = 0 ; j < pow(2,k-j) ; j++)
        {
            cin>>g[i][j];
        }
    }
    cin>>T;
    int x0,x1,x2,x3;
    while(T--)
    {
        cin>>x0>>x1>>x2>>x3;
        srand(time(0));
        cout<<rand()%cnt;
    }
    return 0;
}
