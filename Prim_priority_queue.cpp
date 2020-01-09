 /*
 ----Created by Chivas----
 1. Prim algorithm
 2. MST: Minimum Spanning Tree
 3. it's a Greedy Algorithm
 4. Using priority_queue
 5. O(ElogV)
 ----2019/09/27----
 */
 #include <cstdio>
 #include <queue> 
 #include <algorithm>
 using namespace std;
 #define INF 100000000
 #define MAX_V 10000
 typedef pair<int, int> P;
 int cost[MAX_V][MAX_V];
 bool used[MAX_V];
 int V;
 
 int Prim(int s) {
 	fill(used,used+V,false);
 	priority_queue<P, vector<P>, greater<P> > que;
 	que.push(P(0,s));
 	
 	int cnt=0, res=0;
 	while(cnt<V) {
 		P p=que.top();
 		que.pop();
 		int v=p.second;
 		if(used[v]) continue;
		used[v]=true;
 		res+=p.first;
 		
 		for(int i=0;i<V;i++) {
 			if(cost[v][i]!=INF && !used[i]) {
 				que.push(P(cost[v][i],i)); 
			}
		}
		cnt++;
	}
	return res;
 }
 
 int main() {
 	for(int i=0;i<V;i++) fill(cost[i],cost[i]+V,INF);
 	/* cost[u][v] */
 	
 	return 0;
 } 

