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
	
	//1번 선택 시 연금복권 숫자 추첨
	if (select == 1)
	{
		for(i=0; i<6; i++) // 6개 숫자, 0~9번까지 랜덤 난수 생성 및 result 배열에 삽입
		{
			result[i] = rand() % 10;
		}
		
	
		printf("추첨 결과\n"); //추첨 결과 출력
	
		for(j=0; j<6; j++)
		{
			printf("%d ", result[j]);
		}
		
		
	}
	
	// 2번 선택시 랜덤 로또 번호 추첨
	else if (select == 2)
	{
	
		for(i=0; i<6; i++) // 1 ~ 45까지 랜덤 난수 값 삽입
		{	
			while(1)
			{
				int save;
				result[i] = rand() % 45 + 1;
				save = 0; //스위치 변수
				
				for(j=0; j<i; j++)
				{
					if(result[i] == result[j])
					{
						save = 1;
						break; //중복값 확인 시 for문 종료
					}
				}
				
			}

		}
	
	
		for(j=0; j<6; j++) //Bubble sort 수행
		{
			for(k=0; k<5; k++) // k값이 0에서 1씩 증가하면서 4까지 반복
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