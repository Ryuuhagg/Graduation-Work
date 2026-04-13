#pragma once
#include<vector>
using namespace std;
class Character;
class Skill;

class game {
private:
	int turnCount = 0;
public:
	void Update();
	void Draw();
};
