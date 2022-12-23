#include <iostream>
#include <algorithm> 

const int N = 100; 

using namespace std;


int findMin(int* a, int n) { //функція щоб знайти мінімальний елемент
 int min = a[0];
 for (int i = 1; i < n; i++) {
  if (a[i] < min) {
   min = a[i];
  }
 }
return min;
}


int findMax(int* a, int n) { //функція щоб знайти максимальний елемент
 int max = a[0];
 for (int i = 1; i < n; i++) {
  if (a[i] > max) {
   max = a[i];
  }
 }
 return max;
}

void zavd(){
 //ініціалізуємо змінні
 int a[N]; 
 int n; 
 int l; 
 int p = 1;
 int sum = 0; 

 //просимо вести розмір масиву, його елементи та значення L
 cout << "Введіть розмір масиву: ";
 cin >> n;
 
 if(n < 2){ // Якщо вказана кількість елементів масиву меньше 2, рекурсивно перезапускати функцію
    cout << "Елементів масиву повинно бути більше ніж 1" << endl;
    zavd();
    return;
 }

 cout << "Ввести елементи масиву: ";
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 cout << "Введіть значення L: ";
 cin >> l;
 


 
 
 for (int i = 0; i < n; i += 2) { //обчислюємо добуток P з елементів масиву які меньше L та від'ємні
  if (a[i] < l && a[i] < 0) {
   p *= a[i];
  }
 }
 
 for (int i = 0; i < n; i++) { //сума всіх додотніх елементів
  if (a[i] > 0) {
   sum += a[i];
  }
 }

 
 for (int i = 0; i < n; i++) { //ділимо всі додатні елементи масиву на P
  if (a[i] > 0) {
   a[i] /= p;
  }
 }
 
 //знаходимо мінімальний та максимальний елемент
 int min = findMin(a, n);
 int max = findMax(a, n);
 
 sort(a + min, a + max); //сортуємо

 cout << "Підсумковий масив: "; 
 for (int i = 0; i < n; i++) { //результат
  cout << a[i] << endl;
 }
 
 cout << "Максимальний елемент: " << max << endl;
 cout << "Мінімальний елемент: " << min << endl;
}

int main() {
 setlocale(LC_ALL, "Ukrainian");
 
 zavd();
 
 return 0;
}
