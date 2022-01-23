class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> score;
        for(auto& op: ops){
            if(op[0] <= '9' && op[0] >= '0' || op[0] == '-') {
                score.push((stoi)(op));             //是数
            }else if(op[0] == 'C') {
                score.pop();                //删除上一个分数
            }else if(op[0] == '+'){             //是上两个分数的总和
                int tmp = score.top();          //拿出上一个分数
                score.pop();
                int tmp2 = tmp + score.top();   //记录上一个分数和上上个分数的和
                score.push(tmp);                //放回上一个分数
                score.push(tmp2);                   //放入和
            }else if(op[0] == 'D') {
                score.push(score.top() * 2);         //上一个分数的两倍
            }
        }
        int ans = 0;                        //记录总和
        while(!score.empty()){
            ans += score.top();
            score.pop();
        }
        return ans;
    }
};
