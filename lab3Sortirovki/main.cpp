#include <iostream>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
using namespace std;

using namespace std;

double c2 =0, c =0;
double c21 =0, c1 =0;
double c211 =0, c11 =0;
double t11 = 0, t21 = 0, t31;
double t12 = 0, t22 = 0, t32;
double t13 = 0, t23 = 0, t33;

class AbstrSort {

public:
virtual void Sort(int t);
void Sort1(int t);
void Sort2(int t);
void Sort3(int t);
void in(int s);
void Out(int t);
void Outdo(int t);
void rands(int t);
	int x,a[1000],b,y[1000];
int digit(int t, int p)
{
    return (t>>(8 * p) & 255);
}


};
class bubble : public AbstrSort
{
    public:
void Sort(int t)
{
    t11 = t11 + clock();
    int k=0;
    for (int i=0; i<t ; i++)
    {
        for (int j=0; j<t-i; j++)
        {
            if (a[j]>a[j+1])
            {
                c++;
                c2++;
                swap(a[j],a[j+1]);
            }
        }
    }
    t21 = t21 + clock();
}
};
class Gnome : public AbstrSort
{
    public:
void Sort(int t)
{
    t12 = t12 + clock();
    int i=0;
    while (i < t)
        if (i == 0 || a[i - 1] <= a[i])
            {++i; c21++;}
        else { swap(a[i], a[i - 1]); --i; c1++; }
        t22 = t22 + clock();
}
};
class Radix : public AbstrSort
{
    public:
void Sort(int t)
{
    t13 = t13 + clock();
    int k = sizeof(int);
    for(int i = 0; i < k; i++)
    {
        int c[256] = {0};
        for(int j = 0; j < t; j++)
        {
            c[digit(a[j],i)]++;
        }
        for(int j = 1; j < 256;j++)
        {
           // c11++;
            c[j]+=c[j-1];
        }
        for(int j = t-1; j >-1;j--)
        {
            c11++;
            y[--c[digit(a[j],i)]] = a[j];
        }
        for(int j = 0; j < t; j++)
        {
            //c11++;
            a[j] = y[j];
        }
    }
    t23 = t23 + clock();

}
};

void AbstrSort::rands(int t)
{
    for (int i = 0; i < t; i++)
{
    a[i] = rand()%10+1;
}
}
void AbstrSort::Outdo(int t)
{
    for (int i=0; i<t; i++)
    cout << a[i] <<" ";
    cout << endl;
}
void AbstrSort::Out(int t)
{
    for (int i=0; i<t; i++)
    cout << a[i] <<" ";
    cout << endl;
    delete a;
}
void AbstrSort::Sort(int t)
{

}
void AbstrSort ::Sort2(int t)
{

}
void AbstrSort::Sort3(int t)
{

}



int main()
{
    setlocale(LC_ALL, "rus");
    int b;
    bubble v;
    Gnome v2;
    Radix v3;
    cout << " Введите длину массива : "<< endl;
    cin >> b;
    srand ( time(NULL) );
    for (int i = 1; i<=100; i++)
    {
        v.rands(b);
      //  v.Outdo(b);
        v.Sort(b);
       // cout << "Отсортированный массив методом пузырька :"<<endl;
      // v.Out(b);
        //cout << endl;
    };
         srand ( time(NULL) );
    for (int i = 1; i<=100; i++)
    {
        v2.rands(b);
        //v2.Outdo(b);

        v2.Sort(b);
       // cout << "Отсортированный массив методом пузырька :"<<endl;
       // v2.Out(b);
       // cout << endl;
    };
         srand ( time(NULL) );
    for (int i = 1; i<=100; i++)
    {
        v3.rands(b);
       // v3.Outdo(b);
        v3.Sort(b);
       // cout << "Отсортированный массив методом пузырька :"<<endl;
       // v3.Out(b);
        //cout << endl;
    }
t31 = t21-t11;
t32 = t22-t12;
t33 = t23-t13;
cout <<"перестановки/сравнения: "<< endl;
cout << c/100<<" "<< c2/100<<" "<< t31/100000<< endl;
cout << c1/100<<" "<< c21/100<<" "<< t32/100000<< endl;
cout << c11/100<<" "<< c211/100<<" "<< t33/100000<< endl;
    return main();
}
