#pragma once
#include<vector>
#include<string>
#include"character.h"
#include"skill.h"
#include"BattleState.h"
const int ENEMY_Y = 50;
const int LOG_Y = 200;
const int PLAYER_Y = 350;
const int COMMAND_Y = 450;
class BattleUI {
    vector<string> logs;
public:
	void Draw(const vector<character*>& characters,BattleState state, int selected, int targetIndex);
    void drawCharacters(const vector<character*>& characters);
    void drawStatus(const character* ch, int x, int y);
    void drawSkills(const character* player, int selected);
    void drawTargetCursor(int targetIndex);
    void drawGauge(const character* ch, int x, int y, int gauge);
    void addLog(const string& msg);
    void drawLog();
};