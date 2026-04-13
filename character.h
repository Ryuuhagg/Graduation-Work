#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory> 
using namespace std;
class Skill;
class Buff;
enum class Team {
	Player,
	Enemy
};
struct Status {
	int hp = 0;
	int mp = 0;
	int atk = 0;
	int inte = 0;
	int def = 0;
	int spd = 0;

};
class character {
protected:
	string m_name;
	Team m_team;
	Status m_status;
	vector<shared_ptr<Skill>> m_skills;
	vector<shared_ptr<Buff>> m_buffs;
public:
	character(string name, Status s, Team team);
	virtual ~character() = default;
	void consumeMp(int cost);
	void takeDamage(int dmg);

	Status getFinalStatus() const;

	void updateBuffs();
	void applyBuffEffects();
	void addSkill(shared_ptr<Skill> skill);
	void addBuff(shared_ptr<Buff> buff);
	void useSkill(int index, character& target);
	void showSkils()const;
	const string& getName() const { return m_name; }
	const Team& getTeam() const { return m_team; }
	const Status& status() const { return m_status; }
	const vector<shared_ptr<Skill>>& getSkills() const { return m_skills; }
	bool isAlive()const { return m_status.hp > 0; }
};