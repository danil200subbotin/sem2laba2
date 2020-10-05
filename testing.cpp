//
// Created by Данил Морозов on 01/10/2020.
//


#include "hypocycloid.h"
#include <gtest/gtest.h>
#include <cmath>


const double CALC_ERROR = 0.000000001;

enum angles {PIna1 = 180, PIna2 = 90, PIna3 = 60, PIna4 = 45, PIna6 = 30, PIna9 = 20, PIna180 = 1};

TEST (HCConstructors, ErrorThrow1)                                      //проверять конкретные ошибки
{
    program2::Point point(3,4);
    ASSERT_ANY_THROW(program2::Hypocycloid a(point, 13, 14, 5));
}

TEST (HCConstructors, ErrorThrow2)                                      //объединить в один тест, что можно
{
//    program2::Point point(3,4);
    ASSERT_ANY_THROW(program2::Hypocycloid a(1, 0, 13, 14, 5));
}

TEST (HCGetters, GetBasePoint)
{
    program2::Hypocycloid a(2,3 , 13, 1, 4);
    ASSERT_EQ(2, a.get_base_point().x);
    ASSERT_EQ(3, a.get_base_point().y);
}

TEST (HCGetters, GetLittleRadius)
{
    program2::Hypocycloid a(2,3 , 13, 1, 4);
    ASSERT_EQ(1, a.get_little_radius());
}

TEST (HCGetters, GetBigRadius)
{
    program2::Hypocycloid a(2,3 , 13, 1, 4);
    ASSERT_EQ(13, a.get_big_radius());
}

TEST (HCGetters, GetRealRadius)
{
    program2::Hypocycloid a(2,3 , 13, 1, 4);
    ASSERT_EQ(4, a.get_real_radius());
}


TEST (HCConstructors, DefautConstructor)                        //norm
{
    program2::Hypocycloid a;
    ASSERT_EQ(0, a.get_base_point().x);
    ASSERT_EQ(0, a.get_base_point().y);
    ASSERT_EQ(1, a.get_little_radius());
    ASSERT_EQ(4, a.get_big_radius());
    ASSERT_EQ(1, a.get_real_radius());
}

TEST (HCConstructors, InitConstructor)                          //проверить для разных значений + на плохих тоже
{
    program2::Hypocycloid a(5, 6, 11, 1);
    ASSERT_EQ(5, a.get_base_point().x);
    ASSERT_EQ(6, a.get_base_point().y);
    ASSERT_EQ(11, a.get_big_radius());
    ASSERT_EQ(1, a.get_little_radius());
    ASSERT_EQ(1, a.get_real_radius());
}

TEST (HCConstructors, InitConstructorError1)                          //проверить для разных значений + на плохих тоже
{
    ASSERT_ANY_THROW(program2::Hypocycloid a(5, 6, -5, -6));
}

TEST (HCConstructors, InitConstructorError2)                          //проверить для разных значений + на плохих тоже
{
    ASSERT_ANY_THROW(program2::Hypocycloid a(5, 6, 5, 5));
}

TEST (HCConstructors, InitConstructorError3)                          //проверить для разных значений + на плохих тоже
{
    ASSERT_ANY_THROW(program2::Hypocycloid a(5, 6, 9, 10));
}

TEST (HCConstructors, InitConstructorError4)                          //проверить для разных значений + на плохих тоже
{
    ASSERT_NO_THROW(program2::Hypocycloid a(5, 6, 2, 1));
}

TEST (HCConstructors, InitConstructorError5)                          //проверить для разных значений + на плохих тоже
{
    ASSERT_NO_THROW(program2::Hypocycloid a(32454235, -200, 9.99999, 9.99998));
}


TEST (HCConstructors, PointInitConstructor)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 5);
    ASSERT_EQ(3, a.get_base_point().x);
    ASSERT_EQ(4, a.get_base_point().y);
    ASSERT_EQ(13, a.get_big_radius());
    ASSERT_EQ(10, a.get_little_radius());
 //   ASSERT_EQ(5, a.get_real_radius());

}

TEST (HCSetters, SetLittleRadius)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 5);
    a.set_little_radius(4);
    ASSERT_EQ(4, a.get_little_radius());
}

TEST (HCSetters, SetBigRadius)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 5);
    a.set_big_radius(14);
    ASSERT_EQ(14, a.get_big_radius());
}

TEST (HCSetters, SetRealRadius)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 5);
    a.set_real_radius(2.2345);
    ASSERT_EQ(2.2345, a.get_real_radius());
}

