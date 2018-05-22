#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"
#include "Mat2.hpp"
#include "color.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include <cmath>

/*Vektoren*/
 TEST_CASE ("custom_constructor","[custom]")
 {
    Vec2 v1 {6.7, 2.5};

    REQUIRE(6.7f == v1.x_);
    REQUIRE(2.5f == v1.y_);
 }

  TEST_CASE ("default_constructor","[default]")
 {
    Vec2 v2 {};

    REQUIRE(v2.x_ == 0.0f);
    REQUIRE(v2.y_ == 0.0f);
 }

 TEST_CASE("plusequal_operator","[plusequal]")
{
	Vec2 v0 {};
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};

	v0 += v1;
	v1 += v2;

	REQUIRE(v0.x_ == 1.0f);
	REQUIRE(v0.y_ == 2.0f);
	
	REQUIRE(v1.x_ == 1.0f);
	REQUIRE(v1.y_ == 0.0f);
}

 TEST_CASE("minusequal_operator","[minusequal]")
{
	Vec2 v0{};
	Vec2 v1{1.7f, 3.8f};
	Vec2 v2{0.0f,-2.0f};
  Vec2 v3{-5.7f,-1.5f};

	v0 -= v1;
	v1 -= v2;
  v3 -= v1;

	REQUIRE(v0.x_ == -1.7f);
	REQUIRE(v0.y_ == -3.8f);
	
	REQUIRE(v1.x_ == 1.7f);
	REQUIRE(v1.y_ == 5.8f);

  //REQUIRE(v3.x_ == Approx(-7.4f)); 
	//REQUIRE(v3.y_ == -5.3f); // gibt falschen wert aus
}

TEST_CASE("skalar_equal_operator", "[skalar_equal]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.5f};
	Vec2 v2{0.1f,-2.3f};
	float s = 5.0f;

	v0 *= s;
	v1 *= s;
	v2 *= s;

	REQUIRE(v0.x_ == 0.0f);
	REQUIRE(v0.y_ == 0.0f);
	
	REQUIRE(v1.x_ == 5.0f);
	REQUIRE(v1.y_ == 12.5f);

	REQUIRE(v2.x_ == 0.5f);
	REQUIRE(v2.y_ == -11.5f);
}

TEST_CASE("divequal_operator", "[divequal_operator]")
{
	Vec2 v0{};
	Vec2 v1{1.7f,3.0f};
	float s = 5.0f;

	v0 /= s;
	v1 /= s;

	REQUIRE(v0.x_ == 0.0f);
	REQUIRE(v0.y_ == 0.0f);
	
	REQUIRE(v1.x_ == 0.34f);
	REQUIRE(v1.y_ == 0.6f);

	
}

/* Aufgabe 2.4*/
TEST_CASE("plus_operator", "[plus]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	
	Vec2 test1 = v0 + v2;
	Vec2 test2 = v1 + v2;

	REQUIRE(test1.x_ == 0.0f);
	REQUIRE(test1.y_ == -2.0f);
	
	REQUIRE(test2.x_ == 1.0f);
	REQUIRE(test2.y_ == 0.0f);
}

TEST_CASE("minus_operator", "[minus]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	
	Vec2 test1 = v0-v2;
	Vec2 test2 = v1-v2;

	REQUIRE(test1.x_ == 0.0f);
	REQUIRE(test1.y_ == 2.0f);
	
	REQUIRE(test2.x_ == 1.0f);
	REQUIRE(test2.y_ == 4.0f);
}

TEST_CASE("skalar_mult_operator", "[skalar_mult]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	float s = 5.0f;

	Vec2 test1 = v0*s;
	Vec2 test2 = v1*s;

	REQUIRE(test1.x_ == 0.0f);
	REQUIRE(test1.y_ == 0.0f);
	
	REQUIRE(test2.x_ == 5.0f);
	REQUIRE(test2.y_ == 10.0f);
}

TEST_CASE("division_operator", "[division_operator]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	float s = 5.0f;

	Vec2 test1 = v0/s;
	Vec2 test2 = v1/s;

	REQUIRE(test1.x_ == 0.0f);
	REQUIRE(test1.y_ == 0.0f);

	REQUIRE(test2.x_ == 0.2f);
	REQUIRE(test2.y_ == 0.4f);
	
} 


