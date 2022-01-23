class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r = img.size(), c = img[0].size();
        vector<vector<int>> ans(r,vector<int>(c,-1));
        if(r == 1 && c == 1){
            return img;
        }
        if(r == 2 && c == 2){
            int tempSum = 0;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    tempSum += img[i][j];
                }
            }
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    ans[i][j] = tempSum/4;
                }
            }
            return ans;
        }
        if(r == 1){
            for(int i = 0; i < c; i++){
                if(i == 0){
                    ans[0][i] = (img[0][i] + img[0][i+1])/2;
                }else if(i == c-1){
                    ans[0][i] = (img[0][i] + img[0][i-1])/2;
                }else{
                    ans[0][i] = (img[0][i-1] + img[0][i] + img[0][i+1])/3;
                }
            }
            return ans;
        }
        if(c == 1){
            for(int i = 0; i < r; i++){
                if(i == 0){
                    ans[i][0] = (img[i][0] + img[i+1][0])/2;
                }else if(i == r-1){
                    ans[i][0] = (img[i][0] + img[i-1][0])/2;
                }else{
                    ans[i][0] = (img[i-1][0] + img[i][0] + img[i+1][0])/3;
                }
            }
            return ans;
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(i == 0 && j == 0){
                    ans[i][j] = (img[i][j] + img[i][j+1] + img[i+1][j+1] + img[i+1][j])/4;
                }else if(i == 0 && j == c-1){
                    ans[i][j] = (img[i][j] + img[i][j-1] + img[i+1][j-1] + img[i+1][j])/4;
                }else if(i == r-1 && j == 0){
                    ans[i][j] = (img[i][j] + img[i-1][j] + img[i-1][j+1] + img[i][j+1])/4;
                }else if(i == r-1 && j == c-1){
                    ans[i][j] = (img[i][j] + img[i-1][j] + img[i-1][j-1] + img[i][j-1])/4;
                }else if(i == 0){
                    ans[i][j] = (img[i][j] + img[i][j+1] + img[i+1][j+1] + img[i+1][j]
                                + img[i][j-1] + img[i+1][j-1])/6;
                }else if(i == r-1){
                    ans[i][j] = (img[i][j] + img[i][j+1] + img[i-1][j+1] + img[i-1][j]
                                + img[i][j-1] + img[i-1][j-1])/6;
                }else if(j == 0){
                    ans[i][j] = (img[i][j] + img[i][j+1] + img[i-1][j+1] + img[i-1][j]
                                + img[i+1][j] + img[i+1][j+1])/6;
                }else if(j == c-1){
                    ans[i][j] = (img[i][j] + img[i][j-1] + img[i-1][j-1] + img[i-1][j]
                                + img[i+1][j] + img[i+1][j-1])/6;
                }else{
                    ans[i][j] = (img[i][j] + img[i-1][j] + img[i-1][j+1] + img[i][j+1]
                                + img[i+1][j+1] + img[i+1][j] + img[i+1][j-1] + img[i][j-1]
                                + img[i-1][j-1])/9;
                }
            }
        }
        return ans;
    }
};
