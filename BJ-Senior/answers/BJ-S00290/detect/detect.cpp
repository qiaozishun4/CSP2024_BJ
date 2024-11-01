#include<iostream>
#include<vector>
using namespace std;
int T,n,m,l,v;
struct car
{
    int d,v,a;
    bool cs;
    car():d(0),v(0),a(0),cs(0){}
}cars[100005];
int ans1,ans2,clo[100005],csy[1000005];
vector<int> cy[100005],yc[100005];
int main(void)
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&l,&v);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&cars[i].d,&cars[i].v,&cars[i].a);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&clo[i]);
            if(csy[clo[i]])ans2++;
            else csy[clo[i]]=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int spd=cars[i].v;
        for(int j=cars[i].d;j<=v;j+=spd)
        {
            if(spd>v&&csy[j]!=0)
            {
                if(cars[i].cs==0)cars[i].cs=1,ans1++;
                yc[csy[j]].push_back(i);
                cy[i].push_back(csy[j]);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int flag=true;
        for(int j=0;j<yc[i].size()&&flag;j++)
        {
            if(cy[yc[i][j]].size()<=1)flag=false;
        }
        if(flag)
        {
            ans2++;
            for(int d=0;d<yc[i].size();d++)
            {
                for(int f=0;f<cy[d].size();f++)
                    cy[d].erase(cy[d].begin()+f,cy[d].begin()+f+1);
            }
        }
    }
    printf("%d %d",ans1,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
