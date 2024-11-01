#include<bits/stdc++.h>
using namespace std;




int main(){
    //freopen("duel.in","r",stdin);
    //freopen("duel.out","w",stdout);
    int n;
    int mn=1;

    cin>>n;
    int sum=n;

    bool t[100010];
    memset(t,true,sizeof(t));
    int r[100010];
    for(int i=1;i<=n;i++)
            cin>>r[i];

    sort(r+1,r+n+1);
    int mx=r[n];
    

    //for(int i=1;i<=n;i++)
    //{
        for(int j=mn+1;j<=n;j++)
        {


            //for(int i=1;i<=n;i++)
                //if(r[i]==-1)
                    //sum--;
            if(r[mn]!=r[j]&&r[j]!=-1&&t[j]==true&&r[mn]!=mx)
            {
                r[mn]=-1;


                    mn++;
                t[j]==false;
            }
            if(r[mn]==mx&&r[mn]!=r[j]&&r[j]!=-1&&t[j]==true)
            {
                for(int k=n;k>=1;k--)
                {
                    if(r[mn]>r[k]&&r[k]!=-1)
                    {
                        r[k]=-1;
                        t[mn]=false;
                    }



                }

            }
        }

    for(int i=1;i<=n;i++){
        if(r[i]==-1)
            sum--;
    }
    cout<<sum;
    return 0;
}
