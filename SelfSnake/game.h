
//standard headfile :   only pragma once, use #ifndef , #define , #endif
#include<graphics.h>

#ifndef _GAME_H
#define _GAME_H

#define BLOCK 20 //һ���鳤��
#define LENGTH 32*BLOCK
#define WIDTH 24*BLOCK //���ڳ���
#define maxNode 100 //��������
#define LINECOLOR BLACK //�߿�����ɫ

struct point {
	int x;
	int y;
};
struct SNAKE {
	point position[maxNode]; //ÿ�ڵ�λ��
	int len; //�߳���
	int direction; //�߷���
};
struct FOOD {
	point foodPosition;
};

enum DIRECTION {LEFT = 75, UP = 72 , RIGHT = 77, DOWN = 80}; //ö���ĸ�����

struct point blockPoint(int length, int width); // ����  ��㺯�������㶨λ������һ�����
void draw(COLORREF fillcolor, int x1, int y1, int x2, int y2); // ����  ��������, COLORREF�����ն���
void initWindow(); //��ʼ����Ϸ����
void initSnake(); //��ʼ��һ���ߣ����������в���
void drawSnake(); //���߻�����
void moveSnake(); //�����˶�
void overSnake(); //������
void initFood(); // ����ʳ�����в���
void drawFood(); // ��ʳ��
void eatFood(); //��ʳ��

#endif