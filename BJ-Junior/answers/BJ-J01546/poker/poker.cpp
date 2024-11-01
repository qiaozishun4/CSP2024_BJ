#include<bits/stdc++.h>
using namespace std;
int n;
char s[3];
int a[100][100];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>n;
    int num=0;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(a[s[0]][s[1]]==1) continue;
        else
        {
            a[s[0]][s[1]]=1;
            num++;
        }
    }
    cout<<52-num;
}
