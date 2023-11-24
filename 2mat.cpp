#include <iostream>
using namespace std;

class matris
{
    signed long m[2][2];
    public:
    int menu();
    void input_matris();
    void output_matris();
    matris operator+(matris m2);
    matris operator-(matris m2);
    matris operator*(matris m2);
    double determinate();
    void inverse();
    void i_metod();
};

int matris::menu()
{
    int a;
    cout << "1)addition two matrix 2*2 :" << endl;
    cout << "2)subtraction two matrix 2*2 :" << endl;
    cout << "3)multiplication two matrix 2*2 :" << endl;
    cout << "4)determination a matrix 2*2 :" << endl;
    cout << "5)inverse matrix 2*2 :" << endl;
    cout << "6)print imetod matrix 2*2 :" << endl;
    cout << "7)exit :" << endl;

    cout << '\n' << "enter your selection: ";
    cin >> a;
    cout << endl;
    return a;
}

void matris::input_matris()
{
    //خالی کردن خونه ها
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            m[i][j] = '   ';
        }
    }


    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << "enter a number for [" << i << "]" << "[" << j << "]:" << endl;
            cin >> m[i][j];
            }
        cout << endl << endl;}    
}

void matris::output_matris()
{
    system("clear");
    // if (m[i][j] < 10)
        // m[i][j] = m[i][j] +' '; 

    // cout << "  " << m[0][0] << "  |   " << m[0][1] << "   |  " << m[0][2] << endl;
    cout << "___" << m[0][0] << "___|___" << m[0][1] << "___" << endl;
    // cout << "  " << m[1][0] << "  |   " << m[1][1] << "   |  " << m[1][2] << endl;
    cout << "___" << m[1][0] << "___|___" << m[1][1] << "___" << endl;
    // cout << "  " << m[2][0] << "  |   " << m[2][1] << "   |  " << m[2][2] << endl;

}



matris matris::operator+(matris m2)
{
    matris s;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            s.m[i][j] = m[i][j] + m2.m[i][j];
    return s;
}

matris matris::operator-(matris m2)
{
    matris k;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            k.m[i][j] = m[i][j] - m2.m[i][j];
    return k;
}

matris matris::operator*(matris m2)
{
    matris z;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++){
            z.m[i][j] = 0;
            for (int k = 0; k < 2; k++)
            z.m[i][j] += m[i][k] * m2.m[k][j];
            }
    return z;
}

double matris::determinate()
{
    // input_matris();
    double i;
    i = ((m[0][0]*m[1][1]) - (m[0][1] * m[1][0]));
    return (i);
}

void matris::inverse()
{
    double d, temp, k[2][2];
    input_matris();
    cout << "your matris :" << endl;
    output_matris();
    cout << endl << endl;


    /////////// نتیجه
    d = determinate();
    cout << "finally : " << endl;
    cout << "d:" << d << endl;

 // بررسی قابلیت معکوس بودن ماتریس
    if (d == 0) {
        cout << "we can NOT inverse this mstrix !" << endl;
        return;
    }

// محاسبه معکوس ماتریس
    k[0][0] = m[1][1];
    k[0][1] = -m[0][1];
    k[1][0] = -m[1][0];
    k[1][1] = m[0][0];



    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 2; y++){
            k[x][y] = (k[x][y]/d);
            cout << "[" << x << "][" << y << "]:" << k[x][y] << '\t';
            }
        cout << endl;
        }


}



void matris::i_metod()
{
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++)
            if (i == j)
                cout << "[" << i << "]" << "[" << j << "]:" << (m[i][j] = 1) << '\t';
            else
                cout << "[" << i << "]" << "[" << j << "]:" << (m[i][j] = 0) << '\t';
        cout << endl;
        }
    cout << endl << endl;
}


int main()
{
    matris m1,m2,m3;
     while (1)
    {
        switch (m1.menu())
        {
        case 1:
        cout << "***m1***" << endl;
            m1.input_matris();
            m1.output_matris();
            cout << "***m2***" << endl;
            m2.input_matris();
            m2.output_matris();
            m3 = m1+ m2;
            m3.output_matris();
            cout << "***m3***" << endl;
            break;
        case 2:
            cout << "***m1***" << endl;
            m1.input_matris();
            m1.output_matris();
            cout << "***m2***" << endl;
            m2.input_matris();
            m2.output_matris();
            m3 = m1 - m2;
            m3.output_matris();
            cout << "***m3***" << endl;
            break;
        case 3:
            cout << "***m1***" << endl;
            m1.input_matris();
            m1.output_matris();
            cout << "***m2***" << endl;
            m2.input_matris();
            m2.output_matris();
            m3 = m1 * m2;
            m3.output_matris();
            cout << "***m3***" << endl;
            break;
        case 4:
            m1.input_matris();
            cout << "determinan : " << m1.determinate() << endl << endl;
            break;
        case 5:
            m1.inverse();
            break;
        case 6:
            m1.i_metod();
            break;
        case 7:
            exit(1);
        default:
            cout << "YOUR RUNG!!!" << endl << "try again :" << endl << endl;
            break;
        }
    }
}

