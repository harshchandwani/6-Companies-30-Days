class Solution {
   
public:
    void process(set<pair<int,int>>&st,int x,int y){
        if(st.count({x,y})){
            auto it = st.find({x,y});
            st.erase(it);
            return;
        }

        st.insert({x,y});
    }

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //there is even number of all corners except four corners (outmost corners)
        int bottomX=INT_MAX,bottomY=INT_MAX;
        int topX = INT_MIN,topY = INT_MIN;
        long long areas = 0; //actual area (sum of indivisuals area)

        for(vector<int> &v : rectangles){
            long long l = v[2] - v[0] , b = v[3] - v[1];
            areas += (l*b);
            
            bottomX = min(bottomX,v[0]);
            bottomY = min(bottomY,v[1]);

            topX = max(topX,v[2]);
            topY = max(topY,v[3]);
        }

        long long allRectangleArea = (topX - bottomX) *1LL * (topY - bottomY);
        //sum of areas of all rectangles must be equal to area of overall rectangle
        if(areas != allRectangleArea) return false;
        
        //now check there must be only four points single others are even numbered
        set<pair<int,int>> st;
        for(vector<int> & v : rectangles){
            process(st,v[0],v[1]);
            process(st,v[2],v[3]);
            process(st,v[2],v[1]);
            process(st,v[0],v[3]);
        }
        
        if(st.size() != 4) return false;

        //now check if got points are expected or not
        set<pair<int,int>> expectedPoints;
        expectedPoints.insert({bottomX,bottomY});
        expectedPoints.insert({bottomX,topY});
        expectedPoints.insert({topX,topY});
        expectedPoints.insert({topX,bottomY});

        return st == expectedPoints;
    }
};

