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
		
		return 0;
	}
	
	// 2번 선택시 랜덤 로또 번호 추첨
	else if (select == 2)
	{
	
		for(i=0; i<6; i++) // i = 0 부터 i = 5까지 랜덤 난수 생성 후 삽입
		{	
			while(1) //while 무한 루프
			{
				int save;// 스위치 변수, 1이면 중복 있음, 0이면 중복 없음 판별
				result[i] = rand() % 45 + 1; //1~45 난수 생성 및 삽입
				save = 0; 
				
				for(j=0; j<i; j++)
				{
					if(result[i] == result[j]) // 중복 확인 
					{
						save = 1; //중복 값 있을 시 save 변수 1로 변경11
						break; //중복값 확인 시 for문 종료
					}
				}
				
				if(save == 0) // 중복 없으면
				{
					break; //스위치가 0이면 중복 X While문 종료
				}
			}
		}
	
	
		for(j=0; j<6; j++) //Bubble sort 수행
		{
			for(k=0; k<5; k++) // k값이 0에서 1씩 증가1
			{
				if(result[k] > result[k+1]) // 현재 배열이 뒷 배열보다 더 클 경우
1				{
					temp = result[k]; // 임시 변수에 k값 삽입
					result[k] = result[k+1]; // k값에 뒷 번호 삽입(더 작은 수가 앞에 오게 됨)
					result[k+1] = temp; // 임시 값에 있던 더 큰 수를 뒤로 보냄
				}
			}
		}
	
		printf("추첨 결과\n");
	
		for(j=0; j<6; j++)
		{
			printf("%d ", result[j]);
		}
		printf("\n");
		return 0;
	}
	
	else
	{
		printf("1 또는 2만 입력해주세요.\n");
	}
	return 0;
}