/**编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。  **/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string strcommonTmp,strcommon;
        for (int len = 0; len < strs[0].length(); len++)
        {
            strcommonTmp += strs[0][len];
            int flag = true;
            for (int i = 0; i < strs.size(); i++)
            {
                if(strs[i][len] != strcommonTmp[len])
                    return strcommon;
            }
            strcommon += strs[0][len];
        }
        return strcommon;
    }
};