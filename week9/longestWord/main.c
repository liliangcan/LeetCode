class Solution {
public:
    string longestWord(vector<string>& words) {
        //从小到大排序
        sort(words.begin(), words.end());
        unordered_set<string> mySet;
        //从空开始记录
        string ans = "";  
        mySet.insert(ans);
        for(auto& word: words){
            //若该单词的前n-1位存在mySet中
            if(mySet.find(string(word.begin(), word.end() - 1)) != mySet.end()){
                //如果长度更长，更新答案
                if(word.size() > ans.size()){
                    ans = word; 
                }
                mySet.insert(word);  //记录这个单词
            }
        }
        return ans;
    }
};
