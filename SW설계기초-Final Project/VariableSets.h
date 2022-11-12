#pragma once
#include <Windows.h>
#ifndef VARIABLESETS_H
#define VARIABLESETS_H
//-------------------------------------------
//-------------BackGround ���------------

//���ӿ��� ����
#define BACKGROUND_ROW 90
#define BACKGROUND_COLUMN 43
#define BACKGROUND_ORIGIN_X 8
#define BACKGROUND_ORIGIN_Y 1
#define GAMEBOARD_ROW 90
#define GAMEBOARD_COLUMN 40
#define GAMEBOARD_ORIGIN_X 8
#define GAMEBOARD_ORIGIN_Y 4

//����ȭ���� �̻� ��
int UniBoard[GAMEBOARD_COLUMN + 1][GAMEBOARD_ROW + 2];

//���� ��Ʈ�� ����
char IntroModel[][5][5] = {
	{{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1}},
	{{0,1,1,1,1},{1,0,0,0,0},{0,1,1,1,0},{0,0,0,0,1},{1,1,1,1,0}},
	{{1,1,1,1,1},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0}},
	{{1,1,1,1,0},{1,0,0,0,1},{1,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1}},
	{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}},
	{{1,0,0,0,1},{1,1,0,0,1},{1,0,1,0,1},{1,0,0,1,1},{1,0,0,0,1}},
	{{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1}},
	{{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}},
	{{1,1,1,1,1},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0}}
};

//--------------------------------------------
//--------------StartMenu ���-------------

#define MODESELECTIONBOX_ROW 18 //���� ��� ���ùڽ� ���� ����
#define MODESELECTIONBOX_COLUMN 3 // ���� ��� ���ùڽ� ���� ����
int ModeSelectionBox_Origin_X = BACKGROUND_ORIGIN_X + 14; //���� ��� ���� �ڽ� �ʱ� X��ǥ
int ModeSelectionBox_Origin_Y = BACKGROUND_ORIGIN_Y + BACKGROUND_COLUMN / 2 + 6; //���� ��� ���� �ڽ� �ʱ� Y��ǥ

//���� ���
int GameMode = 0;

//-----------------------------------------------------------
//-------------CharacterSelectionMenu ���--------------

//ĳ���� �ڽ� Dimension
#define CHARACTERBOX_ROW 28
#define CHARACTERBOX_COLUMN 20
#define CHARACTERBOX_ORIGIN_X 6
#define CHARACTERBOX_ORIGIN_Y 12

//-------------------------------------------
//------------StageMenu ���-------------

//�������� ��ȣ
int StageNumber = 1;

//���������� �÷��� �ð�
int StageTime[] = { 60,90,120 };

//���� ���������� �Ѿ �� Duration time
#define STAGEDURATIONTIME 2.0

//-------------------------------------------------------------
//-----------------------Player ���--------------------------

//����� �Է� Ű �ƽ�Ű �ڵ�
#define LEFT VK_LEFT
#define RIGHT VK_RIGHT
#define UP VK_UP
#define DOWN VK_DOWN
#define SPACE 0x20
#define QUIT 0x1A

//�÷��̾� ���� ��ȣ �� ����, ������ �� ����
#define PLAYER 4
#define PLAYERCOLOR 3
#define PLAYERUSINGSKILLCOLOR 13
#define PLAYERINVINSIBLEINDICATECOLOR 6

//�÷��̾� ��ǲŸ�� ���۽ð�
double PLAYERTIMEBUFFER = 0.035;

//�÷��̾� ��ǲŸ�� ���۽ð�
double PlayerInputTime = 0;

//�÷��̾� ���� ��ġ
int PLAYER_POS_X = GAMEBOARD_ORIGIN_X + GAMEBOARD_ROW / 2 - 3;
int PLAYER_POS_Y = GAMEBOARD_ORIGIN_Y + GAMEBOARD_COLUMN - 8;

//�÷��̾� ���ּ�
char PlayerModel[6];
char PlayerUniModel[6] = { PLAYER,PLAYER,PLAYER,PLAYER,PLAYER,PLAYER };

