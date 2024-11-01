#include<bits/stdc++.h>
using namespace std;

struct car
{
    double stop,csd;
    car(){}
    car(double x,double y){csd=x,stop=y;}
    int operator = (int x)
    {
        csd=x;
        return x;
    }
};

bool operator <(car a,car b)
{
    return a.csd<b.csd;
}

bool is(int x,int y,int z,int l,int V)
{
    if(z<=0)
    {
        if(y>V)return 1;
        return 0;
    }
    if(sqrt((l-x)*2*z+y*y)>V)
        return 1;
    else
        return 0;
}

double cal1(int x,int y,int z,int l,int V)
{
    if(z<0)
    {
        return 1.0*(0-y*y)/(z*2)+x;
    }
    return l;
}

car cal(int x,int y,int z,int l,int V)
{
    if(is(x,y,z,l,V))
    {
        if(z==0)return car(x,cal1(x,y,z,l,V));
        return car(1.0*(V*V-y*y)/(z*2)+x,cal1(x,y,z,l,V));
    }
    return car(l+1,cal1(x,y,z,l,V));
}

int main()
{
    freopen("detect1.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int m,n,l,V,cnt=0,cnt2=0;
        car c[110000];
        int p[1000010];
        vector<int>p1[100010];
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            c[i]=cal(x,y,z,l,V);
        }
        sort(c+1,c+n+1);
        for(int i=1;i<=m;i++)
        {
            int x;
            cin>>x;
            p[x]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i].csd!=l+1)
                for(int j=c[i].csd;j<c[i].stop;j++)
                    if(p[j]>=1)
                    {
                        cout<<i<<endl;
                        cnt2++;
                        break;
                    }
        }
        //for(int i=1;i<=l;i++)
        {
            //for(int j=1;j<=n&&c[j].csd!=l+1;j++)
            {
                //if(i<=c[j].stop&&i>=c[i].csd)p1[i].push_back(j);
            }
        }
        cout<<cnt2<<' '<<cnt<<endl;
    }
    return 0;
}
