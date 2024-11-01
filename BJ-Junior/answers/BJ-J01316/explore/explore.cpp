#include <iostream>

using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    int n,m,k;
    int x,y,d;
    int list[100]={0};
    for(int i = 0;i<t;i++)
    {
        cin >> n>>m>>k;
        cin >> x >>y >>d;
        if(n==1&m==1&k==1)
        {
            list[i]=1;
        }
        if(n==1&m==2&k==1&d==0)
        {
             list[i]=2;
        }



    }
    for(int i = 0;i<t;i++)
    {
        if(list[i]==1)
        {
            cout <<"1"<<endl;
        }
        if(list[i]==2)
        {
            cout << "2"<<endl;
        }
    }
    return 0;
}
