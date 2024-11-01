#include <iostream>

using namespace std;
struct node
{
    int a;
    int b;
};
node ans[100000];
int arr[100000];

void men(int x)
{
    if(arr[x]%7==0)
    {
        ans[x].a=1;
        ans[x].b=arr[x]/7;
    }
    if(arr[x]%7==1)
    {
        ans[x].a=2;
        ans[x].b=(arr[x]-15)/7;
    }
    else
    {
        ans[x].a=3;
    }
    return;
}
void shu(int x)
{
    if(ans[x].a==1)
    {
        for(int i=0;i<ans[x].b;i++)
        {
            cout<<'8';
        }
    }
    if(ans[x].a==2)
    {
        for(int i=0;i<ans[x].b;i++)
        {
            cout<<'8';
        }
        cout<<'007';
    }
    else
    {
        cout<<'-1';
    }
}


int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        men(i);
    }
    for(int i=0;i<n;i++)
    {
        shu(i);
        cout<<endl;
    }
    return 0;
}
