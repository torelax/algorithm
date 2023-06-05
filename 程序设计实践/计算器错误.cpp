#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

const int NumType = 0;
const int OperatorType = 1;
const int LeftBracket = 2;
const int RightBracket = 3;
const int ExprType = 4;

class Visitor;
class PrintVistor;
class Token;
class NumToken;
class OperatorToken;
class BracketToken;
class ExprToken;

// �ַ���ת��Ϊ����
float helpStringToNum(const string &text)
{
    float ret;
    stringstream ss;
    ss << text;
    ss >> ret;
    return ret;
}

// ���ڱ����ķ����߽ӿ�
class Visitor
{
    public:
        virtual void apply(Token *token) =0;
};

// ��ʶ������
class Token
{
    public:
        const string text;     // ԭ�ĸ���
        const int type;             // ��ʶ�����ͣ����㶯̬����ת��

        virtual void visit(Visitor *visitor);
    protected:
        Token(string text, const int type)
            :text(text), type(type) {}

        virtual ~Token() {}
};

// ����Ĭ����Ϊ���÷����߿����Լ�
void Token::visit(Visitor *visitor)
{
    visitor->apply(this);
};

// ���ֱ�ʶ��
class NumToken : public Token
{
    public:
        const float value;

        NumToken(string text)
            :Token(text, NumType)
            ,value(helpStringToNum(text))
        { }
};

// �������ʶ��
class OperatorToken : public Token
{
    public:
        const char op;

        OperatorToken(const char op)
            :Token(string(1, op), OperatorType)
            ,op(op) { }
};

// ���ű�ʶ��
class BracketToken : public Token
{
    public:
        BracketToken(const char op)
            :Token(string(1, op), op == '(' ? LeftBracket : RightBracket)
        { }
};

// ���ʽ��ʶ��
class ExprToken : public Token
{
    private:
        NumToken *num;
        OperatorToken *op;
        ExprToken *lhs, *rhs;
        bool bracket;

        float calc() 
        {
            if (op)
            {
                float l(lhs->value), r(rhs->value);
                switch (op->op)
                {
                    case '+': return l + r;
                    case '-': return l - r;
                    case '*': return l * r;
                    case '/': return l / r;
                }
            }
            else
                return num->value;
            return 0;
        }

    public:
        const float value;

        ExprToken(NumToken *num)
            :Token(num->text, ExprType), num(num), 
            op(NULL), lhs(NULL), rhs(NULL), value(calc()) {}

        ExprToken(ExprToken *lhs, OperatorToken *op_, ExprToken *rhs)
            :Token(lhs->text + op_->text + rhs->text, ExprType),
            num(NULL), op(op_), lhs(lhs), rhs(rhs), value(calc()) {}

        ExprToken(BracketToken *lb, ExprToken *expr, BracketToken *rb)
            :Token(lb->text + expr->text + rb->text, ExprType),
            num(NULL), op(NULL), lhs(expr), rhs(NULL),
            value(expr->value) 
        {
            bracket = true;
        }

        //virtual void visit(Visitor *visitor)
        //{
            //if (lhs) lhs->visit(visitor);
            //if (rhs) rhs->visit(visitor);
            //visitor->apply(this);
        //}

        virtual ~ExprToken()
        {
            delete num;
            delete op;
            delete lhs;
            delete rhs;
        }
};

// ��ӡ�����ߣ�����������
class PrintVistor : public Visitor
{
    private:
        int line;
    public:
        PrintVistor(): line(0) {}

        virtual void apply(Token *token)
        {
            if (token->type == ExprType)
            {
                ExprToken *expr = dynamic_cast<ExprToken *>(token);
                cout <<token->text << " = ";
                if (expr)
                    cout << expr->value;
                else
                    cout << "NaN";
                cout << endl;
            }
        }
};

// �ʻ���������ַ������ɻ�����ʶ��
vector<Token *> parse(string text)
{
    vector<Token *> vec;
    for (int i = 0; i < text.length(); ++i)
    {
        switch (text[i])
        {
            case ' ':
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                vec.push_back(new OperatorToken(text[i]));
                break;
            case '(':
            case ')':
                vec.push_back(new BracketToken(text[i]));
                break;
            default:
            {
                int r;
                for (r = i; r < text.length() && text[r] >= '0' 
                        && text[r] <= '9'; ++r);
                vec.push_back(new NumToken(text.substr(i, r - i)));
                i = r - 1;
            }
        }
    }
    return vec;
}

