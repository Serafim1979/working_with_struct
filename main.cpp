#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::max;
using std::setw;
using std::getline;
using std::string;

struct Data
{
    int year;
    int month;
};

struct Person
{
    char l_name[20];
    Data data;
};

Data input()
{
    Data tmp;
    cout << "Input year: ";
    cin >> tmp.year;
    cout << "Input month: ";
    cin >> tmp.month;
    return tmp;
}

void show_data(Data tmp)
{
    cout << tmp.year << " " << tmp.month << endl;
}

void print_data(Data *mas, int n)
{
    for(int i = 0; i < n; i++)
    {
        show_data(mas[i]);
    }
}

void add_data(Data *&mas, int &n)
{
    mas = (Data *)realloc(mas, (n + 1) * sizeof(Data));
    mas[n] = input();
    n++;
}

void del_data(Data *&mas, int &n, int year)
{
    for(int i = 0; i < n; i++)
    {
        while(i < n && mas[i].year == year)
        {
            for(int j = i; j < n - 1; j++)
            {
                mas[j] = mas[j + 1];
            }
            mas = (Data *)realloc(mas, (n - 1) * sizeof(Data));
            n--;
        }
    }
}

int main()
{
    int n = 0;
    Data *mas = NULL;
    add_data(mas, n);
    add_data(mas, n);
    print_data(mas, n);
    del_data(mas, n, 2001);
    print_data(mas, n);
    free(mas);

    return 0;
}
