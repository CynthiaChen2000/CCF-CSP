 /*
 ----Created by Chivas----
 1. Bellman-Ford algorithm 
 2. SSSP: Single-Source Shortest Path 
 3. can work with graphs in which edges can have negative weights
 4. Using Dynamic Programming
 5. O(V*E)
 ----2019/09/22----
 */
 #include <cstdio>
 #include <cstring> 
 #include <algorithm>
 using namespace std;
 #define MAX_E 10000
 #define MAX_V 1000
 #define INF 100000000
 struct edge {
 	int from, to, cost;
 };
 
 edge es[MAX_E];
 int d[MAX_V];
 int V, E;
 
 //cannot work if negative loop exists
 void BellmanFord(int s) {
 	for(int i=0;i<V;i++) d[i]=INF;
 	d[s]=0;
 	while(true) {
 		bool update=false;
 		for(int i=0;i<E;i++) {
 			edge e=es[i];
 			if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost) {
 				d[e.to]=d[e.from]+e.cost;
 				update=true;
 			}
 		}
		if(!update) break;	 
	}
 }
 
 //if negative loop exists, return true
 bool find_negative_loop() {
 	memset(d,0,sizeof(d));
 	
 	for(int i=0;i<V;i++) {
 		for(int j=0;j<E;j++) {
 			edge e=es[j];
 			if(d[e.to]>d[e.from]+e.cost) {
 				d[e.to]=d[e.from]+e.cost;
 				if(i==V-1) return true;
 			}
		}
	}
	return false;
 }
 
 int main () {
 	
 	return 0;
 }
