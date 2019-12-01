// こっちのほうが速い

#include"bits/stdc++.h"

typedef long long ll;

using namespace std;

#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, n) for(ll i=n; i>=0; i--)
#define reps(i, s, e) for(ll i=s; i<e; i++)
#define all(x) x.begin(),x.end()

int main(){
	int N;

	cin >> N;

	vector<int> v(N);
	vector<int> w(N);


	int l, i = 0;
	while (cin >> l) {
        v[i] = l;
        w[i] = l;

        i++;
        if (i >= N) {
            break;
        }
    }

    

    sort(v.begin(), v.end() );
    v.erase(unique(v.begin(), v.end()), v.end());

    size_t v_len = v.size();

    // cout << "v_len : "  << v_len << endl; 


    vector<ll> x(v_len);

    rep(i,v_len){
    	size_t n_count = count(w.begin(), w.end(), v[i]);
    	x[i] = n_count;
    }

    // cout << "x_len : "  << x.size() << endl;

    // rep(i,v_len) cout << v[i] << x[i] << endl;



    ll count = 0;
 
    rep(i,v_len){
    	// 正三角形
    	if(x[i] >= 3) count += ((ll)(x[i]*(x[i] - 1))*(x[i] -2))/6;

    	reps(j,i+1,v_len){
    		// 二等辺三角形			
    		if(x[i] >= 2 && v[j] < 2*v[i]) count += (x[i]*(x[i]-1))/2 * x[j];
    		if(x[j] >= 2 && v[i] < 2*v[j]) count += (x[j]*(x[j]-1))/2 * x[i];

    		reps(k,j+1,v_len){
    			if(abs(v[i] - v[j]) < v[k] && v[k] < v[i] + v[j] ){
    				count += x[i] * x[j] * x[k];
    			}
    			else if(v[k] >= v[i] + v[j]) break;
    		}
    	}
    }

    cout << count << endl;

    return 0;
}	