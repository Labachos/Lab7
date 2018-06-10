#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Enemy
{
	int health = 100;
	int damage = 10;
	int experience;
	vector<int> place;
	Enemy(int x, int y, int exp) {
		place.push_back(x);
		place.push_back(y);
		experience = exp;
	}
};

class Unit
{
public:
	virtual void Gain_experience(int) = 0;
	virtual void Earn_rank(int) = 0;
	virtual void Pay_for_taxes(int) = 0;
	virtual void Show_charge() const = 0;
	virtual void Show_health() const = 0;
	virtual void Attack(Enemy&)=0;
};

//////////////////////////////TOWER///////////////////////////////////

class Tower :public virtual Unit
{
public:
	void virtual Attack(Enemy& one);
	Tower() :rank(10), damage(100) {};
private:
	int rank;
	int damage;
};

void Tower::Attack(Enemy& one) {
	one.health -= damage*(rank + 1);
}

//////////////////////////FARM///////////////////////////////////////

class Barracks;
class Watch;

class Farm :public Unit
{
public:
	Farm() :charge(100), health(50), donation(30), overall_income(0), overall_experince(0), rank(0) {};
	void Add_donation();
	void Gain_experience(int amount_of_experience_needed = 5);
	void Earn_rank(int rank_needed = 1);
	void Pay_for_taxes(int money_needed = 100);
	void Show_charge() const;
	void Show_health() const;
	void Attack(Enemy&);
	friend void Share_resources(int, Farm&, Barracks&);
	friend void Add_experience(int, Watch&, Farm&);
private:
	int charge;
	int health;
	int donation;
	int overall_income;
	int overall_experince;
	int rank;
};

void Farm::Add_donation() {
	int count = 1000;
	while (count) {
		overall_income += donation;
		this_thread::sleep_for(chrono::milliseconds(5000));
		count--;
	}
}

void Farm::Gain_experience(int amount_of_experience_needed) {
	overall_experince += amount_of_experience_needed;
	overall_income -= amount_of_experience_needed;
	cout << "The " << amount_of_experience_needed << " of experience are gained!" << endl;
}

void Farm::Earn_rank(int rank_needed) {
	rank += rank_needed;
	overall_experince -= rank_needed * 10;
	cout << "The " << rank_needed << " rank is gained!" << endl;
}

void Farm::Pay_for_taxes(int money_needed) {
	overall_income -= money_needed;
	cout << "Taxes are paid successfuly!" << endl;
}

void Farm::Show_charge() const {
	cout << "The price for this is" << " " << Farm::charge << endl;
}

void Farm::Show_health() const {
	cout << "The health of this is" << " " << Farm::health << endl;
}

void Farm::Attack(Enemy&) {
	cout << "This unit can not attack!" << endl;
}

/////////////////////////////////WARRIOR//////////////////////////////////
class Warrior :public Unit
{
public:
	Warrior() :charge(20), health(20), damage(10), rank(1), funds(30), experience(0) {};
	Warrior(int dist) :charge(20), health(20), damage(10), rank(1), funds(30), experience(0), distance(dist) {};
	void Gain_experience(int);
	void Earn_rank(int rank_needed = 1);
	void Pay_for_taxes(int money_needed = 0);
	void Show_charge() const;
	void Show_health() const;
	virtual void Attack(Enemy&);
private:
	int charge;
	int health;
	int damage;
	int rank;
	int funds;
	int experience;
	int distance;
};

void Warrior::Gain_experience(int exp_needed) {
	experience += exp_needed;
	funds -= exp_needed;
}

void Warrior::Earn_rank(int rank_needed) {
	rank += rank_needed;
	experience -= rank_needed * 10;
}

void Warrior::Pay_for_taxes(int money_needed) {
	funds -= money_needed;
	cout << "Taxes are paid successfuly!" << endl;
}

