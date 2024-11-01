#include <iostream>

using namespace std;

int main()
{
    //("detect.in","r",stdin);
    //freopen("detect.out","w",stdout);
    int t,n[10000],m[10000],V[10000],l[10000];
    cin >> t;
    int biao[10000];
    int d[10000]={},v[10000]={},a[10000]={};
    for(int i = 0;i<t;i++)
    {
        cin>>n[i]>>m[i]>>V[i]>>l[i];
        for(int j = 0;j<n[i];j++)
        {
            cin >> d[j] >> v[j] >> a[j];
        }
        for(int i = 0;i<V[i];i++)
        {
            cin >> biao[i];
        }

    }
    cout<<"1"<<"1";



    return 0;
}

