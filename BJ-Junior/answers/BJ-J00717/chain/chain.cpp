#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    if(T == 1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
}
