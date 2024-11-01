#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
int n,ans=52;
string s;
string s2[4]={"D","C","H","S"};
string s3[13]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        m[s]=1;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(m[s2[i]+s3[j]])
                ans--;
        }
    }
    cout<<ans;
    return 0;
}

