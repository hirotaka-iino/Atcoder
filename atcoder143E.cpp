#include"bits/stdc++.h"
// #include "prettyprint.hpp"

typedef long long ll;

// #define INF 10000000000;
ll INF = 10000000000;


using namespace std;

#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, n) for(ll i=n; i>=0; i--)
#define reps(i, s, e) for(ll i=s; i<e; i++)
#define all(x) x.begin(),x.end()

typedef struct edge {
	    int to, dist;
	} EDGE;

int main(){

	ll M,N,L;
	// N：町の数  M : 道の数

	cin >> N >> M >> L;

	vector<ll> A(M),B(M),C(M);

	
	
	rep(i,M){
		cin >> A[i] >> B[i] >> C[i];
	}

	ll Q;

	cin >> Q;

	vector<ll> s(Q);
	vector<ll> t(Q);

	// ll l, j = 0;
	// rep(i,Q){
	// 	while (cin >> l) {
	//         d[j] = l;
	//         j++;
	//         if (j >= 2) {
	//             break;
	//         }
	//     }
	// }    

	rep(i,Q){
		cin >> s[i] >> t[i];
	}

	rep(i,M) A[i] --, B[i] --;

	// N*Nの２d行列
	vector<vector<ll> > graph(N, vector<ll>(N,INF));

	rep(i,M){
		if(C[i] <= L){
		graph[A[i]][B[i]] = C[i];
		graph[B[i]][A[i]] = C[i];
		}
	}

	// vector<vector<ll> > least_supply_gs(N, vector<ll>(N));
	// vector<vector<ll> > state(N, vector<ll>(N));


	// // 重み付き隣接リスト

	// vector<edge> graph[N];
	// EDGE e = {0,0};

	// rep(i,M){
	// 	e.to = B[i];
	// 	e.dist = C[i];
	// 	graph[A[i]].push_back(e);

	// 	e.to = A[i];
	// 	e.dist = C[i];
	// 	graph[B[i]].push_back(e)
	// }


	vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(N)));


	// =========================================================
// warshall_floyd法

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++) dp[0][i][j] = graph[i][j];
	}
	
	// cout << dp[0] << endl;

	for(int k = 1; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				dp[k][i][j] = min(dp[k-1][i][j],dp[k-1][i][k]+dp[k-1][k][j]);
			}
		}
		// cout << dp[k] << endl;
	}

// ============================================================  

	// dp[N-1][i][j]がe = (i ,j)最短経路の情報をもつ

// ============================================================ 
// 辺がL以下のところに長さ１の辺を張る	

	vector<vector<ll> > new_graph(N, vector<ll>(N,INF));

	rep(i,N){
		reps(j,i+1,N){
			if(dp[N-1][i][j] <= L){
				new_graph[i][j] = 1;
				new_graph[j][i] = 1;
			}
		}
	}

// ============================================================ 
	// new_graphに対してwarshall_floydを行う

	vector<vector<vector<ll>>> ans(N, vector<vector<ll>>(N, vector<ll>(N)));

	// warshall_floyd法


	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++) ans[0][i][j] = new_graph[i][j];
	}
	
	// cout << dp[0] << endl;

	for(int k = 1; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				ans[k][i][j] = min(ans[k-1][i][j],ans[k-1][i][k]+ans[k-1][k][j]);
			}
		}
		// cout << dp[k] << endl;
	}


// ============================================================ 

	// ans[N-1][i][j]がe = (i ,j)最短経路の情報をもつ

// ============================================================ 


	rep(i,N){
		reps(j,i,N){
			if(ans[N-1][i][j] == INF){
				ans[N-1][i][j] = 0;
				ans[N-1][j][i] = 0;
			}
		}
	}

// ============================================================ 
	// cout << "========================" << endl;
	// cout << ans[N-1] << endl;

	rep(i,Q){
		cout << ans[N-1][s[i]-1][t[i]-1] - 1<< endl;
	}
	
}



