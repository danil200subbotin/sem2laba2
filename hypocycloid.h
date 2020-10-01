//
//  cikloida.h
//  sem3laba2
//
//  Created by Данил Морозов on 19/09/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

//#ifndef cikloida_h
//#define cikloida_h
//#include <math.h>
//#include <iostream>
//
//#endif /* cikloida_h */

#pragma once
#include <iostream>
#include <cmath>
//#include <gtest/gtest.h>

namespace program2 {

    const double PI = 3.141592653589793;

    typedef struct Point Point;
    struct Point {
        double x, y;                //координаты точки на плоскости XoY
        Point(double x0 = 0, double y0 = 0) :x(x0), y(y0){}//конструктор точки по умолчанию
        Point(const Point &p0) :x(p0.x), y(p0.y){}
    };



    class Hypocycloid {
    private:
        Point point;
        double little_radius, big_radius, real_radius;
    public:

        //набор конструкторов
        Hypocycloid(double x0 = 0, double y0 = 0, double big_radious = 4, double little_radious = 1, double real_radius = -1);

        [[maybe_unused]] Hypocycloid(const Point &p0, double big_radius = 4, double little_radius = 1, double real_radius = -1);
        //   ~Hypocycloid(); // деструктор

        double get_little_radius() const { return little_radius; };       //get'теры
        std::ostream& print (std::ostream &) const;   //метод вывода чего-либо
        double get_big_radius() const { return big_radius; }
        double get_real_radius() const { return real_radius; }
        Point get_base_point() const { return point; }

        Hypocycloid& set_little_radius(double little_radius_setter);      //set'теры
        Hypocycloid& set_big_radius(double big_radius_setter);
        Hypocycloid& set_real_radius(double real_radius);
        Hypocycloid& set_base_point(double x0 = 0, double y0 = 0) {point.x = x0; point.y = y0; return *this; }

        [[maybe_unused]] Hypocycloid& set_base_point(Point &point_setter);
        Point return_coordinates_by_angle(double angle = 0); //3    //непосредственно методы работы с классом:
        Point return_radiuses_of_cicles();    //4
        double return_radius_krivizni(double angle);     //5
        void return_type_hypocycloid(); //6
        double return_sector_space(double angle);  //7

    };


    template <class T>

    double getNum (T &a) {                //проверочка ввода соответствующего типа данных
        int i = 1;
        while (i == 1) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> a;
            if (!std::cin.good())
                i = 1;
            else
                i = 0;
            if (i != 0) std::cout << "Вы ввели неприемлимое значение, повторите ввод"<< std::endl;
        }
        return 0;


    }




}




/*

3)* Вернуть координаты точки принадлежащей циклоиде в декартовой системе координат от угла поворота луча, соединяющего центр порождающего круга с центром направляющей окружности.

4)* Вернуть радиусы ограничивающих гипоциклоиду окружностей.

5)* Вернуть радиус кривизны от угла поворота луча, соединяющего центр порождающего круга с центром направляющей окружности.

6)* Вернуть тип гипоциклоиды (обыкновенная, укороченная, удлиненная).

7)* Вернуть секториальную площадь гипоциклоиды относительно начального положения описываемой полярным радиусом.
 */
