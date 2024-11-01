#include<iostream>
using namespace std;
int a[100086];
bool b[100086];//1 red 0 blue
int maxd=0;
int n;
void df(int dq,int dd)
{
    if(dq==n)
    {
        if(dd>maxd) maxd=dd;
        return;
    }
    int f1=0;
    for(int i=dq-1;i>=0;i--)
    {
        if(b[i]==0)
        {
            if(a[i]==a[dq]) f1+=a[i];
            break;
        }
    }
    b[dq]=0;
    df(dq+1,f1+dd);
    b[dq]=1;
    int f2=0;
    for(int i=dq-1;i>=0;i--)
    {
        if(b[i]==1)
        {
            if(a[i]==a[dq]) f2+=a[i];
            break;
            }
    }
    df(dq+1,f2+dd);
    return;

}
int main()
{

    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    df(0,0);
    cout<<maxd<<endl;
    }
    return 0;
}
