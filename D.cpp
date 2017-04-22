/*
	Author: Hamza Hasbi
	Copyrights: "h.hamza" ==> "www.hamzahasbi.me"
	Date: 19/04/2017 13:02:24
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
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int alpha=0,digit=0,symb=0;
		rep(i,0,s.size()-1){
			if(isalpha(s[i])) alpha++;
			else if(isdigit(s[i])) digit++;
			else symb++;
		}
		if(alpha<4) puts("The last character must be a letter.");
		else if(digit<4) puts("The last character must be a digit.");
		else if(symb<2) puts("The last character must be a symbol.");
		else puts("The last character can be any type.");
	}
	
	
	return 0;
}
