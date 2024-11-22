本章节介绍如何安装和配置环境。
# 1.安装和配置gtk环境
[点击此处](https://www.jianshu.com/p/5c387de92a87)
# 运行
在cmd或者msys中输入以下即可生成exe文件
```
gcc -Wall test.c -o test.exe `pkg-config gtk+-3.0 --cflags --libs`
```
然后双击exe即可
# 3.1相关vscode多加的配置
每次都在msys中运行，或者自己编写makefile都可以运行但是没提示，因为在vscode中编写找不到头文件位置，所以我们需要在.vscode文件中的c_cpp_properties.json文件中includePath中添加gtk的头文件目录即可
## 3.2添加方法
获取gtk方法在cmd中输入以下
```
pkg-config gtk+-3.0 --cflags --libs
```
然后稍作修改后加入进去即可之后编写代码就有提示了，如果想要vscode运行需要添加-l这种才行（比如在Linux编写c语言引用了math.h就需要加-lm），本人学艺不精。