class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        int allCircles = (num+1)/2;     //一共allCircles圈
        long n = num;
        //当前坐标在第curCircle圈
        int curCircle = min(min(yPos,xPos), min( num-xPos-1, num-yPos-1)) + 1;
        long area = n*n;    //总面积
        //当前圈的长宽
        long curN = (n - 2*(curCircle - 1));  //curCircle - 1 是外面的圈数
        long curCirArea = curN * curN;   //当前所在圈及以内的面积
        //得到当前圈左上角第一个元素的编号
        long index = (area - curCirArea) % 9 + 1;
        int rightDown = num - curCircle;    //右/下 边界索引
        int leftUp = curCircle - 1;   //左/上 边界索引
        if(xPos == leftUp){
            //在 --- 上
            index += yPos-leftUp;
        }else if(yPos == rightDown){
            //在   |上
            index += rightDown - leftUp;
            index += xPos - leftUp;
        }else if(xPos == rightDown){
            //在 __ 上
            index += 2*(rightDown - leftUp);
            index += rightDown - yPos;
        }else{
            //在 |  上
            index += 3*(rightDown-leftUp);
            index += rightDown - xPos;
        }
        return (int)( index % 9 == 0 ? 9 : index % 9 );
    }
};
