#include<bits/stdc++.h>
using namespace std;
long long t,n,k,q,l[100000],s[10000][10000],r,c,ro=0;
bool fi(long long zhao,long long shang)
{
    //cout<<endl<<endl;
    if(ro==r)
    {
        //cout<<"roend"<<endl;
        return 1;
    }
    ro++;
    for(int i=1;i<=n;i++)
    {
        //cout<<"i="<<i<<",";
        if(i!=shang)
        {
          //  cout<<"yes"<<endl;
            for(int j=1;j<=l[i]-1;j++)
            {
            //    cout<<"j="<<j<<",";
                for(int o=j+1;o<=l[i];o++)
                {
              //      cout<<"o="<<o<<","<<endl;
                    if(s[i][o]==zhao&&o-j+1<=k)
                    {
                        if(ro==r)
                        {
                            if(s[i][j]==1)
                            {
                //                cout<<"2y"<<endl;
                  //              cout<<"dofi("<<s[i][j]<<","<<i<<")"<<endl;
                                if(fi(s[i][j],i))
                                {
                     //               cout<<"3y"<<endl;
                                    return 1;
                                }
                               // else cout<<"3n"<<endl;
                            }
                        }
                        else
                            {
                        //    cout<<"2y"<<endl;
                    //        cout<<"dofi("<<s[i][j]<<","<<i<<")"<<endl;
                            if(fi(s[i][j],i))
                            {
                   //             cout<<"3y"<<endl;
                                return 1;
                            }
                  //          else cout<<"3n"<<endl;
                        }

                    }
                    /*else
                    {
                        cout<<"2n"<<endl;
                        if(s[i][o]!=zhao)cout<<"budeng,s["<<i<<"]["<<o<<"="<<s[i][o]<<",zhao="<<zhao<<",";
                        if(o-j+1>k)cout<<"dale,";
                        if(s[i][j]!=1)cout<<"neb";
                    }*/
                }

            }
        }
        //else cout<<"no"<<endl;

    }
    return 0;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin>>s[i][j];
            }
        }
        while(q--)
        {
            ro=0;
            cin>>r>>c;
            cout<<fi(c,0)<<endl;
        }

    }
    return 0;
}