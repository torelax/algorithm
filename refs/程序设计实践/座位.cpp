#include <iostream>
#include <string>
using namespace std;
const int SEAT_NUM = 10;

class Seat {
    private:
        static int count;
    public:
        void acquire(string name = "seat") {
            if (count < SEAT_NUM)
            {
                ++ count;
                cout <<"boy: allocated "
                    << count << "/" << SEAT_NUM << endl;
            }
            else 
            {
                cout << "out of memory" << endl;
            }
        }

        void release()
        {
            if (count > 0)
            {
                cout << "release: " << count
                    << "/" << SEAT_NUM << endl;
                -- count;
            }
        }

    public:
        virtual ~Seat() {}
};

int Seat::count = 0;


class Boy : public Seat {
    private:
        bool flag;
        string name;
    public:
        Boy():flag(false) { 
        }

        virtual ~Boy() {
            Seat::release();
        }

        void giao() {
            flag = true;
            Seat::acquire(name);
        }
};

Boy *b[26];
int op[100], op2[100];

int main(int argc, char *argv[])
{
    int round_;
    int n;
    cin >> round_ >> n;
    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> op[i] >> c;
        op2[i] = c - 'a';
    }

    for (int i = 0; i < 26; ++i)
    {
        b[i] = NULL;
    }

    for (int r = 0; r < round_; ++r)
    {
        cout << "#round: " << r << endl;
        for (int i = 0; i < n; ++i)
        {
            int d = op2[i];
            delete b[d];
            b[d] = NULL;
            if (op[i] == 0)
            {
                b[d] = new Boy();
                b[d]->giao();
            }
        }
    }

    for (int i = 0; i < 26; ++i)
    {
        delete b[i];
    }
    return 0;
}


