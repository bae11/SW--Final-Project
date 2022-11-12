#pragma once
#pragma warning(disable:4996)
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include "VariableSets.h"
#ifndef TIMER_H
#define TIMER_H

//���� ����
void TimeCheckerStart() {
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
}

//���� �� (���� double�� ��ȯ)
double TimeCheckerEnd() {
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	return ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);
}

// ������ �����ϰ���� ���� �ð��� �� �� ���� int�� �� �� �ֽ��ϴ�.
int TimeCheckerForInt() {
	return ((int)(TimeCheckerEnd()));
}
#endif // !TIMER_H