#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int mx=2;
        
        for(int i=0;i<points.size();i++){
            unordered_map<int,unordered_map<int,int>> M;
            
            for(int j=0;j<points.size();j++){
                if(i==j)
                    continue;
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                
                int val=0;
                if(x1-x2<0)
                    val = ++M[x2-x1][y2-y1];
                else
                    val = ++M[x1-x2][y1-y2];
                cout << "";
                mx = max(mx,val + 1);
            }
            
        }
        
        return mx;
    }
};

int main(){
    vector<vector<int>> points ={{1,1},{2,2},{3,3},{4,0},{0,4},{3,1},{1,3}};

    Solution sol;

    cout << sol.maxPoints(points) <<endl;
    return 0;
}