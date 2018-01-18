#ifndef _CONTACT_H_                       
#define _CONTACT_H_
#define NAME_MAX 20
#define TEL_MAX 20
#define MAIL_MAX 30
#define ADDER_MAX 20
#define PEOPLE_MAX 3

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct people                   //����ͨѶ¼��������ݽṹ��
{
	char name[NAME_MAX];
	char addr[ADDER_MAX];
	char phone[TEL_MAX];
	char tel[TEL_MAX];
	char mail[MAIL_MAX];
}people;

typedef struct contact                  //����һ��Ƕ�׽ṹ�塣
{
	int capacity;
	people *human;
	int count_p;
}Con, *Pcon;

void add_people(Pcon pcon);           //�����ӿڣ�ʵ��������ϵ�˹���
int find_people(Pcon pcon);           //�����ӿڣ�ʵ�ֲ�����ϵ�˹���
void delete_people(Pcon pcon);        //�����ӿڣ�ʵ��ɾ����ϵ�˹���
void alter_people(Pcon pcon);         //�����ӿڣ�ʵ���޸���ϵ����Ϣ����
void show_people(Pcon pcon);          //�����ӿڣ�ʵ����ʾ������ϵ�˹���
void clean_people(Pcon pcon);         //�����ӿڣ� ʵ�������ϵ�˹���
void order_people(Pcon pcon);         //�����ӿڣ�ʵ�������ֶ���ϵ�˽��������ܡ�
void init(Pcon pcon);                 //��ʼ���ṹ��
void menu();                          //ʵ�ֲ˵�����
void free_mem(Pcon pcon);
void save_to_file(Pcon pcon);         //����ϵ����Ϣ�������ļ�
void read_from_file(Pcon pcon);       //���ļ��ж�ȡ��ϵ����Ϣ

void menu()
{
	printf("*******************��ӭʹ��ͨѶ¼*********************\n");
	printf("                   1.�����ϵ����Ϣ      \n");
	printf("                   2.ɾ��ָ����ϵ����Ϣ  \n");
	printf("                   3.����ָ����ϵ����Ϣ  \n");
	printf("                   4.�޸�ָ����ϵ����Ϣ  \n");
	printf("                   5.��ʾ������ϵ����Ϣ  \n");
	printf("                   6.���������ϵ��     \n");
	printf("                   7.�˳�\n");
	printf("******************************************************\n");
}

void print(Pcon pcon, int i)        //��ӡ��ϵ����Ϣ
{
	printf("|   ����   |   ����   |    �ƶ��绰    |    �̶��绰    |    ��������    | \n");
	printf("|  %4s   |    %4s    |    %6s    |   %6s    |   %6s    |\n", pcon->human[i].name, pcon->human[i].addr, 
		pcon->human[i].phone, pcon->human[i].tel , pcon->human[i].mail);

}

void judge_full(Pcon pcon)   //�жϵ�ǰ��ϵ�������Ƿ񳬹�������������������
{
	people *p = { 0 };
	if (pcon->count_p == pcon->capacity)
	{
		p = (people *)realloc(pcon->human, (pcon->capacity + 3)*sizeof(people));
		if (p == NULL)
		{
			printf("out of memery");
			exit(EXIT_FAILURE);
		}
		else
		{
			pcon->human = p;
			pcon->capacity += 3;
		}
	}
}

void add_people(Pcon pcon)
{
	judge_full(pcon);
	printf("�����������ϵ�˵�����,���ᣬ�ƶ��绰���̶��绰���ʼ���(���ÿո����س�������)\n");
	scanf("%s", pcon->human[pcon->count_p].name);
	scanf("%s", pcon->human[pcon->count_p].addr);
	scanf("%s", pcon->human[pcon->count_p].phone);
	scanf("%s", pcon->human[pcon->count_p].tel);
	scanf("%s", pcon->human[pcon->count_p].mail);
	print(pcon, pcon->count_p);
	(pcon->count_p)++;

	printf("��ӳɹ���\n");
}

int find_people(Pcon pcon)
{
	char name[NAME_MAX];
	int i = 0;
	printf("������������");
	scanf("%s", name);
	for (i = 0; i < pcon->count_p; i++)
	{
		if (strcmp(pcon->human[i].name, name) == 0)
		{
			print(pcon, i);
			return i;                  //���������������ϵ���е�һ������������򷵻ظ���ϵ�˵�λ��
		}
	}
	printf("�����ڸ���ϵ��!\n");
	return -1;
}

void delete_people(Pcon pcon)
{
	int i = 0;
	int ret = find_people(pcon);
	if (ret != -1)
	{
		for (i = ret; i < pcon->count_p; i++)
		{
			pcon->human[i] = pcon->human[i + 1];     //������λɾ����ɾ����
		}
		pcon->count_p--;
		printf("ɾ���ɹ���\n");

	}

}

void alter_people(Pcon pcon)
{
	int ret = find_people(pcon);     //����ָ����ϵ��λ��
	if (ret != -1)
	{
		printf("�������������ϵ����Ϣ��(�ÿո����س�������)\n");
		scanf("%s", pcon->human[ret].name);
		scanf("%s", pcon->human[ret].addr);
		scanf("%s", pcon->human[ret].phone);
		scanf("%s", pcon->human[ret].tel);
		scanf("%s", pcon->human[ret].mail);
		print(pcon, ret);
		printf("�޸ĳɹ���\n");

	}
}

void show_people(Pcon pcon)
{
	int i = 0;
	printf("|   ����   |   ����   |    �ƶ��绰    |    �̶��绰    |    ��������    | \n");

	for (i = 0; i < pcon->count_p; i++)  //ѭ����ӡȫ����ϵ��
	{
		printf("|  %4s   |    %4s    |    %6s    |   %6s    |   %6s    |\n", pcon->human[i].name, pcon->human[i].addr, 
		pcon->human[i].phone, pcon->human[i].tel , pcon->human[i].mail);
	}
}

void clean_people(Pcon pcon)         //�������ó�0���������ϵ��
{
	pcon->count_p = 0;
	printf("�ɹ���գ�");
}

void init(Pcon pcon)   //�Խṹ����г�ʼ����
{
	pcon->capacity ;

	people *p = (people *)malloc((PEOPLE_MAX)*sizeof(people));

	if (p == NULL)
	{
		printf("out of memery");
		exit(EXIT_FAILURE);
	}
	else
	{
		pcon->human = p;
	}
	memset(pcon->human, 0, (PEOPLE_MAX)* sizeof(people));
	pcon->count_p = 0;

}

void free_mem(Pcon pcon)
{
	free(pcon->human);
	pcon->human = NULL;
}

void read_from_file(Pcon pcon)   //���ļ��ж�ȡ��ϵ����Ϣ
{
	int i = 0;
	people tmp = { 0 };
	FILE *pfread = fopen("cantact.txt", "r");
	if (pfread == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	while (fread(&tmp, sizeof(people), 1, pfread))
	{
		judge_full(pcon);  //��ֹ�ļ����������������
		pcon->human[i] = tmp;
		i++;
		pcon->count_p++;
	}
	fclose(pfread);
}

void save_to_file(Pcon pcon)      //����ϵ����Ϣ�������ļ�
{
	int i = 0;
	FILE *pfwrite = fopen("cantact.txt", "w");
	if (pfwrite == NULL)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < pcon->count_p; i++)
	{
		fwrite(&(pcon->human[i]), sizeof(people), 1, pfwrite);
	}
	fclose(pfwrite);
}
#endif
