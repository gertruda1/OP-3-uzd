#include "antrastes_vektorius.h"
#include "antrastes2.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Medianos paieska")
{
	std::vector<int> v1{ 1,2,3,4,5 }, v2{ 1,2,3,4 };
	REQUIRE(rastimediana(v1) == 3);
	REQUIRE(rastimediana(v2) == 2.5);
}

TEST_CASE("Tikrinam, ar pirmo studento galutinis balas yra mazesnis nei antro")
{
	student1 s1, s2, s3, s4;
	s1.galBalas(7.8, 9); s2.galBalas(9, 10); s3.galBalas(3.5, 10); s4.galBalas(7.3, 8);
	REQUIRE(rikiuojam_pagal_balaD(s1, s2) == true);
	REQUIRE(rikiuojam_pagal_balaD(s1, s3) == false);
	REQUIRE(rikiuojam_pagal_balaD(s1, s4) == false);
	REQUIRE(rikiuojam_pagal_balaD(s2, s3) == false);
	REQUIRE(rikiuojam_pagal_balaD(s2, s4) == false);
	REQUIRE(rikiuojam_pagal_balaD(s3, s4) == true);
}

TEST_CASE("Tikrinam, ar pirmo studento vardas yra pirmesnis abeceleje nei antro")
{
	student1 s1, s2, s3;
	s1.setVardas("Cecilija"); s2.setVardas("Vytautas"); s3.setVardas("Pranciskus");
	REQUIRE(compareAlphabet(s1, s2) == true);
	REQUIRE(compareAlphabet(s1, s3) == true);
	REQUIRE(compareAlphabet(s2, s3) == false);
}