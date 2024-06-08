功能说明：

CstPack.exe:结合当前目录下CstUnpackInI文件夹的配置文件以及CstUnpackTxT文件夹的剧本文件
最终合成cst文件，合成的文件将储存在Scene文件夹内

CstUnpack.exe:将当前目录下的Scene文件夹下的cst剧本文件导出为配置文件ini和人物对话
文件txt,分别装入到当前文件夹下的CstUnpackTxT文件夹和CstUnpackInI文件夹

使用说明：

1.导出：将含有剧本的Scene文件夹（自行创建，里面装入cst剧本）放于CstUnpack.exe同级目录，之后运行CstUnpack.exe即可导出文本
（将在当前目录下创建含有配置的CstUnpackInI文件夹以及含有剧本的CstUnpackTxT文件夹）

2.导入：将含有配置和剧本的CstUnpackInI和CstUnpackTxT文件夹放于与CstPack.exe同级目录下，之后
运行CstPack.exe即可合成cst剧本（将在当前目录下创建含有cst剧本的Scene文件夹）

！！！！！！！注意：

1.重复将同一个Scene文件夹中的cst反复导入导出，否则将产生编码错误。
原因：原始Scene文件夹中的剧本（Shift_JIS编码）->CstUnpack.exe导出->CstUnpackTxT和CstUnpackInI文件夹(gbk编码)->CstPack.exe封回->Scene文件夹(gbk编码)
可以看到，经过一次的合成后，剧本编码已经发生变化，此时不可再用于剧本导出

2.请保证剧本文件的正确性，切勿对错误的剧本进行本操作。程序不含有安全性检测，因此，由于提供错误的文件导致的一系列电脑问题，作者概不负责
举例（别特么随便拿个改了后缀为Cst的文件放到Scene文件夹里面。一旦读取错误，轻则程序没反应，重则电脑死机，或则文件损坏）导入导出一般在3秒内可以完成

3.对内容进行修改时请保持txt修改前后行数不变

4.请勿修改控制字符如 '\n'    '\@'   '@'

5.请勿擅自更改文本的编码，以免出现乱码问题

作者：黑山老赖

