#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

typedef map<char, int> Map_ci;
typedef map<int, char> Map_ic;
typedef map<size_t, int> Map_ii;

Map_ci priority;

Map_ic getProposition(string formula);//该函数返回所输入公式中的命题变项(不包括运算符)
int findProposition(Map_ic, char p);//命题变项计数并返回下标
int pow2(size_t n);//计算指定数字的二次方
Map_ii toBinary(size_t n_proposition, int index);//返回命题变项的二进制取值，参数index表示一个二进制序列的十进制数值
int calculate(string formula, Map_ic pSet, Map_ii value);//该函数返回给定命题变项组合的运算结果
int check(stack<int>& value, stack<char>& opter);//该函数返回两个命题变项的各种运算结果

int main()
{
    //运算符优先级
    priority['('] = 6;
    priority[')'] = 6;
    priority['!'] = 5;
    priority['&'] = 4;
    priority['|'] = 3;
    priority['^'] = 2;
    priority['~'] = 1;
    priority['#'] = 0;

    //打印提示信息
    cout << "***************************************\n";
    cout << "**                                   **\n";
    cout << "**         欢迎进入逻辑运算软件      **\n";
    cout << "**   (可运算真值表,主范式,支持括号)  **\n";
    cout << "**                                   **\n";
    cout << "**              用!表示非            **\n";
    cout << "**              用&表示与            **\n";
    cout << "**              用|表示或            **\n";
    cout << "**             用^表示蕴含           **\n";
    cout << "**             用~表示等值           **\n";
    cout << "**                                   **\n";
    cout << "***************************************\n\n";
    cout << "请输入一个合法的命题公式(命题变量用单个字母表示): " << endl;
    string formula;
    cin >> formula;
    Map_ic proposition_set = getProposition(formula);

    //预错误处理
    for (int i = 0; i < pow2(proposition_set.size()); i++)
    {
        //bina_set存放对与命题变量的各种赋值,通过toBinary函数
        Map_ii bina_set_test = toBinary(proposition_set.size(), i);
        //计算运算结果
        calculate(formula, proposition_set, bina_set_test);
    }
    cout << "该式子中的变量个数为：" << proposition_set.size() << endl << "输出真值表如下：" << endl;

    //输出变量和输入的表达式
    for (int i = 0; i < proposition_set.size(); i++)
    {
        cout << proposition_set[i] << "\t";
    }
    cout << formula << endl;

    //记录命题公式每次的运算结果
    int* m;
    m = new int[pow2(proposition_set.size())];
    for (int i = 0; i < pow2(proposition_set.size()); i++)
    {
        //bina_set存放对与命题变量的各种赋值,通过toBinary函数，每一个i就对应一个二进制序列
        Map_ii bina_set = toBinary(proposition_set.size(), i);
        for (int j = 0; j < bina_set.size(); j++)
        {
            cout << bina_set[j] << "\t";
        }
        //把这个二进制序列传入calculate函数，得到运算结果
        int result = calculate(formula, proposition_set, bina_set);
        m[i] = result;
        cout << result << endl;
    }
    int n_m = 0, n_M = 0;

    //求主析取范式
    cout << "该命题公式的主析取范式：" << endl;
    for (int i = 0; i < pow2(proposition_set.size()); i++)
    {
        if (m[i] == 1)
        {
            if (n_m == 0)
            {
                cout << "m<" << i << ">";
            }
            else
            {
                cout << " \\/ m<" << i << "> ";
            }
            n_m++;
        }
    }
    if (n_m == 0)
    {
        cout << "0";
    }
    cout << endl;

    //求主合取范式
    cout << "该命题公式的主合取范式：" << endl;
    for (int i = 0; i < pow2(proposition_set.size()); i++)
    {
        if (m[i] == 0)
        {
            if (n_M == 0)
            {
                cout << "M<" << i << ">";
            }
            else
            {
                cout << " /\\ M<" << i << "> ";
            }
            n_M++;
        }
    }
    if (n_M == 0)
    {
        cout << "0";
    }
    cout << endl;
    system("pause");
    return 0;
}

//命题变项计数并返回下标
int findProposition(Map_ic pSet, char p)
{
    Map_ic::iterator it = pSet.begin();
    while (it != pSet.end())
    {
        if (it->second == p)
        {
            return it->first;
        }
        it++;
    }
    return -1;
}

