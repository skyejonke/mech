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

int sword::getDamage(){
	return damage + 1;
}

gun::gun(string nameIn,
	string descriptionIn,
	int damageIn,
	int clipIn,
	int rangeModIn){

	name = nameIn;
	description = descriptionIn;
	damage = damageIn;
	clip = clipIn;
	rangeMod = rangeModIn;
	wtype = 2;
	type = 1;
}

/*gun::gun(gun other){
	description = other.getDescription();
	name = other.getName();
	damage = other.getDamage(0);
	clip = other.getClip();
	rangeMod = other.getRangeMod();
	wtype = 2;
	type = 1;
}
*/

int gun::getDamage(int range){
	return (damage - (range * rangeMod));
}

int gun::getDamage(){
	return damage;
}

int gun::getClip(){
	return clip;
}

int gun::getRangeMod(){
	return rangeMod;
}
