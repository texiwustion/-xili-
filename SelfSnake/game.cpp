#include "game.h"
#include<time.h>
SNAKE snake;
FOOD food; // 实例化蛇和食物


struct point blockPoint(int length, int width) {
	struct point pointExample;
	pointExample.x = length * BLOCK;
	pointExample.y = width * BLOCK;
	return pointExample;
}  // 方便定位，返回一个格点

void draw(COLORREF fillcolor,int x1,int y1,int x2, int y2) {
	setlinecolor(LINECOLOR);
	setfillcolor(fillcolor);
	fillrectangle(x1,y1,x2,y2);
}

void initWindow()
{
	initgraph(LENGTH, WIDTH); //初始化窗口， 长LENGTH 宽WIDTH
	setbkcolor(WHITE); //设定背景颜色
	cleardevice(); //刷新，使背景颜色设定生效
}

void initSnake() {
	snake.position[2] = { 0 };
	snake.position[1] = blockPoint(1, 0);
	snake.position[0] = blockPoint(2, 0); //蛇每一节的位置
	snake.direction = RIGHT;
	snake.len = 3;
}

void drawSnake() {
	for (int i = 0; i < snake.len; i++)
		draw(GREEN, snake.position[i].x, snake.position[i].y, snake.position[i].x + BLOCK, snake.position[i].y + BLOCK);
		//draw(GREEN, 0,0,20,20);
}

void initFood() {
	srand((unsigned)time(NULL)); //获取随机种子
	food.foodPosition = blockPoint(rand() % (LENGTH/BLOCK), rand() % (WIDTH/BLOCK)); //获取食物坐标
}

void drawFood() {
	draw(RED, food.foodPosition.x, food.foodPosition.y, food.foodPosition.x + BLOCK, food.foodPosition.y + BLOCK);//画食物
}

void moveSnake() {
	for (int i = snake.len - 1; i > 0; i--)
		snake.position[i] = snake.position[i - 1]; //非第一节：后一节的位置变成前一节
	//对第一节：
	switch (snake.direction) {
	case	 RIGHT:
		snake.position[0].x += BLOCK;
		break;
	case LEFT:
		snake.position[0].x -= BLOCK;
		break;
	case UP:
		snake.position[0].y -= BLOCK;
		break;
	case DOWN:
		snake.position[0].y += BLOCK;
		break;
	default:
		break;
	}
	Sleep(200); //控制蛇的移动速度
}

void eatFood() {
	if (snake.position[0].x == food.foodPosition.x && snake.position[0].y == food.foodPosition.y) {
		initFood();
		snake.len++;
	} //蛇头与食物重叠，重新初始化食物；加长蛇身
}

void overSnake() {
	if (snake.position[0].x > LENGTH || snake.position[0].y > WIDTH || snake.position[0].x < 0 || snake.position[0].y < 0)
		exit(1); //撞墙退出
	for (int i = 1; i < snake.len; i++)
		if (snake.position[i].x == snake.position[0].x && snake.position[i].y == snake.position[0].y)
			exit(1);//撞自己退出
}