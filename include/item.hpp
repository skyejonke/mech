#include <string>
class item {
	public:
		std::string getName();
		std::string getDescription();
		int getType();


	protected:
		std::string name;
		std::string description;
		int type;
		// 1 = weapon 2 = part 3 = consumable
};

class weapon : public item {
	public:
		virtual int getDamage() = 0;
		int getwType();
	protected:
		int wtype;
		int damage;
		// 1 = Sword 2 = Gun 3 = Spear
};

class sword : public weapon {
	public:
		sword(std::string nameIn,
			std::string descriptionIn,
			int damageIn);
		int getDamage();
};

class gun : public weapon {
	public:
		gun(std::string nameIn,
			std::string descriptionIn,
			int damageIn,
			int clipIn, //if 0, infinity
			int rangeModIn);
		gun(gun* other);
		int getDamage(); //Assumes 0
		int getDamage(int range);
		int getClip();
		int getRangeMod();
	private:
		int clip;
		int rangeMod;
};

class part : public item {
	public:
		int getPrice();
		int getPower();
		int getDefense();
		int getaType();

	private:
		int price;
		int powerNeeded;
		int atype;
		int defense;
};
