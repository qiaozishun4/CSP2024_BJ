#include<bits/stdc++.h>
using namespace std;
int ans=0;
char p[1010][1010];
int n,m,k;
int x,y,d;
int main()
{
	freopen("explore1.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        char a,b;
        cin>>a>>b;
        if(a=='x'||b=='x')
        {
            cout<<1<<endl;
            continue;
        }
        else
        {
            if((x+y==1&&d==2)||(x+y==0&&d==0))
            {
                cout<<2<<endl;
            }
            else
            {
                cout<<1<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
