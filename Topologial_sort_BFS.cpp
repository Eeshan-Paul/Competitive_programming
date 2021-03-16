#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int>v;
	    int indegree[V]={0};
	    for (int u=0;u<V;u++){
	        for (int v:adj[u])
	        indegree[v]++;
	    }
	    int count=-1;
	    queue<int>q;
	    for (int i=0;i<V;i++){
	        if (indegree[i]==0)
	            q.push(i);
	    }
	    while (!q.empty()){
	        int u=q.front();
	        q.pop();
	        v.push_back(u);
	        for (int i:adj[u]){
	            indegree[i]--;
	            if (indegree[i]==0)
	            q.push(i);
	        }
	    }
	    return v;
	}
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  