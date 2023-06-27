#include <iostream>
using namespace std;

int getRows() {
    int a;

    cout << "Введите кол-во строк:\t";
    cin >> a;

    return a;
}

void print(int** mas, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }
}

void printF(float** mas, int m, int n) {
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }
}

int getCols() {
    int b;

    cout << "Введите кол-во столбцов:\t";
    cin >> b;

    return b;
}

void fillArrayRandom(int** mas, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = rand();
        }
    }
}

void fillArrayRandomFloat(float** mas, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = (float)rand() / (float)RAND_MAX;
        }
    }
}

//Tasks
int Task1() {
    /*
        В двумерном целочисленном массиве посчитать среднее арифметическое чётных элементов массива
    */

    int m = getRows();
    int n = getCols();

    int** array = new int *[m];
    for (int i = 0; i < m; i++) array[i] = new int[n];

    fillArrayRandom(array, m, n);

    print(array, m, n);

    int k = 0,
        sum = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] % 2 == 0) {
                sum += array[i][j];
                k++;
            }
        }
    }

    cout << "Среднее арифметическое чётных элементов массива:\t" << sum / k << endl;

    return 0;
}

int Task2() {
    /*
        В двумерном целочисленном массиве найти значение максимального элемента, вывести его номер столбца и строки.
    */

    int m = getRows();
    int n = getCols();

    int** array = new int* [m];
    for (int i = 0; i < m; i++) array[i] = new int[n];

    fillArrayRandom(array, m, n);

    print(array, m, n);

    int col = 0,
        row = 0,
        max = array[0][0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
                row = i;
                col = j;
            }
        }
    }
    
    cout << "Номер строки и столбца максимального элемента:\t" << row << "\t" << col << endl;

    return 0;
}

int Task3() {
    /*
        Дана квадратная матрица вещественных чисел, посчитать сумму главной диагонали.
    */
    int m, n;

    while (true) {
        m = getRows();
        n = getCols();

        if (m != n) cout << "Количество строк должно быть равно количеству столбцов" << endl;
        else break;
    }

    float** array = new float* [m];
    for (int i = 0; i < m; i++) array[i] = new float[n];

    fillArrayRandomFloat(array, m, n);
    printF(array, m, n);

    float sum = 0;

    for (int i = 0; i < m; i++) {
        sum += array[i][i];
    }

    cout << "Сумма главной диагонали:\t" << sum << endl;

    return 0;
}

int Task4() {
    /*
        В прямоугольной вещественной матрице поменять строки следующим образом: первую с последней, вторую с предпоследней и т.д.
    */
    int m, n;

    while (true) {
        m = getRows();
        n = getCols();

        if (m == n) cout << "Количество строк не должно быть равно количеству столбцов" << endl;
        else break;
    }

    float** array = new float* [m];
    for (int i = 0; i < m; i++) array[i] = new float[n];

    fillArrayRandomFloat(array, m, n);
    printF(array, m, n);
    cout << endl;

    for (int i = 0; i < m / 2; i++) {
        for (int j = 0; j < n; j++) {
            swap(array[i][j], array[m - i - 1][j]);
        }
    }

    printF(array, m, n);
    return 0;
}

int Task5() {
    /*
        Дана прямоугольная целочисленная матрица для каждого столбца подсчитать среднее арифметическое нечётных элементов массива, записать их в новый массив.
    */

    int m, n;

    while (true) {
        m = getRows();
        n = getCols();

        if (m == n) cout << "Количество строк не должно быть равно количеству столбцов" << endl;
        else break;
    }

    int** array = new int* [m];
    for (int i = 0; i < m; i++) array[i] = new int[n];

    fillArrayRandom(array, m, n);
    print(array, m, n);
    cout << endl;

    int* srarfs = new int[n];

    for (int i = 0; i < n; i++) {
        int sum = 0,
            k = 0;

        for (int j = 1; j < m; j+=2) {
            sum += array[j][i];
            k++;
        }

        srarfs[i] = sum / k;
    }

    cout << "Среднее арифметическое столбцов нечётных элементов:" << endl;
    for (int i = 0; i < n; i++) {
        cout << srarfs[i] << "\t";
    }
    cout << endl;

    return 0;
}

int Task6() {
    /*
        Даны матрица "а" и вектор "x", нечётные строки матрицы заменить элементами вектора x.
    */

    int m = getRows(),
    n = getCols();

    int** a = new int* [m];
    for (int i = 0; i < m; i++) a[i] = new int[n];

    int* x = new int [n];

    fillArrayRandom(a, m, n);

    for (int i = 0; i < n; i++) x[i] = rand();

    print(a, m, n);
    cout << endl;

    for (int i = 0; i < m; i++) {
        if (i % 2 != 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = x[j];
            }
        }
    }

    print(a, m, n);

    return 0;
}

int main()
{
    setlocale(0, "");
    //Task1();
    //Task2();
    //Task3();
    //Task4();
    //Task5();
    Task6();
    return 0;
}
