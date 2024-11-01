#include<bits/stdc++.h>
using namespace std;
int ans,n;
char s1,s2;
bool t[100];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while (n--)
    {
        cin>>s1>>s2;
        int tmp1=0,tmp2=0;
        //判断花色
        if (s1=='S')
        {
            tmp1=13;
        }
        if (s1=='H')
        {
            tmp1=26;
        }
        if (s1=='D')
        {
            tmp1=39;
        }
        //判断点数
        if (s2=='A')
        {
            tmp2=1;
        }
        if (s2=='T')
        {
            tmp2=10;
        }
        if (s2=='J')
        {
            tmp2=11;
        }
        if (s2=='Q')
        {
            tmp2=12;
        }
        if (s2=='K')
        {
            tmp2=13;
        }
        if (s2>='2'&&s2<='9')
        {
            tmp2=s2-'0';
        }
        //将输入的字符串转化为数字并标记
        t[tmp1+tmp2]=true;
    }
    for (int i=1;i<=52;i++)
    {
        //如果当前类型的牌没有被标记，答案加一
        if (!t[i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}