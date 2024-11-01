
#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n,a[1000001]={},cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);//从小到大
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        q.push(a[i]);
        if(q.front()<q.back())
        {
            cnt++;
            q.pop();
        }
    }
    cout<<q.size();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
