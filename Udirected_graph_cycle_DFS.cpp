#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(vector<int>adj[],int s,bool visited[],int parent){
        visited[s]=true;
        for (int i:adj[s]){
            if (!visited[i]){
                if (DFS(adj,i,visited,s))
                    return true;
            }
            else if (i!=parent)
            return true;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[]){
	    bool visited[V];
	    fill(visited,visited+V,false);
	    for (int i=0;i<V;i++){
	        if (!visited[i]){
	            if (DFS(adj,i,visited,-1))
	            return true;
	        }
	    }
	    return false;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
} 