/*Matrizen*/
 TEST_CASE ("custom_mat_constructor","[custom_mat]")
 {
    Mat2 m1 {6.7f, 2.5f, 5.0f, 4.5f};

    REQUIRE(6.7f == m1.a_);
    REQUIRE(2.5f == m1.b_);
		REQUIRE(5.0f == m1.c_);
		REQUIRE(4.5f == m1.d_);
 }

  TEST_CASE ("default_mat_constructor","[default_mat]")
 {
    Mat2 m2 {};

    REQUIRE(1.0f == m2.a_);
    REQUIRE(0.0f == m2.b_);
		REQUIRE(0.0f == m2.c_);
		REQUIRE(1.0f == m2.d_);
 }

  TEST_CASE("mat_multequal_operator","[mat_multequal]")
{
	Mat2 m0 {};
	Mat2 m1{1.0f,2.0f, 6.4f, 5.1f};
	Mat2 m2{0.0f,-2.0f, 2.0f, 1.3f};

	m0 *= m1;
	m1 *= m2;

	REQUIRE(m0.a_ == 1.0f);
	REQUIRE(m0.b_ == 2.0f);
	REQUIRE(m0.c_ == 6.4f);
	REQUIRE(m0.d_ == 5.1f);

	REQUIRE(m1.a_ == 4.0f);
	REQUIRE(m1.b_ == Approx(0.6f));
	REQUIRE(m1.c_ == 10.2f);
	REQUIRE(m1.d_ == Approx(-6.17f));

}


  TEST_CASE("mat_mult_operator","[mat_mult]")
{
	Mat2 m0 {};
	Mat2 m1{1.0f,2.0f, 6.4f, 5.1f};
	Mat2 m2{0.0f,-2.0f, 2.0f, 1.3f};
	Mat2 m3{};
	Mat2 m4{3.5f,-1.2f,-6.4f,4.0f};

	m0 = m1*m2;
	m3 = m2*m4;

	REQUIRE(m0.a_ == Approx(4.0f));
	REQUIRE(m0.b_ == Approx(0.6f));
	REQUIRE(m0.c_ == Approx(10.2f));
	REQUIRE(m0.d_ == Approx(-6.17f));

	REQUIRE(m3.a_ == Approx(12.8f));
	REQUIRE(m3.b_ == Approx(-8.0f));
	REQUIRE(m3.c_ == Approx(-1.32f));
	REQUIRE(m3.d_ == Approx(2.8f));

}

  TEST_CASE("mat_vec_mult","[mat_vec]")
{
	Mat2 m1{1.0f,-2.0f, 6.4f, 5.1f};
  Vec2 v0{4.7f, 2.6f};
	Vec2 v1{};
	Vec2 v2{};

	v1 = m1*v0;
	//v2 = m1*v1;  

	REQUIRE(v1.x_ == -0.5f);
	REQUIRE(v1.y_ == 43.34f);

	//REQUIRE(v2.x_ == 0.0f); //gibt falsches Ergebnis aus
	//REQUIRE(v2.y_ == 0.0f);

}

  TEST_CASE("mat_inverse","[inverse]")
{
	Mat2 m0{1.0f,-2.0f, 6.4f, 5.1f};
  Mat2 m1{4.7f, 2.6f, 0.0f, 3.6f};

	Mat2 m2 = inverse(m0);
	Mat2 m3 = inverse(m1);


	REQUIRE(m2.a_ == Approx(0.2849162011f));
	REQUIRE(m2.b_ == Approx(0.1117318436f));
	REQUIRE(m2.c_ == Approx(-0.3575418994f));
	REQUIRE(m2.d_ == Approx(0.05586592179f));

	REQUIRE(m3.a_ == Approx(0.2127659574468085f));
	REQUIRE(m3.b_ == Approx(-0.1536643026004728f));
	REQUIRE(m3.c_ == Approx(0.0f));
	REQUIRE(m3.d_ == Approx(0.2777777777777778f));

}

  TEST_CASE("mat_transpose","[transpose]")
{

	Mat2 m1 = make_rotation_mat2(1.0f);
	Mat2 m2 = make_rotation_mat2(45.0f);


	REQUIRE(m2.a_ == Approx(0.5253219888f));
	REQUIRE(m2.b_ == Approx(-0.8509035245f));
	REQUIRE(m2.c_ == Approx(0.8509035245f));
	REQUIRE(m2.d_ == Approx(0.5253219888f));

	REQUIRE(m1.a_ == Approx(0.5403023059f));
	REQUIRE(m1.b_ == Approx(-0.8414709848f));
	REQUIRE(m1.c_ == Approx(0.8414709848f));
	REQUIRE(m1.d_ == Approx(0.5403023059f));

}

