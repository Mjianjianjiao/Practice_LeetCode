leetcode 17 电话号码的字母组合

给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![img](http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

**示例:**

```
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

```

**说明:**
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

```
 char* numtochar[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class Solution {     
    public:
    void  _letterCombinations(string digits,vector<string>& combinations,string onecomb,int i)
    {
        if(i==digits.size())
        {
            combinations.push_back(onecomb);
            return;
        }
        
        string str=numtochar[digits[i]-'0'];//取出数字对应的字符串
        for(int j=0;j<str.size();j++)
        {
            _letterCombinations(digits,combinations,onecomb+str[j],i+1); //每次取一个字符放入，直到所有字符都放入
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty())
            return vector<string> ();
        
        vector<string> combinations;  //存放所有组合
        string onecomb; //存放单个组合
        
        int i=0;//控制层数
        _letterCombinations(digits,combinations,onecomb,0);
        
        return combinations;
    }
};
```

