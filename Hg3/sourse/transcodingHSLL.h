#pragma once
#include<Windows.h>
#include<string>

WCHAR* Utf8_To_Wide(const char* str)//utf8数据转宽字节
{
	WCHAR* wide;
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);//获取str所需要宽字节空间的大小
	wide = new WCHAR[i + 1];//申请空间
	MultiByteToWideChar(CP_UTF8, 0, str, -1, wide, i);//将str中的字符装入宽字节数组wide
	return wide;//返回
}

WCHAR* Char_To_Wide(const char* str)//char转宽字节
{
	WCHAR* wide;
	int i = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);//获取str所需要宽字节空间的大小
	wide = new WCHAR[i + 1];//申请空间
	MultiByteToWideChar(CP_ACP, 0, str, -1, wide, i);//将str中的字符装入宽字节数组wide
	return wide;//返回
}

LPSTR Wide_To_Char(WCHAR* str)//宽字节转char
{
	char* wide;
	int i = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);//获取str所需要字节空间的大小
	wide = new char[i + 1];//申请空间
	WideCharToMultiByte(CP_ACP, 0, str, -1, wide, i, NULL, NULL);//将str中的字符装入字节数组wide
	return wide;//返回
}

LPSTR Utf8_To_Char(const char* str)//utf8转char
{
	WCHAR* wide;
	LPSTR ascii;
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	wide = new WCHAR[i + 1];//申请空间
	MultiByteToWideChar(CP_UTF8, 0, str, -1, wide, i);
	i = WideCharToMultiByte(CP_ACP, 0, wide, -1, NULL, 0, NULL, NULL);
	ascii= new char[i + 1];//申请空间
	WideCharToMultiByte(CP_ACP, 0, wide, -1, ascii, i, NULL, NULL);
	delete[] wide;
	return ascii;//返回
}

std::string Utf8_To_Str(const char* str)//utf8转string
{
	WCHAR* wide;
	LPSTR ascii;
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	wide = new WCHAR[i + 1];//申请空间
	MultiByteToWideChar(CP_UTF8, 0, str, -1, wide, i);
	i = WideCharToMultiByte(CP_ACP, 0, wide, -1, NULL, 0, NULL, NULL);
	ascii = new char[i + 1];//申请空间
	WideCharToMultiByte(CP_ACP, 0, wide, -1, ascii, i, NULL, NULL);
	std::string s =ascii;
	delete[] ascii;
	delete[] wide;
	return s;//返回
}

BYTE* X16_To_Code(char* head, DWORD& size)//将字符串形式的16进制代码转化为比特数组,并返回其大小(第二个参数)
{
	byte* data = new byte[50];
	int i = 0; int k = 0;
	if (strlen(head) % 2)
		return nullptr;
	while (head[i])
	{
		byte x = 0;
		if (head[i] >= 'a' && head[i] <= 'f')
		{
			x += (head[i] - 87) * 16;
		}
		else if (head[i] >= 'A' && head[i] <= 'F')
		{
			x += (head[i] - 55) * 16;
		}
		else if (head[i] >= '0' && head[i] <= '9')
		{
			x += (head[i] - 48) * 16;
		}
		else
		{
			return nullptr;
		};
		if (head[i + 1] >= 'a' && head[i + 1] <= 'f')
		{
			x += (head[i + 1] - 87);
		}
		else if (head[i + 1] >= 'A' && head[i + 1] <= 'F')
		{
			x += (head[i + 1] - 55);
		}
		else if (head[i + 1] >= '0' && head[i + 1] <= '9')
		{
			x += (head[i + 1] - 48);
		}
		else
		{
			return nullptr;
		}
		data[k] = x;
		i += 2; k++;
	}
	data[k] = '\0'; size = k;
	return data;
}

long long  X16_To_Int(char* head)//将16进制字符串转化为转化为16进制数据
{
	int i = 0; long long k = 0;
	while (head[i])
	{
		k = k * 16;
		if (head[i] >= 'a' && head[i] <= 'f')
		{
			k += (head[i] - 87);
		}
		else if (head[i] >= 'A' && head[i] <= 'F')
		{
			k += (head[i] - 55);
		}
		else if (head[i] >= '0' && head[i] <= '9')
		{
			k += (head[i] - 48);
		}
		else
		{
			return -1;
		}
		i++;
	}
	return k;
}

