#pragma once
#include<vector>
#include"character.h"
#include"skill.h"
#include"TurnManager.h"
#include"BattleState.h"
#include"BattleUI.h"
using namespace std;

class Battle {
	vector<character*> m_characters;
	TurnManager m_turn;
	BattleState m_state = BattleState::Command;
	int m_inputWait = 0;
	int m_selectedSkill = 0;
	BattleUI* m_ui = nullptr;
	int m_targetIndex = 0;
	bool m_isActing = false;
public:
	void update();
	int getSelectedSkill() const { return m_selectedSkill; }
	BattleState getState() const { return m_state; }
	character* selectTarget(character* actor);
	character* selectAlly(character* actor);
	void addCharacter(character* ch);
	void setUI(BattleUI* ui) { m_ui = ui; }
	const vector<character*>& getCharacters() const;
	int getTargetIndex() const { return m_targetIndex; }
	vector<character*> getTargets(character* actor, TargetType type);
	void moveTarget(int dir, const vector<character*>& targets);
	void fixTargetIndex(vector<character*>& targets);
	void executeSkill(character* actor, Skill* skill, character* target);
	void endTurn();
	bool isAllDead(Team team);
};