void Warrior::Show_charge() const {
	cout << "The price for this is" << " " << Warrior::charge << endl;
}

void Warrior::Show_health() const {
	cout << "The health of this is" << " " << Warrior::health << endl;
}

void Warrior::Attack(Enemy& rival) {
	if (distance == 0)
		rival.health -= damage*(rank);
	else
		cout << "Need to get closer!" << endl;
}

///////////////////////////ARCHER//////////////////////////////////
class Archer : public virtual Unit
{
public:
	Archer() :charge(30), health(10), damage(15), rank(1), funds(30), experience(0) {};
	Archer(int dist) :charge(30), health(10), damage(15), rank(1), funds(30), experience(0), distance(dist) {};
	void Gain_experience(int);
	void Earn_rank(int rank_needed = 1);
	void Pay_for_taxes(int money_needed = 0);
	void Show_charge() const;
	void Show_health() const;
	virtual void Attack(Enemy&);
private:
	int charge;
	int health;
	int damage;
	int rank;
	int funds;
	int experience;
	int distance;
};

void Archer::Gain_experience(int exp_needed) {
	experience += exp_needed;
	funds -= exp_needed;
}

void Archer::Earn_rank(int rank_needed) {
	rank += rank_needed;
	experience -= rank_needed * 15;
}

void Archer::Pay_for_taxes(int money_needed) {
	funds -= money_needed;
	cout << "Taxes are paid successfuly!" << endl;
}

void Archer::Show_charge() const {
	cout << "The price for this is" << " " << Archer::charge << endl;
}

void Archer::Show_health() const {
	cout << "The health of this is" << " " << Archer::health << endl;
}

void Archer::Attack(Enemy& rival) {
	if (distance)
		rival.health -= damage*(rank + 1 / distance);
	else
		cout << "Can not attack!" << endl;
}

///////////////////////////BARRACKS///////////////////////////
class Warrior;
class Archer;

class Barracks :public Unit
{
public:
	Barracks() :charge(100), health(100), fee(20), overall_experince(0), overall_income(0), rank(0) {};
	void Gain_experience(int amount_of_experience_needed = 30);
	void Earn_rank(int rank_needed = 1);
	void Pay_for_taxes(int money_needed = 10);
	void Earn_funds();
	void Show_charge() const;
	void Show_health() const;
	Warrior* Add_warrior() { return new Warrior; }
	Archer* Add_archer() { return new Archer; }
	void del_warrior(Warrior* one) { delete one; }
	void del_archer(Archer* one) { delete one; }
	friend void Share_resources(int, Farm&, Barracks&);
	void Attack(Enemy&);
private:
	int charge;
	int health;
	int fee;
	int overall_income;
	int overall_experince;
	int rank;
};

void Barracks::Gain_experience(int amount_of_experience_needed) {
	overall_experince += amount_of_experience_needed;
	overall_income -= amount_of_experience_needed;
	cout << "The " << amount_of_experience_needed << " of experience are gained!" << endl;
}

void Barracks::Earn_rank(int rank_needed) {
	rank += rank_needed;
	overall_experince -= rank_needed * 10;
	cout << "The " << rank_needed << " rank is gained!" << endl;
}

void Barracks::Pay_for_taxes(int money_needed) {
	overall_income -= money_needed;
	cout << "Taxes are paid successfuly!" << endl;
}

void Barracks::Earn_funds() {
	int count = 1000;
	while (count)
	{
		overall_income += fee;
		this_thread::sleep_for(chrono::milliseconds(5000));
		count--;
	}
}

void Barracks::Show_charge() const {
	cout << "The price for this is" << " " << Barracks::charge << endl;
}

void Barracks::Show_health() const {
	cout << "The health of this is" << " " << Barracks::health << endl;
}

void Share_resources(int money_needed, Farm& from, Barracks& to) {
	from.overall_income -= money_needed;
	to.overall_income += money_needed;
}

