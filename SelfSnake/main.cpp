#include "game.h"//游戏功能
#include <stdio.h>
#include "communicate.h"//交互功能
int main() {
	initWindow(); //初始化游戏窗口
	initSnake(); //初始化这条蛇
	initFood(); //初始化食物
	while (1) {
		BeginBatchDraw();//开始批量作画，主要为了解决闪烁问题
		cleardevice(); //清除缓存
		eatFood();//判断食物是否被吃
		changeDirection(); //判断是否交互，是否变向
		moveSnake(); //移动蛇
		drawSnake(); //画蛇
		drawFood(); //画食物
		overSnake(); //蛇凉凉的判定
		EndBatchDraw();
	}
	getchar(); // stdio.h 窗口滞留，不会立即退出，增加体验感
	closegraph(); //关闭绘图缓冲（？）
	return 0;
}