#include "stack.h"

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//测试类
class Evaluate
{
public:
    static void evaluate(void)
    {
        Stack<string> ops;
        Stack<double> vals;
        while (!cin.eof())
        {
            string s;
            cin >> s;
            // cout << s << endl;
            if (s == "(")   continue;
            else if (s == "+")  ops.push(s);
            else if (s == "-")  ops.push(s);
            else if (s == "*")  ops.push(s);
            else if (s == "/")  ops.push(s);
            else if (s == "sqrt")   ops.push(s);
            else if (s == ")")
            {
                // cout << "ops.size: " << ops.size() << endl;
                // cout << "vals.size: " << vals.size() << endl;
                string op = ops.pop();
                double v = vals.pop();

                if (op == "+")  v = vals.pop() + v;
                else if (op == "-") v = vals.pop() - v;
                else if (op == "*")  v = vals.pop() * v;
                else if (op == "/") v = vals.pop() / v;
                else if (op == "sqrt")  v = sqrt(v);

                // cout << "v: " << v << endl;
                vals.push(v);
            }
            else
            {
                vals.push(stod(s));
                // cout << stod(s) << "stod(s)" << endl;
            }

            // cout << "------------" << endl;
        }
        cin.clear();
        //cout << "===========" << endl;
        //cout << "size: " << vals.size() << endl;
        //cout << vals.pop() << endl;
    }
};

int main(void)
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);

    cout << stack.pop() << endl;
    cout << stack.size() << endl;
    stack.pop();
    cout << stack.isEmpty() << endl;

    Evaluate::evaluate();

    return 0;
}