void Barracks::Attack(Enemy&) {
	cout << "This unit can not attack" << endl;
}

///////////////////////WATCH/////////////////////////////////

class Watch : public Archer, public Tower
{
public:
	Watch() :health(100), damage(10), charge(100), rank(1), experience(0) {};
	Watch(int distance) :health(100), damage(10), charge(100), rank(1), experience(0), distance(distance) {};
	void Gain_experience(int exp_needed, Farm& one) { Add_experience(exp_needed, *this, one); };
	void Earn_rank(int rank_needed = 1) { rank += rank_needed; experience -= rank_needed * 10; };
	void Pay_for_taxes(int money_needed = 0) { cout << "It is too far away to ask for charge" << endl; }
	void Show_charge() const { cout << "The price for this is " << charge << endl; }
	void Show_health() const { cout << "The health of this is " << health << endl; }
	void Attack(Enemy& rival);
	friend void Add_experience(int, Watch&, Farm&);
private:
	int health;
	int charge;
	int damage;
	int rank;
	int experience;
	int distance;
};

void Add_experience(int exp_needed, Watch& to, Farm& from) {
	to.experience += exp_needed;
	from.overall_experince -= exp_needed;
}

void Watch::Attack(Enemy&rival) {
	if (distance)
		Archer::Attack(rival);
	else
		Tower::Attack(rival);
}

///////////////////////////////ARMY///////////////////////////

class Interface;

class Army
{
public:
	Army(int warriors, int archers, int dist) : number_of_warriors(warriors), number_of_archers(archers), distance(dist) {};
	void Fill_the_army();
	void Abandon_the_army();
	void Attack(Enemy&);
	friend void copy_army(Army&, Interface&);
private:
	int number_of_archers;
	int number_of_warriors;
	int distance;
	vector<Warrior*>sword_men;
	vector<Archer*>bow_men;
	Warrior sword_man;
	Archer bow_man;
	Barracks fabric;
};

void Army::Fill_the_army() {
	for (int i = 0; i < number_of_warriors; ++i)
		sword_men.push_back(fabric.Add_warrior());
	for (int i = 0; i < number_of_archers; ++i)
		bow_men.push_back(fabric.Add_archer());
}

void Army::Abandon_the_army() {
	for (int i = 0; i < sword_men.size(); ++i)
		fabric.del_warrior(sword_men.at(i));
	for (int i = 0; i < bow_men.size(); ++i)
		fabric.del_archer(bow_men.at(i));
}

void Army::Attack(Enemy& rival) {
	if (distance)
		bow_man.Attack(rival);
	else
		sword_man.Attack(rival);
}

class Interface
{
public:
	Interface(int number_of_w, int number_of_a, int distance) {
		Army your_army(number_of_w, number_of_w, distance);
		your_army.Fill_the_army();
		copy_army(your_army, *this);
	}
	friend void copy_army(Army&, Interface&);
	void Add_to_army(Unit*);
	void Send_to_attack(Enemy&, int distance = 0);
private:
	vector<Unit*> army;
};

void copy_army(Army&from, Interface& to) {
	for (int i = 0,  j = 0; i < from.number_of_warriors, j < from.number_of_archers; ++i, ++j) {
		to.army.push_back(from.sword_men.at(i));
		to.army.push_back(from.bow_men.at(i));
	}
}

void Interface::Add_to_army(Unit* new_unit) {
	army.push_back(new_unit);
}

void Interface::Send_to_attack(Enemy& rival, int distance) {
	for (int i = 0; i < army.size(); ++i)
		army.at(i)->Attack(rival);
}

int main() {
	cout << "Kr" << endl;
	Interface one(1, 1, 10);
	Watch* two = new Watch;
	Farm* three = new Farm;
	one.Add_to_army(two); one.Add_to_army(three);
	Enemy rival(1, 1, 123);
	one.Send_to_attack(rival);
	return 0;
}