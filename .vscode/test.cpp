#include <stdio.h>

// 依次输出所有的环境变量
int main(int argc, char *argv[], char **envp) {
  while (*envp)
    printf("%s\n", *envp++);
}