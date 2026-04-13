#pragma once
#include <string>
#include <algorithm>
#include "character.h"
using namespace std;
#pragma region クラス
class character;

enum class TargetType {
    SingleEnemy,
    AllEnemies,
    SingleAlly,
    AllAlly,
    Self
};

class DamageCalculator {
public:
    static int physical(const character& user, const character& target);
    static int magic(const character& user, const character& target);
};

class Effect {
public:
    virtual ~Effect() = default;
    virtual string getName() const = 0;
};

class Skill : public Effect{
protected:
    string m_name;
    int m_mpCost;
public:
    Skill(string name, int mpCost):m_name(name),m_mpCost(mpCost){}
	virtual ~Skill() = default;
    virtual TargetType getTargetType() const = 0;
	virtual void Use(character& user, character& target) = 0;
    int getMpCost() const { return m_mpCost; }
    string getName() const override { return m_name; }
};
class Buff : public Effect {
protected:
    string m_name;
    int m_duration;
public:
    Buff(string name,int duration) :m_name(name), m_duration(duration) {}
    virtual ~Buff() = default;
    virtual void apply(Status& status) const = 0;
    virtual void onTurnEnd(character& ch){}

    string getName() const override { return m_name; }

    void reduceTurn() { m_duration--; }
    bool isExpired() const { return m_duration <= 0; }
};
#pragma endregion
#pragma region スキル
//攻撃スキル
class AttackSkill : public Skill {
public:
    AttackSkill();
    TargetType getTargetType() const override { return TargetType::SingleEnemy; }
	void Use(character& user, character& target)override;
};

class FireSkill : public Skill {
public:
    FireSkill();
    TargetType getTargetType() const override { return TargetType::SingleEnemy; }
	void Use(character& user, character& target)override;
};
class AtkBuffSkill :public Skill {
public:
    AtkBuffSkill();
    TargetType getTargetType() const override { return TargetType::SingleAlly; }
    void Use(character& user, character& target) override;
};
//バフスキル
class AtkBuff : public Buff {
    int m_value;
public:
    AtkBuff();

    void apply(Status& s) const override;
};
#pragma endregion