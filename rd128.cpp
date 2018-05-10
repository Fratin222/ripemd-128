#include"rd128.h"

/*
*****************************************************************************************************

	argv[1] - mode 
1 - hash of a string
2 - hash of a file

 argv[2] -string or the path to the file respectively

*****************************************************************************************************
*/




int main(int argc, char *argv[])
{

	if (argc == 1)
	{
		std::cout << "\nError: please choose mode";
		return 0;
	}
	else
	{
		switch (*argv[1])
		{
		//case of the string
		case '1':
		{
			char *p = argv[2];
			std::cout << "\nSize of the string: " << strlen(p);
			RD128 qwe(p, strlen(p));
			qwe.result();
			break;
		}
		//case of the file
		case '2':
		{
			FILE * fp = fopen(argv[2], "rb");
			fseek(fp, 0, SEEK_END);
			size_t size = ftell(fp);
			fseek(fp, 0, SEEK_SET);
			std::cout << "\nSize of the file: " << size <<"b   |   "<<(float)size/ 1048576<<"Mb"<< std::endl;
			std::cout << "\nNumber of chunks: " << (float)size / 64 + 1<<std::endl;
			char * p_data = new char[size];
			fread(p_data, size, 1, fp);
			fclose(fp);
			double first = clock();
			RD128 test(p_data, size);
			test.result();
			std::cout << "Time: " << (double)((clock() - first) / CLOCKS_PER_SEC) <<" sec\n"<< std::endl;
			delete[] p_data;
			break;
		}
		}
	}
	


	system("pause");
	return 0;
}