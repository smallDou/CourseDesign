#include <stdio.h>                     
#include <string.h>                      
#include <stdlib.h>
#include <time.h>                     
struct time                             
{
	int hour;                                       
	int minute;                                      
};
typedef struct STUDENT                /*����ѧ����Ϣ�ṹ*/
{
	int no;                                          /*ѧ��*/
	char cla[10];                                    /*�༶*/
	char name[10];                                   /*����*/
	int time_hour;                             /*�ϻ�ʱ��*/
	int time_minute;
	struct time begin,end;                           /*Ƕ��ʱ��ṹ*/
};
struct STUDENT student[30];
static int i =0;                           /*ȫ�־�̬����*/
void insert();                             /*���빦�ܺ���*/
void end_money();                          /*���˹��ܺ���*/
void select_no();                          /*ѧ�Ų�ѯ���ܺ���*/
void select_name();                        /*������ѯ���ܺ���*/
void select_cla();                         /*�༶��ѯ���ܺ���*/
void show();
int main()                               
{
	printf("**********************\n");
	printf("***�����շѹ���ϵͳ***\n");
	printf("1.->����ѧ����Ϣ:    *\n");
	printf("2.->����:            *\n");
	printf("3.->��ѧ�Ų�ѯ:      *\n");
	printf("4.->���༶��ѯ:      *\n");
	printf("5.->��������ѯ:      *\n");
	printf("6.->��ʾ�ϻ���Ϣ��   *\n");
	printf("7.->�˳�ϵͳ��       *\n");
	printf("**********************\n");
	while(1)                                      
	{
	int j;
	printf("��ѡ����:");
	scanf("%d",&j);
	
	switch(j)/*ѡ���֧�ṹ*/
	{
	case 1:                       
		{
			insert();
		}break;
	case 2:
		{
			end_money();
		}break;
	case 3:
		{
			select_no();
		}break;
	case 4:
		{
			select_cla();
		}break;
	case 5:                 
		{
			select_name();
		}break;
	case 6:
		show();
		break;
	case 7:
		{
			return 0;
		}
	default :
		printf("������Ч������������!\n");
	}
	}
	return 0;
}
void insert()                                   //������Ϣ
{
	   
		printf("������ѧ��:");
		scanf("%d",&student[i].no);
		printf("����������:");
		scanf("%s",&student[i].name);
		printf("������༶:");
		scanf("%s",&student[i].cla);

		time_t t = time(NULL);
		struct tm* currentTime = localtime( &t );
		student[i].begin.hour = currentTime->tm_hour;
		student[i].begin.minute = currentTime->tm_min;
		printf("��¼�ɹ�!\n");
		i = i + 1;
	
}
void end_money()                                    //����money
{
	int m,minute,hour;                              //����ʱ��
	int no;
	printf("������ѧ��:");
	scanf("%d",&no);
	if(i==0)
		printf("û�иü�¼!\n");
	else
	{
	for(m = 0;m < i;m++)
	{
		if(no == student[m].no)
		{
			time_t t = time(NULL);
			struct tm* currentTime = localtime( &t );
			student[m].end.hour = currentTime->tm_hour;
			student[m].end.minute = currentTime->tm_min;
			
			if(student[m].end.minute <student[m].begin.minute && student[m].end.hour >student[m].begin.hour)
			{
				minute = student[m].end.minute +60 -student[m].begin.minute;
				hour = student[m].end.hour -1 - student[m].begin.hour;
				student[m].time_hour = hour;
				student[m].time_minute = minute;
					
			}
			else
			{
                 minute = student[m].end.minute - student[m].begin.minute;
				 hour = student[m].end.hour - student[m].begin.hour;
				 student[m].time_hour = hour;
				 student[m].time_minute = minute;
				 
			}
			if(minute > 0)
			{
				hour = hour + 1;
				printf("�ϻ�ʱ��Ϊ��%d:%d  ����Ϊ��%d\n",student[m].time_hour,student[m].time_minute,hour);
			}
			else
			{
               printf("�ϻ�ʱ��Ϊ��%d:%d  ����Ϊ��%d\n",student[m].time_hour,student[m].time_minute,hour);
			
			}

		}
		else if( m == (i-1))
		{
		printf("û�иü�¼!\n");
		}
	}
	}	
	}