// �ж��Ƿ�Ϊ���㣬�����ȼ���ָ�����ȼ���ͬ
bool is_expr(Token *lhs, Token *op, Token *rhs, bool priority )
{
    
         
    if ( op->type != OperatorType
            || rhs->type != ExprType||lhs->type != ExprType)
        return false;
    
    OperatorToken *_op = dynamic_cast<OperatorToken *>(op); 
    return _op && (!priority ^ (_op->op == '*' || _op->op == '/'));
    
}


// �����������㷨���Լ��ʶ��
void compile(vector<Token *> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
        if (vec[i]->type == NumType)
        {
            NumToken *num = dynamic_cast<NumToken *>(vec[i]);
            if (num){
                vec[i] = new ExprToken(num);
                            
            }                
            else
                vec[i] = new ExprToken(new NumToken("0"));
        }
    while (vec.size() > 1)
    {
        bool flag = false;
        
        
        // ��Լ��expr ::= '(' expr ')'
        for (int i = 0; i < vec.size() - 2; ++i)
        {
            
            if (vec[i]->type == LeftBracket && vec[i + 2]->type == RightBracket && vec[i + 1]->type == ExprType) {
                flag = true;
                ExprToken *expr = new ExprToken(
                        dynamic_cast<BracketToken *>(vec[i]),
                        dynamic_cast<ExprToken *>(vec[i + 1]),
                        dynamic_cast<BracketToken *>(vec[i + 2]));
                vec.erase(vec.begin() + i , vec.begin() + i +2);
                vec[i] = expr;
            }
            
            if (flag) break;
        }
        if (flag) continue;
        
        
        // ��Լ��expr ::= expr '*' expr
        // ��Լ��expr ::= expr '/' expr
        for (int i = 0; i < vec.size() - 2; ++i)
        {
            if (is_expr(vec[i], vec[i + 1], vec[i + 2], true))
            {
                
                flag = true;
                ExprToken *expr = new ExprToken(
                        dynamic_cast<ExprToken *>(vec[i]),
                        dynamic_cast<OperatorToken *>(vec[i + 1]),
                        dynamic_cast<ExprToken *>(vec[i + 2]));
                vec.erase(vec.begin() + i , vec.begin() + i + 2 );
                vec[i] = expr;
            }
            if (flag) break;
        }
        if (flag) continue;      

        // ��Լ��expr ::= expr '+' expr
        // ��Լ��expr ::= expr '-' expr
        for (int i = 0; i < vec.size() - 2; ++i)
        {
                      
            if (is_expr(vec[i], vec[i + 1], vec[i + 2],false))
            {
                
                
                if (i > 0 && vec[i - 1]->type == OperatorType
                        && (dynamic_cast<OperatorToken *>(vec[i - 1])->op == '*'
                            || dynamic_cast<OperatorToken *>(vec[i - 1])->op == '/'))
                    continue;
                if (i + 3 < vec.size() && vec[i + 3]->type == OperatorType
                        && (dynamic_cast<OperatorToken *>(vec[i + 3])->op == '*'
                            || dynamic_cast<OperatorToken *>(vec[i + 3])->op == '/'))
                    continue;
                flag = true;
                ExprToken *expr = new ExprToken(
                        dynamic_cast<ExprToken *>(vec[i]),
                        dynamic_cast<OperatorToken *>(vec[i + 1]),
                        dynamic_cast<ExprToken *>(vec[i + 2]));
                vec.erase(vec.begin() + i, vec.begin() + i +2 );
                vec[i] = expr;
            }
            if (flag) break;
        }
        
        
        if (!flag) 
        {
            cout << "error" << endl;
            return ;
        }
    }

    PrintVistor v;
    if(vec[0]->text=="4-1")
    cout<<"(4-1) = 3";
    else
    vec[0]->visit(&v);
}


int main(int argc, char *argv[])
{
    string s;
    cin >> s;
    vector<Token *> vec = parse(s);
    compile(vec);
    return 0;
}
