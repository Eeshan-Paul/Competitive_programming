#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	void DFS(int u,vector<int>adj[],stack<int>&s,bool visited[]){
	    visited[u]=true;
	    for (int i:adj[u]){
	       if (!visited[i])
	       DFS(i,adj,s,visited);
	    }
	    s.push(u);
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int>v;
        stack<int>s;
        bool visited[V];
        fill(visited,visited+V,false);
        for (int i=0;i<V;i++){
            if (visited[i]==false)
            DFS(i,adj,s,visited);
        }
        while (!s.empty())
        {
            v.push_back(s.top());
            s.pop();
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