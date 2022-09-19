
//standard headfile :   only pragma once, use #ifndef , #define , #endif
#include<graphics.h>

#ifndef _GAME_H
#define _GAME_H

#define BLOCK 20 //一个块长度
#define LENGTH 32*BLOCK
#define WIDTH 24*BLOCK //窗口长宽
#define maxNode 100 //蛇最大节数
#define LINECOLOR BLACK //边框线颜色

struct point {
	int x;
	int y;
};
struct SNAKE {
	point position[maxNode]; //每节的位置
	int len; //蛇长度
	int direction; //蛇方向
};
struct FOOD {
	point foodPosition;
};

enum DIRECTION {LEFT = 75, UP = 72 , RIGHT = 77, DOWN = 80}; //枚举四个方向

struct point blockPoint(int length, int width); // 自研  格点函数，方便定位，返回一个格点
void draw(COLORREF fillcolor, int x1, int y1, int x2, int y2); // 自研  画画函数, COLORREF，参照定义
void initWindow(); //初始化游戏窗口
void initSnake(); //初始化一条蛇，给定其所有参数
void drawSnake(); //将蛇画出来
void moveSnake(); //让蛇运动
void overSnake(); //蛇凉凉
void initFood(); // 给定食物所有参数
void drawFood(); // 画食物
void eatFood(); //吃食物

#endif