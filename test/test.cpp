#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "item.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
TEST_CASE("Items work as intended", "[item]"){
	sword testBlade = sword("God Blade",
		"God's Blade",
		1000);
	SECTION("Sword constructor's work"){
		REQUIRE(testBlade.getName() == "God Blade");
		REQUIRE(testBlade.getDescription() == "God's Blade");
		REQUIRE(testBlade.getDamage() == 1001);
	}
	vector<weapon*> weaponList = vector<weapon*>();
	SECTION("Weapon interfaces work"){
		weaponList.push_back(&testBlade);
		REQUIRE(weaponList[0]->getDamage() == 1001);
		REQUIRE(weaponList[0]->getwType() == 1);
	}
	vector<item*> itemList = vector<item*>();
	SECTION("Item interfaces work"){
		itemList.push_back(&testBlade);
		REQUIRE(itemList[0]->getName() == "God Blade");
		REQUIRE(itemList[0]->getType() == 1);
		REQUIRE(itemList[0]->getDescription()
			== "God's Blade");
	}
}
