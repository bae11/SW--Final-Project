#pragma once
#include <stdio.h>
#include <Windows.h>
#ifndef RESIZECONSOLE_H
#define RESIZECONSOLE_H

//�ܼ� â ROW ����
#define CONSOLE_ROW 45

//�ܼ� â COLUMN ����
#define CONSOLE_COLUMN 108

//�ܼ� â ũ�� ���� �Լ�
void ResizeConsole() { system("mode con cols=108 lines=45 | title Astronauts"); }

//�ܼ� â ���� ũ�� ���� �Լ�
void ResizeConsoleBuffer() {
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	COORD new_size = { curInfo.srWindow.Right - curInfo.srWindow.Left + 1, curInfo.srWindow.Bottom - curInfo.srWindow.Top + 1 };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), new_size);
}
#endif // !RESIZECONSOLE_H