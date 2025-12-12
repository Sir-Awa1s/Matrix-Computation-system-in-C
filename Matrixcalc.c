#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<stdbool.h>

#define EPSILON_FLOAT 1e-6
#define EPSILON 1e-12

int c;

int row_column_define(int *row_one,int *row_two,int *column_one,int *column_two,int *define_matrix_amount);

int menu(int row_one,int row_two,int column_one,int column_two);

int menu_two(int row_one,int column_one);

int matrix_addition(int row_one,int row_two,int column_one,int column_two);

int matrix_subtraction(int row_one,int row_two,int column_one,int column_two);

int matrix_multiplication(int row_one,int row_two,int column_one,int column_two);

int scalar_multiplication(int row_one,int column_one);

int transposition(int row_one,int column_one);

int determinant(int row_one,int column_one);

int inverse(int row_one,int column_one);

int main()
{
    int row_one=0;
    int row_two=0;
    int column_one=0;
    int column_two=0;
    int define_matrix_amount=0;

    printf("How many matrices to be Defined, 1 OR 2? ");
    scanf("%d",&define_matrix_amount);

    row_column_define(&row_one,&row_two,&column_one,&column_two,&define_matrix_amount);

    /*while((c=getchar()) != '\n' && c != EOF);
    getchar();*/

    if(define_matrix_amount == 1)
    {
         menu_two(row_one,column_one);

    } else
    {
        menu(row_one,row_two,column_one,column_two);
    }
}

int row_column_define(int *row_one,int *row_two,int *column_one,int *column_two,int *define_matrix_amount)
{
    if(*define_matrix_amount == 1)
    {
        printf("Define Row? ");
        scanf("%d",row_one);

        printf("Define Column? ");
        scanf("%d",column_one);

    } else if(*define_matrix_amount == 2)
    {
       printf("Define Row of matrix 1? ");
        scanf("%d",row_one);

        printf("Define Column of matrix 1? ");
        scanf("%d",column_one);

        printf("Define Row of matrix 2? ");
        scanf("%d",row_two);

        printf("Define Column of matrix 2? ");
        scanf("%d",column_two);
    }else{
        getchar();
        system("cls");
        main();
    }

}

int menu(int row_one,int row_two,int column_one,int column_two)
{
    system("cls");
    int menu_opt;
    printf("1-Matrix Addition\n2-Matrix Subtraction\n3-Matrix Multiplication\n");
    scanf("%d",&menu_opt);

    switch(menu_opt)
    {
            case 1:
            system("cls");
            matrix_addition(row_one,row_two,column_one,column_two);
            break;

            case 2:
            system("cls");
            matrix_subtraction(row_one,row_two,column_one,column_two);
            break;

            case 3:
            system("cls");
            matrix_multiplication(row_one,row_two,column_one,column_two);
            break;
        }
    }

int menu_two(int row_one,int column_one)
{
    system("cls");
    int menu_opt=0;
    printf("1-Scalar Multiplication\n2-Transposition\n3-Determinant\n4-Inverse\n");
    scanf("%d",&menu_opt);

    switch(menu_opt)
    {
        case 1:
        system("cls");
        scalar_multiplication(row_one,column_one);
        break;

        case 2:
        system("cls");
        transposition(row_one,column_one);
        break;

        case 3:
        system("cls");
        determinant(row_one,column_one);
        break;

        case 4:
        system("cls");
        inverse(row_one,column_one);
        break;
    }
}

int matrix_addition(int row_one,int row_two,int column_one,int column_two)
{
        int matrix_one[row_one][column_one];
        int matrix_two[row_two][column_two];
        int add_result[row_one][column_one];

        printf("Enter elements of Matrix 1:\n");
            for(int i=0;i<row_one;i++)
            {
                for(int j=0;j<column_one;j++)
                {
                    scanf("%d",&matrix_one[i][j]);
                }
            }

        printf("Enter elements of Matrix 2:\n");
            for(int i=0;i<row_one;i++)
            {
                for(int j=0;j<column_one;j++)
                {
                    scanf("%d",&matrix_two[i][j]);
                }
            }

            for(int i=0;i<row_one;i++)
            {
                for(int j=0;j<column_one;j++)
                {
                    add_result[i][j]=matrix_one[i][j]+matrix_two[i][j];
                }
            }

        printf("Sum of matrix 1 and 2: \n");
            for(int i=0;i<row_one;i++)
            {
                printf("\n");
                for(int j=0;j<column_one;j++)
                {
                    printf("%d\t",add_result[i][j]);
                }
            }

            while((c=getchar()) != '\n' && c != EOF);
            getchar();
}

