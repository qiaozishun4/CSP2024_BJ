#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define fin freopen("duel.in","r",stdin);
#define fout freopen("duel.out","w",stdout);
using namespace std;
int n;
int a[100005];
int num,cnt1,cnt2;
int main()
{
    fin
    fout
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(cnt1+cnt2==0)
        {
            num=a[i];
            cnt2++;
        }
        else if(a[i]==num)
        {
            if(cnt1)
                cnt1--;
            cnt2++;
        }
        else
        {
            cnt1+=cnt2;
            if(cnt1)
                cnt1--;
            cnt2=1;
            num=a[i];
        }
    }
    cout << (cnt1+cnt2) << endl;
    return 0;
}
