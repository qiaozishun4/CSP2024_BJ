#include <bits/stdc++.h>
using namespace std;
int a[]={88,10,18,22,20,28,68};
int b[]={14,8, 9, 10,11,12,13};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n==1) cout<<"-1"<<endl;
        else if(n==2) cout<<"1"<<endl;
        else if(n==3) cout<<"7"<<endl;
        else if(n==4) cout<<"4"<<endl;
        else if(n==5) cout<<"2"<<endl;
        else if(n==6) cout<<"6"<<endl;
        else if(n==7) cout<<"8"<<endl;
        else if(n%7==0&&n>=100)
        {
            for(int i=1;i<=n/7;i++) cout<<"8";
            cout<<endl;
        }
        else{
            int x=(n-7)%7;
            n-=b[x];
            if(x==3&&n>=6)
            {
                cout<<a[x]/10<<"00";
                n-=6;
            }
            else cout<<a[x];
            for(int i=1;i<=n/7;i++) cout<<"8";
            cout<<endl;
        }
    }
    return 0;
}
