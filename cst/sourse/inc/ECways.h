#ifndef HS_PACK
#define HS_PACK
#include<Windows.h>

//���ܻ�������ݷ���(����Ϊ�ֽ�����)
//Data:����
//Size:�������鳤�ȣ�����������С��
class REdata
{
public:
	BYTE* data;
	DWORD size;
	~REdata();
};


// dCompress����ѹ��
// dUncompress���ݽ�ѹ
class ECways
{
public:

	//zlibѹ��
	//Data:��Ҫ���������
	//Size:�������鳤�ȣ�����������С��
	//Levelѹ�����𣺿�����-1��9��    
	//-1 Ĭ��ѹ��
	//0 ��ѹ��
	//1--9ѹ��������ߵ��ٶ��½�
	static REdata* dCompress_Zlib(BYTE* Data, DWORD Size, int Level);

	//zlib��ѹ
	//Data:��Ҫ���������
	//Size:�������鳤�ȣ�����������С��
	//MaxSize:��������ѹ��С����Ҫ�û�������
	//�����zlib.h�����뾲̬�⣬������64λ�¿����С�
	static REdata* dUncompress_Zlib(BYTE* Data, DWORD Size, DWORD MaxSize);
};

#endif HS_PACK