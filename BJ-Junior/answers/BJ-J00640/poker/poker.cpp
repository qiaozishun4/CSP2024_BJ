#include <bits/stdc++.h>
using namespace std;
set<string> a;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        a.insert(s);
    }
    int cnt=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            string s;
            if(i==1)//DCHS
                s+="D";
            else if(i==2)
                s+="C";
            else if(i==3)
                s+="H";
            else
                s+="S";
            if(j==1)
                s+="A";
            else if(j>1&&j<10)
                s+=(j+'0');
            else if(j==10)
                s+="T";
            else if(j==11)
                s+="J";
            else if(j==12)
                s+="Q";
            else
                s+="K";
            if(!a.count(s))
                cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
