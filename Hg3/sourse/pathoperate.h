#pragma once
#include<windows.h>
//去掉扩展名，即.xxx
void PathRemoveExtensionW(LPWSTR path)//去掉路径上中的文件扩展名
{
	for (int i = wcslen(path) - 1; i >= 0; i--)
	{
		if (path[i] == '.')
		{
			path[i] = '\0';
			break;
		}
		path[i] = '\0';
	}
}
//去掉路径上的指定字符
void pathremove(LPWSTR& str,LPCWSTR replace,LPCWSTR to)
{
	int length=lstrlenW(replace);
	WCHAR* result = new WCHAR[lstrlenW(str)+1]();
	for (int i = 0; i < lstrlenW(str); i++)
	{
		if (str[i] == replace[0])
		{
			int count = 1;
			for (int k = 0; k < length; k++)
			{
				if (str[i + k] != replace[k])
					count = 0;	break;
			}
			if (count)
			{
				lstrcatW(result, to);
				i += length-1;
				continue;
			}
		}
		else
		{
			result[lstrlenW(result)] = str[i];
		}
	}
	WCHAR * TrueReturn = new WCHAR[lstrlenW(result)+1];
	lstrcpynW(TrueReturn, result, lstrlenW(result) + 1);
	delete[]result;
	str = TrueReturn;
}