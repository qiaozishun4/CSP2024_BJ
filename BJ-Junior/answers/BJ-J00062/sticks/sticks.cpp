#include <bits/stdc++.h>
using namespace std;
char a[2][8]={{'0','0','1','7','4','2','0','8'},{'0','0','1','7','4','2','6','8'}};
string ans,s;
void f(int n,int x,int y)
{
    if(n==0)
    {
        if((ans.size()>s.size())||(ans.size()==s.size()&&ans>s)||(ans==""))
        {
            ans=s;
        }
        return;
    }
    if(y>n)return ;
    int k;
    if(x==1)k=1;
    else k=0;
    for(int i=7;i>=y;i--)
    {
        if(n<i)continue;
        s=s+a[k][i];
        f(n-i,x+1,i);
        s=s.substr(0,s.size()-1);
    }

}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ans="",s="";
        f(n,1,2);
        if(ans=="")cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}