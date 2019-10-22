// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"
#include "iostream"
using namespace std;

int main(int argc,char* argv[])
{
	//string path = argv+1;
	freopen(argv[1],"r",stdin);
	freopen("out1.txt","w",stdout);
	//printf("hello");
	string s;
	int num[27]={0},sum=0;
	char e='a';
	double fre[27];
	while (cin>>s) {//printf(":sdfsdjk");
		for (int i = 0; i < s.size(); i++)
			if (isalpha(s[i]))
			num[tolower(s[i])-'a']++,sum++;
		
	}
	for (int i = 0; i < 26; i++) {
			fre[i] = 1.0*num[i] / sum;
			printf("%c: %lf\n", e + i, fre[i]);//printf(":sdfsdjk");
		}
	
	getchar();

	fclose(stdin);
	fclose(stdout);
    return 0;
}