//�÷��̾� �������� �� �������� ���ӽð�, �Ѿ� �� �� ���ּ��� �浹�� �ð�
#define InvinsibleTime 1
int Invinsible = 0; double CollisionTime = 0;

//�÷��̾��� ������������
int SelectedLife = 5; int CurrentLife; int *LifeGauge;

//�÷��̾��� ��ġ
int PlayerPos = 0;

//�÷��̾��� �ӵ�
double SelectedSpeed, CurSpeed;

//---------------------------------------------------------------
//----------------------Enemy ���----------------------------

//�� NPC ��ǲŸ�� ���� �ð�
double ENEMYTIMEBUFFER = 0.02;

//�� NPC ��ǲŸ�� ���۽ð�
double EnemyInputTime = 0;

//�� ���ּ� �� �Ѿ�
#define ENEMY 2
#define ENEMYDAMAGE 2
#define ENEMYBULLET 3

//�� ���ּ� ��ġ �� �̵�����
int ENEMY_POS_X = GAMEBOARD_ORIGIN_X + GAMEBOARD_ROW / 2 - 3;
int ENEMY_POS_Y = GAMEBOARD_ORIGIN_Y + 1;
int direction = 0;

//�� ���ּ� �𵨸�
char EnemyModel[3][5] = { {' ','^','V','^',' '},{'<','<','O','>','>'},{' ','^','V','^',' '} };
char EnemyUniModel[3][5] = { {0,ENEMY,ENEMY,ENEMY,0},{ENEMY,ENEMY,ENEMY,ENEMY,ENEMY},{0,ENEMY,ENEMY,ENEMY,0} };

//-------------------------------------------------------------------
//-------------------------Timer ���------------------------------

//Timer �Լ� �̿�� �ʿ��� ���
LARGE_INTEGER ticksPerSec;
LARGE_INTEGER start, end, diff;

//�� ������ ����
double CurrentTime = 1;

//-------------------------------------------------------------------
//------------------------UI ���-----------------------------------

//Modified �Լ�
int Strlen(const char *src) {
	int cnt = 0;
	for (const char *p = src; *p != '-'; p++) cnt++;
	return cnt + 1;
}

//���� ����
#define MAPLENGTH 15

//--------------------------------------------------------------------
//-----------------------ITEM ���----------------------------------

//������ ������ ���� �ð�
#define ITEMTIMEBUFFER 0.2
double ItemInputTime = 0;
double ItemCreationLoop = 1;

//������ ȿ�� ������
#define SPEEDINCREASERATE 0.5
#define FLASHDISTANCE 3
int BulletSpeed = 2;

//���Ӻ��峻 ������ ��� ����
int itemFLAG = 0;

// ���� Ȯ�� �� ����
int flashFLAG = 0;

//������ X, Y ��ǥ
int ITEM_POS_X, ITEM_POS_Y;

//�����۰� �÷��̾� �浹 ���� ����
int ItemCollisionDetected = 0;

int ItemNumber = 0;

//�÷��̾��� �� ��ų, ���� ��ų, ��� ���� ��ų
int CurSkill = 4, SubSkill = 4, UsingSkill = 0;

//��ų ���ӽð�, ��ų �ߵ� ���۽ð�
int SkillTime = 3; double SkillActivationTime = 0;

//�÷��̾��� ��ų �� string
char Skillstr[] = { "MainSkill " }; char SubSkillstr[] = { "SubSkill  " };
char SkillSets[][101] = { "-NONE-", "-SPEEDUP-","-SLOW-", "-INVINSIBLE-","-DASH-","-ERASEBULLET-" };

//������ ��� ������ ����Ʈ
int itemList[] = { 1, 2, 3, 4, 5 };

// ������ ��� ���� ���� ����
int CheckFLAG = 0;

//--------------------------------------------------------------------
//-----------------------EFFECT ���----------------------------------

//EFFECT ������ ���� �ð�
#define EFFECTTIMEBUFFER 0.05
double EffectInputTime = 0;
double EffectCreationLoop = 1;

//EFFECT X, Y ��ǥ
int EFFECT_POS_X, EFFECT_POS_Y;

// EFFECT üũ�� ����
int EffectCheck = 0;

#endif // !VARIABLESETS_H
