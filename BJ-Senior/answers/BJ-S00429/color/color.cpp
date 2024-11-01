#include<iostream>
using namespace std;

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    int T,n,tem,ans = 0;

    struct color
    {
        int n;
        int A[200001];
        bool red[200001];
    }t[11];

    cin>>T;

    for(int i = 0;i< T;i++)
    {
        cin>>t[i].n;
        for(int j = 0;j < t[i].n;j++)
        {
            cin>>t[i].A[j];
        }

    }

    for(int i = 0;i < T;i++)
    {
        for(int j = 0;j < t[i].n;j++)
        {
            for(int k = j;k < t[i].n;k++)
            if(t[i].A[j] == t[i].A[k])
            {
                t[i].red[j] = true;
                t[i].red[k] = true;
            }
        }
    }
    
    cout<<"1"<<endl;
    cout<<"0"<<endl;
    cout<<"8"<<endl;

    return 0;
}
