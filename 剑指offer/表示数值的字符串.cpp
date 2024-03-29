#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// 有限状态自动机
enum State
{
    STATE_INITIAL,
    STATE_INT_SIGN,
    STATE_INTEGER,
    STATE_POINT,
    STATE_POINT_WITHOUT_INT,
    STATE_FRACTION,
    STATE_EXP,
    STATE_EXP_SIGN,
    STATE_EXP_NUMBER,
    STATE_END,
};
enum CharType
{
    CHAR_NUMBER,
    CHAR_EXP,
    CHAR_POINT,
    CHAR_SIGN,
    CHAR_SPACE,
    CHAR_ILLEGAL,
};
CharType getCharType(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return CHAR_NUMBER;
    }
    else if (ch == 'e' || ch == 'E')
    {
        return CHAR_EXP;
    }
    else if (ch == '.')
    {
        return CHAR_POINT;
    }
    else if (ch == '+' || ch == '-')
    {
        return CHAR_SIGN;
    }
    else if (ch == ' ')
    {
        return CHAR_SPACE;
    }
    else
    {
        return CHAR_ILLEGAL;
    }
}
bool isNumber(string s)
{
    //转移规则，c++没有HashMap
    unordered_map<State, unordered_map<CharType, State>> transfer{
        {
            STATE_INITIAL, {
                {CHAR_SPACE, STATE_INITIAL}, 
                {CHAR_SIGN, STATE_INT_SIGN},
                {CHAR_NUMBER,STATE_INTEGER}, //这个漏了
                {CHAR_POINT, STATE_POINT_WITHOUT_INT}
        }}, {
            STATE_INT_SIGN, {
                {CHAR_NUMBER, STATE_INTEGER}, 
                {CHAR_POINT, STATE_POINT_WITHOUT_INT}
        }}, 
        {
            STATE_INTEGER, {
                {CHAR_NUMBER, STATE_INTEGER}, 
                {CHAR_POINT, STATE_POINT}, 
                {CHAR_SPACE, STATE_END}, 
                {CHAR_EXP, STATE_EXP}
        }}, 
        {   
            STATE_POINT, {
            {CHAR_NUMBER, STATE_FRACTION}, 
            {CHAR_SPACE, STATE_END}, 
            {CHAR_EXP, STATE_EXP} //这个漏了
            }},
        {
            STATE_POINT_WITHOUT_INT, {
                {CHAR_NUMBER, STATE_FRACTION}
        }},
        {
            STATE_FRACTION, {
                {CHAR_NUMBER, STATE_FRACTION}, 
                {CHAR_SPACE, STATE_END}, 
                {CHAR_EXP, STATE_EXP} //这个漏了
        }},
        {
            STATE_EXP, {
                {CHAR_SIGN, STATE_EXP_SIGN}, 
                {CHAR_NUMBER, STATE_EXP_NUMBER}
        }},
        {
            STATE_EXP_SIGN, {
                {CHAR_NUMBER, STATE_EXP_NUMBER}
        }},
        {
            STATE_EXP_NUMBER, {
                {CHAR_NUMBER, STATE_EXP_NUMBER}, 
                {CHAR_SPACE, STATE_END} //这个也漏了
        }},
        {   
            STATE_END, {
                {CHAR_SPACE, STATE_END}
        }}};

    State st = STATE_INITIAL;//初始状态
    for (int i = 0; i < s.length(); i++)
    {
        CharType ct = getCharType(s[i]);
        if (transfer[st].find(ct) == transfer[st].end())
        {
            return false;//不存在这样的转移规则，提前中止
        }
        else
        {
            st = transfer[st][ct];//状态转移
        }
    }
    return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;//接受状态
}
// 原书上的解法，要多增加几个判断，见代码最后
// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
// bool scanUnsignedInteger(const char **s)
// {
//     const char *before = *s;
//     while (**s != '\0' && **s >= '0' && **s <= '9')
//     {
//         ++(*s);
//     }
//     return *s > before;
// }
// bool scanInteger(const char **s)
// {
//     if (**s == '+' || **s == '-')
//     {
//         ++(*s);
//     }
//     return scanUnsignedInteger(s);
// }
// bool isNumber(string s)
// {
//     const char *str = s.c_str(); //string转换为char *，方法c_str()指定返回const char *
//     if (str == nullptr)
//     {
//         return false;
//     }
//     while (*str == ' ')
//     {
//         str++;
//     }

//     bool re = scanInteger(&str);

//     if (*str == '.')
//     {
//         str++;

//         re = scanUnsignedInteger(&str) || re;
//         // re = re || scanUnsignedInteger(&str);//这里或的东西前后位置不一样都不行，仔细斟酌。re已经为true，程序就不会执行||后面的东西，指针就不会后移
//     }

//     if (*str == 'e' || *str == 'E')
//     {
//         str++;
//         re = re && scanInteger(&str);
//     }
//     while (*str == ' ')
//     {
//         str++;
//     }

//     return re && *str == '\0';
// }

int main()
{
    cout << isNumber(".") << endl;
    return 0;
}
// 力扣上这个题比原书上多加了几个该死的测试点，即允许字符串首末两端有一些额外的空格。
// "1 "
// " "
// " 0"