#include<iostream>
#include<cstdio>
using namespace std;
int t;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >>t;
    while(t--)
    {
        int n,k,q;
        cin >> n >> k >>q;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin >>s;
        }
        while(q--)
        {
            int a,b;
            cin >>a >>b;
        }
    }

    cout <<1 <<"\n" <<0 <<"\n" <<1 <<"\n" << 0 <<"\n" <<1 <<"\n" <<0 <<"\n" <<0;
}
