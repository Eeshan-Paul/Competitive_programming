#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(int s,vector<int>adj[],vector<bool>&visited,vector<bool>&recst){
        visited[s]=true;
        recst[s]=true;
        for (int i:adj[s]){
            if (!visited[i] && DFS(i,adj,visited,recst))
                    return true;
            else if (recst[i]==true)
                return true;
        }
        recst[s]=false;
        return false;
    }
	bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>visited(V+1,false);
        vector<bool>recst(V+1,false);
        for (int i=0;i<V;i++){
            if (!visited[i])
                if(DFS(i,adj,visited,recst))
                    return true;
        }
        return false;
	}
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}