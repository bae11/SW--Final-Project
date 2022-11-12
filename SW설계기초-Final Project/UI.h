#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "VariableSets.h"
#include "CursorFunctions.h"
#include "Timer.h"
#ifndef UI_H
#define UI_H

//�ʱ� X, Y��ǥ
int modifiedX_Text = BACKGROUND_ORIGIN_X + BACKGROUND_ROW / 2 - 28;
int modifiedY_Text = BACKGROUND_ORIGIN_Y;

//�������� ��ȣ ���
void InvalidateStageNumber() {
	COORD ptr = { BACKGROUND_ORIGIN_X, BACKGROUND_ORIGIN_Y };
	int modifiedX = ptr.X + 2, modifiedY = ptr.Y + 1;
	SetCurrentCursorPos(modifiedX, modifiedY);
	printf("Stage : %d", StageNumber);
}

//---------------������ ������ ���� �Լ�----------------
//������ ������ �����Ҵ�
void InitializeLifeGauge() { 
	LifeGauge = (int *)malloc(sizeof(int)*SelectedLife); for (int i = 0; i < SelectedLife; i++) LifeGauge[i] = 1;
	CurrentLife = SelectedLife;
	COORD ptr = { BACKGROUND_ORIGIN_X, BACKGROUND_ORIGIN_Y };
	int modifiedX = ptr.X + 2, modifiedY = ptr.Y + 2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	for (int i = 0; i < SelectedLife; i++) { SetCurrentCursorPos(modifiedX + i * 2, modifiedY); if (LifeGauge[i] == 1) printf("��"); }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetCurrentCursorPos(ptr.X, ptr.Y);
}

//������ ������ UI ����
void InvalidateLifeGauge() {
	COORD ptr = { BACKGROUND_ORIGIN_X, BACKGROUND_ORIGIN_Y };
	int modifiedX = ptr.X + 2, modifiedY = ptr.Y + 2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	for (int i = 0; i < SelectedLife; i++) { 
		SetCurrentCursorPos(modifiedX + i * 2, modifiedY); 
		if (LifeGauge[i] == 1) printf("��"); 
		else { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); printf("��"); }
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetCurrentCursorPos(ptr.X, ptr.Y);
}
//----------------------------------------------------------

//-----------------�� ���� �Լ�----------------------
//�� �� ĳ���� ��ġ Ŀ�� ����� �Լ�
void HidePlayerPosCursor(int x, int y) {
	SetCurrentCursorPos(x, y);
	printf("  ");
}

//�� �� ĳ���� ��ġ Ŀ�� ��Ÿ���� �Լ�
void ShowPlayerPosCursor(int x, int y) {
	SetCurrentCursorPos(x, y);
	printf("��");
}

//�� �׸���
void ShowMap() {
	COORD ptr = { BACKGROUND_ORIGIN_X + BACKGROUND_ROW, BACKGROUND_ORIGIN_Y };
	int modifiedX = ptr.X - 32, modifiedY = ptr.Y + 1;
	for (int i = 0; i <= MAPLENGTH; i++) {
		SetCurrentCursorPos(modifiedX + 2 * i, modifiedY);
		if (i == 0) printf("��");
		else if (i == MAPLENGTH) printf("��");
		else if (i % 5 == 0) printf("��");
		else printf("��");
	}
	SetCurrentCursorPos(GAMEBOARD_ORIGIN_X, GAMEBOARD_ORIGIN_Y);
}

//�� �� ĳ���� ��ġ ����
void InvalidateMap() {
	COORD ptr = { BACKGROUND_ORIGIN_X + BACKGROUND_ROW, BACKGROUND_ORIGIN_Y };
	int modifiedX = ptr.X - 32, modifiedY = ptr.Y + 1;
	ShowPlayerPosCursor(modifiedX + CurrentTime - 1, modifiedY + 1);
	if (TimeCheckerEnd() > CurrentTime * (StageTime[StageNumber - 1] / (MAPLENGTH * 2))) {
		HidePlayerPosCursor(modifiedX + CurrentTime - 1, modifiedY + 1);
		CurrentTime++; PlayerPos++;
	}
	SetCurrentCursorPos(GAMEBOARD_ORIGIN_X, GAMEBOARD_ORIGIN_Y);
}
//-----------------------------------------------------

//--------------��ų UI ���� �Լ�------------------

//�� ������ų �� ������ų �����
void HidePreviousCurrentNSubSkill() {
	int Skillstrlen = Strlen(Skillstr), SubSkillstrlen = Strlen(SubSkillstr);
	int Currentlen = Strlen(SkillSets[CurSkill]), Sublen = Strlen(SkillSets[SubSkill]);
	int len = 23;
	for (int i = 1; i <= 2; i++) {
		for (int j = 0; j <= len; j++) {
			SetCurrentCursorPos(modifiedX_Text + j, modifiedY_Text + i);
			printf(" ");
		}
	}
}

//���� ������ų �� ������ų  ���
void ShowCurrentNSubSkill() {
	SetCurrentCursorPos(modifiedX_Text, modifiedY_Text + 1);
	printf("%s %s", Skillstr, SkillSets[CurSkill]);
	SetCurrentCursorPos(modifiedX_Text, modifiedY_Text + 2);
	printf("%s %s", SubSkillstr, SkillSets[SubSkill]);
}

//---------------------------------------------------

#endif // !UI_H