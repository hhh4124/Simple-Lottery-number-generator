#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	printf("랜덤 번호 추첨기입니다.\n");
	printf("연금복권, 로또 중 1 택: 1-연금복권, 2-로또\n");
	
	int select;
	
	scanf("%d", &select);
	
		int i;
		int j;
		int k;
		int temp;
		int random_num;
		int result[6];
		
		srand(time(NULL));
	
	
	if (select == 1)
	{
		for(i=0; i<6; i++)
		{
			random_num = rand() % 10;
			result[i] = random_num;
		}
		
	
		printf("추첨 결과\n");
	
		for(j=0; j<6; j++)
		{
			printf("%d ", result[j]);
		}
		
		
	}
	
	else if (select == 2)
	{
	
		for(i=0; i<6; i++)
		{	
			random_num = rand() % 45 + 1;
			result[i] = random_num;	
		}
	
	
		for(j=0; j<6; j++)
		{
			for(k=0; k<5; k++)
			{
				if(result[k] > result[k+1])
				{
					temp = result[k];
					result[k] = result[k+1];
					result[k+1] = temp;
				}
			}
		}
	
		printf("추첨 결과\n");
	
		for(j=0; j<6; j++)
		{
			printf("%d ", result[j]);
		}
	}
	
	else
	{
		printf("1 또는 2만 입력해주세요.\n");
	}
	return 0;
}