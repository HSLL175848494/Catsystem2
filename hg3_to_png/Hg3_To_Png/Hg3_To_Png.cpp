#include"MainWay_Nomalway.h"
#include<stdio.h>
int main() {
	SIGN://goto标记
	printf("请输入对应值转变当前目录下的hg3图片:\n1.只提取hg3配置文件\n\n2.提取配置文件，并将图片转化为bitmap图片\n");
	printf("(bitmap图片确实可以储存透明色，但是该通道本意是预留通道，并非真正的alpha透明通道。\n导出显示比特图大面积黑色属于是正常现象，因为软件并为将该通道识别为透明色通道)\n\n");
	printf("3.提取配置文件，并将其转化为png图片\n\n4.还原hg3图片：请另创建一个文件夹(放入同属于一张hg3图片的所有png图片和配置文件)\n 再将该文件放于当前目录下,合成之后的图片将命名为所创文件夹名\n");
	printf("请务必保证png图片数量与ini配置数量一致,否则程序将意外终止\n\n");
	scanf_s("%d",&mode);
	if (mode > 4 || mode <= 0)
	{
		system("cls");//清理控制台界面
		printf("请输入正确值!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
		goto SIGN;
	}
	trans_hg3();
	printf("\n3秒后自动关闭当前界面\n");
	Sleep(3000);//休眠一段时间，方便观察转化结果
	return 0;
}