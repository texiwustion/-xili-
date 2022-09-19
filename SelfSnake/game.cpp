#include "game.h"
#include<time.h>
SNAKE snake;
FOOD food; // ʵ�����ߺ�ʳ��


struct point blockPoint(int length, int width) {
	struct point pointExample;
	pointExample.x = length * BLOCK;
	pointExample.y = width * BLOCK;
	return pointExample;
}  // ���㶨λ������һ�����

void draw(COLORREF fillcolor,int x1,int y1,int x2, int y2) {
	setlinecolor(LINECOLOR);
	setfillcolor(fillcolor);
	fillrectangle(x1,y1,x2,y2);
}

void initWindow()
{
	initgraph(LENGTH, WIDTH); //��ʼ�����ڣ� ��LENGTH ��WIDTH
	setbkcolor(WHITE); //�趨������ɫ
	cleardevice(); //ˢ�£�ʹ������ɫ�趨��Ч
}

void initSnake() {
	snake.position[2] = { 0 };
	snake.position[1] = blockPoint(1, 0);
	snake.position[0] = blockPoint(2, 0); //��ÿһ�ڵ�λ��
	snake.direction = RIGHT;
	snake.len = 3;
}

void drawSnake() {
	for (int i = 0; i < snake.len; i++)
		draw(GREEN, snake.position[i].x, snake.position[i].y, snake.position[i].x + BLOCK, snake.position[i].y + BLOCK);
		//draw(GREEN, 0,0,20,20);
}

void initFood() {
	srand((unsigned)time(NULL)); //��ȡ�������
	food.foodPosition = blockPoint(rand() % (LENGTH/BLOCK), rand() % (WIDTH/BLOCK)); //��ȡʳ������
}

void drawFood() {
	draw(RED, food.foodPosition.x, food.foodPosition.y, food.foodPosition.x + BLOCK, food.foodPosition.y + BLOCK);//��ʳ��
}

void moveSnake() {
	for (int i = snake.len - 1; i > 0; i--)
		snake.position[i] = snake.position[i - 1]; //�ǵ�һ�ڣ���һ�ڵ�λ�ñ��ǰһ��
	//�Ե�һ�ڣ�
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
	Sleep(200); //�����ߵ��ƶ��ٶ�
}

void eatFood() {
	if (snake.position[0].x == food.foodPosition.x && snake.position[0].y == food.foodPosition.y) {
		initFood();
		snake.len++;
	} //��ͷ��ʳ���ص������³�ʼ��ʳ��ӳ�����
}

void overSnake() {
	if (snake.position[0].x > LENGTH || snake.position[0].y > WIDTH || snake.position[0].x < 0 || snake.position[0].y < 0)
		exit(1); //ײǽ�˳�
	for (int i = 1; i < snake.len; i++)
		if (snake.position[i].x == snake.position[0].x && snake.position[i].y == snake.position[0].y)
			exit(1);//ײ�Լ��˳�
}