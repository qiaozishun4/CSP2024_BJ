#include <bits/stdc++.h>
using namespace std;
int t;
int n,num[9]={6,2,5,0,4,0,6,3,7},pos;
string ans;
int main()
{
    freopen("sticks.in","r",stdin);
    frepoen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        string ans;
        cin>>n;
        if(n==1)
        {
            cout<<-1;
            continue;
        }
        while(n)
        {
            if(pos==0)
            {
                if(n==6||n==2||n==5||n==4||n==3||n==7)
                {
                    for(int i=1;i<9;i++)
                    {
                        if(num[i]==n)
                        {
                            cout<<i;
                            n=0;
                            pos++;
                            break;
                        }
                    }
                }
                else
                {
                    ans[0]='1';
                    n-=2;
                    pos++;
                }
            }
            else
            {
                if(n==6||n==2||n==5||n==4||n==3||n==7)
                {
                    for(int i=1;i<9;i++)
                    {
                        if(num[i]==n)
                        {
                            cout<<i;
                            n=0;
                            pos++;
                            break;
                        }
                    }
                }
                else
                {
                    for(int i=0;i<9;i++)
                    {
                        if(num[i]!=0)
                        {
                            if(num[i]<n)
                            {
                                ans+=to_string(i);
                                pos++;
                                n-=num[i];
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}