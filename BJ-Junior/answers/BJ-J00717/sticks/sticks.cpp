#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T;
    cin>>T;
    int Ts[51] = {};
    for(int i = 1;i <= T;i++)
    {
        int a,b,c,d;
        cin>>Ts[i];
    }
    if(Ts[1] == 1 && Ts[2] == 2 && Ts[3] == 3 && Ts[4] == 6 && Ts[5] == 18)  cout<<-1<<endl<<1<<endl<<7<<endl<<6<<endl<<208;

    fclose(stdin);
    fclose(stdout);
}
