#include <stdio.h>
#include <unistd.h>
#include <dirent.h> 
#include <string.h>
#include <stdlib.h>

#define MAX_BUF 256

// ls -R 
void list_dir (const char* dirpath)
{
	
	DIR *pdir; // 디렉토리 구조체 포인터
	struct dirent *pde = NULL; // 디렉토리 내용 
	char *dirlist[MAX_BUF]; // 서브 디렉토리 경로 저장 배열
	char path[MAX_BUF] = ""; // 서브디렉토리 이름 
	int i = 0; 
	int count = 0;


	printf("\n\n%s\n",dirpath);

	// 디렉토리 open
	if ( (pdir = opendir(dirpath)) < 0 ) {
		perror("opendir");
		exit(1);
	}
	
	//디렉토리 내용을 한줄씩 읽어들인다
	while ((pde = readdir(pdir)) != NULL) {

		// 서브 디렉토리 확인
		if( pde->d_type == DT_DIR )
		{
			if( strcmp( pde -> d_name, ".") && strcmp(pde -> d_name, "..") )
			{
				// 배열에 서브 디렉토리 경로 저장
				sprintf(path, "%s/%s" , dirpath, pde -> d_name);
				dirlist[count] = (char*)malloc(sizeof(char) * strlen(path));
				strcpy(dirlist[count], path);		
				count++;
			}
			
		}


		printf("%20s ", pde->d_name);
		if (++i % 3 == 0)
		printf("\n");

	}
	
	//재귀
	if(dirlist[0] != NULL){
		for(i=0; i < count; i++)
		{
			list_dir(dirlist[i]);
		}
	}

	printf("\n");
	closedir(pdir);
}

int main(int argc, char *argv[])
{

	char * currentpath;
	char buf[MAX_BUF];

	// 현재 디렉토리
	currentpath = getcwd(buf,MAX_BUF);
	list_dir (currentpath);

}

