#include "communicate.h"
// ����ļ������û���Ϊ����

void changeDirection()
{
	if (_kbhit()) {//������¼���
		char userType = _getch(); //��ȡ�û�����
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
			}// ������������²Ų���
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
