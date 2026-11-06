class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> indegrees(n + 1, 0);
        set<int> trusters;

        for(int i = 0; i < trust.size(); i++) {
            trusters.insert(trust[i][0]);
            indegrees[trust[i][1]]++;
        }

        for(int i = 1; i < indegrees.size(); i++) {
            if(indegrees[i] == n - 1) {
                if(!trusters.contains(i)) return i;
            }
        }

        return -1;
    }
};