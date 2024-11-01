#include<bits/stdc++.h>
using namespace std;
map<string,bool> exist;
string A[4]={"D","C","H","S"},B[13]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;cin>>n;
    for(int i=0;i<4;i++)
        for(int j=0;j<13;j++)
            exist[A[i]+B[j]]=false;
    for(int i=0;i<n;i++)
    {
        string a;cin>>a;
        if(!exist[a])
        {
            exist[a]=true;
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}