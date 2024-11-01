#include <iostream>

using namespace std;
long long dfs(long long a,int b)
{
    if(b==0)
        return a;
    if(b<0)
        return 0x7fffffffffffffff;
    else
        return min(dfs(10*a,b-6),min(dfs(10*a+1,b-2),min(dfs(10*a+2,b-5),min(dfs(10*a+3,b-5),min(dfs(10*a+4,b-4),min(dfs(10*a+5,b-5),min(dfs(10*a+6,b-6),min(dfs(10*a+7,b-3),min(dfs(10*a+8,b-7),dfs(10*a+9,b-6))))))))));
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        int k;
        cin>>k;
        if(min(dfs(1,k-2),min(dfs(2,k-5),min(dfs(3,k-5),min(dfs(4,k-4),min(dfs(5,k-5),min(dfs(6,k-6),min(dfs(7,k-3),min(dfs(8,k-7),dfs(9,k-6)))))))))!=0x7fffffffffffffff)
            cout<<min(dfs(1,k-2),min(dfs(2,k-5),min(dfs(3,k-5),min(dfs(4,k-4),min(dfs(5,k-5),min(dfs(6,k-6),min(dfs(7,k-3),min(dfs(8,k-7),dfs(9,k-6)))))))))<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
