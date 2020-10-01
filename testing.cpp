//
// Created by Данил Морозов on 01/10/2020.
//


#include "hypocycloid.h"
#include <gtest/gtest.h>
#include <cmath>


TEST (HCConstructors, DefautConstructor)
{
    program2::Hypocycloid a;
    ASSERT_EQ(0, a.get_base_point().x);
    ASSERT_EQ(0, a.get_base_point().y);
    ASSERT_EQ(1, a.get_little_radius());
    ASSERT_EQ(4, a.get_big_radius());
    ASSERT_EQ(1, a.get_real_radius());
  //  ASSERT_EQ( )
}

TEST (HCConstructors, InitConstructor)
{
    program2::Hypocycloid a(5, 6, 11, 1);
    ASSERT_EQ(5, a.get_base_point().x);
    ASSERT_EQ(6, a.get_base_point().y);
    ASSERT_EQ(11, a.get_big_radius());
    ASSERT_EQ(1, a.get_little_radius());
    ASSERT_EQ(1, a.get_real_radius());
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

TEST (HCConstructors, ErrorThrow1)
{
    program2::Point point(3,4);
    ASSERT_ANY_THROW(program2::Hypocycloid a(point, 13, 14, 5));

}

TEST (HCConstructors, ErrorThrow2)
{
//    program2::Point point(3,4);
    ASSERT_ANY_THROW(program2::Hypocycloid a(1, 0, 13, 14, 5));

}

TEST (HCConstructors, ConstructorsThrowMinus)
{
    program2::Point point(3,4);
    ASSERT_ANY_THROW(program2::Hypocycloid a(point, -5, -10, 5));

}

TEST (HCConstructors, ErrorThrowMinus2)
{
    ASSERT_ANY_THROW(program2::Hypocycloid a(1, 4, -5, -10, 5));

}


TEST (HCSetters, SetLittleBigRealRadiuses)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 5);
    a.set_little_radius(4);
    a.set_big_radius(5);
    a.set_real_radius(2.2345);
    ASSERT_EQ(3, a.get_base_point().x);
    ASSERT_EQ(4, a.get_base_point().y);
    ASSERT_EQ(5, a.get_big_radius());
    ASSERT_EQ(4, a.get_little_radius());
    ASSERT_EQ(2.2345, a.get_real_radius());

}

TEST (HCSetters, SettingThrows)
{
    program2::Point point(3,4);
    program2::Hypocycloid a(point, 13, 10, 5);
    ASSERT_ANY_THROW(a.set_big_radius(9));
    ASSERT_ANY_THROW(a.set_little_radius(-1));
    ASSERT_ANY_THROW(a.set_big_radius(0));
}

TEST (HCGetters, GetAll)
{
    program2::Hypocycloid a(2,3 , 13, 1, 4);
    ASSERT_EQ(2, a.get_base_point().x);
    ASSERT_EQ(3, a.get_base_point().y);
    ASSERT_EQ(1, a.get_little_radius());
    ASSERT_EQ(13, a.get_big_radius());
    ASSERT_EQ(4, a.get_real_radius());
}

TEST (HCCheckValue, ChekCoordinates0) {
    program2::Hypocycloid a;
    double angle, angle_radian;
    angle = 0;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, a.get_big_radius() * pow(cos(angle_radian), 3), 0.000000000000000001);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, a.get_big_radius() * pow(sin(angle_radian), 3), 0.000000001);
}

TEST (HCCheckValue, ChekCoordinates10) {
    program2::Hypocycloid a;
    double angle, angle_radian;
    angle = 10;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, a.get_big_radius() * pow(cos(angle_radian), 3), 0.000000001);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, a.get_big_radius() * pow(sin(angle_radian), 3), 0.000000001);
}

TEST (HCCheckValue, ChekCoordinates20) {
    program2::Hypocycloid a;
    double angle, angle_radian;
    angle = 20;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, a.get_big_radius() * pow(cos(angle_radian), 3), 0.000000001);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, a.get_big_radius() * pow(sin(angle_radian), 3), 0.000000001);
}

TEST (HCCheckValue, ChekCoordinates30) {
    program2::Hypocycloid a;
    double angle, angle_radian;
    angle = 30;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, a.get_big_radius() * pow(cos(angle_radian), 3), 0.000000001);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, a.get_big_radius() * pow(sin(angle_radian), 3), 0.000000001);
}

TEST (HCCheckValue, ChekCoordinates45) {
    program2::Hypocycloid a;
    double angle, angle_radian;
    angle = 45;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, a.get_big_radius() * pow(cos(angle_radian), 3), 0.000000001);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, a.get_big_radius() * pow(sin(angle_radian), 3), 0.000000001);
}

TEST (HCCheckValue, ChekCoordinates60) {
    program2::Hypocycloid a;
    double angle, angle_radian;
    angle = 60;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, a.get_big_radius() * pow(cos(angle_radian), 3), 0.000000001);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, a.get_big_radius() * pow(sin(angle_radian), 3), 0.000000001);
}
TEST (HCCheckValue, ChekCoordinates90) {
    program2::Hypocycloid a;
    double angle, angle_radian;
    angle = 90;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, a.get_big_radius() * pow(cos(angle_radian), 3), 0.000000001);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, a.get_big_radius() * pow(sin(angle_radian), 3), 0.000000001);
}

TEST (HCCheckValue, ChekCoordinates180) {
    program2::Hypocycloid a;
    double angle, angle_radian;
    angle = 180;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, a.get_big_radius() * pow(cos(angle_radian), 3), 0.000000001);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, a.get_big_radius() * pow(sin(angle_radian), 3), 0.000000001);
}

TEST (HCCheckValue, ChekCoordinates5467_4343) {
    program2::Hypocycloid a;
    double angle, angle_radian;
    angle = 5467.4343;
    angle_radian = angle / 180 * program2::PI;
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).x, a.get_big_radius() * pow(cos(angle_radian), 3), 0.000000001);
    ASSERT_NEAR(a.return_coordinates_by_angle(angle).y, a.get_big_radius() * pow(sin(angle_radian), 3), 0.000000001);
}





int _tmain(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}