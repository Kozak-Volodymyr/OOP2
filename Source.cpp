#include<iostream>
#include<cmath>
#include<Windows.h>
using namespace std;
class Kvadrat2D {
private:
	 int n;
	 double *Massyv;
public:
	 Kvadrat2D(double *Massyv) {//конструктор
		  this->n = 4; this->Massyv = new double[this->n];
		  for (int i = 0; i <this->n; i++) 
				this->Massyv[i] = Massyv[i];
		  
	 };
	  Kvadrat2D(int n,double *Massyv)//конструктор копіювання
	  {
     this->n = n; this->Massyv = new double[this->n];
     for (int i = 0; i < this->n; i++)
     this->Massyv[i] = Massyv[i];
	  }
	  Kvadrat2D(const Kvadrat2D&obj)
	  {
			n = obj.n, Massyv = new double[this->n];
			for (int i = 0; i < n; i++)
				 Massyv[i] = obj.Massyv[i];
	  }
	  ~Kvadrat2D() { delete[] Massyv;}//деструктор
	 int N(){
		  return n;
	 }
	 double Pl(double St)//площа
	 {
		  double k;
		  k = pow(St, 2);
		  return k;
	 }
	 double Pe(double St)//периметр
	 {
		  double g;
		  g = 4 * St;
		  return g;
	 }
	 double GetX() {
		  return Massyv[0];
	 }

	 double GetX1() {
		  return Massyv[1];
	 }
	 double GetY() {
		  return Massyv[2];
	 }
	 double GetY1() {
		  return Massyv[3];
	 }
	 double St(double *Massyv)//значення сторони
	 {
		  double St = 0;
		  St = sqrt(pow((Massyv[0] - Massyv[1]), 2) + pow((Massyv[2] - Massyv[3]), 2)) / sqrt(2);
		  return St;
	 }
};
int main() {
	 SetConsoleOutputCP(1251);
	 SetConsoleCP(1251);
	 double st,pl,pl1,st1;
	 double *arr=new double[4];
	 cout << "Введіть x:";
	 cin >> arr[0];
	 cout << "Введіть x1:";
	 cin >> arr[1];
	 cout << "Введіть y:";
	 cin >> arr[2];
	 cout << "Введіть y1:";
	 cin >> arr[3];
	 Kvadrat2D obj(arr);
	 Kvadrat2D obj1(3,arr);
	 Kvadrat2D obj2(obj);
	 st=obj.St(arr);
	 st1 = sqrt(pow((obj1.GetX() - obj2.GetX1()), 2) + pow((obj.GetY() - obj2.GetY1()), 2)) / sqrt(2);
	 if (st != st1) {
		  cout << "Неправильно";
		  return 0;
	 }
	 pl = obj2.Pl(st);
	 pl1 = obj1.Pl(st);
	 if (pl != pl1) {
		  cout << "Неправильно";
		  return 0;
	 }
	 cout << "Сторона квадрата:" << st << endl; 
	 cout << "Площа квадрата:" << obj.Pl(st) << endl;
	 cout << "Периметер квадрата:" << obj2.Pe(st) << endl;
	 return 0;
}