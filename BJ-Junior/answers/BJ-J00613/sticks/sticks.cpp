#include<iostream>
using namespace std;
const int arr[13]={6,2,5,5,4,5,6,3,7,6};
bool chch(int num,int sd)
{
    int tio=0,kl=0;
    while(num!=0)
    {
        tio=num%10;
        kl+=arr[tio];
        num/=10;
    }
    return kl==sd?true:false;
}
int main()
{
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t!=0)
    {
        int a=0;
        int sd;
        cin>>sd;
        if(sd<2)
        {
            cout<<"-1"<<endl;
        }
        while(chch(a,sd)==0)
        {
            a++;
        }
        cout<<a<<endl;
        t--;
    }
    return 0;
}