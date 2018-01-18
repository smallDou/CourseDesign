#include <stdio.h>                     
#include <string.h>                      
#include <stdlib.h>
#include <time.h>                     
struct time                             
{
	int hour;                                       
	int minute;                                      
};
typedef struct STUDENT                /*定义学生信息结构*/
{
	int no;                                          /*学号*/
	char cla[10];                                    /*班级*/
	char name[10];                                   /*姓名*/
	int time_hour;                             /*上机时间*/
	int time_minute;
	struct time begin,end;                           /*嵌套时间结构*/
};
struct STUDENT student[30];
static int i =0;                           /*全局静态变量*/
void insert();                             /*输入功能函数*/
void end_money();                          /*结账功能函数*/
void select_no();                          /*学号查询功能函数*/
void select_name();                        /*姓名查询功能函数*/
void select_cla();                         /*班级查询功能函数*/
void show();
int main()                               
{
	printf("**********************\n");
	printf("***机房收费管理系统***\n");
	printf("1.->输入学生信息:    *\n");
	printf("2.->结账:            *\n");
	printf("3.->按学号查询:      *\n");
	printf("4.->按班级查询:      *\n");
	printf("5.->按姓名查询:      *\n");
	printf("6.->显示上机信息：   *\n");
	printf("7.->退出系统：       *\n");
	printf("**********************\n");
	while(1)                                      
	{
	int j;
	printf("请选择功能:");
	scanf("%d",&j);
	
	switch(j)/*选择分支结构*/
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
		printf("输入无效，请重新输入!\n");
	}
	}
	return 0;
}
void insert()                                   //插入信息
{
	   
		printf("请输入学号:");
		scanf("%d",&student[i].no);
		printf("请输入姓名:");
		scanf("%s",&student[i].name);
		printf("请输入班级:");
		scanf("%s",&student[i].cla);

		time_t t = time(NULL);
		struct tm* currentTime = localtime( &t );
		student[i].begin.hour = currentTime->tm_hour;
		student[i].begin.minute = currentTime->tm_min;
		printf("记录成功!\n");
		i = i + 1;
	
}
void end_money()                                    //计算money
{
	int m,minute,hour;                              //保存时间
	int no;
	printf("请输入学号:");
	scanf("%d",&no);
	if(i==0)
		printf("没有该记录!\n");
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
				printf("上机时间为：%d:%d  费用为：%d\n",student[m].time_hour,student[m].time_minute,hour);
			}
			else
			{
               printf("上机时间为：%d:%d  费用为：%d\n",student[m].time_hour,student[m].time_minute,hour);
			
			}

		}
		else if( m == (i-1))
		{
		printf("没有该记录!\n");
		}
	}
	}	
	}
void select_no()                                                //按学号查询
{
    int no;
	int m;
	printf("请输入学号:");
	scanf("%d",&no);
	if(i==0)
		printf("没有该记录:\n");
	else
	{
		for(m = 0;m < i;m++)
		{
			if(no == student[m].no)
			{
				printf("学号为:%d\t",student[m].no);
				printf("班级为:%s\t",student[m].cla);
				printf("姓名为:%s\t",&student[m].name);
				printf("上机开始时间为:%d:%d\t",student[m].begin.hour,student[m].begin.minute);
				printf("上机结束时间为:%d:%d\t",student[m].end.hour,student[m].end.minute);
				printf("上机时间为：%d:%d\n",student[m].time_hour,student[m].time_minute);
			}
			else if( m == (i-1))
			{
			printf("没有该记录!\n");
			}

		}		
	}
}   
void select_cla()                                                 //按班级查询
{
    char cla[10];
	int m;
	printf("请输入班级:");
	scanf("%s",cla);
	if(i==0)
		printf("没有该记录!\n");
	else
	{
	for(m = 0;m < i;m++)
	{
		if(!strcmp(cla,student[m].cla))
		{
			 printf("学号为%d\t",student[m].no);
			 printf("班级为%s\t",student[m].cla);
			 printf("姓名为%s\t",&student[m].name);
			 printf("上机开始时间为%d:%d\t",student[m].begin.hour,student[m].begin.minute);
			 printf("上机结束时间为%d:%d\t",student[m].end.hour,student[m].end.minute);
			 printf("上机时间为：%d:%d\n",student[m].time_hour,student[m].time_minute);
		}
		else if( m == (i-1))
		{
			printf("没有该记录!\n");
		}

	}
	}
}  
void select_name() //按姓名查询
{
    char name[10];
	int m;
	printf("请输入姓名:");
	scanf("%s",name);
	if(i==0)
		printf("没有该记录!\n");
	else
	{
	for(m = 0;m < i;m++)
	{
		if(!strcmp(name,student[m].name))/*字符串的比较  非0为真执行*/
		{

			 printf("学号为:%d\t",student[m].no);
			 printf("班级为:%s\t",student[m].cla);
			 printf("姓名为:%s\t",&student[m].name);
			 printf("开始上机时间为:%d:%d\t",student[m].begin.hour,student[m].begin.minute);
			 printf("结束上机时间为:%d:%d\t",student[m].end.hour,student[m].end.minute);
			 printf("上机时间为:：%d:%d\n",student[m].time_hour,student[m].time_minute);
		}
		else if( m == (i-1))
		{
			printf("没有该记录!\n");
		}
	}
	}
}

void show()
{
	int m = 0;
	if(i==0)
		printf("没有记录!\n");
	else
	{
		for(m = 0;m < i;m++)
		{
			printf("学号为%d\t",student[m].no);
			printf("班级为%s\t",student[m].cla);
			printf("姓名为%s\t",&student[m].name);
			printf("上机开始时间为%d:%d\t",student[m].begin.hour,student[m].begin.minute);
			printf("上机结束时间为%d:%d\t",student[m].end.hour,student[m].end.minute);
			printf("上机时间为：%d:%d\n",student[m].time_hour,student[m].time_minute);
		}
	}
}