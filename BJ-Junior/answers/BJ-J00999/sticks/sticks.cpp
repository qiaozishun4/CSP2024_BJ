#include<bits/stdc++.h>
using namespace std;
int a[11]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        int sh=n/7+1;
        int cnt=0;
        while(sh--)
        {
            for(int i=0;i<=9;i++)
            {
                if(cnt==0&&i==0) continue;
                if(n-a[i]>=0&&n-a[i]<=7*sh)
                {
                    printf("%d",i);
                    n-=a[i];
                    break;
                }
            }
            cnt++;
        }
        //if(n!=0) cout<<"  WTF is that?!";
        cout<<endl;
    }
    return 0;
}
