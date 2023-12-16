#pragma once
#include<windows.h>
#include<vector>
#include<queue>
#include"zlib.h"
#pragma comment(lib,"zlib.lib")
#define TRANS_BYTE 1
#define TRANS_BIT 0
//BYTE* RLEcompress(BYTE* src, DWORD& size);//rel压缩
//BYTE* RLEuncompress(BYTE* scr, DWORD& size);//rle解压
//BYTE* ZlibCompress(BYTE* scr, DWORD& size);//zlib压缩
//BYTE* ZlibUncompress(BYTE* scr, DWORD& size);//zlib解压
//BYTE* Data_to_Bit(BYTE* data, DWORD& size);//数据转比特
//DWORD* cEliasGammaCode(BYTE* data, DWORD& size);//EliasGammaCode解压
//BYTE* uEliasGammaCode(DWORD* data, DWORD& size);//EliasGammaCode压缩
//void  CompleteReversee(BYTE* data, DWORD size);//函数逆置
//std::vector<mpair> GetHuffmanCode(int* precode, DWORD* frequens, DWORD arraysize);//哈夫曼编码
// //BYTE* data_reform(BYTE*data,DWORD size)://数据重洗
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////RLE压缩
BYTE* RLEcompress(BYTE* src, DWORD& size)//将数据src以RLE形式压缩，size将更新为新的值数据大小值
{
	if (!src)
		return nullptr;
	BYTE* compressed = new BYTE[size * 2];
	DWORD count = 0;
	DWORD ptr = 0; DWORD pre = src[0];
	for (int i = 0; i < size; i++)
	{
		if (src[i] != pre)
		{
			compressed[ptr] = count;
			compressed[ptr + 1] = pre;
			ptr = ptr + 2;
			pre = src[i]; count = 1;
			continue;
		}
		else if ((i == size - 1) && src[i] == pre)
		{
			compressed[ptr] = count + 1;
			compressed[ptr + 1] = pre;
			size = ptr + 2;
			break;
		}
		else if ((i == size - 1) && src[i] != pre)
		{
			compressed[ptr] = count;
			compressed[ptr + 1] = pre;
			ptr = ptr + 2;
			compressed[ptr] = 1;
			compressed[ptr + 1] = src[i];
			size = ptr + 2;
			break;
		}
		count++;
	}
	BYTE* result = new BYTE[size];
	memcpy(result, compressed, size);
	delete[]compressed;
	return result;
}
//RLE解压缩（原版，未改变）
BYTE* RLEuncompress(BYTE* scr, DWORD& size)//将数据src以RLE形式解压缩，size将更新为新的值数据大小值
{
	BYTE* uncompressed = new BYTE[size * 5];//预留大小
	if (size % 2)
		return nullptr;
	DWORD ptr = 0;
	for (int i = 0; i < size / 2; i++)
	{
		for (int k = 0; k < scr[i * 2]; k++)
		{
			uncompressed[ptr] = scr[i * 2 + 1];
			ptr = ptr + 1;
		}
	}
	size = ptr;
	BYTE* result = new BYTE[size];
	memcpy(result, uncompressed, size);
	delete[]uncompressed;
	return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////zlib压缩
BYTE* ZlibCompress(BYTE* scr, DWORD& size)//请包含zlib.h并导入静态库，函数仅64位下可运行。
{
	DWORD pre = size;
	size = 9999999;
	BYTE* result = new BYTE[size];
	int a = compress(result, &size, scr, pre);
	if (a != Z_OK)
	{
		printf_s("解压错误码%d\n",a);
		delete[]result;
		return nullptr;
	}
	return result;
}
//zlib解压
BYTE* ZlibUncompress(BYTE* scr, DWORD& size)//请包含zlib.h并导入静态库，函数仅64位下可运行。
{
	DWORD pre = size;
	size =9999999;
	BYTE* result = new BYTE[size];
	int a = uncompress(result, &size, scr, pre);
	if (a!=Z_OK)
	{
		printf_s("解压错误码%d\n", a);
		delete[]result;
		return nullptr;
	}
	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////字节数组转比特位数组
BYTE* Data_to_Bit(BYTE* data, DWORD& size)
{
	BYTE* bData = new BYTE[size * 8];
	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			bData[i * 8 + k] = ((data[i] >> (7 - k))) % 2;
		}
	}
	size = size * 8;
	return bData;
}

