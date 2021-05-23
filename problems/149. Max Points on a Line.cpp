#include<bits/stdc++.h>
using namespace std;

// solved
// TODO : ALGO:
// Bruteforce : {
//     --> select a pair of numbers from the array  ( O(n*n) )
//     --> make a line .... i.e find a slope and intercept (or something equivalent)
//     --> count all other points which are on that line;( O(n) )

//     time complexity : O(n*n*n)
// }

// If we select one point on a line and if other point lies on the same line they will have the same slope (m);

// Optimized {
//     --> select a point 
//     --> iterate on array and Store the slope in MAP.
//     --> if the slope is same for a point then it lies on the same line,
//      hence MAP value should be increased

//      -->STORING IN MAP {
//          Now here is the real trick 

//         --> if we store slope in double format... we cannot be accurate always.

//          so we can use denominator{x1-x2} and numerator{y1-y2} as keys to 2-D MAP; 
//             eg : M[x1-x2][y1-y2]

//         -->it has a issues what about 2,3 and 4,6 they are same.

//         Sol ::.... use gcd of numerator and denominator and divide both of them to map to same value;
//      }
//      time complexity : O(n*n)
//      space complexity : O(n*n*n*n) due to map in worst case
// }


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {\
        // if points less than 2
        if(points.size()<2)
            return points.size();

        int mxInLine=2;
        for(int i=0;i<points.size();i++){
            // make a 2d map 
            unordered_map<int,unordered_map<int,int>> M;
            
            for(int j=0;j<points.size();j++){
                if(i==j)
                    continue;

                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                
                int temp=0;
                int gcd = __gcd(abs(x2-x1),abs(y2-y1));
                if(x1-x2<0){
                    temp = ++M[(x2-x1)/gcd][(y2-y1)/gcd];
                }
                else
                    temp = ++M[(x1-x2)/gcd][(y1-y2)/gcd];
                
                mxInLine = max(mxInLine,temp+1);
            }
            
        }
        
        return mx;
    }
};


int main(){
    vector<vector<int>> points ={{1,1},{2,2},{3,3},{4,0},{0,4},{3,1},{1,3}};

    Solution sol;
    // cout << "hello" <<endl;
    cout << sol.maxPoints(points) <<endl;
    
    return 0;
}