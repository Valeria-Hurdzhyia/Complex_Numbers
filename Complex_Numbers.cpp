#include<iostream>
#include<string>

using namespace std;

template <class T>    //шаблон класса Т

class Complex     //класс Complex
{
protected:
    T im;
    T re;

public:
    char i = 'i';

    Complex(T im = 0, T re = 0)    // конструктор с параметрами
    {
        this->im = im;
        this->re = re;
    }

    Complex(const Complex<T>& im, const Complex<T>& re)  // консруктор копирования
    {
        this->im = im.im;
        this->re = re.re;
    }

    ~Complex()   // деструктор 
    {

    }

    void Print()    // функция вывода
    {
        if (re < 0)
        {
            cout << im << re;
        }
        else
        {
            cout << im << "+" << re;
        }
    }


    template <class T> friend Complex<T> operator + (const Complex<T>& first, const Complex<T>& second);   // дружественная функцию класса для перегрузки оператора (+)
    template <class T> friend Complex<T> operator *(const Complex<T>& first, T chislo);        // дружественная функцию класса для перегрузки оператора (*)
    template <class T> friend Complex<T> operator -(const Complex<T>& first, const Complex<T>& second);   //дружественная функцию класса для перегрузки оператора (-)
    Complex& operator =(const Complex<T>& d);        //дружественная функцию класса для перегрузки оператора (=)

};




template <class T> Complex<T> operator + (const Complex<T>& first, const Complex<T>& second)    //Описываем дружественную функцию класса для перегрузки оператора (+)

{
    int im;
    int re;
    im = first.im + second.im;
    re = first.re + second.re;

    return Complex<T>(im, re);
}

template <class T> Complex<T> operator - (const Complex<T>& first, const Complex<T>& second)    //Описываем дружественную функцию класса для перегрузки оператора (-)
{
    int im;
    int re;

    im = first.im - second.im;
    re = first.re - second.re;
    return Complex<T>(im, re);
}

template <class T> Complex<T> operator *(const Complex<T>& first, T chislo)    //Описываем дружественную функцию класса для перегрузки оператора (*)
{

    int im = first.im * chislo;
    int re = first.re * chislo;
    return Complex<T>(im, re);


}
template <class T> Complex<T>& Complex<T>::operator =(const Complex<T>& d)   //Описываем дружественную функцию класса для перегрузки оператора (=)
{

    this->im = d.im;
    this->re = d.re;
    return *this;

}
int main()
{
    setlocale(LC_ALL, "ru");

    int im_1, re_1, im_2, re_2;
    cout << "Первое комплексное число:" << endl;
    cout << "Введите целое :" << endl;
    cin >> im_1;
    cout << "Введите воображаемое:" << endl;
    cin >> re_1;

    cout << "Второе комплексное число:" << endl;
    cout << "Введите целое:" << endl;
    cin >> im_2;
    cout << "Введите воображаемое целое:" << endl;
    cin >> re_2;

    cout << endl;

    Complex<int> a(im_1, re_1), b(im_2, re_2), c, d, f, imag;     //інстанціювання
    cout << "Первое комплексное число:" << endl;

    a.Print();
    cout << imag.i << endl;
    cout << "--------" << endl;
    cout << "Второе комплексное число: " << endl;

    b.Print();
    cout << imag.i << endl;
    cout << "--------" << endl;
    cout << "Результат суммирования комплексных чисел:" << endl;

    c = a + b;
    c.Print();
    cout << imag.i << endl;
    cout << "--------" << endl;
    cout << "Результат отнимания комплексных чисел: " << endl;

    f = a - b;
    f.Print();
    cout << imag.i << endl;
    cout << "--------" << endl;
    cout << "Операция умножения комплексного числа на действительное:" << endl;
    int chislo;
    cout << "Введите число для умножения первого комплексного числа:" << endl;
    cin >> chislo;

    d = a * chislo;
    d.Print();
    cout << imag.i << endl;
    cout << "--------" << endl;

    return 0;
}