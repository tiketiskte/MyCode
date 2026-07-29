#include <bits/stdc++.h>

using namespace std;

struct stu {
    char name[20];
    int score;
}stu, *p;

int main(void) {
    p = &stu;
    cout << "请输入学生姓名和成绩：" << endl;
    gets(stu.name);
    scanf("%d", &stu.score);
    printf("%s的成绩是%d\n", p->name, p->score);
    system("pause");
    return 0;
}