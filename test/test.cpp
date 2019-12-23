#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "item.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
TEST_CASE("Items work as intended", "[item]"){
	gun testBlaster = gun("Laser Cannon", "Shoots Lasers", 10, 0, 1);
	sword testBlade = sword("God Blade",
		"God's Blade",
		1000);
	SECTION("Sword constructors work"){
		REQUIRE(testBlade.getName() == "God Blade");
		REQUIRE(testBlade.getDescription() == "God's Blade");
		REQUIRE(testBlade.getDamage() == 1001);
	}
	SECTION("Gun constructors work"){
		REQUIRE(testBlaster.getName() == "Laser Cannon");
		REQUIRE(testBlaster.getDescription() ==
			"Shoots Lasers");
		REQUIRE(testBlaster.getDamage(0) == 10);
	}
	vector<weapon*> weaponList = vector<weapon*>();
	SECTION("Weapon interfaces work"){
		weaponList.push_back(&testBlade);
		weaponList.push_back(&testBlaster);
		REQUIRE(weaponList[0]->getDamage() == 1001);
		REQUIRE(weaponList[0]->getwType() == 1);
		REQUIRE(weaponList[1]->getDamage() == 10);
		REQUIRE(weaponList[1]->getwType() == 2);
	}
	vector<item*> itemList = vector<item*>();
	SECTION("Item interfaces work"){
		itemList.push_back(&testBlade);
		itemList.push_back(&testBlaster);
		REQUIRE(itemList[0]->getName() == "God Blade");
		REQUIRE(itemList[0]->getType() == 1);
		REQUIRE(itemList[0]->getDescription()
			== "God's Blade");
		REQUIRE(itemList[1]->getName() == "Laser Cannon");
		REQUIRE(itemList[1]->getType() == 1);
		REQUIRE(itemList[1]->getDescription()
			== "Shoots Lasers");
	}
}