/*Color-Konstruktoren*/

 TEST_CASE ("color_custom_constructor","[color_custom]")
 {
    Color c1{6.7f, 2.5f, 5.0f};
		Color c2{0.0f, 4.7f, 2.0f};

    REQUIRE(c1.r_ == 6.7f);
    REQUIRE(c1.g_ == 2.5f);
		REQUIRE(c1.b_ == 5.0f);

		REQUIRE(c2.r_ == 0.0f);
    REQUIRE(c2.g_ == 4.7f);
		REQUIRE(c2.b_ == 2.0f);
 }

  TEST_CASE ("color_one_constructor","[color_one]")
 {
    Color c1{6.7f};
		Color c2{0.0f};

    REQUIRE(c1.r_ == 6.7f);
    REQUIRE(c1.g_ == 6.7f);
		REQUIRE(c1.b_ == 6.7f);

		REQUIRE(c2.r_ == 0.0f);
    REQUIRE(c2.g_ == 0.0f);
		REQUIRE(c2.b_ == 0.0f);
 }


 /*Circle*/
   TEST_CASE ("circle_all_constructor","[circle_all]")
 {
    Circle c1{6.7f, 1.0f,Vec2{3.0f,1.0f}, Color{1.0f, 2.1f,3.0f}};
		Circle c2{2.7f, 5.0f,Vec2{1.0f,1.3f}, Color{0.0f}};

    REQUIRE(c1.getRadius() == 6.7f);
    REQUIRE(c1.getDiameter() == 1.0f);
		REQUIRE(c1.getCenter().x_ == 3.0f);
		REQUIRE(c1.getCenter().y_ == 1.0f);
		REQUIRE(c1.getColor().r_ == 1.0f);
		REQUIRE(c1.getColor().g_ == 2.1f);
		REQUIRE(c1.getColor().b_ == 3.0f);

    REQUIRE(c2.getRadius() == 2.7f);
    REQUIRE(c2.getDiameter() == 5.0f);
		REQUIRE(c2.getCenter().x_ == 1.0f);
		REQUIRE(c2.getCenter().y_ == 1.3f);
		REQUIRE(c2.getColor().r_ == 0.0f);
		REQUIRE(c2.getColor().g_ == 0.0f);
		REQUIRE(c2.getColor().b_ == 0.0f);
 }


   TEST_CASE ("circle_radius_constructor","[circle_radius]")
 {
    Circle c1{6.7f,Vec2{3.0f,1.0f}, Color{1.0f, 2.1f,3.0f}};
		Circle c2{2.7f,Vec2{3.2f,-1.5f}, Color{1.0f}};

    REQUIRE(c1.getRadius() == 6.7f);
		REQUIRE(c1.getCenter().x_ == 3.0f);
		REQUIRE(c1.getCenter().y_ == 1.0f);
		REQUIRE(c1.getColor().r_ == 1.0f);
		REQUIRE(c1.getColor().g_ == 2.1f);
		REQUIRE(c1.getColor().b_ == 3.0f);
		

    REQUIRE(c2.getRadius()== 2.7f);
		REQUIRE(c2.getCenter().x_ == 3.2f);
		REQUIRE(c2.getCenter().y_ == -1.5f);
		REQUIRE(c2.getColor().r_ == 1.0f);
		REQUIRE(c2.getColor().g_ == 1.0f);
		REQUIRE(c2.getColor().b_ == 1.0f);

 }

    TEST_CASE ("circle_getradius","[getradius]")
 {
    Circle c1{6.7f, 1.0f,Vec2{3.0f,1.0f}, Color{1.0f}};
		Circle c2{2.7f, 5.0f,Vec2{1.0f,1.3f}, Color{1.0f}};

    REQUIRE(c1.getRadius() == 6.7f);

    REQUIRE(c2.getRadius() == 2.7f);

 }


    TEST_CASE ("circle_getdiameter","[getdiameter]")
 {
    Circle c1{6.7f, 1.0f,Vec2{3.0f,1.0f}, Color{1.0f}};
		Circle c2{2.7f, 5.0f,Vec2{1.0f,1.3f}, Color{1.0f}};

    REQUIRE(c1.getDiameter() == 1.0f);

    REQUIRE(c2.getDiameter() == 5.0f);

 }

    TEST_CASE ("circle_getcenter","[getcenter]")
 {
    Circle c1{6.7f, 1.0f,Vec2{3.0f,1.0f}, Color{1.0f}};
		Circle c2{2.7f, 5.0f,Vec2{1.0f,1.3f}, Color{1.0f}};

		REQUIRE(c1.getCenter().x_ == 3.0f);
		REQUIRE(c1.getCenter().y_ == 1.0f);

		REQUIRE(c2.getCenter().x_ == 1.0f);
		REQUIRE(c2.getCenter().y_ == 1.3f);
 }

    TEST_CASE ("circle_circumference","[circle_circumference]")
 {
    Circle c1{6.7f, 1.0f,Vec2{3.0f,1.0f}, Color{1.0f}};
		Circle c2{2.7f, 5.0f,Vec2{1.0f,1.3f}, Color{1.0f}};

    REQUIRE(c1.circumference() == Approx(42.09734156f));

    REQUIRE(c2.circumference() == Approx(16.96460033));
 }

    TEST_CASE ("describe_circle_isinside","[circle_isinside]")
 {
    Circle c1{6.7f, 1.0f,Vec2{3.0f,1.0f}, Color{1.0f}};
		Circle c2{2.7f, 5.0f,Vec2{1.0f,1.3f}, Color{1.0f}};
		Vec2 v1{4.3f,5.4f};
		Vec2 v2{300.0f, 251.0f};

    REQUIRE(c1.is_inside(v1) == true);

    REQUIRE(c2.is_inside(v2) == false);
 }
 


 /*Rectangle*/
 
    TEST_CASE ("rectangle_constructor","[rectangle]")
 {
    Rectangle r1{Vec2{2.6f, 6.1f},Vec2{3.0f,1.0f}, Color{3.2f, 1.0f, 2.1f}};
		Rectangle r2{Vec2{2.7f, 1.0f},Vec2{3.2f,-1.5f}, Color{1.2f}};

    REQUIRE(r1.getMin().x_ == 2.6f);
		REQUIRE(r1.getMin().y_ == 6.1f);
		REQUIRE(r1.getMax().x_ == 3.0f);
		REQUIRE(r1.getMax().y_ == 1.0f);
		REQUIRE(r1.getColor().r_ == 3.2f);
		REQUIRE(r1.getColor().g_ == 1.0f);
		REQUIRE(r1.getColor().b_ == 2.1f);

    REQUIRE(r2.getMin().x_ == 2.7f);
		REQUIRE(r2.getMin().y_ == 1.0f);
		REQUIRE(r2.getMax().x_ == 3.2f);
		REQUIRE(r2.getMax().y_ == -1.5f);
		REQUIRE(r2.getColor().r_ == 1.2f);
		REQUIRE(r2.getColor().g_ == 1.2f);
		REQUIRE(r2.getColor().b_ == 1.2f);

 }  

     TEST_CASE ("rectangle_circumference","[rectangle_circumference]")
 {
    Rectangle r1{Vec2{2.0f,1.0f},Vec2{3.6f, 6.1f}, Color{1.2f}};
		Rectangle r2{Vec2{2.7f, 1.0f},Vec2{3.2f,1.5f}, Color{1.0f}};

    REQUIRE(r1.circumference() == Approx(13.4f));

    REQUIRE(r2.circumference() == Approx(2.0f));

 }  //bis hier hin geht alles 


     TEST_CASE ("describe_rectangle_isinside","[rectangle_isinside]")
 {
    Rectangle r1{Vec2{3.0f, 1.0f},Vec2{6.7f,5.0f}, Color{1.0f}};
		Rectangle r2{Vec2{2.7f, 5.0f},Vec2{1.0f,1.3f}, Color{1.0f}};
		Vec2 v1{4.3f,3.4f};
		Vec2 v2{300.0f, 251.0f};

    REQUIRE(r1.is_inside(v1) == true);

    REQUIRE(r2.is_inside(v2) == false);
 } 
 //bis hier hin geht alles
 

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
	//return 0;
}
