Pack.exe:结合当前目录下CstUnpackInI文件夹的配置文件以及CstUnpackTxT文件夹的剧本文件
最终合成cst文件，合成的文件将储存在Scene文件夹内

Unpack.exe:将当前目录下的Scene文件夹下的cst剧本文件导出为配置文件ini和人物对话
文件txt,分别装入到当前文件夹下的CstUnpackTxT文件夹和CstUnpackInI文件夹

导出：将含有剧本的Scene文件夹（自行创建，里面装入cst剧本）放于Unpack.exe同级目录，之后运行Unpack.exe即可导出文本
（将在当前目录下创建含有配置的CstUnpackInI文件夹以及含有剧本的CstUnpackTxT文件夹）

导入：将含有配置和剧本的CstUnpackInI和CstUnpackTxT文件夹放于与Pack.exe同级目录下，之后
运行Pack.exe即可合成cst剧本（将在当前目录下创建含有cst剧本的Scene文件夹）

注意：

1.重复将同一个Scene文件夹中的cst反复导入导出，否则将产生编码错误。
原因：原始Scene文件夹中的剧本（Shift_JIS编码）->Unpack.exe导出->CstUnpackTxT和CstUnpackInI文件夹(gbk编码)->Pack.exe封回->Scene文件夹(gbk编码)
可以看到，经过一次的合成后，剧本编码已经发生变化，此时不可再用于剧本导出

2.程序不含有安全性检测，请保证剧本文件的正确性，切勿对错误的剧本进行本操作。

3.对内容进行修改时请保持txt修改前后行数不变，包括空行

4.请勿修改控制字符如 '\n'    '\@'   '@'

5.请勿更改文本的编码，避免出现乱码问题

6.导入时已对某些控制字符进行替换：
隐藏人名字符'＠'，不再需要手动替换为字符'仐'
人名注释字符'※'不再需要手动替换为字符'仸'

2025.10.6更新:
修复由于忽略字符长度差异误将文本字符当作控制字符替换导致的乱码的问题