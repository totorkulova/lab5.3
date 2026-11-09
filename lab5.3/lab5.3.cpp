// lab5.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Функция, для которой вычисляется интеграл
double f(double x)
{
    return (x - 2) * (x - 2);
}

int main()
{
    setlocale (LC_ALL, "Russian");
    double a, b;
    int n;

    double h;
    double integral = 0;
    double exactIntegral;
    double error;

    // Ввод исходных данных
    cout << "Введите нижний предел интегрирования a: ";
    cin >> a;

    cout << "Введите верхний предел интегрирования b: ";
    cin >> b;

    cout << "Введите количество отрезков n: ";
    cin >> n;

    // Проверка корректности данных
    if (a >= b || n <= 0)
    {
        cout << "Ошибка: неверные исходные данные.";
        return 1;
    }

    // Вычисление шага интегрирования
    h = (b - a) / n;

    // Вычисление интеграла методом трапеций
    integral = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;

        integral += f(x);
    }

    integral *= h;

    // Вычисление точного значения интеграла
    exactIntegral =
        (pow(b - 2, 3) - pow(a - 2, 3)) / 3.0;

    // Вычисление абсолютной погрешности
    error = fabs(integral - exactIntegral);

    // Вывод результатов
    cout << fixed << setprecision(10);

    cout << "\nРезультаты вычислений:\n";

    cout << "Шаг интегрирования h = "
        << h << endl;

    cout << "Интеграл методом трапеций = "
        << integral << endl;

    cout << "Точное значение интеграла = "
        << exactIntegral << endl;

    cout << "Абсолютная погрешность = "
        << error << endl;

    return 0;
}
