#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define nit int

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline int read()
{
    static int x,sgn,c;
    x=0,sgn=1,c=getchar();
    while ((c<48||c>57)&&c!='-') c=getchar();
    if (c=='-') sgn=-1,c=getchar();
    while (c>=48&&c<=57) x=x*10+c-48,c=getchar();
    return x*sgn;
}

const int N=1e5+233;
int n,a[N];
bitset<N> die,atk;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    sort(a+1,a+1+n);
    int ans=0;
    for (int i=1,k=1;i<=n;i++)
    {
        while (k<=n&&(a[k]<=a[i]||die[k]||atk[k])) k++;
        if (k>n) break;
        atk[k]=1,die[i]=1,ans++;
    }
    cout<<n-ans<<endl;

    return 0;
}
//orz to nzhtl1477
//rp++
