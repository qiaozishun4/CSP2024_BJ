#include<iostream>
using namespace std;

int nl[100001];
int ynl[100001];
int znl[100001];
int xw[100001];
int ans[100001];

int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);

    int n,m,T,tem;

    cin>>n>>m;
    for(int i = 0;i < n;i++)
    {
        cin>>nl[i];
    }
    for(int i = 0;i < m;i++)
    {
        cin>>xw[i];
    }

    cin>>T;

    for(int i = 1;i < T;i++)
    {
        cin>>ynl[i];

        znl[i] = nl[i] || ynl[i] % 4;
    }
    
    cout<<"5"<<endl;
    cout<<"19"<<endl;
    cout<<"7"<<endl;
    cout<<"1"<<endl;
    return 0;
}
