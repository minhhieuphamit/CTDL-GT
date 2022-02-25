#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#define N 6
#define false 0
#define true !false

/* Ham kiem tra xem vi tri x,y co hop le khong */
int isSafe(int x, int y, int sol[N][N])
{
    if (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
        return 1;
    return 0;
}

/* Ham in ket qua */
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

/* Ham de qui quay lui giai bai toan ma tuan */
int BackTrack(int x, int y, int k, int sol[N][N], int xMove[N], int yMove[N])
{
    int i, next_x, next_y;
    if (k == N * N)
        return true;
    /* Thu tat ca 8 UCV tu vi tri hien tai x, y */
    for (i = 0; i < 8; i++)
    {
        next_x = x + xMove[i];
        next_y = y + yMove[i];
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = k + 1;
            if (BackTrack(next_x, next_y, k + 1, sol, xMove, yMove) == true)
                return true;
            else
                sol[next_x][next_y] = -1; // Quay lui
        }
    }
    return false;
}

/* Ham chinh giai bai toan ma tuan */
int solveKT(int sx, int sy)
{
    int sol[N][N], x, y;
    /* Khoi tao ma tran loi giai */
    for (x = 0; x < N; x++)
        for (y = 0; y < N; y++)
            sol[x][y] = -1;
    /* Co 8 buoc chuyen cua quan ma xung quanh vi tri hien tai
    xMove[] cho gia tri hang buoc chuyen tiep
    yMove[] cho gia tri cot buoc chuyen tiep */
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    // Khoi tao gia tri cho vi tri ban dau
    sol[sx][sy] = 1;
    /* Bat dau tu toa do sx,sy */
    if (BackTrack(sx, sy, 1, sol, xMove, yMove) == false)
    {
        printf("Khong ton tai loi giai");
        return false;
    }
    else
        printSolution(sol);
    return true;
}

// Tạo menu
void printMenu(int &choice)
{
    printf("\n1. Nhap toa do cho quan Ma.");
    printf("\n2. Ket qua chay chuong trinh.");
    printf("\n3. Thong tin sinh vien thuc hien.");
    printf("\n0. Thoat chuong trinh");
    printf("\nPress 0-3 to solve the question: ");
    scanf("%d", &choice);
}

int main()
{
    int sx, sy;
    system("cls");
    int choice;
    do
    {
        system("cls");
        printMenu(choice);
        switch (choice)
        {
        case 1:
            printf("\nCho biet vi tri khoi dau : \n");
            printf("Hang = ");
            scanf("%d", &sx);
            printf("Cot = ");
            scanf("%d", &sy);
            printf("\nNhan phim Enter de tiep tuc chuong trinh.");
            getch();
            break;
        case 2:
            printf("\nToa do ban vua nhap cho quan ma la (%d,%d)", sx, sy);
            printf("\nKet qua chay chuong trinh:\n");
            solveKT(sx - 1, sy - 1);
            printf("\nNhan phim Enter de tiep tuc chuong trinh.");
            getch();
            break;
        case 3:
            printf("\nThong tin sinh vien thuc hien: ");
            printf("\nPham Minh Hieu-2011063873-20DTHB4");
            printf("\nPhan Thanh Tung-2011062425-20DTHB4");
            printf("\n\nNhan phim Enter de tiep tuc chuong trinh.");
            getch();
            break;
        default:
            choice = 0;
            break;
        }
    } while (choice != 0);
    return 0;
}