int matrix_subtraction(int row_one,int row_two,int column_one,int column_two)
{
        int matrix_one[row_one][column_one];
        int matrix_two[row_two][column_two];
        int sub_result[row_one][column_one];

        printf("Enter elements of Matrix 1:\n");
            for(int i=0;i<row_one;i++)
            {
                for(int j=0;j<column_one;j++)
                {
                    scanf("%d",&matrix_one[i][j]);
                }
            }

        printf("Enter elements of Matrix 2:\n");
            for(int i=0;i<row_one;i++)
            {
                for(int j=0;j<column_one;j++)
                {
                    scanf("%d",&matrix_two[i][j]);
                }
            }

            for(int i=0;i<row_one;i++)
            {
                for(int j=0;j<column_one;j++)
                {
                sub_result[i][j]=matrix_one[i][j]-matrix_two[i][j];
                }
            }
        printf("\n");

        printf("Subtraction of matrix 1 and 2: \n");

        for(int i=0;i<row_one;i++)
        {
            printf("\n");
            for(int j=0;j<column_one;j++)
            {
                printf("%d\t",sub_result[i][j]);
            }
        }

    while((c=getchar()) != '\n' && c != EOF);
    getchar();
}

int matrix_multiplication(int row_one,int row_two,int column_one,int column_two)
{
    int matrix_one[row_one][column_one];
    int matrix_two[row_two][column_two];
    int product[row_one][column_two];
    int sum=0;

    printf("Enter elements of Matrix 1:\n");
    for(int i=0;i<row_one;i++)
    {
        for(int j=0;j<column_one;j++)
        {
            scanf("%d",&matrix_one[i][j]);
        }
    }

    printf("Enter elements of Matrix 2:\n");
    for(int i=0;i<row_two;i++)
    {
        for(int j=0;j<column_two;j++)
        {
            scanf("%d",&matrix_two[i][j]);
        }
    }

    for(int i=0;i<row_one;i++)
    {
        for(int j=0;j<column_two;j++)
        {
            sum=0;
            for(int k=0;k<row_two;k++)
            {
                sum+=matrix_one[i][k]*matrix_two[k][j];
            }
            product[i][j]=sum;
        }
    }

    for(int i=0;i<row_one;i++)
    {
        printf("\n");
        for(int j=0;j<column_two;j++)
        {
            printf("%d\t",product[i][j]);
        }
    }

    while((c = getchar()) != '\n' && c != EOF);
    getchar();

}

