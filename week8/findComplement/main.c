class Solution {
public:
    int findComplement(int num) {
        //设置标志flag，用来记录num数的符号位
        int flag = 0;
        //i=1时，表示跳过第0位，从第1位开始遍历
        for (int i = 1; i <= 30; ++i) {
            if (num >= (1 << i)) {
                flag = i;
            }
            else {
                break;
            }            
        }
        //设置一个全1的数，用来与num值异或
        //当num31位的时候，使用0x7fffffff，否则使用后者
        int allone = (flag == 30 ? 0x7fffffff : (1 << (flag + 1)) - 1);
        return num ^ allone;
    }
};
