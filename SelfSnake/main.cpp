#include "game.h"//��Ϸ����
#include <stdio.h>
#include "communicate.h"//��������
int main() {
	initWindow(); //��ʼ����Ϸ����
	initSnake(); //��ʼ��������
	initFood(); //��ʼ��ʳ��
	while (1) {
		BeginBatchDraw();//��ʼ������������ҪΪ�˽����˸����
		cleardevice(); //�������
		eatFood();//�ж�ʳ���Ƿ񱻳�
		changeDirection(); //�ж��Ƿ񽻻����Ƿ����
		moveSnake(); //�ƶ���
		drawSnake(); //����
		drawFood(); //��ʳ��
		overSnake(); //���������ж�
		EndBatchDraw();
	}
	getchar(); // stdio.h �������������������˳������������
	closegraph(); //�رջ�ͼ���壨����
	return 0;
}