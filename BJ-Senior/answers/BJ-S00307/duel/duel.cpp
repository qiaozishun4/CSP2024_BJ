#include<bits/stdc++.h>
using namespace std;
long long box[200000],a[200000],sbox[200000];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n,used=0;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        box[a[i]]++;
    }
    for (int i=1;i<=200000;i++)sbox[i]=sbox[i-1]+box[i];
    long long ans=0;
    for (int i=1;i<=200000;i++)
    {
        if (box[i]!=0)
        {
            used=max(0*1ll,used-box[i]);
            if (n-sbox[i]-used<box[i])
            {
                ans+=box[i]-n+sbox[i]+used;
            }
            else used=box[i];
            //cout << i << " " << box[i] <<" " <<used << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
