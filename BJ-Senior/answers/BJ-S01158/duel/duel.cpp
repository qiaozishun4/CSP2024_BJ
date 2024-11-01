#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n;
int a[N];
int b[N],c[N];
int att[N],leave[N],attable[N];
int k = 0;
int ans;
bool cmp(int a,int b)
{
    return a<b;
}
void work(int num,int id)
{
    for(int i = id-1;i>=1;i--)
    {
        if(leave[c[i]] == 0) continue;
        if(attable[num]>=leave[c[i]]) attable[num]-=leave[c[i]],leave[c[i]] = 0;
        else {leave[c[i]]-=attable[num],attable[num] = 0;break; }
    }
    return;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    memset(c,0x3f,sizeof c);
    for(int i = 1;i<=n;i++) {scanf("%d",&a[i]);if(!leave[a[i]]) {c[++k] = a[i];/*cout << c[k] << " " << k << endl;*/}leave[a[i]]++;attable[a[i]]++;}
    sort(c+1,c+N,cmp);
    /*for(int i = 1;i<=k;i++) cout << c[i] << endl;
    for(int i = 1;i<=k;i++) cout << leave[c[i]] << " " << attable[c[i]] << endl;*/
    for(int i = 1;i<=k-1;i++)
    {
        if(leave[c[i]]<attable[c[i+1]]) attable[c[i+1]]-=leave[c[i]],leave[c[i]] = 0,work(c[i+1],i);
        else if(leave[c[i]] == attable[c[i+1]]) attable[c[i+1]] = 0,leave[c[i]] = 0;
        else leave[c[i]]-=attable[c[i+1]],attable[c[i+1]] = 0;
        /*cout << leave[c[i]] << " " << attable[c[i+1]] << endl;*/
    }
    for(int i = 1;i<=k;i++)
    {
        ans+=leave[c[i]];
    }
    printf("%d",ans);
    return 0;
}
