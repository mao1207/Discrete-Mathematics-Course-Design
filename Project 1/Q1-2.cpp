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

Map_ic getProposition(string formula);//�ú������������빫ʽ�е��������(�����������)
int findProposition(Map_ic, char p);//�����������������±�
int pow2(size_t n);//����ָ�����ֵĶ��η�
Map_ii toBinary(size_t n_proposition, int index);//�����������Ķ�����ȡֵ������index��ʾһ�����������е�ʮ������ֵ
int calculate(string formula, Map_ic pSet, Map_ii value);//�ú������ظ������������ϵ�������
int check(stack<int>& value, stack<char>& opter);//�ú������������������ĸ���������

int main()
{
    //��������ȼ�
    priority['('] = 6;
    priority[')'] = 6;
    priority['!'] = 5;
    priority['&'] = 4;
    priority['|'] = 3;
    priority['^'] = 2;
    priority['~'] = 1;
    priority['#'] = 0;

    //��ӡ��ʾ��Ϣ
    cout << "***************************************\n";
    cout << "**                                   **\n";
    cout << "**         ��ӭ�����߼��������      **\n";
    cout << "**   (��������ֵ��,����ʽ,֧������)  **\n";
    cout << "**                                   **\n";
    cout << "**              ��!��ʾ��            **\n";
    cout << "**              ��&��ʾ��            **\n";
    cout << "**              ��|��ʾ��            **\n";
    cout << "**             ��^��ʾ�̺�           **\n";
    cout << "**             ��~��ʾ��ֵ           **\n";
    cout << "**                                   **\n";
    cout << "***************************************\n\n";
    cout << "������һ���Ϸ������⹫ʽ(��������õ�����ĸ��ʾ): " << endl;
    string formula;
    cin >> formula;
    Map_ic proposition_set = getProposition(formula);

    //Ԥ������
    for (int i = 0; i < pow2(proposition_set.size()); i++)
    {
        //bina_set��Ŷ�����������ĸ��ָ�ֵ,ͨ��toBinary����
        Map_ii bina_set_test = toBinary(proposition_set.size(), i);
        //����������
        calculate(formula, proposition_set, bina_set_test);
    }
    cout << "��ʽ���еı�������Ϊ��" << proposition_set.size() << endl << "�����ֵ�����£�" << endl;

    //�������������ı��ʽ
    for (int i = 0; i < proposition_set.size(); i++)
    {
        cout << proposition_set[i] << "\t";
    }
    cout << formula << endl;

    //��¼���⹫ʽÿ�ε�������
    int* m;
    m = new int[pow2(proposition_set.size())];
    for (int i = 0; i < pow2(proposition_set.size()); i++)
    {
        //bina_set��Ŷ�����������ĸ��ָ�ֵ,ͨ��toBinary������ÿһ��i�Ͷ�Ӧһ������������
        Map_ii bina_set = toBinary(proposition_set.size(), i);
        for (int j = 0; j < bina_set.size(); j++)
        {
            cout << bina_set[j] << "\t";
        }
        //��������������д���calculate�������õ�������
        int result = calculate(formula, proposition_set, bina_set);
        m[i] = result;
        cout << result << endl;
    }
    int n_m = 0, n_M = 0;

    //������ȡ��ʽ
    cout << "�����⹫ʽ������ȡ��ʽ��" << endl;
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

    //������ȡ��ʽ
    cout << "�����⹫ʽ������ȡ��ʽ��" << endl;
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

//�����������������±�
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

//�ú������������빫ʽ�е��������(�����������)
Map_ic getProposition(string formula)
{
    Map_ic proposition;
    //��ʾ�����������Ӧ�ı��
    int n_proposition = 0;
    for (int i = 0; i < formula.length(); i++)
    {
        char c = formula[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            //��ʱ���������������
            int r = findProposition(proposition, c);
            if (r == -1)
            {
                //˵�������������δ��������
                proposition[n_proposition] = c;
                n_proposition++;
            }
        }
        //�ж��Ƿ��в��Ϸ��ַ�����
        else if (!priority.count(c))
        {
            cout << c << "����������Ҫ��" << endl;
            system("pause");
            exit(2);
        }
    }
    return proposition;
}

//�����������Ķ�����ȡֵ������index��ʾһ�����������е�ʮ������ֵ
Map_ii toBinary(size_t n_proposition, int index)
{
    Map_ii result;
    for (size_t i = 0; i < n_proposition; i++)
    {
        int r = index % 2;
        result[n_proposition - 1 - i] = r;//ÿ����������õ�һ����ֵ
        index = index / 2;
    }
    return result;//���ص������������Ӧ�Ķ���������
}

//����ָ�����ֵĶ��η�
int pow2(size_t n)
{
    if (n == 0)
        return 1;
    else
        return 2 * pow2(n - 1);
}

//���������������ĸ���������
int check(stack<int>&value, stack<char>&opter)
{
    bool p, q, result;
    char opt = opter.top();

    switch (opt)
    {
    //������
    case '&':
        if (value.size() < 2)
        {
            cout << "������ʽ���Ϸ�!" << endl;
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

    //������
    case '|':
        if (value.size() < 2)
        {
            cout << "������ʽ���Ϸ�!" << endl;
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

    //������
    case '!':
        p = value.top();
        value.pop();
        result = !p;
        value.push(result);
        opter.pop();
        break;

    //�̺�����
    case '^':
        if (value.size() < 2)
        {
            cout << "������ʽ���Ϸ�!" << endl;
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

    //��ֵ����
    case '~':
        if (value.size() < 2)
        {
            cout << "������ʽ���Ϸ�!" << endl;
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
    
    //�ж��Ƿ������
    case '#':
        if (value.size() != 1)
        {
            cout << "������ʽ���Ϸ�!" << endl;
            system("pause");
            exit(-1);
        }
        break;

    //����������
    case '(':
        break;

    //����������
    case ')':
        opter.pop();
        while (opter.top() != '(')
        {
            if (value.size() == 1) {
                cout << "������ʽ���Ϸ�!" << endl;
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

//���ظ������������ϵ�������
int calculate(string formula, Map_ic pSet, Map_ii value)
{
    //���������ջ��������ջ
    stack<char> opter;
    stack<int> pvalue;
    //����#�����﷨����
    opter.push('#');
    formula = formula + "#";
    for (int i = 0; i < formula.length(); i++)
    {
        char c = formula[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            //��������ջ
            pvalue.push(value[findProposition(pSet, c)]);
        }
        else
        {
            char tmp = opter.top();
            //��ջ��Ԫ�����ȼ�С��ջ��Ԫ�أ�����м���
            if (priority[tmp] > priority[c])
            {
                while (priority[tmp] > priority[c] && tmp != '(')
                {
                    int sum = check(pvalue, opter);
                    if (sum == -1)
                    {
                        cout << "������ʽ���Ϸ�!" << endl;
                        system("pause");
                        exit(-1);
                    }
                    tmp = opter.top();
                    //�ж����ջ���Ƿ�ֻ���½��
                    if (tmp == '#' && c == '#')
                    {
                        if (pvalue.size() == 1)
                        {
                            return pvalue.top();
                        }
                        else
                        {
                            cout << "������ʽ���Ϸ�!" << endl;
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
        cout << "������ʽ���Ϸ�!" << endl;
        system("pause");
        exit(-1);
    }
}
