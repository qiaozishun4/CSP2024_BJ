#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,tu[1000][1000]={0},chao=0,c[4][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
    };
    int x,y,ans;
    char tu2[1000][2000];
    cin>>T;
    for (int i=0;i<T;i++)
    {
        ans=0;
        x=0;
        y=0;
        chao=0;
        cin>>n>>m>>k>>x>>y>>chao;
        x--;
        y--;
        for (int j=0;j<n;j++)
        {
            cin>>tu2[j];
        }
        for (int i2=0;i2<n;i2++)
        {
            for (int j=0,k=0;j<m;j++)
            {
                if (tu2[i2][k]=='x')
                {
                    k++;
                    tu[i2][j]=1;
                }
                else
                {
                    k+=1;
                    tu[i2][j]=0;
                }
            }
        }
        for (int j=0;j<k;j++)
        {
            tu[x][y]=-1;
            int x2=x+c[chao][0],y2=y+c[chao][1];
            if (tu[x2][y2]==1||x2<0||x2>=n||y2>=m||y2<0)
            {
                chao=(chao+1)%4;
                //cout<<"if"<<endl;
            }
            else
            {
                x=x2;
                y=y2;
                tu[x][y]=-1;
               // cout<<"else"<<endl;
            }
        }
        for (int j=0;j<n;j++)
        {
            for (int k=0;k<m;k++)
            {
                if (tu[j][k]==-1)
                {
                    ans++;
                }
                //cout<<tu[j][k]<<" ";
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
	return 0;
}