TEST (HCSetters, SetBasePoint)
{
    program2::Point point1(3,4), point2(5 ,6);
    program2::Hypocycloid a(point1, 13, 10, 5);
    a.set_base_point(point2);
    ASSERT_EQ(point2.x, a.get_base_point().x);
    ASSERT_EQ(point2.y, a.get_base_point().y);
}


TEST (HCSetters, SettingThrowBigLossLittle)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 5);
    ASSERT_ANY_THROW(a.set_big_radius(9));
}

TEST (HCSetters, SettingThrowMinusLittle)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 5);
    ASSERT_ANY_THROW(a.set_little_radius(-1));
}

TEST (HCSetters, SettingThrowMinusReal)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 5);
    ASSERT_ANY_THROW(a.set_real_radius(-1));
}

TEST (HCSetters, SettingThrowZeroLittle)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 5);
    ASSERT_ANY_THROW(a.set_little_radius(0));
}

TEST (HCSetters, SettingNoThrowLittle)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 5);
    ASSERT_NO_THROW(a.set_little_radius(9));
}

TEST (HCSetters, SettingNoThrowReal)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 1);
    ASSERT_NO_THROW(a.set_real_radius(2002190));
}

TEST (HCSetters, SettingNoThrowZeroReal)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 1);
    ASSERT_NO_THROW(a.set_real_radius(0));
}


//point_returner.x = (big_radius - little_radius) * cos(angle) + (real_radius * cos((big_radius - little_radius) * angle / little_radius)) + point.x;
//point_returner.y = (big_radius - little_radius) * sin(angle) - (real_radius * sin((big_radius - little_radius) * angle / little_radius)) + point.y;
//return point_returner;


TEST (HCCheckCoordinatesValue, ChekCoordinatesCicloida1) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 4, 1, 1);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna1;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}

TEST (HCCheckCoordinatesValue, ChekCoordinatesCicloida2) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 4, 1, 1);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna2;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}

TEST (HCCheckCoordinatesValue, ChekCoordinatesCicloida3) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 4, 1, 1);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna3;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}

TEST (HCCheckCoordinatesValue, ChekCoordinatesCicloida4) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 4, 1, 1);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna4;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}

TEST (HCCheckCoordinatesValue, ChekCoordinatesCicloida5) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 4, 1, 1);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna6;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}

TEST (HCCheckCoordinatesValue, ChekCoordinatesCicloida6) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 4, 1, 1);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna9;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}

TEST (HCCheckCoordinatesValue, ChekCoordinatesCicloida7) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 4, 1, 1);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna180;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}


TEST (HCCheckCoordinatesValue, ChekCoordinatesBigMoreBiggerThenLittle1) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna1;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}

TEST (HCCheckCoordinatesValue, ChekCoordinatesBigMoreBiggerThenLittle2) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna2;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}

TEST (HCCheckCoordinatesValue, ChekCoordinatesBigMoreBiggerThenLittle3) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna3;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}


TEST (HCCheckCoordinatesValue, ChekCoordinatesBigMoreBiggerThenLittle4) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna4;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}


TEST (HCCheckCoordinatesValue, ChekCoordinatesBigMoreBiggerThenLittle5) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna6;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}

TEST (HCCheckCoordinatesValue, ChekCoordinatesBigMoreBiggerThenLittle6) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna9;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}

TEST (HCCheckCoordinatesValue, ChekCoordinatesBigMoreBiggerThenLittle7) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna180;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, (big_radius - little_radius) * cos(angle_radian) + (real_radius * cos((big_radius - little_radius) * angle_radian / little_radius)) + point.x, CALC_ERROR);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, (big_radius - little_radius) * sin(angle_radian) - (real_radius * sin((big_radius - little_radius) * angle_radian / little_radius)) + point.y, CALC_ERROR);
}

//point_returner.x = fabs(big_radius - little_radius - real_radius);
//point_returner.y = fabs(big_radius - little_radius + real_radius);

TEST (HCCheckCercleRadiuses, CheckLittleRadius1) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    ASSERT_NEAR(a.return_radiuses_of_cicles().x, fabs(big_radius - little_radius - real_radius), CALC_ERROR);
}

TEST (HCCheckCercleRadiuses, CheckBigRadius1) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    ASSERT_NEAR(a.return_radiuses_of_cicles().y, fabs(big_radius - little_radius + real_radius), CALC_ERROR);
}

