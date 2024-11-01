#include <bits/stdc++.h>
using namespace  std;
int T;
int a[200005];
int f[200005];
int n, maxn , cnt,bl[20005],re[20005],cur1,cur2;
void dfs(int step)
{
    if(step==n+1){
        int sum=0;
        for(int i = 2; i <= cur1; i++){
            if(bl[i]==bl[i-1])sum+=bl[i];
        }
        for(int i = 2; i <= cur2; i++){
            if(re[i]==re[i-1])sum+=re[i];
        }
        maxn=max(maxn,sum);
        return;
    }
    for(int i = 1; i <= 2; i++)
    {
        if(i==1){
            bl[++cur1]=a[step];
            dfs(step+1);
            cur1--;
        }
        if(i==2){
            re[++cur2]=a[step];
            dfs(step+1);
            cur2--;
        }
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        dfs(1);
        cout << maxn <<endl;
        maxn = 0;
        memset(a,0,sizeof(0));
    }


    return 0;
}


