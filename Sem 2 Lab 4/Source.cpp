#include <math.h>
#include <stdio.h>

#include <iostream>
#include <locale>
#include <random>  // для std::random_device и std::mt19937
#include <vector>

using namespace std;
const int N = 1000;  //Максимальное количество элементов в массивах
const int length = 8;  //Максимальное количество разрядов в числе

void print_array(double a[], int m) {
  // cout << "Результат работы с массивом:" << endl;
  for (int i = 0; i < m; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void zadanie1() {
  double k = 0, min, max, a[N] /*= { 1,-40,33,28,74,62,43,88,12,3 }*/,
         new_element = 0;
  int i = 0, max_index = 0, min_index = 0, new_element_index = 0, m = 0;
  bool b[N] = {false}, k_bool = false;

  cout << "Введите количество элементов массива: " << endl;
  cin >> m;
  while ((m <= 0) || (m > N)) {
    cout
        << "Вы неверно введи количество элементов массива. Попробуйте еще раз: "
        << endl;
    cin >> m;
  }

  cout << "Введите элементы массива: " << endl;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  /*for (int i = 0; i < N; i++) {
          a[i] = double(i)+1;
  }*/

  cout << "Начальный массив:" << endl;
  for (int i = 0; i < m; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  //Поиск максимального и минимального элемента массивов
  min = a[0];
  max = a[0];
  for (i = 0; i < m; i++) {
    if (a[i] > max) {
      max = a[i];
      max_index = i;
    }
    if (a[i] < min) {
      min = a[i];
      min_index = i;
    }
  }
  cout << "Max = " << max << ", Min = " << min << endl;
  new_element_index = (max_index + min_index) / 2;

  //Смещение элементов массива
  for (i = m - 1; i > new_element_index; i--) {
    k = a[i - 1];
    a[i - 1] = a[i];
    a[i] = k;
  }
  cout << "Введите новое значение для элемента массива" << endl;
  cin >> new_element;
  a[new_element_index] = new_element;

  // cout << "Этап работы №1:" << endl; //Внедрение нового элемента массива с
  // последующим смещением дальшестоящих вправо
  print_array(a, m);

  for (i = 0; i < m; i++) {  //Изменение значения элементов в массиве
    if (abs(a[i]) < abs(a[i] - new_element)) {
      b[i] = true;
    }
    a[i] = abs(a[i] - new_element);
  }

  // cout << "Этап работы №2:" << endl;
  // print_array(a);

  for (i = 0; i < m; i++) {  //Перестановка элементов в массиве

    for (int j = 0; j < m; j++) {
      if (a[i] < a[j]) {
        k = a[i];
        a[i] = a[j];
        a[j] = k;
        k_bool = b[i];
        b[i] = b[j];
        b[j] = k_bool;
      }
    }
  }

  // cout << "Этап работы №3:" << endl;
  // print_array(a);

  for (i = 0; i < m; i++) {  //Восстановление значения элементов в массиве
    if (b[i] == true) {
      a[i] -= new_element;
      a[i] *= -1;
    } else
      a[i] += new_element;
  }

  // cout << "Этап работы №4:" << endl;
  print_array(a, m);
}

void zadanie2() {
  int a[N] = {0}, b[length] = {0}, i = 0, j = 0, count, m;

  cout << "Введите количество элементов массива: " << endl;
  cin >> m;
  while ((m <= 0) || (m > N)) {
    cout
        << "Вы неверно введи количество элементов массива. Попробуйте еще раз: "
        << endl;
    cin >> m;
  }

  cout << "Введите элементы массива: " << endl;
  for (i = 0; i < m; i++) {
    cin >> a[i];
  }

  for (i = 0; i < m; i++) {
    j = 0;
    //Разложение числа на символы
    while (a[i] > 0) {
      b[j] = a[i] % 10;
      a[i] = a[i] / 10;
      j++;
    }
    //Перестановка символов
    int n = b[0];
    b[0] = b[j - 1];
    b[j - 1] = n;

    //Восстановление нового числа из символов
    for (int k = 0; k < j; k++) {
      a[i] += b[k] * pow(10, k);
    }
  }
  //Упорядочивание полученных чисел
  for (int i = 0; i < m - 1; i++) {
    if (a[i] < a[i + 1]) {
      int n = a[i];
      a[i] = a[m - i - 1];
      a[m - i - 1] = n;
    }
  }

  cout << "Результаты работы:" << endl;
  for (int i = 0; i < m; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void zadanie3() {}

int main() {
  zadanie1();
  zadanie2();


  return 0;
}