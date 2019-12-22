#include "item.hpp"
using namespace std;

string item::getName(){
	return name;
}

string item::getDescription(){
	return description;
}

int item::getType(){
	return type;
}

int weapon::getwType(){
	return wtype;
}

sword::sword(string nameIn, string descriptionIn, int damageIn){
	name = nameIn;
	description = descriptionIn;
	damage = damageIn;
	wtype = 1;
	type = 1;
}
int weapon::getDamage(){
	return damage;
}

int sword::getDamage(){
	return damage + 1;
}

