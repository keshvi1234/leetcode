class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<points.size();i++)
        {
            v.push_back({(points[i][0]*points[i][0]+points[i][1]*points[i][1]),i});
        }
        sort(v.begin(),v.end());
        vector<vector<int>>a;
        for(int i=0;i<v.size();i++)
        {
            if(k!=0)
            {
                a.push_back(points[v[i].second]);
                k--;
            }
        }
        return a;
    }
};