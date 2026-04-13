#pragma once
#include<vector>
#include"character.h"

class TurnManager {
	struct Entry {
		character* ch;
		int gauge = 0;
	};
	vector<Entry> m_entries;
	const int MAX_GAUGE = 100;
public:
	void addCharacter(character* ch);
	character* update();
	void endTurn(vector<character*>& characters);
};