#include "communicate.h"
// 这个文件用来用户行为交互

void changeDirection()
{
	if (_kbhit()) {//如果按下键盘
		char userType = _getch(); //获取用户键入
		switch (userType) {
			if (snake.direction == UP || snake.direction == DOWN) {
		case RIGHT:
		case 'd':
			snake.direction = RIGHT;
			break;
		case LEFT:
		case 'a':
			snake.direction = LEFT;
			break;
			}// 如果方向是上下才捕获
			else {
		case UP:
		case 'w':
			snake.direction = UP;
			break;
		case DOWN:
		case 's':
			snake.direction = DOWN;
			break;
			}
		default:
			break;
		}
	}
}
