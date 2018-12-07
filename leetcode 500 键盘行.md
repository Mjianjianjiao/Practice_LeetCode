leetcode 500 键盘行

给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。

 

![American keyboard](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/keyboard.png)

 

**示例：**

```
输入: ["Hello", "Alaska", "Dad", "Peace"]
输出: ["Alaska", "Dad"]

```

 

**注意：**

1. 你可以重复使用键盘上同一字符。
2. 你可以假设输入的字符串将只包含字母。

```
//解法一
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        if(words.empty())
            return vector<string> ();
        //建立每个字符所在行的标识，与字母的映射
        int arr[]={2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
        
        vector<string> return_s;
        
        int flag = 0;
        int i = 0, j = 0;
        
        for(i = 0; i < words.size(); ++i){
            
            flag = arr[tolower(words[i][0]) - 97];
            for(j = 1; j < words[i].size(); ++j){
                //如果该单词中有其他行的字母，跳到下一个单词
                if(arr[tolower(words[i][j]) - 97] != flag)
                    break;
            }
            
            //如果所有字母都在同一行就将其插入
            if(j == words[i].size()){
                return_s.push_back(words[i]);
            }
                
        }
            
        return return_s;
    }
};
```