int scalar_multiplication(int row_one,int column_one)
{
    int matrix[row_one][column_one];
    int result[row_one][column_one];
    int scalar_value=0;

    printf("Enter elements of Matrix :\n");
    for(int i=0;i<row_one;i++)
    {
        for(int j=0;j<column_one;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("Enter value for multiplication: ");
    scanf("%d",&scalar_value);

    for(int i=0;i<row_one;i++)
    {
        for(int j=0;j<column_one;j++)
        {
            result[i][j]=matrix[i][j]*scalar_value;
        }
    }

    for(int i=0;i<row_one;i++)
    {
        printf("\n");
        for(int j=0;j<column_one;j++)
        {
            printf("%d\t",result[i][j]);
        }
    }

    while((c=getchar()) != '\n' && c != EOF);
    getchar();
}

int transposition(int row_one,int column_one)
{
    int matrix[row_one][column_one];
    int transposed_matrixval[column_one][row_one];
    bool symmetry_check = false;

    printf("Enter elements of Matrix :\n");

        for(int i=0;i<row_one;i++)
        {
            for(int j=0;j<column_one;j++)
            {
                scanf("%d",&matrix[i][j]);
            }
        }

        for(int i=0;i<row_one;i++)
        {
            for(int j=0;j<column_one;j++)
            {
                transposed_matrixval[j][i]=matrix[i][j];
            }
        }

        printf("Transposed Matrix: \n");

        for(int i=0;i<row_one;i++)
        {
            printf("\n");
            for(int j=0;j<column_one;j++)
            {
                printf("%d\t",transposed_matrixval[i][j]);
            }
        }

        for(int i=0;i<row_one;i++)
        {
            for(int j=0;j<column_one;j++)
            {
                if(matrix[i][j] != transposed_matrixval[i][j])
                {
                   symmetry_check = false;
                   break;
                }else
                {
                    symmetry_check = true;
                    break;
                }
            }
        }
          printf("\n");

        if(symmetry_check == true)
        {
            printf("Matrix does HOLD Symmetry.");
        }else{
            printf("Matrix does NOT hold Symmetry.");
        }

        while((c=getchar()) != '\n' && c != EOF);
        getchar();

}

int determinant(int row_one,int column_one)
{
    int matrix[row_one][column_one];
    int determinantval=0;

    float matrix_RR[row_one][column_one];
    float determinant_RR = 1;

    if(row_one && column_one > 3)
    {
        printf("Enter the elements of Matrix: \n");

        for(int i=0;i<row_one;i++)
        {
            for(int j=0;j<column_one;j++)
            {
                printf("element[%d][%d]: ",i+1,j+1);
                scanf("%f",&matrix_RR[i][j]);
                system("cls");
            }
        }

    }else
     {
     printf("Enter elements of Matrix :\n");

        for(int i=0;i<row_one;i++)
        {
            for(int j=0;j<column_one;j++)
            {
                scanf("%d",&matrix[i][j]);
            }
        }

    }

    if(row_one == 2 && column_one == 2)
    {
        determinantval = (matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
        printf("Det = %d",determinantval);

        while((c=getchar()) != '\n' && c != EOF);
        getchar();

    } else if(row_one == 3 && column_one == 3)
    {
        int minor_a11=0;// 11*22-12*21//
        int minor_a12=0;//10*22-12*20//
        int minor_a13=0;//10*21-11*20//

        minor_a11 = (matrix[1][1]*matrix[2][2])-(matrix[1][2]*matrix[2][1]);
        minor_a12 = (matrix[1][0]*matrix[2][2])-(matrix[1][2]*matrix[2][0]);
        minor_a13 = (matrix[1][0]*matrix[2][1])-(matrix[1][1]*matrix[2][0]);

        determinantval = (matrix[0][0]*minor_a11)-(matrix[0][1]*minor_a12)+(matrix[0][2]*minor_a13);

        printf("Determinant of first Row: %d\n",determinantval);
        printf("Minor M11 = %d\n",minor_a11);
        printf("Minor M12 = %d\n",minor_a12);
        printf("minor M13 = %d",minor_a13);

        while((c=getchar()) != '\n' && c != EOF);
        getchar();
    }
    else
    {

        for(int p=0;p<row_one;p++)
    {
            if(fabs(matrix_RR[p][p]) < EPSILON_FLOAT)
            {
                for(int a=p+1;a<row_one;a++)
                {
                    if(fabs(matrix_RR[a][p]) >= EPSILON_FLOAT)
                    {
                        for(int b=0;b<column_one;b++)
                        {
                            float temp = matrix_RR[p][b];
                            matrix_RR[p][b]=matrix_RR[a][b];
                            matrix_RR[a][b] = temp;
                        }
                        break;
                    }
                }
                if(fabs(matrix_RR[p][p]) < EPSILON_FLOAT)
                    {
                        continue;
                    }
            }

            float pivot = matrix_RR[p][p];
            /*printf("pivot %d: %.2f\n",p,pivot);*/ //Pivot-PRINT Checker//
        for(int r=p+1;r<row_one;r++)
        {
            float multiplier = matrix_RR[r][p]/pivot;
            /*printf("multiplier %d: %.2f\n",r,multiplier);*/ //Multiplier-PRINT checker//

            for(int q=p;q<column_one;q++)
            {
                matrix_RR[r][q]=matrix_RR[r][q]-(multiplier*matrix_RR[p][q]);
            }
        }
    }

    /*for(int i=0;i<row_one;i++)
    {
        printf("\n");
        for(int j=0;j<column_one;j++)               MATRIX-PRINT CHECKING LOOP
        {
            printf("%.3f\t",matrix_RR[i][j]);
        }
    }*/

    float mult = 1;
    for(int c=0;c<row_one;c++)
    {
         mult *= matrix_RR[c][c];
    }

    printf("\n");
    printf("Determinant of Matrix: %.2f",mult);

        while((c = getchar()) != '\n' && c != EOF);
        getchar();
    }

}

int inverse(int row_one,int column_one)
{

    double matrix[row_one][column_one];
    double identity[row_one][column_one];

    for(int c=0;c<row_one;c++)
    {
        for(int d=0;d<column_one;d++)
        {
            identity[c][d]=0;
        }
    }

    for(int w=0;w<row_one;w++)
    {
        identity[w][w] = 1.0;
    }

    printf("Enter all elements of Matrix: \n");

    for(int i=0;i<row_one;i++)
    {
        for(int j=0;j<column_one;j++)
        {
            printf("Element[%d][%d]: ",i,j);
            scanf("%lf",&matrix[i][j]);
        }
    }

    for(int p=0;p<row_one;p++)
    {
        if(fabs(matrix[p][p]) < EPSILON)
            {
                for(int a=p+1;a<row_one;a++)
                {
                    if(fabs(matrix[a][p]) >= EPSILON)
                    {
                        for(int b=0;b<column_one;b++)
                        {
                            double temp = matrix[p][b];
                            matrix[p][b]=matrix[a][b];
                            matrix[a][b] = temp;

                            double temp_identity = identity[p][b];
                            identity[p][b]=identity[a][b];
                            identity[a][b]=temp_identity;
                        }
                        break;
                    }
                }
                if(fabs(matrix[p][p]) < EPSILON)
                    {
                        continue;
                    }
            }
        double pivot = matrix[p][p];

        for(int k=0;k<column_one;k++)
        {
            matrix[p][k]/=pivot;
            identity[p][k]/=pivot;
            /*printf("matrix pivot = %.2f, identity pivot =%0.2f",matrix[p][k],identity[p][k]);*/
        }

        for(int m=0;m<row_one;m++)
        {
            if(m == p) continue;
            double multiplier=matrix[m][p];
            /*printf("%.2f\n",multiplier);*/

            for(int n=0;n<column_one;n++)
            {
                matrix[m][n]-=multiplier*matrix[p][n];
                identity[m][n]-=multiplier*identity[p][n];
            }
        }
    }

    printf("Inverse: \n");

    for(int x=0;x<row_one;x++)
    {
        printf("\n");
        for(int z=0;z<column_one;z++)
        {
            printf("%15.17g\t",identity[x][z]);
        }
    }
    while((c=getchar()) != '\n' && c != EOF);
    getchar();

}
