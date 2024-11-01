#include<bits/stdc++.h>
using namespace std;

int stk[11]={6,2,5,5,4,5,6,3,7,6};
int stk1[11]={8,0,6,9,2,3,5,4,7,1};
int a[11];
vector<string> v;
void dfs(int n,int sum)
{
    if(sum>n)
        return;
    if(sum==n)
    {
        int x=-1,b[11];
        for(int i=0;i<10;i++)
        {
            b[i]=a[i];
        }
        for(int i=1;i<10;i++)
        {
            if(b[i]>=1)
            {
                x=i;
                break;
            }
        }
        if(x==-1)
        {
            if(b[0]>=1)x=6,b[0]--,b[6]++;
            else return;
        }
        string ans;
        ans+=x+'0';
        b[x]--;
        for(int i=0;i<10;i++)
        {
            while(b[i]-->0)ans+=i+'0';
        }
        v.push_back(ans);
    }
    for(int i=0;i<10;i++)
    {
        a[i]++;
        dfs(n,sum+stk[i]);
        a[i]--;
    }
}

bool cmp(string s1,string s2)
{
    return stoll(s1)<stoll(s2);
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n%7==0&&n>=100)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==1&&n>=100)
        {
            cout<<"10";
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        v.clear();
        memset(a,0,sizeof(a));
        dfs(n,0);
        sort(v.begin(),v.end(),cmp);
        if(v.empty())cout<<-1<<endl;
        else cout<<v[0]<<endl;
    }
    return 0;
}
