#pragma once
#pragma warning(disable:4996)
#include <conio.h>
#include <WinUser.h>
#include "VariableSets.h"
#include "CursorFunctions.h"
#include "Item.h"
#include "Timer.h"
#include "UI.h"
#ifndef EFFECT_H
#define EFFECT_H

int CalculateEffectTimeBuffer() {
	if (TimeCheckerEnd() - EffectInputTime > EFFECTTIMEBUFFER) { EffectInputTime += EFFECTTIMEBUFFER; return 0; }
	else return 1;
}

void ShowEffect(){
	if (EffectCheck == 0) {
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y);
		printf("####");
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y+1);
		printf("####");
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y-1);
		printf("####");
	}
	else if (EffectCheck == 1) {
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y);
		printf("####");
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y + 1);
		printf("####");
	}
	else if (EffectCheck == 2) {
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y + 1);
		printf("####");
	}
	else {
		return;
	}
	EffectCheck++;
}
void HideEffect() {
	if (EffectCheck == 1) {
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y);
		printf("    ");
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y + 1);
		printf("    ");
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y - 1);
		printf("    ");
	}
	else if (EffectCheck == 2) {
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y);
		printf("    ");
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y + 1);
		printf("    ");
	}
	else if (EffectCheck == 3) {
		SetCurrentCursorPos(EFFECT_POS_X, EFFECT_POS_Y + 1);
		printf("    ");
	}
	else {
		return;
	}
}

void flashEffect() {
	HideEffect();
	ShowEffect();
}

void printEffect() {
		switch (CheckFLAG) {
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: flashEffect(); break;
		case 5: break;
		default: break;
		}
}

void InvalidateEffect() {
	if (!CalculateEffectTimeBuffer()) { if (CheckFLAG != 0)printEffect(); }
	
}


#endif // !EFFECT_H