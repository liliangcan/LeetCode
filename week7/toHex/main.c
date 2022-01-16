class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        int val;
        char digit;
        string temp = "";
        // for (int i = 7; i >= 0; i --) {            
        //     val = (num >> (4 * i)) & 0xf;   //每次取低四位到val中
        //     if (temp.length() > 0 || val > 0) {
        //         //此处是ASC码计算
        //         digit = val < 10 ? (char) ('0' + val) : (char) ('a' + val - 10);
        //         temp.push_back(digit);
        //     }
        // }
        while(num != 0 && temp.length() < 8){
            val = num & 0xf;
            digit = val < 10 ? (char) ('0' + val) : (char) ('a' + val - 10);
            // temp.push_back(digit);
            temp.insert(temp.begin(),digit);
            num >>= 4;
        }
        return temp;
    }
};
