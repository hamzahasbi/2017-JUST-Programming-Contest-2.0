/*
	Author: Hamza Hasbi
	Copyrights: "h.hamza" ==> "www.hamzahasbi.me"
	Date: 19/04/2017 16:27:50
*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ui unsigned int
#define ud unsigned double
#define uf unsigned float
#define pi 2*acos(0.0)
#define module cin.ignore()
#define rep(i,l,r) for(auto i=l;i<=r;i++)
#define range(x,y) for(auto x:y)
//inline lcm(int a,int b) {return a*b/__gcd(a,b);}
//inline gcd(ll a,ll b) {return 1LL*b == 0 ? a : gcd(1LL*b, a*1LL % b*1LL);}
using namespace std;

main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	scanf("%d",&n);
	vector<long long>offer;
	rep(i,0,n-1){
		long long a;
		scanf("%lld",&a);
		offer.push_back(a);
	}
	int m;
	sort(offer.begin(),offer.end());
	scanf("%d",&m);
	while(m--){
		long long a;
		scanf("%lld",&a);
		auto it=lower_bound(offer.begin(),offer.end(),a);
		if(it!=offer.end()){
			cout<<*it<<"\n";
			//offer.erase(it);
		}
		else cout<<"Dr. Samer cannot take any offer :(."<<"\n";
	}
	return 0;
}
