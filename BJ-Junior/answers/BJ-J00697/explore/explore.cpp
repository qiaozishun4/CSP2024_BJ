#include<bits/stdc++.h>
namespace std;
int main()
{
    int n,a[100];
    cin>>n;
    for(int i = 1;i <= n ;i++)
    {
        cin>>a[i];
        if(a[i]=7)
        {
            cout<<"8";
        }
        if(a[i]=5)
        {
            cout<<"2";
        }
        if(a[i]=4)
        {
            cout<<"4";
        }
        if(a[i]=6)
        {
            cout<<"6";
        }
        if(a[i]!=6||a[i]!=4||a[i]!=5||a[i]=7||a[i]-7-6-5-4!=0||a[i]-7-6-5!=0||a[i]-7-6-4!=0||a[i]-7-5-4!=0||a[i]-7-6!=0||a[i]-7-5!=0||a[i]-7-4!=0)
        {   
            cout<<"-1";
        }
        if(a[i]-6!=0||a[i]-6-4!=0||a[i]-6-5!=0||a[i]-5-4!=0||a[i]-5!=0||a[i]-4!=0||a[i]-7!=0)
        {
            cout<<"-1";
        }
        
    }
    return 0;
}
