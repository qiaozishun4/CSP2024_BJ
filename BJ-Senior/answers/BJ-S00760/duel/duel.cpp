#include <bits/stdc++.h>
using namespace std;
struct node{
    int num;
    bool isok;
}a[100005];
bool cmp(node x,node y){
    return x.num > y.num;
}int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
         cin >> a[i].num;
         a[i].isok = 1;
    }
    sort(a+1,a+1+n,cmp);
    int left=1,right=n,cnt=0;
    while (left <= right)
    {
        if (left == right)
        {
            cnt++;
            break;
        }
        if (a[left].num>a[right].num&&a[left].isok==1&&a[right].isok==1)
        {
            cnt++;
            a[right].isok = 0;
        }
        left++,right--;
    }
    cout << n-cnt;
    return 0;
}