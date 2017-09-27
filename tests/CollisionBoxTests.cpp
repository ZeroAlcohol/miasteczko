#include "CollisionBox.hpp"
#include "catch.hpp"
#include <iostream>

TEST_CASE ("Circle radius calculation", "[circle]")
{
	CollisionBox a({ {1, 2}, {2,2} });
	CollisionBox b({ {2,2}, {4.4, 4.4} });
	CollisionBox c({ {1, 1} , {1, 2}, {2, 1}, {2, 2}});

	REQUIRE(a.calculateRadius() == 1);
	REQUIRE(b.calculateRadius() == Approx(3.3941125));
	REQUIRE(c.calculateRadius() == 0);
}

TEST_CASE("Collision circle-circle", "[circle]")
{
	CollisionBox a({ { 0,0 }, { 5, 5 } });
	CollisionBox b({ { 6, 6 }, { 5, 5 } });
	CollisionBox c({ {0, 0}, {5.01, 5} });

	REQUIRE(a.detectCollision(b) == false);
	REQUIRE(b.detectCollision(a) == false);
	REQUIRE(c.detectCollision(b) == true);
	REQUIRE(b.detectCollision(c) == true);
	REQUIRE(c.detectCollision(a) == true);
	REQUIRE(a.detectCollision(c) == true);
}

TEST_CASE("Collision circle-rectangle", "[circle][rectangle]")
{
	//circles
	CollisionBox a({ { 1, 1 },{ 1, 3 } });
	CollisionBox a1({ { 0, -4 },{ 1, -3 } });
	
	//rectangles
	CollisionBox b({ { 1, 2.99 },{ 3, 3 }, {3,5}, {1,5}});
	CollisionBox c({ { 1, 3 },{ 3, 3 },{ 3,5 },{ 1,5 } });
	CollisionBox d({ { 2, 0 },{ 4, -2 },{ 2, -4 },{ 1, -3 } });
	CollisionBox e({ { -0.5, -2 },{ -3, -1 },{ -5, -6 },{ -0.5, 3 } });


	REQUIRE(a.detectCollision(b) == true);
	REQUIRE(b.detectCollision(a) == true);

	REQUIRE(c.detectCollision(a) == false);
	REQUIRE(a.detectCollision(c) == false);

	REQUIRE(a.detectCollision(d) == true);
	REQUIRE(d.detectCollision(a) == true);

	REQUIRE(a.detectCollision(e) == true);
	REQUIRE(e.detectCollision(a) == true);

	REQUIRE(a1.detectCollision(b) == false);
	REQUIRE(b.detectCollision(a1) == false);

	REQUIRE(c.detectCollision(a1) == false);
	REQUIRE(a1.detectCollision(c) == false);

	REQUIRE(a1.detectCollision(d) == false);
	REQUIRE(d.detectCollision(a1) == false);

	REQUIRE(a1.detectCollision(e) == false);
	REQUIRE(e.detectCollision(a1) == false);

}

TEST_CASE("Collision rectangle-rectangle", "[rectangle]")
{
	CollisionBox a({ { 2,  -1},{ 2, 1 },{ -2, 1 },{ -2, -1 } });
	CollisionBox b({ { 4, 4 },{ 6, 4 },{ 6, 5 },{ 4, 5 } });
	CollisionBox c({ { -6, -2 },{ -1, -2 },{ -1, 6 },{ -6, 6 } });
	
	CollisionBox d({ { -3, -5 },{ 4, 2 },{ 2, 4 },{ -5, -3 } });
	CollisionBox e({ { 6, 2 },{ 9, 3 },{ 7, 9 },{ 4, 8 } });

	REQUIRE(a.detectCollision(b) == false);
	REQUIRE(b.detectCollision(a) == false);
	REQUIRE(c.detectCollision(a) == true);
	REQUIRE(a.detectCollision(c) == true);
	REQUIRE(a.detectCollision(d) == true);
	REQUIRE(d.detectCollision(a) == true);
	REQUIRE(a.detectCollision(e) == false);
	REQUIRE(e.detectCollision(a) == false);
	
	
	REQUIRE(b.detectCollision(c) == false);
	REQUIRE(c.detectCollision(b) == false);
	REQUIRE(b.detectCollision(d) == false);
	REQUIRE(d.detectCollision(b) == false);
	REQUIRE(b.detectCollision(e) == true);
	REQUIRE(e.detectCollision(b) == true);

	REQUIRE(c.detectCollision(d) == true);
	REQUIRE(d.detectCollision(c) == true);
	REQUIRE(c.detectCollision(e) == false);
	REQUIRE(e.detectCollision(c) == false);

	REQUIRE(d.detectCollision(e) == false);
	REQUIRE(e.detectCollision(d) == false);
}
