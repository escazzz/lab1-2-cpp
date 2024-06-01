#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//#include "stdafx.h"
using namespace std;
class expo // Класс экспонент
{
    string name;   // Имя
    double cost;   // Стоимость одного дня экспонирования
    int duration;  // Время экспонирования
    double price;  // Цена за все экспонирование
public:
    expo() // Конструктор без параметров создает "пустой" объект
    {
        price = 0;
        duration = 0;
        cost = 0;
    }
    void set(string na, double r, int d, double p) // Функция для инициализации полей для
        // созданного "пустого" объекта
    {
        price = p;
        name = na; // Копируем строку, содержащую марку автомобиля
        cost = r; // Задаем значение расхода топлива на 100 км
        duration = d; //Задаем значение длительности экспонирования
    }
    expo(string na, double r, int d, double p) // Конструктор для инициализации полей
    {
        price = p;
        duration = d;
        name = na; // Копируем строку, содержащую название экспонента
        cost = r; // Задаем значение цены
    }
    double findMax(double max)
    {
        if (price > max)
            max = price;
        return max;
    }
    friend ostream& operator<<(ostream& os, const expo& ob);
};
ostream& operator<<(ostream& os, const expo& ob) {
    os << "name: " << ob.name << " cost: " << ob.cost << " duration: " << ob.duration << " price: " << ob.price << endl;
    return os;
}
int main()
{
    ifstream input("D:/text/input.txt");
    ofstream output("D:/text/output.txt");
    int n; // Неизвестное число объектов
    input >> n;
    string str; double r; int d; double p; // Вспомогательные переменные для ввода марки
    // автомобиля и расхода топлива

    expo* pExpo; // Указатель на массив
    pExpo = new expo[n]; // Для каждого объекта вызывается конструктор без параметров,
    // т.е. созданы "пустые" объекты
    vector<expo> vecExpo(n); // Создаем пустые объекты, вызывается конструктор без параметров

    // Цикл ввода данных для объектов
    for (size_t i = 0; i < n; i++)
    {
        input >> str; // Ввод названия
        input >> r; // Ввод стоимости
        input >> d; // Ввод длительности экспонирования
        p = d * r; //Подсчет суммы
        pExpo[i].set(str, r, d, p); // Вызываем функцию set для инициализации полей
        vecExpo[i].set(str, r, d, p); // Инициализация для vector
        // объектов
    }
    // Цикл печати полей для объектов
    for (size_t i = 0; i < n; i++) {
        output << pExpo[i] << endl;
        cout << pExpo[i] << endl;
    }
    double max = 0;
    for (size_t i = 0; i < n; i++) if (max < pExpo[i].findMax(max)) max = pExpo[i].findMax(max);
    cout << "Max price= " << max;
    output << "Max price= " << max;
    //system("pause");
}
