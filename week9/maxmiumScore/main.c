class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(),cards.end());
        int n = cards.size();
        int sum = 0, count = 0, lastOdd = 0, lastEven = 0;
        for(int i = n-1; count < cnt && i >= 0; i--){
            if(cards[i]%2 != 0){
                //记录最后一个奇数
                lastOdd = cards[i];
            }else{
                //记录最后一个偶数
                lastEven = cards[i];
            }
            sum += cards[i];    //sum随时累加上
            count++;            //count记录此时已经有了几个数了
            //如果数量已经齐了但是sum却不是偶数时
            if(count == cnt && sum%2 != 0){
                //如果已经到了第一个数，说明没有可替换的，直接返回0
                if(i == 0){
                    return 0;
                }
                while(i > 0){
                    if(cards[i-1]%2 == 0){
                        //如果前一个数是偶数，则用它替换lastOdd
                        sum += cards[i-1] - lastOdd;
                        break;
                    }else if(lastEven != 0){
                        //如果lastEven存在，且前一个数是奇数，用它替代lastEven
                        sum += cards[i-1] - lastEven;
                        break;
                    }else if(i-1 == 0){
                        //若前一个数是奇数且没有可以跟它替换的lastEven，则返回0
                        return 0;
                    }else{
                        //以上都满足，就继续去找前一个元素
                        i--;
                    }
                }
            }
        }
        return sum;
    }
};
