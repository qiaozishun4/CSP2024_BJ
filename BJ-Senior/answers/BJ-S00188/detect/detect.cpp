#include<bits/stdc++.h>
using namespace std;
struct car{
    int d;
    int v;
    int a;
}vech[100001];
struct test{
    int p;
}test[100001];
int main()
{
    int T;
    int cnt=0;
    cin>>T;
    char n[100001],m[100001],L[20],V[1001];
    for(int i=1;i<=T;i++)
    {
        cin>>n[i]>>m[i]>>L[i]>>V[i];
    }
    int len=strlen(n);
    int len1=strlen(m);
    int len2=strlen(L);
    int len3=strlen(V);
    for(int i=1;i<=len;i++)
    {
        cin>>vech[i].d>>vech[i].v>>vech[i].a;
    }
    for(int i=1;i<=len1;i++)
    {
        cin>>test[i].p;
    }                           //a=moving speed
    for(int i=1;i<=100001;i++)  //d=start position
    {                           //v=start speed
        if(vech[i].v==0||vech[i].v*vech[i].a==0)
        {
            vech[i].v=0;
            vech[i].a=0;
        }
        else if(vech[i].v*vech[i].a>V[i])
        {
            cnt++;
        }
    }
    cout<<cnt;
}
