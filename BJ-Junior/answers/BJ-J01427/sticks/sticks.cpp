#include<bits/stdc++.h>
using namespace std;
int num[15]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        bool flag=false;
        cin>>n;
        if(n==1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(int j=0;j<=9;j++)
        {
            if(num[j]==n && j!=0)
            {
                cout<<j<<endl;
                flag=true;
                break;
            }
        }
        for(int j=0;j<=9;j++)
        {
            if(num[j]<n)
            {
                for(int s0=0;s0<=9;s0++)
                {
                    for(int s1=0;s1<=9;s1++)
                    {
                        if(num[s0]+num[s1]==n && s0!=0 && !flag)
                        {
                            cout<<s0*10+s1<<endl;
                            flag=true;
                            continue;
                        }
                    }
                }
                for(int s0=0;s0<=9;s0++)
                {
                    for(int s1=0;s1<=9;s1++)
                    {
                        for(int s2=0;s2<=9;s2++)
                        {
                            if(num[s0]+num[s1]+num[s2]==n && s0!=0 && !flag)
                            {
                                cout<<s0*100+s1*10+s2<<endl;
                                flag=true;
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
