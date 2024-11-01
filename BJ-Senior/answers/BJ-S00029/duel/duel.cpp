#include<bits/stdc++.h>
using namespace std;
int r[100005];
int main()
{
    //greedy
    //sort all of them
    //for all r_a:find the "upper_bound" value r_b
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;++i)
        cin>>r[i];
    sort(r+1,r+n+1);
    //copied successfully
    int a=1,i;//attacker
    for(i=1;i<=n;++i,++a)
    {
        while(r[a]<=r[i] and a<=n)++a;
        if(a==n+1)break;
    }
    cout<<n-i+1;
    fclose(stdin);fclose(stdout);
    //1 2 3 1 2
    //1 1 2 2 3
    //2 2 3
    return 0;
}
