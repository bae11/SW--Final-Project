#pragma once
#include <Windows.h>
#include <stdio.h>
#include "VariableSets.h"
#include "ResizeConsole.h"
#include "CursorFunctions.h"
#ifndef CHARACTERSELECTIONMENU_H
#define CHARACTERSELECTIONMENU_H

INPUT_RECORD rec;
DWORD dwNOER;
DWORD CIN;
DWORD mode;

//ĳ���� ���� �ڽ� ����� �Լ�
void CreateSelectionBox(int x, int y) {
	COORD ptr = { x,y };
	for (int i = 0; i <= CHARACTERBOX_COLUMN; i++) {
		SetCurrentCursorPos(ptr.X, ptr.Y + i);
		if (i == 0) printf("��");
		else if (i == CHARACTERBOX_COLUMN) printf("��");
		else printf("��");
		SetCurrentCursorPos(ptr.X + CHARACTERBOX_ROW, ptr.Y + i);
		if (i == 0) printf("��");
		else if (i == CHARACTERBOX_COLUMN) printf("��");
		else printf("��");
	}
	SetCurrentCursorPos(ptr.X, ptr.Y);
	for (int i = 2; i < CHARACTERBOX_ROW; i += 2) {
		SetCurrentCursorPos(ptr.X + i, ptr.Y);
		printf("��");
		SetCurrentCursorPos(ptr.X + i, ptr.Y + CHARACTERBOX_COLUMN);
		printf("��");
	}
}

//���콺 Ŭ�� �̺�Ʈ �޴� �Լ�
void CharacterBoxClick(int *xx, int *yy) {
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

//ĳ���� ���� �ڽ� ��� �Լ�
void ShowCharacterBox() {
	//Print Text
	SetCurrentCursorPos(CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW * 2 - CHARACTERBOX_ROW / 2 - 17, CHARACTERBOX_ORIGIN_Y - 5);
	printf("------------SELECT YOUR CHARACTER------------");

	//Character Box Number 1
	CreateSelectionBox(CHARACTERBOX_ORIGIN_X, CHARACTERBOX_ORIGIN_Y);
	SetCurrentCursorPos(CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW / 2 - 2, CHARACTERBOX_ORIGIN_Y + CHARACTERBOX_COLUMN / 2);
	printf("<OAAO>");
	SetCurrentCursorPos(CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW / 2 - 10, CHARACTERBOX_ORIGIN_Y + CHARACTERBOX_COLUMN + 2);
	printf("Health : 7   Speed : 1");

	//Character Box Number 2
	CreateSelectionBox(CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW + 5, CHARACTERBOX_ORIGIN_Y);
	SetCurrentCursorPos(CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW * 2 - CHARACTERBOX_ROW / 2 + 3, CHARACTERBOX_ORIGIN_Y + CHARACTERBOX_COLUMN / 2);
	printf("<-AA->");
	SetCurrentCursorPos(CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW * 2 - CHARACTERBOX_ROW / 2 - 5, CHARACTERBOX_ORIGIN_Y + CHARACTERBOX_COLUMN + 2);
	printf("Health : 5   Speed : 2");

	//Character Box Number 3
	CreateSelectionBox(CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW * 2 + 10, CHARACTERBOX_ORIGIN_Y);
	SetCurrentCursorPos(CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW * 3 - CHARACTERBOX_ROW / 2 + 8, CHARACTERBOX_ORIGIN_Y + CHARACTERBOX_COLUMN / 2);
	printf("<-[]->");
	SetCurrentCursorPos(CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW * 3 - CHARACTERBOX_ROW / 2, CHARACTERBOX_ORIGIN_Y + CHARACTERBOX_COLUMN + 2);
	printf("Health : 3   Speed : 3");
}

//ĳ���� �ڽ� ����� �Լ�
void HideCharacterBox() {
	COORD ptr = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', CONSOLE_ROW * CONSOLE_COLUMN, ptr, &dw);
}

//ĳ���� ���� ȭ�� ��� �Լ�
void ShowCharacterSelectionMenu() {

	//ĳ���� ���� â ����
	ShowCharacterBox();

	//���콺 Ŭ���� ���� ���� ��� ���� ������ ��� ����
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	int xx, yy;
	while (1) {
		CharacterBoxClick(&xx, &yy);
		if (yy >= CHARACTERBOX_ORIGIN_Y && yy <= CHARACTERBOX_ORIGIN_Y + CHARACTERBOX_COLUMN) {
			if (xx >= CHARACTERBOX_ORIGIN_X && xx <= CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW) {
				SelectedLife = 7; SelectedSpeed = CurSpeed = 1.0; memcpy(PlayerModel, "<OAAO>", sizeof(char) * 6); break;
			}
			else if (xx >= CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW + 5 && xx <= CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW * 2 + 5) {
				SelectedLife = 5; SelectedSpeed = CurSpeed = 1.5; memcpy(PlayerModel, "<-AA->", sizeof(char) * 6); break;
			}
			else if (xx >= CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW * 2 + 10 && xx <= CHARACTERBOX_ORIGIN_X + CHARACTERBOX_ROW * 3 + 10) {
				SelectedLife = 3; SelectedSpeed = CurSpeed = 2.0; memcpy(PlayerModel, "<-[]->", sizeof(char) * 6); break;
			}
		}
	}
	
	//ĳ���� ���� â �����
	HideCharacterBox();
}

#endif // !CHARACTERSELECTIONMENU_H