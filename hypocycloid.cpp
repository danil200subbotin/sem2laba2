//
//  hypocycloid.cpp
//  sem3laba2
//
//  Created by Данил Морозов on 19/09/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//
#include "hypocycloid.h"
#include <cmath>

//namespace program2 {

//------------------------конструкторы---------------------------------------

program2::Hypocycloid::Hypocycloid(double x0, double y0, double big_radius, double little_radius, double real_radius) : point(x0, y0)
{
    if (big_radius <= 0)
        throw "invalid big radius";
    if (little_radius <= 0)
        throw "invalid little radius";
    if (little_radius >= big_radius)
        throw "invalid radius (little >= big)";
    Hypocycloid::little_radius = little_radius;
    Hypocycloid::big_radius = big_radius;
    if (real_radius < 0)
        Hypocycloid::real_radius = Hypocycloid::little_radius;
    else
        Hypocycloid::real_radius = real_radius;

}


[[maybe_unused]] program2::Hypocycloid::Hypocycloid(const Point &p0, double big_radius, double little_radius, double real_radius) : point(p0)
{
    if (big_radius <= 0)
        throw "invalid big radius";
    if (little_radius <= 0)
        throw "invalid little radius";
    if (little_radius >= big_radius)
        throw "invalid radius (little >= big)";
    Hypocycloid::little_radius = little_radius;
    Hypocycloid::big_radius = big_radius;
    if (real_radius < 0)
        Hypocycloid::real_radius = Hypocycloid::little_radius;
    else
        Hypocycloid::real_radius = real_radius;
}

//--------------------------вывод-------------------------------------

std::ostream& program2::Hypocycloid::print(std::ostream &ostream) const
{
    ostream << "Координаты центра гипоциклоиды: x = " << point.x << "; y = " << point.y << std::endl;
    ostream << "Радиусы большого и маленького кругов соответственно: " << big_radius << "; " << little_radius << std::endl << "Реальный рабочий радиус малого круга =" << real_radius << std::endl;

    return ostream;
}

//--------------------------сеттеры-------------------------------------
[[maybe_unused]] program2::Hypocycloid& program2::Hypocycloid::set_base_point(Point &point_setter)
{
    Hypocycloid::point.x = point_setter.x;
    Hypocycloid::point.y = point_setter.y;
    return *this;
}

program2::Hypocycloid& program2::Hypocycloid::set_big_radius(double big_radius_setter)
{
    if (big_radius_setter < 0)
        throw "invalid big radius";
    if (big_radius_setter <= little_radius)
        throw "invalid radius (little >= big)";
    Hypocycloid::big_radius = big_radius_setter;
    return *this;
}

program2::Hypocycloid& program2::Hypocycloid::set_little_radius(double little_radius_setter)
{
    if (little_radius_setter <= 0)
        throw "invalid little radius";
    if (little_radius_setter >= big_radius)
        throw "invalid radius (little >= big)";
    Hypocycloid::little_radius = little_radius_setter;
    return *this;
}

program2::Hypocycloid& program2::Hypocycloid::set_real_radius(double real_radius_setter)
{
    if (real_radius_setter < 0)
        throw "invalid real radius";
    Hypocycloid::real_radius = real_radius_setter;
    return *this;
}


//-------------------------методы--------------------------------------


program2::Point program2::Hypocycloid::return_coordinates_by_angle(double angle) const
{
    Point point_returner;
    angle = angle / 180 * PI;
    point_returner.x = (big_radius - little_radius) * cos(angle) + (real_radius * cos((big_radius - little_radius) * angle / little_radius)) + point.x;
    point_returner.y = (big_radius - little_radius) * sin(angle) - (real_radius * sin((big_radius - little_radius) * angle / little_radius)) + point.y;
    return point_returner;
}

program2::Point program2::Hypocycloid::return_radiuses_of_cicles() const
{
    Point point_returner;
    point_returner.x = fabs(big_radius - little_radius - real_radius);
    point_returner.y = fabs(big_radius - little_radius + real_radius);
    return point_returner;
}

double program2::Hypocycloid::return_radius_krivizni(double angle) const
{
    double helper;
    angle = angle / 180 * PI;
    helper = (big_radius - little_radius) * (pow(real_radius * real_radius + little_radius * little_radius - 2 * real_radius * cos(big_radius * angle / (-little_radius)), 1.5) / fabs(-pow(little_radius, 3) + real_radius * real_radius * (big_radius - little_radius) - real_radius * little_radius * (big_radius - 2 * little_radius) * cos(big_radius * angle / (-little_radius))));
    return helper;

}


int program2::Hypocycloid::return_type_hypocycloid() const
{
    enum lenght {SHORT, LONG, STANDART};
    if (little_radius > real_radius)
        return SHORT;
    if (little_radius < real_radius)
        return LONG;
    if (little_radius == real_radius)
        return  STANDART;
}

double program2::Hypocycloid::return_sector_space(double angle) const
{
    double helper;

    angle = angle / 180 * PI;

    helper = (big_radius - little_radius) / 2 * (angle * (big_radius - little_radius - real_radius * real_radius / little_radius) - (real_radius * (big_radius - 2 * little_radius) / big_radius) * sin(big_radius * angle / (-little_radius)));
    return helper;
}




//}






//Hypocycloid::Hypocycloid(double big_radius, double little_radius) :point(0, 0)
//{
//    if ((big_radius < 0) || (little_radius < 0) || (little_radius >= big_radius))
//        throw std::exception("invalid radius");
//    Hypocycloid::little_radius = little_radius;
//    Hypocycloid::big_radius = big_radius;
//}
