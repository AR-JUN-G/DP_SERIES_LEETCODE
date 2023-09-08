class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;
        ans.push_back({1});

        for(int i=1;i<n;i++)
        {
            vector<int>previousRow=ans.back();
            vector<int>newRow={1};
            for(int j=1;j<previousRow.size();j++)
            {
                newRow.push_back(previousRow[j-1]+previousRow[j]);
            }
            newRow.push_back({1});
            ans.push_back(newRow);
        }
        return ans;
    }
};
