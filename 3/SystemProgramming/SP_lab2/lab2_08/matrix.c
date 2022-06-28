#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j;
	int row, col;
	int **matrix1 = NULL;
	int **matrix2 = NULL;
	int **matrix_sum = NULL;

	printf("enter row of matrix : ");
	scanf("%d", &row);
	printf("enter col of matrix : ");
	scanf("%d", &col);

	/* allocate first matrix */
	matrix1 = (int **)malloc(row * sizeof(int *));
	
	for(i=0; i<row; i++)
	{
		matrix1[i] = (int *)malloc(col * sizeof(int));
	}

	if (matrix1 == NULL)
	{
		printf("fail to allocate first matrix");
		exit(-1);
	}

	/* allocate second matrix */
	matrix2 = (int **)malloc(row * sizeof(int *));
	
	for(i=0; i<row; i++)
	{
		matrix2[i] = (int *)malloc(col * sizeof(int));
	}
	
	if (matrix2 == NULL)
	{
		printf("fail to allocate second matrix");
		exit(-1);
	}

	/* allocate sum matrix */
	matrix_sum = (int **)malloc(row * sizeof(int *));

	for(i=0; i<row; i++)
	{
		matrix_sum[i] = (int *)malloc(col * sizeof(int));
	}
	if (matrix_sum == NULL)
	{
		printf("fail to allocate sum matrix");
		exit(-1);
	}


	/* enter first matrix */
	printf("\nenter first matrix\n");
	for (i=0; i<row; i++)
	{
		for (j=0; j<col; j++)
		{
			scanf("%d", &matrix1[i][j]);
		}
	}

	/* enter second matrix */
	printf("\nenter second matrix\n");
	for (i=0; i<row; i++)
	{
		for (j=0; j<col; j++)
		{
			scanf("%d", &matrix2[i][j]);
		}
	}

	/* print first matrix */
	printf("\nfirst matrix\n");
	for (i=0; i<row; i++)
	{
		for (j=0; j<col; j++)
		{
			printf("%d  ", matrix1[i][j]);
		}
		printf("\n");
	}

	/* print second matrix */
	printf("\nsecond matrix\n");
	for (i=0; i<row; i++)
	{
		for (j=0; j<col; j++)
		{
			printf("%d  ", matrix2[i][j]);
		}
		printf("\n");
	}

	/* matrix sum process */
	for (i=0; i<row; i++)
	{
		for (j=0; j<col; j++)
		{
			matrix_sum[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	/* print sum matrix */
	printf("\nresult of first matrix + second matrix\n"); 
	for (i=0; i<row; i++)
	{
		for (j=0; j<col; j++)
		{
			printf("%d  ", matrix_sum[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	/* free all matrix (col-> row) */
	for (j=0; i<row; j++)
	{
		free(matrix1[j]);
		free(matrix2[j]);
		free(matrix_sum[j]);
	}
	free(matrix1);
	free(matrix2);
	free(matrix_sum);

	return 0;
}
