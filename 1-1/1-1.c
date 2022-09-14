#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int main() {

	int matrixA[3][3], matrixB[3][3], matrixR[3][3];
	int alt3A[3][3], alt3B[3][3], alt4A[4][4], alt4B[4][4];
	int resA, resB;
	resA = 0;
	resB = 0;
	
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			matrixA[x][y] = rand() % 3;
			matrixB[x][y] = rand() % 3;
		}
	}

	for (int y = 0; y < 3; y++) {
		printf("|");
		for (int x = 0; x < 3; x++) {
			printf(" %d",matrixA[x][y]);
		}
		printf("|   |");
		for (int x = 0; x < 3; x++) {
			printf(" %d", matrixB[x][y]);
		}
		printf("|\n");
	}

	bool isrun = true;
	char input;
	bool isdefcal = true;//true는 기본 계산, false는 행렬식
	int type = 0;//0은 기본 1은 더하기 2는 빼기 3은 곱하기 
	bool hasresult = false;
	bool alttype = false; // true일때 0은 행렬식, 1은 전치행렬, 2는 4x4
	while (isrun)
	{
		resA = 0;
		resB = 0;
		input = getch();
		switch (input) {
		case 'm'://곱하기
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					matrixR[x][y] = 0;
					for (int a = 0; a < 3; a++) {
						matrixR[x][y] += matrixA[a][y] * matrixB[x][a];
					}
				}
			}
			type = 3;
			hasresult = true;
			alttype = false;
			break;
		case 'a'://더하기
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					matrixR[x][y] = matrixA[x][y] + matrixB[x][y];
				}
			}
			type = 1;
			hasresult = true;
			alttype = false;
			break;
		case 'd'://빼기
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					matrixR[x][y] = matrixA[x][y] - matrixB[x][y];
				}
			}
			type = 2;
			hasresult = true;
			alttype = false;
			break;
		case 'r'://행렬식의 값
			type = 0;
			hasresult = false;
			alttype = true;
			resA = (matrixA[0][0] * matrixA[1][1] * matrixA[2][2] +
				matrixA[0][1] * matrixA[1][2] * matrixA[2][0] +
				matrixA[0][2] * matrixA[1][0] * matrixA[2][1]) -
				(matrixA[0][0] * matrixA[1][2] * matrixA[2][1] +
					matrixA[0][1] * matrixA[1][0] * matrixA[2][2] +
					matrixA[0][2] * matrixA[1][1] * matrixA[2][0]);

			resB = (matrixB[0][0] * matrixB[1][1] * matrixB[2][2] +
				matrixB[0][1] * matrixB[1][2] * matrixB[2][0] +
				matrixB[0][2] * matrixB[1][0] * matrixB[2][1]) -
				(matrixB[0][0] * matrixB[1][2] * matrixB[2][1] +
					matrixB[0][1] * matrixB[1][0] * matrixB[2][2] +
					matrixB[0][2] * matrixB[1][1] * matrixB[2][0]);
			break;
		case 't'://전치 행렬 하고 행렬식
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					alt3A[x][y] = matrixA[y][x];
				}
			}
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					alt3B[x][y] = matrixB[y][x];
				}
			}
			resA = (alt3A[0][0] * alt3A[1][1] * alt3A[2][2] +
				alt3A[0][1] * alt3A[1][2] * alt3A[2][0] +
				alt3A[0][2] * alt3A[1][0] * alt3A[2][1]) -
				(alt3A[0][0] * alt3A[1][2] * alt3A[2][1] +
					alt3A[0][1] * alt3A[1][0] * alt3A[2][2] +
					alt3A[0][2] * alt3A[1][1] * alt3A[2][0]);

			resB = (alt3B[0][0] * alt3B[1][1] * alt3B[2][2] +
				alt3B[0][1] * alt3B[1][2] * alt3B[2][0] +
				alt3B[0][2] * alt3B[1][0] * alt3B[2][1]) -
				(alt3B[0][0] * alt3B[1][2] * alt3B[2][1] +
					alt3B[0][1] * alt3B[1][0] * alt3B[2][2] +
					alt3B[0][2] * alt3B[1][1] * alt3B[2][0]);
			type = 1;
			hasresult = false;
			alttype = true;
			break;
		case 'h'://3x3 to 4x4 하고 행렬식
			for (int x = 0; x < 4; x++) {
				for (int y = 0; y < 4; y++) {
					if (x == 3 && y == 3) alt4A[x][y] = 1;
					else if (y == 3)alt4A[x][y] = 0;
					else if (x == 3)alt4A[x][y] = 0;
					else alt4A[x][y] = matrixA[x][y];
				}
			}
			for (int x = 0; x < 4; x++) {
				for (int y = 0; y < 4; y++) {
					if (x == 3 && y == 3) alt4B[x][y] = 1;
					else if (y == 3)alt4B[x][y] = 0;
					else if (x == 3)alt4B[x][y] = 0;
					else alt4B[x][y] = matrixB[x][y];
				}
			}

			resA = (alt4A[0][0] * ((alt4A[1][1] * alt4A[2][2] * alt4A[3][3] +
				alt4A[1][2] * alt4A[2][3] * alt4A[3][1] +
				alt4A[1][3] * alt4A[2][1] * alt4A[3][2]) -
				(alt4A[1][1] * alt4A[2][3] * alt4A[3][2] +
					alt4A[1][2] * alt4A[2][1] * alt4A[3][3] +
					alt4A[1][3] * alt4A[2][2] * alt4A[3][1])))
				- (alt4A[1][0] * ((alt4A[0][1] * alt4A[2][2] * alt4A[3][3] +
					alt4A[0][2] * alt4A[2][3] * alt4A[3][1] +
					alt4A[0][3] * alt4A[2][1] * alt4A[3][2]) -
					(alt4A[0][1] * alt4A[2][3] * alt4A[3][2] +
						alt4A[0][2] * alt4A[2][1] * alt4A[3][3] +
						alt4A[0][3] * alt4A[2][2] * alt4A[3][1])))
				+ (alt4A[2][0] * ((alt4A[0][1] * alt4A[1][2] * alt4A[3][3] +
					alt4A[0][2] * alt4A[1][3] * alt4A[3][1] +
					alt4A[0][3] * alt4A[1][1] * alt4A[3][2]) -
					(alt4A[0][1] * alt4A[1][3] * alt4A[3][2] +
						alt4A[0][2] * alt4A[1][1] * alt4A[3][3] +
						alt4A[0][3] * alt4A[1][2] * alt4A[3][1])))
				- (alt4A[3][0] * ((alt4A[0][1] * alt4A[1][2] * alt4A[2][3] +
					alt4A[0][2] * alt4A[1][3] * alt4A[2][1] +
					alt4A[0][3] * alt4A[1][1] * alt4A[2][2]) -
					(alt4A[0][1] * alt4A[1][3] * alt4A[2][2] +
						alt4A[0][2] * alt4A[1][1] * alt4A[2][3] +
						alt4A[0][3] * alt4A[1][2] * alt4A[2][1])));

			resB = (alt4B[0][0] * ((alt4B[1][1] * alt4B[2][2] * alt4B[3][3] +
				alt4B[1][2] * alt4B[2][3] * alt4B[3][1] +
				alt4B[1][3] * alt4B[2][1] * alt4B[3][2]) -
				(alt4B[1][1] * alt4B[2][3] * alt4B[3][2] +
					alt4B[1][2] * alt4B[2][1] * alt4B[3][3] +
					alt4B[1][3] * alt4B[2][2] * alt4B[3][1])))
				- (alt4B[1][0] * ((alt4B[0][1] * alt4B[2][2] * alt4B[3][3] +
					alt4B[0][2] * alt4B[2][3] * alt4B[3][1] +
					alt4B[0][3] * alt4B[2][1] * alt4B[3][2]) -
					(alt4B[0][1] * alt4B[2][3] * alt4B[3][2] +
						alt4B[0][2] * alt4B[2][1] * alt4B[3][3] +
						alt4B[0][3] * alt4B[2][2] * alt4B[3][1])))
				+ (alt4B[2][0] * ((alt4B[0][1] * alt4B[1][2] * alt4B[3][3] +
					alt4B[0][2] * alt4B[1][3] * alt4B[3][1] +
					alt4B[0][3] * alt4B[1][1] * alt4B[3][2]) -
					(alt4B[0][1] * alt4B[1][3] * alt4B[3][2] +
						alt4B[0][2] * alt4B[1][1] * alt4B[3][3] +
						alt4B[0][3] * alt4B[1][2] * alt4B[3][1])))
				- (alt4B[3][0] * ((alt4B[0][1] * alt4B[1][2] * alt4B[2][3] +
					alt4B[0][2] * alt4B[1][3] * alt4B[2][1] +
					alt4B[0][3] * alt4B[1][1] * alt4B[2][2]) -
					(alt4B[0][1] * alt4B[1][3] * alt4B[2][2] +
						alt4B[0][2] * alt4B[1][1] * alt4B[2][3] +
						alt4B[0][3] * alt4B[1][2] * alt4B[2][1])));

			type = 2;
			hasresult = false;
			alttype = true;
			break;
		case 's'://행렬 리셋
			type = 0;
			hasresult = false;
			alttype = false;
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					matrixA[x][y] = rand() % 3;
					matrixB[x][y] = rand() % 3;
				}
			}
			break;
		case 'q'://나가기
			isrun = false;
			break;
		default:
			break;
		}
		system("cls");
		if (alttype) {
			if (type == 2) {
				for (int y = 0; y < 4; y++) {
					printf("|");
					for (int x = 0; x < 4; x++) {
						printf(" %2d", alt4A[x][y]);;
					}
					if (y == 1) {
						printf("|  = %2d  |", resA);
					}
					else
						printf("|        |");
					for (int x = 0; x < 4; x++) {
						printf(" %2d", alt4B[x][y]);
					}
					if (y == 1) {
						printf("|  = %2d\n", resB);
					}
					else
						printf("|\n");
				}
			}
			else {
				for (int y = 0; y < 3; y++) {
					printf("|");
					for (int x = 0; x < 3; x++) {
						if (type == 1)printf(" %2d", alt3A[x][y]);
						else printf(" %2d", matrixA[x][y]);
					}
					if (y == 1) {
						printf("|  = %2d  |", resA);
					}
					else
						printf("|        |");
					for (int x = 0; x < 3; x++) {
						if (type == 1)printf(" %2d", alt3B[x][y]);
						else printf(" %2d", matrixB[x][y]);
					}
					if (y == 1) {
						printf("|  = %2d\n", resB);
					}
					else
						printf("|\n");
				}
			}
		}
		else {
			for (int y = 0; y < 3; y++) {
				printf("|");
				for (int x = 0; x < 3; x++) {
					printf(" %2d", matrixA[x][y]);
				}
				if (y == 1) {
					if (type == 1)printf("| + |");
					else if (type == 2)printf("| - |");
					else if (type == 3)printf("| * |");
					else
						printf("|   |");
				}
				else
					printf("|   |");
				for (int x = 0; x < 3; x++) {
					printf(" %2d", matrixB[x][y]);
				}
				if (hasresult) {
					if (y == 1) printf("| = |");
					else printf("|   |");
					for (int x = 0; x < 3; x++) {
						printf(" %2d", matrixR[x][y]);
					}
					printf("|\n");
				}
				else
					printf("|\n");
			}
		}
		
	}
	
}