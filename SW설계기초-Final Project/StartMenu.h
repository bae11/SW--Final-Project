#pragma once
#pragma warning(disable:4996)
#include <conio.h>
#include "VariableSets.h"
#include "ResizeConsole.h"
#include "CursorFunctions.h"
#include "BackGround.h"
#include "GameFile.h"
#ifndef STARTMENU_H
#define STARTMENU_H

INPUT_RECORD rec;
DWORD dwNOER;
DWORD CIN;
DWORD mode;


//���� ��� ���� �ڽ� 
void CreateModeSelectionBox(int x, int y) {
	COORD ptr = { x,y };
	for (int i = 0; i < MODESELECTIONBOX_COLUMN; i++) {
		SetCurrentCursorPos(ptr.X, ptr.Y + i);
		if (i == 0) printf("��");
		else if (i == MODESELECTIONBOX_COLUMN - 1) printf("��");
		else printf("��");
		SetCurrentCursorPos(ptr.X + MODESELECTIONBOX_ROW, ptr.Y + i);
		if (i == 0) printf("��");
		else if (i == MODESELECTIONBOX_COLUMN - 1) printf("��");
		else printf("��");
	}
	SetCurrentCursorPos(ptr.X, ptr.Y);
	for (int i = 2; i < MODESELECTIONBOX_ROW; i += 2) {
		SetCurrentCursorPos(ptr.X + i, ptr.Y);
		printf("��");
		SetCurrentCursorPos(ptr.X + i, ptr.Y + MODESELECTIONBOX_COLUMN - 1);
		printf("��");
	}
}

//��Ʈ�� ȭ�� ���
void ShowIntro() {
	COORD center = { BACKGROUND_ORIGIN_X + BACKGROUND_ROW / 2, BACKGROUND_ORIGIN_Y + BACKGROUND_COLUMN / 2 };
	int modifiedX = center.X - 52, modifiedY = center.Y - 5;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				SetCurrentCursorPos(modifiedX + i * 12 + 2 * k, modifiedY + j);
				if (IntroModel[i][j][k] == 1) printf("��");
			}
		}
	}
	CreateModeSelectionBox(ModeSelectionBox_Origin_X, ModeSelectionBox_Origin_Y);
	SetCurrentCursorPos(ModeSelectionBox_Origin_X + (MODESELECTIONBOX_ROW - strlen("Story Mode")) / 2 + 1, ModeSelectionBox_Origin_Y + 1);
	printf("Story Mode");
	CreateModeSelectionBox(ModeSelectionBox_Origin_X + MODESELECTIONBOX_ROW + 4, ModeSelectionBox_Origin_Y);
	SetCurrentCursorPos(ModeSelectionBox_Origin_X + MODESELECTIONBOX_ROW + 4 + (MODESELECTIONBOX_ROW - strlen("Challenge Mode")) / 2 + 1, ModeSelectionBox_Origin_Y + 1);
	printf("Challenge Mode");
	CreateModeSelectionBox(ModeSelectionBox_Origin_X + MODESELECTIONBOX_ROW * 2 + 8, ModeSelectionBox_Origin_Y);
	SetCurrentCursorPos(ModeSelectionBox_Origin_X + MODESELECTIONBOX_ROW * 2 + 8 + (MODESELECTIONBOX_ROW - strlen("Quit")) / 2 + 1, ModeSelectionBox_Origin_Y + 1);
	printf("Quit");
}

//��Ʈ�� ȭ�� ����
void HideIntro() {
	COORD ptr = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', CONSOLE_COLUMN * CONSOLE_ROW, ptr, &dw);
}

//���콺 Ŭ�� �̺�Ʈ �޴� �Լ�
void GameModeBoxClick(int *xx, int *yy) {
	while (1)
	{
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // �ܼ�â �Է��� �޾Ƶ���.
		if (rec.EventType == MOUSE_EVENT) {// ���콺 �̺�Ʈ�� ���
			if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
				int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
				int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

				*xx = mouse_x; //x���� �ѱ�
				*yy = mouse_y; //y���� �ѱ�
				break;
			}
		}
	}
}

//���� ���� �޴�
int StartMenu() {
	//system �Լ��� �� ���Ŀ� INPUT �ڵ� �ٽ� ��Ȱ��ȭ
	HANDLE CIN = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	//��Ʈ�� ȭ�� ���
	ShowIntro();
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	int xx, yy; int flag = 0;
	while (1) {
		GameModeBoxClick(&xx, &yy);
		if (yy >= ModeSelectionBox_Origin_Y && yy <= ModeSelectionBox_Origin_Y + MODESELECTIONBOX_COLUMN) {
			if (xx >= ModeSelectionBox_Origin_X && xx <= ModeSelectionBox_Origin_X + MODESELECTIONBOX_ROW) {
				GameMode = 0; flag = 1; break;
			}
			else if (xx >= ModeSelectionBox_Origin_X + MODESELECTIONBOX_ROW + 4 && xx <= ModeSelectionBox_Origin_X + 2 * MODESELECTIONBOX_ROW + 4) {
				GameMode = 1; flag = 1; break;
			}
			else if (xx >= ModeSelectionBox_Origin_X + 2 * (MODESELECTIONBOX_ROW + 4) && xx <= ModeSelectionBox_Origin_X + 3 * MODESELECTIONBOX_ROW + 8) break;
		}
	}
	HideIntro();
	return flag;
}
#endif // !STARTMENU_H