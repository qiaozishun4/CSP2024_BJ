#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    int n;
    cin>>t;
    int a[10]={6,2,5,5,4,5,6,3,7,6};
    int cnt=0;
    int fl=0;
    for(int p=1;p<=t;p++)
    {
        fl=0;
        cin>>n;
        cnt=0;
        if(n<2)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(n<=40)
        {
            int xmm=pow(10,7);
            for(long long i=1;i<=xmm;i++)
            {
                cnt=0;
                int i1=i;
                int c1;
                while(i1!=0)
                {
                    c1=i1%10;
                    cnt=cnt+a[c1];
                    i1=i1/10;
                }
                if(cnt==n)
                {
                    cout<<i<<endl;
                        break;
                }
            }
            continue;
            
        }
        else if(n%7==0)
        {
            int nb=n/7;
            for(int i=1;i<=nb;i++)
            {
                cout<<'8';
            }
            cout<<endl;
            continue;
            fl=1;
        }
        else if(n%7==1)
        {
            cout<<"10";
            int nbs=n/7-1;
            for(int i=1;i<=nbs;i++)
            {
                cout<<'8';
            }
            cout<<endl;
            continue;
            fl=1;
        }
        else if(n%5==0)
        {
            int nb2=n/5;
            for(int i=1;i<=nb2;i++)
            {
                cout<<'2';
            }
            cout<<endl;
            fl=1;
            continue;
        }
        else if(n>8)
        {
            int nbb=n/7;
            int nb1=n-(nbb*7);
            for(int i=1;i<=9;i++)
            {
                if(a[i]==nbb)
                {
                    cout<<i;
                }
            }
            for(int i=1;i<=nbb;i++)
            {
                cout<<'8';
            }
            cout<<endl;
            fl=1;
        }
        else if(fl==0)
        {
            cout<<"-1";
            cout<<endl;
        }


    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
