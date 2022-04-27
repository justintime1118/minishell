#include <dirent.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void	classify(struct dirent *ent)
{
	printf("%s\t", ent->d_name);
	if (ent->d_type == DT_BLK)
		printf("Block Device\n");
	else if (ent->d_type == DT_CHR)
		printf("Character Device\n");
	else if (ent->d_type == DT_DIR)
		printf("Directory\n");
	else if (ent->d_type == DT_LNK)
		printf("Symbolic Link\n");
	else if (ent->d_type == DT_REG)
		printf("Regular File\n");
	else if (ent->d_type == DT_SOCK)
		printf("Unix Domain Socket\n");
	else
		printf("Unknown Type File\n");
}

int		main(void)
{
	int				temp;
	DIR				*dirp;
	struct dirent	*file;

	dirp = opendir(".."); // 인자로 들어온 char *에 해당하는 디렉토리 스트림을 반환
	if (!dirp)
	{
		printf("error\n");
		return (1);
	}
	while (true)
	{
		temp = errno;
		file = readdir(dirp); // opendir로 가져온 디렉토리 스트림을 읽어서, 디렉토리 엔트리 dirent 포인터를 반환
		if (!file && temp != errno)
		{
			printf("error\n");
			break ;
		}
		if (!file)
			break ;
		classify(file);
	}
	closedir(dirp); // 닫아주기
	return (0);
}