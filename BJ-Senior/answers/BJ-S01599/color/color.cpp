#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int a[200010];
int ans = 0;

int dfs(int red,int blue,int step,int score)
{
    if(step > n)
    {
        ans = max(ans,score);
        return score;
    }
    int cnt1 = score,cnt2 = score;
    if(a[step] == red)
    {
        cnt1 = score +red;
    }
    if(a[step] == blue)
    {
        cnt2 = score + blue;
    }
    //cout <<"//" << step <<" "<< a[step] <<" " << red <<" " << blue << " " << score<< "//\n";
    return max(dfs(a[step],blue,step+1,cnt1),dfs(red,a[step],step+1,cnt2));
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {

        cin >> n;
        ans = 0;
        memset(a,sizeof(a),0);
        for(int i = 1;i <= n;i ++)
        {
            cin >>a[i];
        }
        cout << dfs(0,0,1,0) << endl;
        //cout <<"$$$" << ans << endl;
    }
    return 0;
}