//该函数返回所输入公式中的命题变项(不包括运算符)
Map_ic getProposition(string formula)
{
    Map_ic proposition;
    //表示这个命题变相对应的编号
    int n_proposition = 0;
    for (int i = 0; i < formula.length(); i++)
    {
        char c = formula[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            //此时遍历所有命题变项
            int r = findProposition(proposition, c);
            if (r == -1)
            {
                //说明该命题变项尚未被遍历过
                proposition[n_proposition] = c;
                n_proposition++;
            }
        }
        //判断是否有不合法字符出现
        else if (!priority.count(c))
        {
            cout << c << "不符合输入要求" << endl;
            system("pause");
            exit(2);
        }
    }
    return proposition;
}

//返回命题变项的二进制取值，参数index表示一个二进制序列的十进制数值
Map_ii toBinary(size_t n_proposition, int index)
{
    Map_ii result;
    for (size_t i = 0; i < n_proposition; i++)
    {
        int r = index % 2;
        result[n_proposition - 1 - i] = r;//每个命题变量得到一个赋值
        index = index / 2;
    }
    return result;//返回的是命题变量对应的二进制序列
}

//计算指定数字的二次方
int pow2(size_t n)
{
    if (n == 0)
        return 1;
    else
        return 2 * pow2(n - 1);
}

//返回两个命题变项的各种运算结果
int check(stack<int>&value, stack<char>&opter)
{
    bool p, q, result;
    char opt = opter.top();

    switch (opt)
    {
    //与运算
    case '&':
        if (value.size() < 2)
        {
            cout << "输入算式不合法!" << endl;
            system("pause");
            exit(-1);
        }
        p = value.top();
        value.pop();
        q = value.top();
        value.pop();
        result = p && q;
        value.push(result);
        opter.pop();
        break;

    //或运算
    case '|':
        if (value.size() < 2)
        {
            cout << "输入算式不合法!" << endl;
            system("pause");
            exit(-1);
        }
        p = value.top();
        value.pop();
        q = value.top();
        value.pop();
        result = p || q;
        value.push(result);
        opter.pop();
        break;

    //非运算
    case '!':
        p = value.top();
        value.pop();
        result = !p;
        value.push(result);
        opter.pop();
        break;

    //蕴含运算
    case '^':
        if (value.size() < 2)
        {
            cout << "输入算式不合法!" << endl;
            system("pause");
            exit(-1);
        }
        q = value.top();
        value.pop();
        p = value.top();
        value.pop();
        result = !p || q;
        value.push(result);
        opter.pop();
        break;

    //等值运算
    case '~':
        if (value.size() < 2)
        {
            cout << "输入算式不合法!" << endl;
            system("pause");
            exit(-1);
        }
        p = value.top();
        value.pop();
        q = value.top();
        value.pop();
        result = (!p || q) && (p || !q);
        value.push(result);
        opter.pop();
        break;
    
    //判断是否处理完毕
    case '#':
        if (value.size() != 1)
        {
            cout << "输入算式不合法!" << endl;
            system("pause");
            exit(-1);
        }
        break;

    //处理左括号
    case '(':
        break;

    //处理右括号
    case ')':
        opter.pop();
        while (opter.top() != '(')
        {
            if (value.size() == 1) {
                cout << "输入算式不合法!" << endl;
                system("pause");
                exit(-1);
            }
            check(value, opter);
        }
        if (opter.top() == '(')
        {
            opter.pop();
        }
        break;

    default:
        break;
    }
    return 0;
}

//返回给定命题变项组合的运算结果
int calculate(string formula, Map_ic pSet, Map_ii value)
{
    //定义运算符栈与运算数栈
    stack<char> opter;
    stack<int> pvalue;
    //增添#进行语法分析
    opter.push('#');
    formula = formula + "#";
    for (int i = 0; i < formula.length(); i++)
    {
        char c = formula[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            //运算数入栈
            pvalue.push(value[findProposition(pSet, c)]);
        }
        else
        {
            char tmp = opter.top();
            //若栈外元素优先级小于栈顶元素，则进行计算
            if (priority[tmp] > priority[c])
            {
                while (priority[tmp] > priority[c] && tmp != '(')
                {
                    int sum = check(pvalue, opter);
                    if (sum == -1)
                    {
                        cout << "输入算式不合法!" << endl;
                        system("pause");
                        exit(-1);
                    }
                    tmp = opter.top();
                    //判断最后栈内是否只留下结果
                    if (tmp == '#' && c == '#')
                    {
                        if (pvalue.size() == 1)
                        {
                            return pvalue.top();
                        }
                        else
                        {
                            cout << "输入算式不合法!" << endl;
                            system("pause");
                            exit(-1);
                        }
                    }
                }
                opter.push(c);
            }
            else {
                opter.push(c);
            }
        }
    }
    if (pvalue.size() == 1)
    {
        return pvalue.top();
    }
    else
    {
        cout << "输入算式不合法!" << endl;
        system("pause");
        exit(-1);
    }
}
