#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        vector<char> ans;
        cin>>n;
        int h=n;







        if(n==2)
        {
            ans.push_back('1');;
            n-=2;
        }
        else if(n==3)
        {
            ans.push_back('7');;
            n-=3;
        }
        else if(n==4)
        {
            ans.push_back('4');;
            n-=4;
        }
        else if(n==6)
        {
            ans.push_back('6');;
            n-=6;
        }
        else if(n-5>=0)
        {
            ans.push_back('2');;
            n-=5;
        }
        while(n-6>=0 && n!=7 && n/7==n/6)
        {
            if(n/7.0==n/6.0 && n%7<n%6) break;
            ans.push_back('0');;
            n-=6;
        }
        while(n-7>=0  )
        {

            ans.push_back('8');;
            n-=7;
        }

        if(n==1)
        {
            cout<<"-1\n";
            continue;
        }

        else
        {
            if(n==2) ans.push_back('1');
            if(n==3) ans.push_back('7');
            if(n==4) ans.push_back('4');
            if(n==6) ans.push_back('0');
            if(n==5) ans.push_back('2');
            if(n==7) ans.push_back('8');
        }
        for(int i=0; i<ans.size(); i++) cout<<ans[i];
        puts("");
        for(int i=1; i<ans.size(); i++)
        {
            for(int j=i-1; j>0; j--)
            {
                if(ans[j]>ans[j+1]) swap(ans[j],ans[j+1]);
            }
        }
        for(int i=0; i<ans.size(); i++) cout<<ans[i];
        puts("");
    }

    return 0;
}
