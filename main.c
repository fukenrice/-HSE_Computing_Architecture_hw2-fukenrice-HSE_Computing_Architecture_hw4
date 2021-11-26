//
// Created by rhy on 27.11.2021.
//

#include <stdio.h>
#include <fstream>
#include <stdlib.h> // для функций rand() и srand()
#include <time.h>   // для функции time()
#include <string.h>
#include <iostream>
#include "cmath"

using namespace std;

inline auto Random(int a, int b) {
    return a + (rand() % (abs((a - b)) + 1));
}

struct circle{
    int x1, y1, radius;
    enum color{RED = 0, ORANGE, YELLOW, GREEN, BLUE, DARK_BLUE, VIOLET};
    int color_index;
};

void In(circle &c, ifstream &ifst){
    ifst >> c.x1 >> c.y1 >> c.radius >> c.color_index;

    if (c.radius <= 0) {
        throw invalid_argument("Circle radius is less then zero");
    }
}

// Вычисление площади круга
double Area(circle &c){
    return 3.141592653589793 * c.radius * c.radius;
}

// Случайный ввод круга треугольника
void InRnd(circle &c){
    c.x1 = Random(-100, 100);
    c.y1 = Random(-100, 100);
    c.radius = Random(1, 100);
    while(Area(c) == 0){
        c.radius = Random(1, 100);
    }
    c.color_index = Random(0, 6);
}

// Вывод параметров круга в форматируемый поток
void Out(circle &c, ofstream &ofst){
    string color;

    switch (c.color_index) {
        case 0:
            color = "red";
            break;
        case 1:
            color = "orange";
            break;
        case 2:
            color = "yellow";
            break;
        case 3:
            color = "green";
            break;
        case 4:
            color = "blue";
            break;
        case 5:
            color = "dark blue";
            break;
        case 6:
            color = "violet";
            break;
        default:
            color = "none";
    }
    ofst << "It is circle: (x1, x2) = (" << c.x1
         << ", " << c.y1 << ") with radius = "
         << c.radius << ". Color: " << color << ". Area = " << Area(c) << endl;
}




struct rectangle {
    int x1, y1, x2, y2; // Координаты левого верхнего угла
    enum colors{RED = 0, ORANGE, YELLOW, GREEN, BLUE, DARK_BLUE, VIOLET};
    int color_index;
};

void In(rectangle &r, ifstream &ifst) {
    ifst >> r.x1 >> r.y1 >> r.x2 >> r.y2 >> r.color_index;
    if (r.x1 >= r.x2 || r.y1 <= r.y2){
        throw invalid_argument("Rectangles' left point should be upper and lefter, than right point");
    }
}

//------------------------------------------------------------------------------
// Вычисление площади прямоугольника
double Area(rectangle &r) {
    return std::abs(r.x2 - r.x1) * std::abs(r.y1 - r.y2);
}

// Случайный ввод параметров прямоугольника
void InRnd(rectangle &r) {
    r.x1 = Random(-100, 100);
    r.y1 = Random(-100, 100);
    r.x2 = Random(r.x1, 100);
    r.y2 = Random(-100, r.y1);
    while (Area(r) == 0) {
        r.x2 = Random(r.x1, 100) + 1;
        r.y2 = Random(-100, r.y1) - 1;
    }
    r.color_index = Random(0, 6);
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Out(rectangle &r, ofstream &ofst) {

    string color;
    // Находим нужный цвет в перичислении.
    switch (r.color_index) {
        case 0:
            color = "red";
            break;
        case 1:
            color = "orange";
            break;
        case 2:
            color = "yellow";
            break;
        case 3:
            color = "green";
            break;
        case 4:
            color = "blue";
            break;
        case 5:
            color = "dark blue";
            break;
        case 6:
            color = "violet";
            break;
        default:
            color = "none";
    }
    ofst << "It is Rectangle: (x1, y1) = (" << r.x1 << ", "
         << r.y1 << ") (x2, y2)= (" << r.x2 << ", " << r.y2
         << "). Color: " << color << ". Area = " << Area(r) << "\n";
}

struct triangle {
    int x1, x2, x3, y1, y2, y3; // координаты вершин
    enum color{RED = 0, ORANGE, YELLOW, GREEN, BLUE, DARK_BLUE, VIOLET};
    int color_index;
};

// Вычисление периметра треугольника
double Area(triangle &t){
    double a = std::sqrt(std::pow((t.x2 - t.x1), 2) + std::pow((t.y2 - t.y1), 2));
    double b = std::sqrt(std::pow((t.x3 - t.x2), 2) + std::pow((t.y3 - t.y2), 2));
    double c = std::sqrt(std::pow((t.x1 - t.x3), 2) + std::pow((t.y1 - t.y3), 2));
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

// Ввод параметров треугольника из файла
void In(triangle &t, ifstream &ifst){
    ifst >> t.x1 >> t.y1 >> t.x2 >> t.y2 >> t.x3 >> t.y3 >> t.color_index;
    if (Area(t) == 0){
        throw invalid_argument("Triangles' area can't be 0");
    }
}

// Случайный ввод параметров треугольника
void InRnd(triangle &t){
    t.x1 = Random(-100, 100);
    t.y1 = Random(-100, 100);
    t.x2 = Random(-100, 100);
    t.y2 = Random(-100, 100);
    t.x3 = Random(-100, 100);
    t.y3 = Random(-100, 100);
    while (Area(t) == 0){
        t.x3 = Random(-100, 100);
        t.y3 = Random(-100, 100);
    }
    t.color_index = Random(0, 6);
}

// Вывод параметров треугольника в форматируемый поток
void Out(triangle &t, ofstream &ofst){

    string color;

    switch (t.color_index) {
        case 0:
            color = "red";
            break;
        case 1:
            color = "orange";
            break;
        case 2:
            color = "yellow";
            break;
        case 3:
            color = "green";
            break;
        case 4:
            color = "blue";
            break;
        case 5:
            color = "dark blue";
            break;
        case 6:
            color = "violet";
            break;
        default:
            color = "none";
    }

    ofst << "It is Triangle: (x1, x2) = ("
         << t.x1 << ", " << t.y1 << ") (x2, y2) = ("
         << t.x2 << ", " << t.y2 << ") (x3, y3) = (" << t.x3 << ", " << t.y3
         << "). Color: " << color << ". Area = " << Area(t) << "\n";
}

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct shape {
    // значения ключей для каждой из фигур
    enum key {RECTANGLE = 1, TRIANGLE, CIRCLE};
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        rectangle r;
        triangle t;
        circle c;
    };
};

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
shape* In(ifstream &ifst) {
    shape *sp;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            sp = new shape;
            sp->k = shape::RECTANGLE;
            In(sp->r, ifst);
            return sp;
        case 2:
            sp = new shape;
            sp->k = shape::TRIANGLE;
            In(sp->t, ifst);
            return sp;
        case 3:
            sp = new shape;
            sp->k = shape::CIRCLE;
            In(sp->c, ifst);
            return sp;
        default:
            return nullptr;
    }
}

