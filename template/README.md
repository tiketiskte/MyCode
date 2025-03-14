# 使用方式

## 编译方式

本模板推荐使用本地编译环境进行编译，经测试Overleaf编译运行效果也很好

本地编译需要安装TeXLive工具包，使用**XeLaTex**引擎

## 参考文献

在`thebibliography`环境中添加参考文献，然后在前文引用即可。

1. 不上浮的引用序号：`\cite{}`
2. 上浮的引用序号：`\textsuperscript{\cite{}}`

**注意**：需要运行两次才能正常出现序号

## 个人信息页

个人信息页及中英文封面页，本模板提供了非常方便的使用方式，直接根据`documentclass`中的提示修改填写即可，会自动补全下划线。

如果需要调整个人信息部分下划线的宽度。前往`settings/cover.tex`找到“第一页大封面”的`tabularx`环境（本模板使用表格的方式对个人信息进行标准化排版），`tabularx`环境代码示例如下所示

```tex
\begin{tabularx}{280pt}{c >{\centering}X}
学生姓名： & \uline{\hfill \StudentName\hfill}
\end{tabularx}
```

其中`280pt`表示整个表格的宽度，同学们自行调整大小即可，中英文模板都可以用该方法调整。
## 答辩信息页
答辩信息需要使用者自行填写，这是整个模板唯一需要修改的部分，前往`settings/cover.tex`找到“论文扉页”下的“答辩表格”部分，将答辩老师信息填入表格中即可。

# 文件说明

1. pic/：用于保存中航大logo图片的文件夹（勿动）
2. figures/：用于存放用于插入论文的图片
2. fonts/: 用于存放模板使用的各个字体文件，这么做会导致文件夹较大，但是能够有效解决不同系统、不同版本因字体产生的问题。
3. settings/：存放模板的各种配置文件，其中包含：
   1. commands.tex：自定义和重新定义的一些命令
   2. contents：目录格式设置
   3. cover.tex：封面页的信息
   4. fonts.tex：字体的设置以及字体命令的重定义
   5. format.tex：全文的一些一般化的格式设置，例如页眉、行距等
   6. pakages.tex：导入宏包
4. cauc_thesis.cls：所有格式、设置的汇总文件
5. cauc_thesis.tex：论文主文件
6. gbt7714-2005-numerical.bst：国标2005版参考文献引用格式（学校要求规范）
7. reference.bib：参考文献bibtex引用格式信息的储存文件
