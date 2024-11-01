#include <bits/stdc++.h>

using namespace std;
int b[200000+1]={0};

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    vector <int> a[T];
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int f;
            cin>>f;
            a[t].push_back(f);
        }
        int q=1000000;
        for(int i=0;i<a[t].size();i++)
        {
            if(a[t][i]<q)
            {
                q=a[t][i];
            }
        }
        while(1)
        {
            int p[2]={0};
            for(int i=0;i<a[t].size();i++)
            {
                if(a[t][i]>p[0]&&b[i]==0)
                {
                    p[0]=a[t][i];
                    p[1]=i;
                }
            }
            for(int j=p[1]+1;j<a[t].size();j++)
            {
                if(a[t][j]==p[0])
                {
                    bool red=0,blue=0;
                    for(int i=p[1]+1;i<j;i++)
                    {
                        if(b[i]==1)
                            red=1;
                        if(b[i]==1)
                            blue=1;
                    }
                    if(red==0)
                    {
                        b[j]=1;
                        b[p[1]]=1;
                    }
                    else if(blue==0)
                    {
                        b[j]=2;
                        b[p[1]]=1;
                    }
                }
            }
            if(p[0]=q)
                break;
        }
        int c=0;
        for(int i=a[t].size();i>0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(b[i]==0||b[j]==0)
                    continue;
                if(a[t][i]==a[t][j]&&b[i]==b[j])
                {
                    c+=a[t][i];
                }
                if(b[i]==b[j])
                {
                    break;
                }
            }
        }
        cout<<c<<endl;
    }
    return 0;
}