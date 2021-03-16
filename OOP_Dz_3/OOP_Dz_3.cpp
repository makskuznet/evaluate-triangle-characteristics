// OOP_Dz_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

class Triangle
{
private:
	float side1, side2, angle;
public:
	Triangle(): side1(0.0), side2(0.0), angle(0.0)
	{}
	Triangle(float s1,float s2,float an)
	{
		side1=s1;
		side2=s2;
		angle=an;
	}
	float get_side1() const
	{
		return side1;
	}
	float get_side2()
	{
		return side2;
	}
	float get_angle()
	{
		return angle;
	}
	void set_side1(float val)
	{
		 side1=val;
	}
	void set_side2(float val)
	{
		 side2=val;
	}
	void set_angle(float val)
	{
		 angle=val;
	}
	virtual float square()  = 0;
	virtual float perimeter()  = 0;
	virtual ~Triangle() = 0;
};
class Rectangular: public Triangle
{
public:
	Rectangular(): Triangle()
	{};
	Rectangular(float s1,float s2,float an): Triangle(s1,s2,an)
	{};
	float square() override
	{
		return (get_side1()*get_side2()/2);
	}
	float perimeter() override
	{
		float side3=sqrt(get_side1()*get_side1()+get_side2()*get_side2());
		return (get_side1()+get_side2()+side3);
	}
};
class Isosceles: public Triangle
{
public:
	Isosceles(): Triangle()
	{};
	Isosceles(float s1,float s2,float an): Triangle(s1,s2,an)
	{};
	float square() override
	{
		return (get_side1()*get_side2()*sin(get_angle())/2);
	}
	float perimeter()
	{
		float side3 = sqrt(get_side1()*get_side1()+get_side2()*get_side2()-2*get_side1()*get_side2()*cos(get_angle()));
		return (get_side1()+get_side2()+side3);
	}
};
class Equilateral: public Triangle
{
public:
	Equilateral(): Triangle()
	{};
	Equilateral(float s1,float s2,float an): Triangle(s1,s2,an)
	{};
	~Equilateral()
	{};
	float square()
	{
		return (get_side1()*get_side1()*sqrt(3.0)/4);
	}
	float perimeter()
	{
		return (3*get_side1());
	}
};
class App {
private:
	int i;
public:
	App() {	}
	void Run() {
		while (i != 0) {
			cout << "Посчитать площадь и периметр прямоугольного треугольника: 1" << endl;
			cout << "Посчитать площадь и периметр равнобедренного треугольника: 2" << endl;
			cout << "Посчитать площадь и периметр равностороннего треугольника: 3" << endl;
			cout << "Выход : 0" << endl;
			cin >> i;
			system("cls");
			switch (i) {
			case 1: {
				cout << "Введите длины катетов: "<<endl;
				float s1,s2;
				cin>>s1>>s2;
				Rectangular treug(s1,s2,90);
				Triangle *pBase = &treug;
				while (i != 0) {
					cout << "Вывести площадь: 1" << endl;
					cout << "Вывести периметр: 2" << endl;
					cout << "Завершить работу: 0" << endl;
					cin >> i;
					system("cls");
					switch (i) {
					case 1: {
						cout<<pBase->square()<<endl;
						break;
					}
					case 2: {
						cout << pBase->perimeter() << endl;
						break;
					}
					case 0: break;
					default: {
						cout << "Неверный номер." << endl;
						break;
					}
							 
					}
				}
				break;
			}
			case 2: {
				cout << "Введите длины неравных сторон и угол между ними: "<<endl;
				float s1,s2,an;
				cin>>s1>>s2>>an;
				Isosceles treug(s1,s2,an);
				Triangle *pBase = &treug;
				while (i != 0) {
					cout << "Вывести площадь: 1" << endl;
					cout << "Вывести периметр: 2" << endl;
					cout << "Завершить работу: 0" << endl;
					cin >> i;
					system("cls");
					switch (i) {
					case 1: {
						cout << pBase->square() << endl;
						break;
					}
					case 2: {
						cout << pBase->perimeter() << endl;
						break;
					}
					case 0: break;
					default: {
						cout << "Неверный номер." << endl;
						break;
					}
							 
					}
				}
				break;
			}
			case 3: {
				cout << "Введите длину стороны: "<<endl;
				float s1;
				cin>>s1;
				Equilateral treug(s1,s1,60);
				Triangle *pBase = &treug;
				while (i != 0) {
					cout << "Вывести площадь: 1" << endl;
					cout << "Вывести периметр: 2" << endl;
					cout << "Завершить работу: 0" << endl;
					cin >> i;
					system("cls");
					switch (i) {
					case 1: {
						cout << pBase->square() << endl;
						break;
					}
					case 2: {
						cout << pBase->perimeter() << endl;
						break;
					}
					case 0: break;
					default: {
						cout << "Неверный номер." << endl;
						break;
					}
							 
					}
				}
				break;
			}
			case 0: break;
			default: {
				cout << "Неверный номер." << endl;
			}
			}
			}
		}
};

void main()
{
	setlocale(0, "russian");
	App a;
	a.Run();
}