BYTE* Bit_to_Data(BYTE* bit, DWORD& size)//比特数组转字节数组(没有单位元素1比特的数组，所以用字节数组代替)
{
	DWORD presize = size;
	size % 8 == 0 ? size = size / 8 : size=size/8+1;
	BYTE* result = new BYTE[size]();
	for (int i = 0; i < size; i++)
	{
		for (int k = 7; k >= 0; k--)
		{
			if(i * 8 + 7 - k<presize)
			result[i] += (bit[i * 8 +7-k] << k);
		}
	}
	return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////EliasGammaCode正整数编码
DWORD* uEliasGammaCode(BYTE* data, DWORD& size)//EliasGammaCode解码，size更新为返回数组的大小解码。无符号整型数组
{
	DWORD count = 0;
	DWORD* table = new DWORD[99999999]{};
	DWORD ptr = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == 1 && i + count < size)
		{
			table[ptr] = 1;
			for (int k = 1; k <= count; k++)
			{
				table[ptr] = table[ptr] * 2 + data[i + k];
			}
			i = i + count;
			ptr = ptr + 1;
			count = 0;
			continue;
		}
		count++;
	}
	size = ptr;
	DWORD* result = new DWORD[size];
	memcpy(result, table, size * 4);
	delete[]table; table = nullptr;
	return result;
}
/////////////////////////////////////////////////////////////////////用EliasGammaCode编码数字数组，并修改size大小
BYTE* cEliasGammaCode(DWORD* data, DWORD& size,DWORD TRANS_KIND)//TRANS_KIND的不同影响是否最后将编码的比特位重新转化为字节数组节省空间。
{
	BYTE* table = new BYTE[size *32]();
	DWORD ptr = 0;
	for (int k = 0; k < size; k++)
	{
		if (data[k] == 0)
			return nullptr;
		for (int i = 31; i >= 0; i--)
		{
			if ((data[k] >> i) == 1)
			{
				ptr = ptr + i;
				for (int w = i; w >= 0; w--, ptr++)
				{
					table[ptr] = (data[k] >> w) % 2;
				}
			}
		}
	}
	if (TRANS_KIND)
	{
		if (ptr % 8 != 0)
			ptr = ptr + 8 - (ptr % 8);
		size = ptr / 8;
		BYTE* result = new BYTE[ptr / 8]();
		for (int i = 0; i < ptr / 8; i++)
		{
			for (int k = 0; k < 8; k++)
			{
				result[i] = result[i] + (table[i * 8 + k] << (7 - k));
			}
		}
		delete[]table;
		return result;
	}
	BYTE* rebit = new BYTE[ptr](); size = ptr;
	memcpy(rebit, table, ptr);
	delete[]table;
	return rebit;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Reverse
void  CompleteReversee(BYTE* data, DWORD size)//将字节数组的比特位完全逆转，如10110100->00101101
{
	for (int i = 0; i < size; i++)
	{
		BYTE sample = 0;
		for (int k = 0; k < 8; k++)
		sample = sample + (((data[i] >> k) % 2) << (7 - k));
		data[i] = sample;
	}
	return;
}
void BitReverse(BYTE* data, DWORD size)//将元素按每比特逆转，每字节中的元素顺序不变
{
	for (int i = 0; i < size; i++)
		data[i] = ((data[i] % 4) << 6) + (((data[i] >> 2) % 4) << 4) + (((data[i] >> 4) % 4) << 2) + ((data[i] >> 6) % 4);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////哈夫曼编码
struct huffmannode//哈夫曼code结构体
{
	DWORD frequens = 0;
	int value = 0;
	DWORD CODE = 0;
	huffmannode* nextl = nullptr;
	huffmannode* nextr = nullptr;
	huffmannode() {}
	huffmannode(int frequens2, int value2)
	{
		frequens = frequens2;
		value = value2;
	}
};
//哈夫曼码值表
struct mpair
{
	int VALUE;
	DWORD CODE;
};
//将哈夫曼树转为哈夫曼编码放于result里面
void recode(std::vector<mpair>& result, huffmannode* n)
{
	std::queue<huffmannode*> queue;
	queue.push(n);
	while (queue.size() > 0)
	{
		if (queue.front()->nextl != nullptr)
		{
			queue.front()->nextl->CODE = queue.front()->CODE * 2;
			queue.front()->nextr->CODE = queue.front()->CODE * 2 + 1;
			queue.push(queue.front()->nextl);
			queue.push(queue.front()->nextr);
			queue.pop();
		}
		else
		{
			DWORD count = 0;
			result.push_back({ queue.front()->value, queue.front()->CODE });
			queue.pop();
		}
	}
}
//优先队列比较方法
struct compare {
	bool operator()(const huffmannode* huffmannode1, const huffmannode* huffmannode2)
	{
		return huffmannode1->frequens > huffmannode2->frequens;
	}
};
//主方法，结果已经根据了哈夫曼码值的长度进行了排序
std::vector<mpair> GetHuffmanCode(int* precode, DWORD* frequens, DWORD arraysize)
{
	std::priority_queue<huffmannode*, std::vector<huffmannode*>, compare> queue;
	huffmannode** arr = new huffmannode * [arraysize]();
	for (int i = 0; i < arraysize; i++)
	{
		arr[i] = new huffmannode(frequens[i], precode[i]);
		queue.push(arr[i]);
	}
	while (queue.size() != 1)
	{
		huffmannode* father = new huffmannode();
		father->frequens += queue.top()->frequens;
		father->nextr = (huffmannode*)(queue.top());
		queue.pop();
		father->frequens += queue.top()->frequens;
		father->nextl = (huffmannode*)(queue.top());
		queue.pop();
		queue.push(father);
	}
	std::vector<mpair>s1;
	recode(s1, queue.top());
	return s1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////数据重洗
BYTE* data_reform(BYTE* data, DWORD size)//数据大小为4的倍数才可重洗
{
	if (size % 4)
	{
		printf("数据大小为4的倍数才可重洗");
		return nullptr;
	}
	BYTE* BIT1 = data;
	BYTE* BIT2 = BIT1 + size / 4;
	BYTE* BIT3 = BIT2 + size / 4;
	BYTE* BIT4 = BIT3 + size / 4;
	BYTE* result = new BYTE[size]();
	DWORD ptr = 0;
	for (int i = 0; i < size; i++)
	for (int k = 0; k < 4; k++)
	result[i] = ((BIT1[i] >> (6 - k * 2)) << 6) + ((BIT2[i] >> (6 - k * 2)) << 4) + ((BIT3[i] >> (6 - k * 2)) << 2) + (BIT4[i] >> (6 - k * 2));
	return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////重洗还原
BYTE* reform_back(char* data, DWORD size)//数据大小为4的倍数才可还原
{
	if (size % 4)
	{
		printf("数据大小为4的倍数才可还原");
		return nullptr;
	}
	BYTE* BIT1 = new BYTE[size * 4]();
	BYTE* BIT2 = BIT1 +size/4;
	BYTE* BIT3 = BIT2 + size / 4;
	BYTE* BIT4 = BIT3 + size / 4;
	DWORD ptr = 0;
	for (int i = 0; i < size / 4; i++, ptr++)
	{
		for (int k = 0; k < 4; k++)
		{
			BIT1[i] += ((data[i * 4 + k] >> 6) % 4) << (6 - k * 2);
			BIT2[i] += ((data[i * 4 + k] >> 4) % 4) << (6 - k * 2);
			BIT3[i] += ((data[i * 4 + k] >> 2) % 4) << (6 - k * 2);
			BIT4[i] += (data[i * 4 + k] % 4) << (6 - k * 2);
		}
	}
	return BIT1;
}