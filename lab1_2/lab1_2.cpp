#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//#include "stdafx.h"
using namespace std;
class expo // ����� ���������
{
    string name;   // ���
    double cost;   // ��������� ������ ��� ��������������
    int duration;  // ����� ��������������
    double price;  // ���� �� ��� ��������������
public:
    expo() // ����������� ��� ���������� ������� "������" ������
    {
        price = 0;
        duration = 0;
        cost = 0;
    }
    void set(string na, double r, int d, double p) // ������� ��� ������������� ����� ���
        // ���������� "�������" �������
    {
        price = p;
        name = na; // �������� ������, ���������� ����� ����������
        cost = r; // ������ �������� ������� ������� �� 100 ��
        duration = d; //������ �������� ������������ ��������������
    }
    expo(string na, double r, int d, double p) // ����������� ��� ������������� �����
    {
        price = p;
        duration = d;
        name = na; // �������� ������, ���������� �������� ����������
        cost = r; // ������ �������� ����
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
    int n; // ����������� ����� ��������
    input >> n;
    string str; double r; int d; double p; // ��������������� ���������� ��� ����� �����
    // ���������� � ������� �������

    expo* pExpo; // ��������� �� ������
    pExpo = new expo[n]; // ��� ������� ������� ���������� ����������� ��� ����������,
    // �.�. ������� "������" �������
    vector<expo> vecExpo(n); // ������� ������ �������, ���������� ����������� ��� ����������

    // ���� ����� ������ ��� ��������
    for (size_t i = 0; i < n; i++)
    {
        input >> str; // ���� ��������
        input >> r; // ���� ���������
        input >> d; // ���� ������������ ��������������
        p = d * r; //������� �����
        pExpo[i].set(str, r, d, p); // �������� ������� set ��� ������������� �����
        vecExpo[i].set(str, r, d, p); // ������������� ��� vector
        // ��������
    }
    // ���� ������ ����� ��� ��������
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
