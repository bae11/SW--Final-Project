#pragma once
#include "CursorFunctions.h"
#include "ResizeConsole.h"
#include "BackGround.h"
#include "StartMenu.h"
#include "CharacterSelectionMenu.h"
#include "StageMenu.h"
#include "Player.h"
#include "Enemy.h"
#include "UI.h"
#include "Timer.h"
#ifndef GAMEFILE_H
#define GAMEFILE_H

//���丮 ���
void StoryMode() { 
	while (StageNumber < 4) {
		InvalidateStageNumber();
		ShowCurrentNSubSkill();
		ShowMap();
		ShowStageNumber();
		TimeCheckerStart();
		while (1) { InvalidateMap(); InvalidateItem(); InvalidateEnemy();  InvalidatePlayer(); if (GameOver()) return; if (StageOver()) break; }
	}
}

//���� ���


//���� ���� �Լ�
void RunGame() {
	ResizeConsole(); RemoveCursor(); InitUniBoard();
	if (StartMenu()) {
		ShowCharacterSelectionMenu();
		ShowBackGround();
		InitializeLifeGauge();
		switch (GameMode) {
		case 0: StoryMode(); break;
		case 1: break;
		}
	}
	return;
}
#endif // !GAMEFILE_H
