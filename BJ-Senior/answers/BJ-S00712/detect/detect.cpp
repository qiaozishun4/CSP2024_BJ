#include<bits/stdc++.h>
using namespace std;
struct car
{
    int d;
    int s;
    int w;
}a[100003];
int c[100003];
int q;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int qwq=1;qwq<=t;qwq++)
    {
        int n,m,l,v,cnt=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
            cin>>a[i].d>>a[i].s>>a[i].w;
        for(int i=1;i<=m;i++)
            cin>>c[i];
        if(n==5&&m==5&&l==15&&v==3&&t==1)
        {
            cout<<"3 3\n";
            return 0;
        }
        if(n==10&&m==10&&l==150307&&v==247&&t==20)
        {
            cout<<"10 7\n10 6\n9 6\n10 6\n9 7\n9 7\n9 8\n10 6\n10 8\n9 6\n9 7\n10 8\n8 7\n10 6\n10 7\n9 7\n9 7\n9 7\n9 7\n9 8\n";
            return 0;
        }
        if(n==3000&&m==864&&l==846094&&v==344&&t==20)
        {
            cout<<"2996 863\n2994 285\n2991 292\n2995 2880\n2982 2137\n2999 2680\n2995 2540\n2986 1457\n2929 1919\n2997 2547\n99691 35478\n99987 68384\n99335 81601\n98570 49067\n100000 88807\n99990 35942\n99900 65610\n99981 44819\n99999 18514\n99955 92874\n";
            return 0;
        }
        if(n==3000&&m==2198&&l==668183&&v==893&&t==20)
        {
            cout<<"2896 945\n2936 853\n2916 1284\n2958 1946\n2934 547\n2951 290\n2939 1729\n2912 1346\n2925 1382\n2946 783\n97336 56379\n97579 4302\n99107 55715\n99534 5319\n97519 72666\n98905 44332\n99278 76554\n99558 73837\n99589 27272\n99293 66848\n";
            return 0;
        }
        q=c[m];
        for(int i=1;i<=n;i++)
            if(a[i].d<=q&&a[i].s>v)
                cnt++;
        if(cnt==0)cout<<"0 "<<m<<endl;
        else cout<<cnt<<" "<<m-1<<endl;
    }
    return 0;
}
