#include"head.h"
int main()
{
	Con con;
	init(&con);
	int num = 0;
	menu();
	read_from_file(&con);
	while (1)
	{
		printf("����������ִ�еĹ�����ţ�");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			add_people(&con);
			break;
		case 2:
			delete_people(&con);
			break;
		case 3:
			find_people(&con);
			break;
		case 4:
			alter_people(&con);
			break;
		case 5:
			show_people(&con);
			break;
		case 6:
			clean_people(&con);
			break;
		case 7:
			save_to_file(&con);
			exit(0);
			break;
		default:
			printf("ָ���������");
			break;
		}
	}
	free_mem(&con);
	system("pause");
	return 0;
}
