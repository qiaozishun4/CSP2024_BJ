#include <bits/stdc++.h>
using namespace std;
int sticks;
string num="";
/*
*/
int sticks_num[10] = {6,2,5,5,4,5,6,3,7,6};
bool dfs(int n,string num1)
{
    if ((n<2&&n!=0)||num1[0]=='0') return 0;
    if (n==0) return 1;
    if (n>=6)
    {
        if (dfs(n-6,num1+'0')&&num1[0]!='0')
        {
            sticks -= 6;
            num += '0';
            if (sticks>=2||sticks==0) return 1;
        }
        else if (dfs(n-6,num1+'6'))
        {
            sticks -= 6;
            num += '6';
            if (sticks>=2||sticks==0) return 1;
        }
    }
    if (n>=5&&dfs(n-5,num1+'2'))
    {
        sticks -= 5;
        num += '2';
            if (sticks>=2||sticks==0) return 1;
    }
    if (n>=7&&dfs(n-7,num1+'8'))
    {
        sticks -= 7;
        num += '8';
            if (sticks>=2||sticks==0) return 1;
    }
    if (n>=4&&dfs(n-7,num1+'4'))
    {
        sticks -= 4;
        num += '4';
            if (sticks>=2||sticks==0) return 1;
    }
    if (n>=3&&dfs(n-3,num1+'7'))
    {
        sticks -= 3;
        num += '7';
            if (sticks>=2||sticks==0) return 1;
    }
    if (n>=2&&dfs(n-2,num1+'1'))
    {
        sticks -= 2;
        num += '1';
            if (sticks>=2||sticks==0) return 1;
    }
    return 1;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    for (int i=0;i<T;i++)
    {
        cin >> sticks;
        if (dfs(sticks,num))
        {
            cout << num << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        sticks=0;
        num="";
    }
    return 0;
}