TEST (HCCheckCercleRadiuses, CheckLittleRadius2) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 0);
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    ASSERT_NEAR(a.return_radiuses_of_cicles().x, fabs(big_radius - little_radius - real_radius), CALC_ERROR);
}

TEST (HCCheckCercleRadiuses, CheckBigRadius2) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 0);
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    ASSERT_NEAR(a.return_radiuses_of_cicles().y, fabs(big_radius - little_radius + real_radius), CALC_ERROR);
}

TEST (HCCheckCercleRadiuses, CheckLittleRadius3) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 0.0001, 0);
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    ASSERT_NEAR(a.return_radiuses_of_cicles().x, fabs(big_radius - little_radius - real_radius), CALC_ERROR);
}

TEST (HCCheckCercleRadiuses, CheckBigRadius3) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 0.0001, 0);
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    ASSERT_NEAR(a.return_radiuses_of_cicles().y, fabs(big_radius - little_radius + real_radius), CALC_ERROR);
}



/*
(big_radius - little_radius) * (pow(real_radius * real_radius + little_radius * little_radius - 2 * real_radius * cos(big_radius * angle / (-little_radius)), 1.5) / fabs(-pow(little_radius, 3) + real_radius * real_radius * (big_radius - little_radius) - real_radius * little_radius * (big_radius - 2 * little_radius) * cos(big_radius * angle / (-little_radius))))
*/


TEST (HCCheckKriviznaValue, ChekKrivizna1) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna1;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_radius_krivizni(angle), (big_radius - little_radius) * (pow(real_radius * real_radius + little_radius * little_radius - 2 * real_radius * cos(big_radius * angle_radian / (-little_radius)), 1.5) / fabs(-pow(little_radius, 3) + real_radius * real_radius * (big_radius - little_radius) - real_radius * little_radius * (big_radius - 2 * little_radius) * cos(big_radius * angle_radian / (-little_radius)))), CALC_ERROR);
}

TEST (HCCheckKriviznaValue, ChekKrivizna2) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna2;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_radius_krivizni(angle), (big_radius - little_radius) * (pow(real_radius * real_radius + little_radius * little_radius - 2 * real_radius * cos(big_radius * angle_radian / (-little_radius)), 1.5) / fabs(-pow(little_radius, 3) + real_radius * real_radius * (big_radius - little_radius) - real_radius * little_radius * (big_radius - 2 * little_radius) * cos(big_radius * angle_radian / (-little_radius)))), CALC_ERROR);
}

TEST (HCCheckKriviznaValue, ChekKrivizna3) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna3;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_radius_krivizni(angle), (big_radius - little_radius) * (pow(real_radius * real_radius + little_radius * little_radius - 2 * real_radius * cos(big_radius * angle_radian / (-little_radius)), 1.5) / fabs(-pow(little_radius, 3) + real_radius * real_radius * (big_radius - little_radius) - real_radius * little_radius * (big_radius - 2 * little_radius) * cos(big_radius * angle_radian / (-little_radius)))), CALC_ERROR);
}

TEST (HCCheckKriviznaValue, ChekKrivizna4) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna4;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_radius_krivizni(angle), (big_radius - little_radius) * (pow(real_radius * real_radius + little_radius * little_radius - 2 * real_radius * cos(big_radius * angle_radian / (-little_radius)), 1.5) / fabs(-pow(little_radius, 3) + real_radius * real_radius * (big_radius - little_radius) - real_radius * little_radius * (big_radius - 2 * little_radius) * cos(big_radius * angle_radian / (-little_radius)))), CALC_ERROR);
}

TEST (HCCheckKriviznaValue, ChekKrivizna5) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna6;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_radius_krivizni(angle), (big_radius - little_radius) * (pow(real_radius * real_radius + little_radius * little_radius - 2 * real_radius * cos(big_radius * angle_radian / (-little_radius)), 1.5) / fabs(-pow(little_radius, 3) + real_radius * real_radius * (big_radius - little_radius) - real_radius * little_radius * (big_radius - 2 * little_radius) * cos(big_radius * angle_radian / (-little_radius)))), CALC_ERROR);
}


TEST (HCCheckKriviznaValue, ChekKrivizna6) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna9;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_radius_krivizni(angle), (big_radius - little_radius) * (pow(real_radius * real_radius + little_radius * little_radius - 2 * real_radius * cos(big_radius * angle_radian / (-little_radius)), 1.5) / fabs(-pow(little_radius, 3) + real_radius * real_radius * (big_radius - little_radius) - real_radius * little_radius * (big_radius - 2 * little_radius) * cos(big_radius * angle_radian / (-little_radius)))), CALC_ERROR);
}

