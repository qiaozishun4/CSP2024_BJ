#include<bits/stdc++.h>
#define ll long long
//son problem 1:bound search
//son problem 2:cover problem
using namespace std;
const ll INF=20000000000000016;
struct car
{
    ll d,v,a;
}dat[100005];
struct line
{
    ll l,r;
};
ll p[100005];
ll n,m,l,v;
vector<line>vec;
ll cmp(line x,line y)
{
	if(x.l<y.l)return 1;
	if(x.l>y.l)return 0;
	return x.r<y.r;
}
bool ck(ll pos,ll start,ll speed,ll ac)
{
	if(pos<start)return false;
	if(pos==start)
	{if(speed>v)return true;else return false;}
	if(ac==0)
	{
		if(speed>v)return true;
		else return false;
	}
	//pos
	if(ac>0)
	{if(2*ac*(pos-start)+speed*speed>v*v)return true;
	else return false;}
	
	if(ac<0)
	{
		if(2*ac*(pos-start)+speed*speed>v*v)return true;
		else return false;
	}
	return false;
}
void solve_1()
{
	ll popcat=0;
    for(ll i=1;i<=n;i++)
    {
        ll l=1,r=m;
        ll mid=0;
        //ll mid1=0,mid2=0;
        ll ans=m+1;
        ll pos1=m+1,pos2=0;
        //find first detected
        if(dat[i].a<0)
        {
        ans=1;
        while(1)
        {
			if(ans>m)break;
			if(ck(p[ans],dat[i].d,dat[i].v,dat[i].a))break;
			ans++;
		}
		}
		else
		{
        while(l+5<=r)
        {
            /////////////////
            
            /////////////////
            mid=(l+r)>>1;
            bool flg1=ck(p[mid],dat[i].d,dat[i].v,dat[i].a);
            //bool flg2=ck(p[mid2],dat[i].d,dat[i].v,dat[i].a);
            if(flg1)r=mid;
            else l=mid;
        }
        for(int j=l;j<=r;j++)
        {
			if(ck(p[j],dat[i].d,dat[i].v,dat[i].a))
			{
				ans=j;
				break;
			}
		}
	}
    
    pos1=ans;
    ans=m+1;
    l=pos1,r=m;
    while(l<=r)
        {
            /////////////////
            if(l==r)
            {
                if(!ck(p[l],dat[i].d,dat[i].v,dat[i].a))
                {
                    ans=l;
                    break;
                }
                break;
            }
            else if(l==r-1)
            {
                if(!ck(p[l],dat[i].d,dat[i].v,dat[i].a))
                {
                    ans=l;
                    break;
                }
                if(!ck(p[r],dat[i].d,dat[i].v,dat[i].a))
                {
                    ans=r;
                    break;
                }
                break;
            }
            else if(l==r-2)
            {
                if(!ck(p[l],dat[i].d,dat[i].v,dat[i].a))
                {
                    ans=l;
                    break;
                }
                if(!ck(p[l+1],dat[i].d,dat[i].v,dat[i].a))
                {
                    ans=l+1;
                    break;
                }
                if(!ck(p[r],dat[i].d,dat[i].v,dat[i].a))
                {
                    ans=r;
                    break;
                }
                break;
            }
            /////////////////
            mid=(l+r)>>1;
            if(!ck(p[mid],dat[i].d,dat[i].v,dat[i].a))
            {
				ans=min(ans,mid);
                r=mid;
            }
            else
            {
                l=mid;
            }
        }
       pos2=ans-1;
       //cout<<pos1<<'|'<<pos2<<endl;
       if(pos1<=pos2)
       {
		   popcat++;
		   line le;
		   le.l=pos1;
		   le.r=pos2;
		   vec.push_back(le);
	   }
    }
    cout<<popcat<<' ';
    return;
}
void solve_2()
{
	if(vec.size()==0)
	{
		//cout<<"NO!";
		cout<<m<<'\n';
		return;
	}
	if(vec.size()==1)
	{
		cout<<m-1<<'\n';
		return;
	}
	sort(vec.begin(),vec.end(),cmp);
	ll cnt=1,r=vec[0].r;
	for(ll i=0;i<(ll)vec.size();i++)
	{
		if(vec[i].r<r)r=vec[i].r;
		if(vec[i].l>r)cnt++,r=vec[i].r;
	}
	/*ll minr=vec[0].r,maxl=vec[0].l;
	for(ll i=0;i<(ll)vec.size();i++)
	{
		//cout<<vec[i].l<<' '<<vec[i].r<<endl;
		minr=min(minr,vec[i].r);
		maxl=max(maxl,vec[i].l);
	}
	cout<<m-(maxl-minr+1)<<'\n';*/
	cout<<m-cnt<<'\n';
	return;
}
void work()
{

    cin>>n>>m>>l>>v;
    for(ll i=1;i<=n;i++)
    {
        cin>>dat[i].d>>dat[i].v>>dat[i].a;
    }
    
    for(ll i=1;i<=m;i++)
    cin>>p[i];
    
    sort(p+1,p+m+1);
    
    p[m+1]=INF;
    vec.clear();
    //cout<<"AK!";
    solve_1();
    solve_2();
	return;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ll t;
	cin>>t;
	while(t--)work();
	return 0;
}
