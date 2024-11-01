#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    int num[50];
    int tmp=t;
    for(int i=0;i<t;i++) cin>>num[i];
    for(int i=0;i<t;i++)
    {
        if(num[i]%7==0)
        {
            for(int j=1;j<=99995;j++)
            {
                if(j==num[i])
                {
                    for(int k=0;k<j/7;k++) cout<<8;
                    cout<<endl;
                }
            }
        }
        else{
            cout<<10;
            num[i]-=8;
            while(num[i]/7>1)
{
cout<<8;
num[i]/=7;
}
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