TEST (HCCheckKriviznaValue, ChekKrivizna7) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna180;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_radius_krivizni(angle), (big_radius - little_radius) * (pow(real_radius * real_radius + little_radius * little_radius - 2 * real_radius * cos(big_radius * angle_radian / (-little_radius)), 1.5) / fabs(-pow(little_radius, 3) + real_radius * real_radius * (big_radius - little_radius) - real_radius * little_radius * (big_radius - 2 * little_radius) * cos(big_radius * angle_radian / (-little_radius)))), CALC_ERROR);
}

TEST (HCCheckTypeValue, ChekType0) {
    enum lenght {SHORT, LONG, STANDART};
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 13);
    ASSERT_NEAR(SHORT, a.return_type_hypocycloid(), CALC_ERROR);
}

TEST (HCCheckTypeValue, ChekType1) {
    enum lenght {SHORT, LONG, STANDART};
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 15);
    ASSERT_NEAR(LONG, a.return_type_hypocycloid(), CALC_ERROR);
}

TEST (HCCheckTypeValue, ChekType2) {
    enum lenght {SHORT, LONG, STANDART};
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 14);
    ASSERT_NEAR(STANDART, a.return_type_hypocycloid(), CALC_ERROR);
}



//(big_radius - little_radius) / 2 * (angle * (big_radius - little_radius - real_radius * real_radius / little_radius) - (real_radius * (big_radius - 2 * little_radius) / big_radius) * sin(big_radius * angle / (-little_radius)))

TEST (HCCheckSpaceValue, ChekSpace1) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna1;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_sector_space(angle), (big_radius - little_radius) / 2 * (angle_radian * (big_radius - little_radius - real_radius * real_radius / little_radius) - (real_radius * (big_radius - 2 * little_radius) / big_radius) * sin(big_radius * angle_radian / (-little_radius))), CALC_ERROR);
}

TEST (HCCheckSpaceValue, ChekSpace2) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna2;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_sector_space(angle), (big_radius - little_radius) / 2 * (angle_radian * (big_radius - little_radius - real_radius * real_radius / little_radius) - (real_radius * (big_radius - 2 * little_radius) / big_radius) * sin(big_radius * angle_radian / (-little_radius))), CALC_ERROR);
}

TEST (HCCheckSpaceValue, ChekSpace3) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna3;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_sector_space(angle), (big_radius - little_radius) / 2 * (angle_radian * (big_radius - little_radius - real_radius * real_radius / little_radius) - (real_radius * (big_radius - 2 * little_radius) / big_radius) * sin(big_radius * angle_radian / (-little_radius))), CALC_ERROR);
}

TEST (HCCheckSpaceValue, ChekSpace4) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna4;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_sector_space(angle), (big_radius - little_radius) / 2 * (angle_radian * (big_radius - little_radius - real_radius * real_radius / little_radius) - (real_radius * (big_radius - 2 * little_radius) / big_radius) * sin(big_radius * angle_radian / (-little_radius))), CALC_ERROR);
}

TEST (HCCheckSpaceValue, ChekSpace5) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna6;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_sector_space(angle), (big_radius - little_radius) / 2 * (angle_radian * (big_radius - little_radius - real_radius * real_radius / little_radius) - (real_radius * (big_radius - 2 * little_radius) / big_radius) * sin(big_radius * angle_radian / (-little_radius))), CALC_ERROR);
}

TEST (HCCheckSpaceValue, ChekSpace6) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna9;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_sector_space(angle), (big_radius - little_radius) / 2 * (angle_radian * (big_radius - little_radius - real_radius * real_radius / little_radius) - (real_radius * (big_radius - 2 * little_radius) / big_radius) * sin(big_radius * angle_radian / (-little_radius))), CALC_ERROR);
}


TEST (HCCheckSpaceValue, ChekSpace7) {
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 10567, 14, 10001);
    double angle, angle_radian;
    double big_radius = a.get_big_radius();
    double little_radius = a.get_little_radius();
    double real_radius = a.get_real_radius();
    angle = PIna180;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_sector_space(angle), (big_radius - little_radius) / 2 * (angle_radian * (big_radius - little_radius - real_radius * real_radius / little_radius) - (real_radius * (big_radius - 2 * little_radius) / big_radius) * sin(big_radius * angle_radian / (-little_radius))), CALC_ERROR);
}

int _tmain(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}