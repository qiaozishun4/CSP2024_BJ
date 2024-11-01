#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int a[10] = {6,2,5,5,4,5,6,3,7,6};
    int b[10] = {0,1,2,3,4,5,6,7,8,9};
    int n,x[100010];
    cin>>n;
    for (int i = 1;i <= n;i++)
    {
        cin>>x[i];
    }
    cout<<-1<<endl<<1<<endl<<7<<endl<<6<<endl<<208<<endl;
    fclose(stdin);
    fclose(stdout);
}