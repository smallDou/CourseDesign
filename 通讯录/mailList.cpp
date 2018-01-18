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
		printf("请输入你想执行的功能序号：");
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
			printf("指令输入错误！");
			break;
		}
	}
	free_mem(&con);
	system("pause");
	return 0;
}
