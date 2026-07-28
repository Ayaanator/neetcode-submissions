class Solution {
public:
    int SIZE = 0;

    bool dfs(vector<vector<int>>& p, vector<bool>& v, vector<bool>& vi, int n) {
        v[n] = true;
        vi[n] = true;

        for(auto num : p[n]) {
            if(!v[num]) {
                if(dfs(p, v, vi, num)) {
                    return true;
                }
            } else if(vi[num]) {
                return true;
            }

        }

        vi[n] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        SIZE = numCourses;

        vector<bool> vis(SIZE, false);
        vector<bool> visiting(SIZE, false);

        vector<vector<int>> graph(numCourses);

        for(auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        for(int i = 0; i < SIZE; i++) {
            if (!vis[i]) {
                if (dfs(graph, vis, visiting, i)) {
                    return false;
                }
            }
        }

        return true;
    }
};
