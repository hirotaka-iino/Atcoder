//しゃくとり法

#include"bits/stdc++.h"

typedef long long ll;

#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, n) for(ll i=n; i>=0; i--)
#define reps(i, s, e) for(ll i=s; i<e; i++)
#define all(x) x.begin(),x.end()

using namespace std;

int main(){
	ll N, K;
	cin >> N >> K;

	vector<ll> s(N);
	rep(i,N) cin >> s[i];

	ll l = 0 ; 
	ll r = 0 ;

	// 差積
	ll product_diffs = 1;

	ll ans = 0;

	if(*min_element(all(s))==0){
		cout << N << endl;
		return 0;
	}

	else if (K == 0){
		cout << 0 << endl;
		return 0;
	}	

	// しゃくとり法
	else if (K >= 1) {
		while(1){
		while(product_diffs <= K && r < N){
			product_diffs *= s[r]; 
			r += 1;
		}

		if(product_diffs <= K && r == N){
			ans = max(ans, r-l);
			break;
		} 

		if(product_diffs > K && r == N){
			ans = max(ans, r-l-1);
			break;
		} 

		ans = max(ans, r-l-1);

		product_diffs /= s[l];
		l += 1;

		}

		cout << ans << endl;
		return 0;
	}	
}




