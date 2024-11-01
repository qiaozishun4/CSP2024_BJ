#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int T;
struct car{
    int d;
    int v;
    int a;
    bool overspeed;
    int st,en;
};

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>T;
    for(int i=0;i<T;i++){
        int n,m,l,V;
        int p[100005];
        car c[100005];
        cin>>n>>m>>l>>V;
        for(int j=0;j<n;j++)
            cin>>c[j].d>>c[j].v>>c[j].a;
        for(int j=0;j<m;j++)
            cin>>p[j];

        int cnt=0;
        for(int j=0;j<n;j++){
            if(c[j].v<=V&&c[j].a<=0)
                continue;
            else if(c[j].v>V&&c[j].a>=0){
                for(int k=0;k<m;k++){
                    if(p[k]>=c[i].d){
                        c[j].overspeed=1;
                        c[j].st=k;
                        c[j].en=m-1;
                        cnt++;
                        break;
                    }
                }
            } else if(c[j].v>V&&c[j].a<0){
                double down=((V*V)-(c[j].v*c[j].v))*1.0/(2.0*c[j].a)+c[j].d;
                bool flag1=0,flag2=0;
                for(int k=0;k<m;k++){
                    if(p[k]>=c[j].d&&p[k]<down){
                        if(!c[j].overspeed){
                            cnt++;
                            c[j].st=k;
                            c[j].overspeed=1;
                            flag1=1;
                        }
                    } else if(p[k]>=down){
                        c[j].en=k-1;
                        flag2=1;
                        break;
                    }
                }
                if(flag1&&(!flag2))
                    c[j].en=m-1;
            } else if(c[j].v<V&&c[j].a>0){
                double up=((V*V)-(c[j].v*c[j].v))*1.0/(2.0*c[j].a)+c[j].d;
                bool flag=0;
                for(int k=0;k<m;k++){
                    if(p[k]>up){
                        c[i].st=k;
                        c[j].overspeed=1;
                        flag=1;
                        cnt++;
                        break;
                    }
                }
                if(flag)
                    c[j].en=m-1;
            }
        }
        cout<<cnt<<" ";

        bool nec[100005];
        int ass[100005];
        for(int j=0;j<n;j++)
            for(int k=c[j].st;k<=c[j].en;k++)
                if(c[j].overspeed)
                    ass[k]++;

        int maxn=-1,poi=0;
        do{
            maxn=-1,poi=0;
            for(int j=0;j<m;j++){
                if(ass[j]>maxn){
                    maxn=ass[j];
                    poi=j;
                }
            }
            nec[poi]=1;
            for(int k=0;k<n;k++)
                if(c[k].overspeed&&poi>=c[k].st&&poi<=c[k].en)
                    for(int h=c[k].st;h<=c[k].en;h++)
                        ass[h]--;
        }while(maxn>0);
        int _cnt=0;
        for(int j=0;j<m;j++)
            if(!nec[j])
                _cnt++;
        cout<<_cnt<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
