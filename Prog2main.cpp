//
//  main.cpp
//  sem3laba2
//
//  Created by Данил Морозов on 19/09/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

//пилим гипоциклоиду

#include "hypocycloid.h"
#include <iostream>
#include <cmath>

//#pragma once

//namespace program2
//{

const char *messages[] = {"0 - finish programm", "1 - установить значения радиуса малого (производящего) круга", "2 - установить значения радиуса большого (статического) круга", "3 - установить значение реального радиуса малого круга", "4 - установить значение базовой точки", "5 - получить значение радиуса малого (производящего) круга", "6 - получить значение радиуса большого (статического) круга", "7 - получить значение реального радиуса малого круга", "8 - получить значение базовой точки", "9 - получить координаты точки гипоциклоиды от угла поворота", "10 - получить радиусы кольца, в когором заключена гипоциклоида", "11 - получить радиус кривизны гипоциклоиды", "12 - получить тип гипоциклоиды", "13 - получить площадь сектора от угла", "14 - вывести основную информацию о гипоциклоиде"};

const int Cmassages = sizeof(messages)/sizeof(messages[0]);

int main() {
    std::cout << "Добро пожаловать на лабу номер 2" << std::endl;
    //<< "cos90 = " << cos(1.57) << std::endl;
    int i = 1, a = 0;
    program2::Hypocycloid hypocycloid;
    while(i)
    {
        std::cout << "Cоздаю экземпляр класса по умолчанию" << std::endl << "что вы хотите сделать с классом?" << std::endl;

        program2::Point point;
        double first = 0.0, second = 0.0;
        int j = 1;
        while (j) {
            for (int index = 0; index < Cmassages; ++index)
            {
                std::cout << messages[index] << std::endl;
            }

            std::cout << "-----<<";
            program2::getNum(a);
            switch (a) {
                case 0:
                {
                    i = 0;
                    j = 0;
                    break;
                }
                case 1:
                {
                    std::cout << "-----<<";
                    program2::getNum(first);
                    std::cout << std::endl;
                    hypocycloid.set_little_radius(first);
                    break;
                }
                case 2:
                {
                    std::cout << "-----<<";
                    program2::getNum(first);
                    std::cout << std::endl;
                    hypocycloid.set_big_radius(first);
                    break;
                }
                case 3:
                {
                    std::cout << "-----<<";
                    program2::getNum(first);
                    std::cout << std::endl;
                    hypocycloid.set_real_radius(first);
                    break;
                }
                case 4:
                {
                    std::cout << "-----<<";
                    program2::getNum(first);
                    std::cout << std::endl;
                    std::cout << "-----<<";
                    program2::getNum(second);
                    std::cout << std::endl;
                    hypocycloid.set_base_point(first, second);
                    break;
                }
                case 5:
                {
                    first = hypocycloid.get_little_radius();
                    std::cout << "-----<<" << first << std::endl;
                    break;
                }
                case 6:
                {
                    first = hypocycloid.get_big_radius();
                    std::cout << "-----<<" << first << std::endl;
                    break;
                }
                case 7:
                {
                    first = hypocycloid.get_real_radius();
                    std::cout << "-----<<" << first << std::endl;
                    break;
                }
                case 8:
                {
                    point = hypocycloid.get_base_point();
                    std::cout << "x0 = " << point.x << "y0 = " << point.y << std::endl;
                    break;
                }
                case 9:
                {
                    std::cout << "Введите угол, для которого нужно посчитать величину" << std::endl;
                    program2::getNum(first);
                    point = hypocycloid.return_coordinates_by_angle(first);
                    std::cout << "X = " << point.x << "; Y = " << point.y << std::endl;
                    break;
                }
                case 10:
                {
                    point = hypocycloid.return_radiuses_of_cicles();
                    std::cout << "радиус одного кольца = " << point.x << "; радиус второго кольца = " << point.y << std::endl;
                    break;
                }
                case 11:
                {
                    std::cout << "Введите угол, для которого нужно посчитать величину" << std::endl;
                    program2::getNum(first);
                    first = hypocycloid.return_radius_krivizni(first);
                    std::cout << "-----<<" << first << std::endl;
                    break;
                }
                case 12:
                {
                    hypocycloid.return_type_hypocycloid();
                    break;
                }
                case 13:
                {
                    std::cout << "Введите угол, для которого нужно посчитать величину" << std::endl;
                    program2::getNum(first);
                    first = hypocycloid.return_sector_space(first);
                    std::cout << "-----<<" << first << std::endl;
                    break;
                }
                case 14:
                {
                    hypocycloid.print(std::cout);
                    break;
                }

                default:
                {
                    a = 0;
                    std::cout << "вы ввели неправильное значение, попробуйте еще раз";
                    break;
                }
            }
        }

    }
    return 0;
}


//}