void select_no()                                                //��ѧ�Ų�ѯ
{
    int no;
	int m;
	printf("������ѧ��:");
	scanf("%d",&no);
	if(i==0)
		printf("û�иü�¼:\n");
	else
	{
		for(m = 0;m < i;m++)
		{
			if(no == student[m].no)
			{
				printf("ѧ��Ϊ:%d\t",student[m].no);
				printf("�༶Ϊ:%s\t",student[m].cla);
				printf("����Ϊ:%s\t",&student[m].name);
				printf("�ϻ���ʼʱ��Ϊ:%d:%d\t",student[m].begin.hour,student[m].begin.minute);
				printf("�ϻ�����ʱ��Ϊ:%d:%d\t",student[m].end.hour,student[m].end.minute);
				printf("�ϻ�ʱ��Ϊ��%d:%d\n",student[m].time_hour,student[m].time_minute);
			}
			else if( m == (i-1))
			{
			printf("û�иü�¼!\n");
			}

		}		
	}
}   
void select_cla()                                                 //���༶��ѯ
{
    char cla[10];
	int m;
	printf("������༶:");
	scanf("%s",cla);
	if(i==0)
		printf("û�иü�¼!\n");
	else
	{
	for(m = 0;m < i;m++)
	{
		if(!strcmp(cla,student[m].cla))
		{
			 printf("ѧ��Ϊ%d\t",student[m].no);
			 printf("�༶Ϊ%s\t",student[m].cla);
			 printf("����Ϊ%s\t",&student[m].name);
			 printf("�ϻ���ʼʱ��Ϊ%d:%d\t",student[m].begin.hour,student[m].begin.minute);
			 printf("�ϻ�����ʱ��Ϊ%d:%d\t",student[m].end.hour,student[m].end.minute);
			 printf("�ϻ�ʱ��Ϊ��%d:%d\n",student[m].time_hour,student[m].time_minute);
		}
		else if( m == (i-1))
		{
			printf("û�иü�¼!\n");
		}

	}
	}
}  
void select_name() //��������ѯ
{
    char name[10];
	int m;
	printf("����������:");
	scanf("%s",name);
	if(i==0)
		printf("û�иü�¼!\n");
	else
	{
	for(m = 0;m < i;m++)
	{
		if(!strcmp(name,student[m].name))/*�ַ����ıȽ�  ��0Ϊ��ִ��*/
		{

			 printf("ѧ��Ϊ:%d\t",student[m].no);
			 printf("�༶Ϊ:%s\t",student[m].cla);
			 printf("����Ϊ:%s\t",&student[m].name);
			 printf("��ʼ�ϻ�ʱ��Ϊ:%d:%d\t",student[m].begin.hour,student[m].begin.minute);
			 printf("�����ϻ�ʱ��Ϊ:%d:%d\t",student[m].end.hour,student[m].end.minute);
			 printf("�ϻ�ʱ��Ϊ:��%d:%d\n",student[m].time_hour,student[m].time_minute);
		}
		else if( m == (i-1))
		{
			printf("û�иü�¼!\n");
		}
	}
	}
}

void show()
{
	int m = 0;
	if(i==0)
		printf("û�м�¼!\n");
	else
	{
		for(m = 0;m < i;m++)
		{
			printf("ѧ��Ϊ%d\t",student[m].no);
			printf("�༶Ϊ%s\t",student[m].cla);
			printf("����Ϊ%s\t",&student[m].name);
			printf("�ϻ���ʼʱ��Ϊ%d:%d\t",student[m].begin.hour,student[m].begin.minute);
			printf("�ϻ�����ʱ��Ϊ%d:%d\t",student[m].end.hour,student[m].end.minute);
			printf("�ϻ�ʱ��Ϊ��%d:%d\n",student[m].time_hour,student[m].time_minute);
		}
	}
}