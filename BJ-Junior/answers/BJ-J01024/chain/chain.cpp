#include<bits/stdc++.h>
using namespace std;
int len[100005],r,c;
string s[100005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T,n,m,q,i,j,k;
	cin>>T;
	while(T--)
    {
        cin>>n>>m>>q;
        int suml=0;
        for(i=1;i<=n;i++)
        {
            cin>>len[i];
            char c;
            for(j=1;j<=len[i];j++)
            {
                cin>>c;
                if(c==' ')
                {
                    j--;
                    continue;
                }
                s[i]+=c;
            }
        }
        while(q--)
        {
            cin>>r>>c;
            if(r==1)
            {
                if(c>m)
                {
                    cout<<0<<endl;
                    continue;
                }
                for(i=1;i<=n;i++)
                {
                    bool flagg=0;
                    for(j=1;j<=len[i];j++)
                    {
                        bool flag=0;
                        if(s[i][j]=='1')
                        {
                            for(k=j;k<=min(len[i],j+m);k++)
                            {
                                if(s[i][k]==char(c+'0'))
                                {
                                    flag=1;
                                    cout<<1<<endl;
                                    break;
                                }
                            }
                            j=k;
                            if(flag)
                            {
                                flagg=1;
                                break;
                            }
                        }
                    }
                    if(flagg)
                        break;
                }
            }
        }
    }
	return 0;
}
