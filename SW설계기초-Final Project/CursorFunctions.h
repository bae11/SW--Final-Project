#pragma once
#include <stdio.h>
#include <Windows.h>
#ifndef CURSORFUNCTIONS_H
#define CURSORFUNCTIONS_H

//Ŀ�� ��ġ ����
void SetCurrentCursorPos(int x, int y) {
	COORD ptr = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ptr);
}

//Ŀ�� ��ġ ��ȯ
COORD GetCurrentCursorPos() {
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint = curInfo.dwCursorPosition;
	return curPoint;
}

//�ð������� ǥ���Ǵ� Ŀ�� �����
void RemoveCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
#endif // !CURSORFUNCTION_H