使用说明：
1.导出：将含有剧本的Scene文件夹放于CstUnpack.exe同级目录，运行CstUnpack.exe即可导出
（将在当前目录下创建含有配置的CstUnpackInI文件夹以及导出剧本的CstUnpackTxT文件夹）

2.导入：将含有配置和剧本的CstUnpackInI和CstUnpackTxT文件夹放于与CstPack.exe同级目录
，运行CstPack.exe即可合成cst剧本（将在当前目录下创建含有cst剧本的Scene文件夹）

CstPack.exe:结合当前目录下CstUnpackInI文件夹的配置文件 
和CstUnpackTxT文件夹的剧本文件合成cst文件，合成的文件将储存在Scene文件夹内

CstUnpack.exe:将当前目录下的Scene文件夹下的cst剧本文件导出为配置文件ini和人物对话
文件txt,分别装入到当前文件夹下的CstUnpackTxT文件夹和CstUnpackInI文件夹

注意：
1.CstUnpack.exe会将对话部分日文编码转化为gbk编码，重复将一个cst文件导出再合成
会产生编码错误（以转化为gbk编码的文字以shift_jis的读取方式再转化为gbk但实际上
cst导出后已经更改编码为中文编码）

2.请勿使用虚假的cst文件以及修改ini文件（数据出错或者其它文件改后缀为ini,cst）
程序因文件异常产生的对电脑的
损害（死机，极大内存占用）作者概不负责

3.对内容进行修改时请保持txt修改前后行数不变
对于含有标题和选择支的部分，请勿修改代码部分，仅修改日文部分
请勿删除代码符号'\n'  '\@'

User Instructions:

Export: Place the Scene folder containing the script near the CstUnpack.exe in the same directory and run CstUnpack.exe to export. (A CstUnpackInI folder containing configurations and a CstUnpackTxT folder containing exported scripts will be created in the current directory.)

Import: Place the CstUnpackInI and CstUnpackTxT folders containing configurations and scripts near the CstPack.exe in the same directory, and run CstPack.exe to synthesize the cst script (A Scene folder containing the synthesized cst script will be created in the current directory).

CstPack.exe: Combines the configuration files in the CstUnpackInI folder with the script files in the CstUnpackTxT folder in the current directory to synthesize cst files. The synthesized files will be stored in the Scene folder.

CstUnpack.exe: Exports cst script files from the Scene folder in the current directory into configuration ini files and character dialogue txt files, which are placed into the CstUnpackTxT and CstUnpackInI folders respectively.

Caution: 
1. CstUnpack.exe will convert the dialogue parts from Japanese encoding to GBK encoding. Repeatedly exporting and then recombining a cst file can lead to encoding errors (when a text already converted to GBK encoding is read with shift_jis and then converted back to GBK, even though the encoding has been changed to Chinese encoding upon export).

2.Do not use fake cst files or modify ini files (data errors or other files renamed with the ini or cst extension). The author is not responsible for any damage to the computer caused by abnormal files (system freeze, excessive memory usage).

3.When modifying the content, please keep the number of lines before and after modifying the txt file unchanged. For parts that contain titles and choice branches, do not modify the code parts, only the Japanese text. Do not delete code symbols '\n' and '\@'.

