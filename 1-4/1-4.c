#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int main() {

	int rect1_x1, rect1_x2, rect1_y1, rect1_y2;
	int rect2_x1, rect2_x2, rect2_y1, rect2_y2;

	rect1_x1 = rand() % 801;
	rect1_x2 = rand() % 801;
	rect2_x1 = rand() % 801;
	rect2_x2 = rand() % 801;

	rect1_y1 = rand() % 601;
	rect1_y2 = rand() % 601;
	rect2_y1 = rand() % 601;
	rect2_y2 = rand() % 601;

	char input;
	bool turn = true;
	bool border;
	bool iscollide = false;
	printf("RECT1 : (%3d, %3d) (%3d, %3d)\n", rect1_x1, rect1_y1, rect1_x2, rect1_y2);
	printf("RECT2 : (%3d, %3d) (%3d, %3d)\n", rect2_x1, rect2_y1, rect2_x2, rect2_y2);
	while (true)
	{
		border = false;
		input = getch();
		switch (input)
		{
		case 'w':
			if (turn) {
				rect1_y1 += 10;
				rect1_y2 += 10;

				if (rect1_y1 > 600 || rect1_y2 > 600) {
					rect1_y1 -= 10;
					rect1_y2 -= 10;
					border = true;
				}
				turn = false;
			}
			else {
				rect2_y1 += 10;
				rect2_y2 += 10;

				if (rect2_y1 > 600 || rect2_y2 > 600) {
					rect2_y1 -= 10;
					rect2_y2 -= 10;
					border = true;
				}
				turn = true;
			}
			break;
		case 'a':
			if (turn) {
				rect1_x1 -= 10;
				rect1_x2 -= 10;

				if (rect1_x1 < 0 || rect1_x2 < 0) {
					rect1_x1 += 10;
					rect1_x2 += 10;
					border = true;
				}
				turn = false;
			}
			else {
				rect2_x1 -= 10;
				rect2_x2 -= 10;

				if (rect2_x1 < 0 || rect2_x2 < 0) {
					rect2_x1 += 10;
					rect2_x2 += 10;
					border = true;
				}
				turn = true;
			}
			break;
		case 's':
			if (turn) {
				rect1_y1 -= 10;
				rect1_y2 -= 10;

				if (rect1_y1 < 0 || rect1_y2 < 0) {
					rect1_y1 += 10;
					rect1_y2 += 10;
					border = true;
				}
				turn = false;
			}
			else {
				rect2_y1 -= 10;
				rect2_y2 -= 10;

				if (rect2_y1 < 0 || rect2_y2 < 0) {
					rect2_y1 += 10;
					rect2_y2 += 10;
					border = true;
				}
				turn = true;
			}
			break;
		case 'd':
			if (turn) {
				rect1_x1 += 10;
				rect1_x2 += 10;

				if (rect1_x1 > 800 || rect1_x2 > 800) {
					rect1_x1 -= 10;
					rect1_x2 -= 10;
					border = true;
				}
				turn = false;
			}
			else {
				rect2_x1 += 10;
				rect2_x2 += 10;

				if (rect2_x1 > 800 || rect2_x2 > 800) {
					rect2_x1 -= 10;
					rect2_x2 -= 10;
					border = true;
				}
				turn = true;
			}
			break;
		default:
			break;
		}

		system("cls");
		printf("RECT1 : (%3d, %3d) (%3d, %3d)\n", rect1_x1, rect1_y1, rect1_x2, rect1_y2);
		printf("RECT2 : (%3d, %3d) (%3d, %3d)\n", rect2_x1, rect2_y1, rect2_x2, rect2_y2);

		if (border)
			printf("out of border!\n");

		if ((rect1_x1 >= rect2_x1 && rect1_x1 <= rect2_x2) ||
			(rect1_x1 <= rect2_x1 && rect1_x1 >= rect2_x2)) {
			if (((rect1_y1 >= rect2_y1 && rect1_y1 <= rect2_y2) ||
				(rect1_y1 <= rect2_y1 && rect1_y1 >= rect2_y2))
				|| ((rect1_y2 >= rect2_y1 && rect1_y2 <= rect2_y2) ||
					(rect1_y2 <= rect2_y1 && rect1_y2 >= rect2_y2)))
				iscollide = true;
		}
		else if ((rect1_x2 >= rect2_x1 && rect1_x2 <= rect2_x2) ||
			(rect1_x2 <= rect2_x1 && rect1_x2 >= rect2_x2)) {
			if (((rect1_y1 >= rect2_y1 && rect1_y1 <= rect2_y2) ||
				(rect1_y1 <= rect2_y1 && rect1_y1 >= rect2_y2))
				|| ((rect1_y2 >= rect2_y1 && rect1_y2 <= rect2_y2) ||
					(rect1_y2 <= rect2_y1 && rect1_y2 >= rect2_y2)))
				iscollide = true;
		}
		else iscollide = false;

		if (iscollide) printf("RECT1 & RECT2 has collide\n");
	}
}