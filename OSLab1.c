#include <stdio.h>

void add(int m,int M1[m][m],int M2[m][m])
{
    int i,j;
    int M3[m][m];
    printf("The Sum is :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            M3[i][j]=M1[i][j]+M2[i][j];
            printf("%d ",M3[i][j]);
        }
        printf("\n");
    }
}

void sub(int m,int M1[m][m],int M2[m][m])
{
    int i,j;
    int M3[m][m];
    printf("The Difference is :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            M3[i][j]=M1[i][j]-M2[i][j];
            printf("%d ",M3[i][j]);
        }
        printf("\n");
    }
}

void multiply(int m,int M1[m][m],int M2[m][m])
{
    int M3[m][m];
    int i,j,k;

for ( i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            M3[i][j] = 0;
            for (int k = 0; k < m; k++) {
                M3[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",M3[i][j]);
        }
        printf("\n");
    }
    }


//void sumRC(int m,int M1[m+1][m+1]) {
    //int sumR, sumC,i,j;
    //int M3[m][m];
   // printf("Sum of rows:\n");
    //for (int i = 0; i < m; i++) {
       // sumR = 0;
       // for (int j = 0; j < m; j++) {
         //   sumR += M1[i][j];
       // }
       // M1[i][j+1]=sumR;
        //printf("Row %d: %d\n", i + 1, sumR);
    //}

    //printf("Sum of columns:\n");
    //for (int j = 0; j < m; j++) {
        //sumC = 0;
        //for (int i = 0; i < m; i++) {
        //    sumC += M1[i][j];
       // }
       // M1[i][j+1]=sumC;
        //printf("Column %d: %d\n", j + 1, sumC);

   //}
   // }

   void sumRC(int n, int mat1[n][n]) {
    int sumr, sumc,i,j;
    int mat3[n+1][n+2];


    for (i = 0; i < n; i++) {
        sumr = 0;
        for (j = 0; j < n; j++) {
            mat3[i][j] = mat1[i][j];
            sumr += mat1[i][j];
        }
        mat3[i][n] = sumr;
    }

    for (j = 0; j < n; j++) {
        sumc = 0;
        for (i = 0; i < n; i++) {
            sumc += mat1[i][j];
        }
        mat3[n][j] = sumc;
    }
    mat3[n][n]=0;
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < n+1; j++) {
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }
}

void SumD(int m,int M1[m][m]) {
    int SumP = 0, SumNP = 0,i;

    for (i = 0; i < m; i++) {
        SumP += M1[i][i];
        SumNP += M1[i][m - 1 - i];
    }

    printf("Sum of principal diagonal: %d\n", SumP);
    printf("Sum of non-principal diagonal: %d\n", SumNP);
}

void transposeM(int m,int M1[m][m]) {
    int i,j;
    printf("Transpose of the matrix:\n");
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < m; i++) {
            printf("%d\t", M1[i][j]);
        }
        printf("\n");
    }
}

void isSymmetric(int m,int M1[m][m]) {
    if (m != m) {
        printf("Not Symmetric\n");
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (M1[i][j] != M1[j][i]) {
                printf("Not Symmetric\n");
            }
        }
    }

    printf("Matrix is Symmetric\n");
}


void main()
{
    int m,ch,i,j;
    printf("Enter order of the square matrix\n");
    scanf("%d",&m);
    int M1[m][m];
    int M2[m][m];
    printf("Enter a square matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&M1[i][j]);
        }
    }
    while(1)
    {
        printf("MENU\n");
        printf("1.Add Matrix\n2.Subtract Matrix\n3.Multiply Matrix\n4.Sum of Principle and non principle diagonal of a Matrix\n5.Sum of rows and columns of Matrix\n6.Transpose of a Matrix\n");
        printf("7.Check if matrix is symmetric\n8.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter a square matrix to add to M1\n");
                    for(i=0;i<m;i++)
                    {
                        for(j=0;j<m;j++)
                        {
                            scanf("%d",&M2[i][j]);
                        }
                    }
                    add(m,M1,M2);
                    break;
            case 2: printf("Enter a square matrix to subtract from M1\n");
                    for(i=0;i<m;i++)
                    {
                        for(j=0;j<m;j++)
                        {
                            scanf("%d",&M2[i][j]);
                        }
                    }
                    sub(m,M1,M2);
                    break;
            case 3: printf("Enter a square matrix to Multiply to M1\n");
                    for(i=0;i<m;i++)
                    {
                        for(j=0;j<m;j++)
                        {
                            scanf("%d",&M2[i][j]);
                        }
                    }
                    multiply(m,M1,M2);
                    break;
            case 4: SumD(m,M1);
                    break;
            case 5: sumRC(m,M1);
                    break;

            case 6: transposeM(m,M1);
                    break;
            case 7: isSymmetric(m,M1);
                    break;
            case 8: exit(0);
            default: printf("\nWrong Choice!!Try Again");
        }
    }
}
