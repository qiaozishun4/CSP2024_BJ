#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005],sum;
bool tmp(int a, int b)
{
    if(a>b)
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    sum=n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n+1,tmp);
    //for(int i=0;i<n;i++)
    //{
    //    cout<<a[i]<<" ";
    //}
    //cout<<endl;
    for(int i=n-1;i>=0;i--)
    {
        //cout<<"a"<<i<<"b"<<" ";
        for(int j=i+1;j<n;j++)
        {
            //cout<<a[j]<<i<<" ";
            if(a[j]<a[i])
            {
                sum--;
                break;
            }
        }
        //cout<<a[i]<<endl;
    }
    cout<<sum;
    return 0;
}
//god bless me
//duel!