// Случайный ввод обобщенной фигуры
shape *InRnd() {
    shape *sp;
    auto k = rand() % 3 + 1;
    switch(k) {
        case 1:
            sp = new shape;
            sp->k = shape::RECTANGLE;
            InRnd(sp->r);
            return sp;
        case 2:
            sp = new shape;
            sp->k = shape::TRIANGLE;
            InRnd(sp->t);
            return sp;
        case 3:
            sp = new shape;
            sp->k = shape::CIRCLE;
            InRnd(sp->c);
            return sp;
        default:
            return nullptr;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(shape &s, ofstream &ofst) {
    switch(s.k) {
        case shape::RECTANGLE:
            Out(s.r, ofst);
            break;
        case shape::TRIANGLE:
            Out(s.t, ofst);
            break;
        case shape::CIRCLE:
            Out(s.c, ofst);
            break;
        default:
            ofst << "Incorrect figure!" << endl;
            break;
    }
}

//------------------------------------------------------------------------------
// Вычисление площади фигуры
double Area(shape &s) {
    switch(s.k) {
        case shape::RECTANGLE:
            return Area(s.r);
        case shape::TRIANGLE:
            return Area(s.t);
        case shape::CIRCLE:
            return Area(s.c);
        default:
            return 0.0;
    }
}

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    enum {max_len = 10001}; // максимальная длина
    int len; // текущая длина
    shape *cont[max_len];
};

// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for (int i = 0; i < c.len; ++i) {
        delete c.cont[i];
    }
    c.len = 0;
}

// Ввод содержимого контейнера из указанного потока
void In(container &c, ifstream &ifst) {
    while (!ifst.eof()) {
        if ((c.cont[c.len] = In(ifst)) != nullptr) {
            c.len++;
        }
    }
}

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size){
    while(c.len < size) {
        if((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

// Вывод содержимого контейнера в указанный поток
void Out(container &c, ofstream &ofst){
    ofst << "Container contains " << c.len << " elements." << endl;
    for(int i = 0; i < c.len; i++) {
        ofst << i + 1 << ": ";
        Out(*(c.cont[i]), ofst);
    }
}

// Сортировка контейнера алгоритмом Шелла
void ShellSort(container &c){
    int d = c.len / 2;
    while (d != 0){
        for (int i = d; i < c.len; i += d) {
            int j = i;
            while (j > 0 && Area(*c.cont[j - d]) > Area(*c.cont[j])){
                std::swap(c.cont[j - d], c.cont[j]);
                j -= d;
            }
        }
        d /= 2;
    }
}

void errMessage1() {
    printf( "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }
    clock_t start = clock();
    printf("Start\n");
    container c;
    Init(c);



    if(!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        try {
            In(c, ifst);
        }
        catch (invalid_argument e){
            printf(e.what());
            return 3;
        }
    }

    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);

        if((size < 1) || (size > 10000)) {
            printf("%s %i %s",
                   "incorrect numer of figures =", size,
                   ". Set 0 < number <= 10000\n");
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    Out(c, ofst1);

    // The 2nd part of task
    ofstream ofst2(argv[4]);
    // Вторая часть задания, сортируем перед выводом.
    ShellSort(c);
    ofst2 << "Sorted container:\n";
    Out(c, ofst2);

    Clear(c);
    printf("Stop\n");
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    return 0;
}
