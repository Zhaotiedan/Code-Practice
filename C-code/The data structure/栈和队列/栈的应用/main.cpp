1. 栈在括号匹配中的应用
链接：https://www.nowcoder.com/questionTerminal/37548e94a270412c8b9fb85643c8ccc2
来源：牛客网

给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。

//cpp写法，利用stack容器

class Solution {
public:
    
    bool isValid(string s) {
        /*   //如果括号总数为奇数，直接报错 注意该条件可有可无，因为当扫描到右括号时，如果栈空（代表没有一个左括号）会直接返回false
        if(s.size()%2!=0)
        {
            return false;
        }*/
        
        stack<char> st;
        
        for(int i=0;i<s.size();i++)
        {
            //左括号 直接入栈
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                st.push(s[i]);
            }
            //右括号
            else
            {
             //如果此时栈空，则直接false
                if(st.empty())
                {
                    return false;
                }
                char temp=st.top();//获取栈顶的左括号
                st.pop();//注意一定要出栈
                
                //不合法的三种情况
                if(s[i]==')')
                {
                    if(temp!='(')
                    {
                        return false;
                    }
                }
                else if(s[i]==']')
                {
                    if(temp!='[')
                    {
                        return false;
                    }
                }
                else if(s[i]=='}')
                {
                    if(temp!='{')
                    {
                        return false;
                    }
                }
            }
        }
        //如果栈为空，则说明全部匹配，合法
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
