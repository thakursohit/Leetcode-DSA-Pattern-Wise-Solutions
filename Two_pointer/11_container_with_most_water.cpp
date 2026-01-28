class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int minInd = 0;
        int maxArea = 0;
        while(i<j){
            minInd = min(height[i],height[j]);
            int b = j-i;
            int area = b*minInd;
            maxArea = max(maxArea,area);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
        
    }
};
