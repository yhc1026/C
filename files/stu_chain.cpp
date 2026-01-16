#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student
{ // 每个学生对应一个结构体
    int listNum = 0;
    Student *next = 0;
    char ID[20];   // 学号
    char Name[10]; // 姓名
    float Mark1;   // 语文成绩
    float Mark2;   // 数学成绩
    float Mark3;   // 英语成绩
    float Mark4;   // 计算机成绩
    float All;     // 总分
    float Average; // 平均成绩
} students[1000];
int num = 0; // 计数器
Student *head = 0;
void Copy(struct Student *arr, int i, int j)
{
    strcpy(arr[i].ID, arr[j].ID);
    strcpy(arr[i].Name, arr[j].Name);
    arr[i].Mark1 = arr[j].Mark1;
    arr[i].Mark2 = arr[j].Mark2;
    arr[i].Mark3 = arr[j].Mark3;
    arr[i].Mark4 = arr[j].Mark4;
    arr[i].All = arr[j].All;
    arr[i].Average = arr[j].Average;
}
Student *CreateList(Student *s, char *ID, char *name, float m1, float m2, float m3, float m4, int n = num)
{
    if (s)
    {
        s->next = (Student *)malloc(sizeof(Student));
        s = s->next;
        s->listNum = n;
        s->Mark1 = m1;
        s->Mark2 = m2;
        s->Mark3 = m3;
        s->Mark4 = m4;
        strcpy(s->Name, name);
        strcpy(s->ID, ID);
        s->All = m1 + m2 + m3 + m4;
        s->Average = s->All / 4.f;
        s->next = 0;
    }
    else
    {
        s = (Student *)malloc(sizeof(Student));
        s->listNum = n;
        s->Mark1 = m1;
        s->Mark2 = m2;
        s->Mark3 = m3;
        s->Mark4 = m4;
        strcpy(s->Name, name);
        strcpy(s->ID, ID);
        s->All = m1 + m2 + m3 + m4;
        s->Average = s->All / 4.f;
        s->next = 0;
    }
    return s;
}
Student *GetStu(int index)
{
    Student *s = head;
    for (size_t i = 0; i < index; i++)
    {
        if (s->next)
            s = s->next;
        else
            break;
    }
    return s;
}
Student *GetLast()
{
    Student *s = head;
    while (true)
    {
        if (!s->next)
            return s;
        s = s->next;
    }
    return 0;
}
Student *Student_SearchByName(char name[]) // 通过姓名来检索学生
{
    Student *s = head;
    while (true)
    {
        if (s)
        {
            if (strcmp(s->Name, name) == 0) // 通过strcmp函数来对比学生id，找到返回位置
            {
                return s;
            }
        }
        else
            break;
        s = s->next;
    }
    return 0; // 未找到返回 0
}
Student *Student_SearchByIndex(char id[]) // 通过学号来检索学生信息
{
    Student *s = head;
    while (true)
    {
        if (s)
        {
            if (strcmp(s->ID, id) == 0) // 通过strcmp函数来对比学生id，找到返回位置
            {
                return s;
            }
        }
        else
            break;
        s = s->next;
    }
    return 0; // 未找到返回 0
}
void Student_DisplaySingle(Student *s) // 输出表
{
    printf("%10s%10s%8s%8s%8s%10s\n", "学号", "姓名", "语文", "数学", "英语", "计算机", "总成绩", "平均成绩");
    printf("-------------------------------------------------------------\n");
    printf("%10s%10s%8.2f%8.2f%8.2f%8.2f%10.2f%10.2f\n", s->ID, s->Name,
           s->Mark1, s->Mark2, s->Mark3, s->Mark4, s->All, s->Average);
}
void inputt() // 利用循环录入学生信息
{
    char ID[20];   // 学号
    char Name[10]; // 姓名
    float Mark1;   // 语文成绩
    float Mark2;   // 数学成绩
    float Mark3;   // 英语成绩
    float Mark4;   // 计算机成绩
    float All;     // 总分
    float Average; // 平均成绩
    Student *s = head;
    while (1)
    {
        printf("请输入学号:");
        scanf("%s", &ID);
        getchar();
        printf("请输入姓名:");
        scanf("%s", &Name);
        getchar();
        printf("请输入成绩:");
        scanf("%f", &Mark1);
        getchar();
        printf("请输入成绩:");
        scanf("%f", &Mark2);
        getchar();
        printf("请输入成绩:");
        scanf("%f", &Mark3);
        getchar();
        printf("请输入成绩:");
        scanf("%f", &Mark4); // 依次输入各项数据
        getchar();
        All = Mark1 + Mark2 + Mark3 + Mark4; // 输完数据后自动计算总成绩与平均成绩
        Average = (Mark1 + Mark2 + Mark3 + Mark4) / 4;
        if (Student_SearchByIndex(ID) == 0)
        {
            if (!head)
                head = CreateList(0, ID, Name, Mark1, Mark2, Mark3, Mark4);
            else
            {
                Student *s = GetLast();
                CreateList(s, ID, Name, Mark1, Mark2, Mark3, Mark4);
            }
            num++; // 移向下一个位置
        }
        else
        {
            printf("学号重复，输入数据无效 !!!\n");
        }

        printf("是否继续?(y/n)");
        if (getchar() == 'n')
        {
            break;
        }
    }
}
void modify() // 修改成绩
{
    while (1)
    {
        char id[20];
        Student *s;
        printf("请输入要修改的学生的学号:");
        scanf("%s", &id);
        getchar();
        s = Student_SearchByIndex(id); // 调用搜查id函数，根据其返回值确定位置
        if (s == 0)
        {
            printf("学生不存在!\n");
        }
        else
        {
            printf("你要修改的学生信息为:\n");
            Student_DisplaySingle(s);
            printf("-- 请输入新值--\n");
            printf("请输入学号:");
            scanf("%s", &s->ID);
            getchar();
            printf("请输入姓名:");
            scanf("%s", &s->Name);
            getchar();
            printf("请输入语文成绩:");
            scanf("%f", &s->Mark1);
            getchar();
            printf("请输入数学成绩:");
            scanf("%f", &s->Mark2);
            getchar();
            printf("请输入英语成绩:");
            scanf("%f", &s->Mark3);
            getchar();
            printf("请输入计算机成绩:");
            scanf("%f", &s->Mark4); // 重新录入一套新的数据替代
            getchar();
            s->All = s->Mark1 + s->Mark2 + s->Mark3 + s->Mark4;
            s->Average = (s->Mark1 + s->Mark2 + s->Mark3 + s->Mark4) / 4;
        }
        printf("是否继续?(y/n)");
        if (getchar() == 'n')
        {
            break;
        }
    }
}
void deletee() // 删除学生信息
{
    int i;
    while (1)
    {
        char id[20];
        Student *s;
        printf("请输入要删除的学生的学号:");
        scanf("%s", &id);
        getchar();
        s = Student_SearchByIndex(id); // 调用搜查id函数，根据其返回值确定位置
        if (s == 0)
        {
            printf("学生不存在!\n");
        }
        else
        {
            printf("你要删除的学生信息为:\n");
            Student_DisplaySingle(s);
            printf("是否真的要删除?(y/n)");
            if (getchar() == 'y')
            {
                Student *s2 = head;
                Student *s3 = s->next;
                while (true)
                {
                    if (s2->next == s)
                    {
                        s2->next = s3;
                    }
                    if (!s2)
                        break;
                    s2 = s2->next;
                }
                while (true)
                {
                    if (s3)
                    {
                        s3->listNum--;
                    }
                    else
                        break;
                    s3 = s3->next;
                }
                num--;
            }
            getchar();
        }
        printf("是否继续?(y/n)");
        if (getchar() == 'n')
        {
            break;
        }
    }
}
void display() // 打印已录入的学生信息
{
    printf("%10s%10s%8s%8s%8s%8s%10s%10s\n", "学号", "姓名", "语文", "数学", "英语", "计算机", "总成绩", "平均成绩");
    printf("-------------------------------------------------------------\n");
    Student *s = head;

    if (!head)
        return;
    while (true)
    {
        printf("%10s%10s%8.2f%8.2f%8.2f%8.2f%10.2f%10.2f\n", s->ID, s->Name,
               s->Mark1, s->Mark2, s->Mark3, s->Mark4, s->All, s->Average);
        s = s->next;
        if (!s)
            break;
    }
    system("pause");
}
void insert() // 指定位置插入学生信息
{
    int a, b, c;
    printf("请输入你要插入的位置");
    scanf("%d", &a);
    if (a > num)
    {
        printf("输入的位置有误，请重新输入,当前共%d条数据\n", num);
        scanf("%d", &a);
    }

    b = num - 1;
    for (; b >= a - 1; b--)
    {
        // strcpy(students[b+1].ID,students[b].ID);
        // strcpy(students[b+1].Name,students[b].Name);
        // students[b+1].Mark1=students[b].Mark1;
        // students[b+1].Mark2=students[b].Mark2;
        // students[b+1].Mark3=students[b].Mark3;
        // students[b+1].Mark4=students[b].Mark4;
        // students[b+1].All=students[b].All;
        // students[b+1].Average=students[b].Average;
        Copy(students, b + 1, b); // 根据其输入的位置，将其及以后的数据向后移动一个位置
    }
    num++;
    printf("请输入学号:");
    scanf("%s", &students[a - 1].ID);
    getchar();
    printf("请输入姓名:");
    scanf("%s", &students[a - 1].Name);
    getchar();
    printf("请输入语文成绩:");
    scanf("%f", &students[a - 1].Mark1);
    getchar();
    printf("请输入数学成绩:");
    scanf("%f", &students[a - 1].Mark2);
    getchar();
    printf("请输入英语成绩:");
    scanf("%f", &students[a - 1].Mark3);
    getchar();
    printf("请输入计算机成绩:");
    scanf("%f", &students[a - 1].Mark4); // 输入新数据
    getchar();
    students[a - 1].All = students[a - 1].Mark1 + students[a - 1].Mark2 + students[a - 1].Mark3 + students[a - 1].Mark4;
    students[a - 1].Average = (students[a - 1].Mark1 + students[a - 1].Mark2 + students[a - 1].Mark3 + students[a - 1].Mark4) / 4;
}
void search() // 查询学生信息
{
    while (1)
    {
        char name[20];
        Student *s;
        printf("请输入要查询的学生的姓名:");
        scanf("%s", &name);
        getchar();
        s = Student_SearchByName(name); // 调用搜查name函数，根据其返回值确定位置
        if (s == 0)
        {
            printf("学生不存在!\n");
        }
        else
        {
            printf("你要查询的学生信息为:\n");
            Student_DisplaySingle(s);
        }
        printf("是否继续?(y/n)");
        if (getchar() == 'n')
        {
            break;
        }
    }
}
void sort() // 根据平均分排序
{
    int i = 0, j;
    Student *s = head;
    if (!head)
        return;
    while (true)
    {
        students[i].Mark1 = s->Mark1;
        students[i].Mark2 = s->Mark2;
        students[i].Mark3 = s->Mark3;
        students[i].Mark4 = s->Mark4;
        strcpy(students[i].Name, s->Name);
        strcpy(students[i].Name, s->ID);
        students[i].All = s->Mark1 + s->Mark2 + s->Mark3 + s->Mark4;
        students[i].Average = s->All / 4.f;
        s = s->next;
        i++;
        if (!s)
            break;
    }
    for (i = 0; i < num; i++)
    {
        students[i].Average = (students[i].Mark1 + students[i].Mark2 + students[i].Mark3 + students[i].Mark4) / 4;
    }

    for (i = 0; i < num; i++)
    {
        for (j = 1; j < num - i; j++)
        {
            if (students[j - 1].Average < students[j].Average)
            {

                Copy(students, num, j - 1);
                Copy(students, j - 1, j);
                Copy(students, j, num);
                // tmp=students[j-1];
                // students[j-1]=students[j];
                // students[j]=tmp;      //冒泡排序
            }
        }
    }
    int a;
    printf("%10s%10s%8s%8s%8s%10s\n", "学号", "姓名", "语文", "数学", "英语", "计算机", "总成绩", "平均成绩");
    printf("-------------------------------------------------------------\n");
    for (a = 0; a < num; a++)
    {
        printf("%10s%10s%8.2f%8.2f%8.2f%8.2f%10.2f%10.2f\n", students[a].ID, students[a].Name,
               students[a].Mark1, students[a].Mark2, students[a].Mark3, students[a].Mark4, students[a].All, students[a].Average);
    }
    system("pause");
}

void SearchLow() // 搜索不及格的并输出
{
    printf("           语文不及格的有%10s%10s%8s\n", "学号", "姓名", "语文");
    Student *s = head;
    while (true)
    {
        if (s->Mark1 < 60)
            printf("%10s%10s%8.2f\n", s->Name, s->ID, s->Mark1); // 从头搜索到尾，若小于60就输出
        s = s->next;
        if (!s)
            break;
    }
    printf("           数学不及格的有%10s%10s%8s\n", "学号", "姓名", "数学");
    s = head;
    while (true)
    {
        if (s->Mark2 < 60)
            printf("%10s%10s%8.2f\n", s->Name, s->ID, s->Mark2);
        s = s->next;
        if (!s)
            break;
    }
    printf("           英语不及格的有%10s%10s%8s\n", "学号", "姓名", "英语");
    s = head;
    while (true)
    {
        if (s->Mark3 < 60)
            printf("%10s%10s%8.2f\n", s->Name, s->ID, s->Mark3);
        s = s->next;
        if (!s)
            break;
    }
    printf("           计算机不及格的有%10s%10s%8s\n", "学号", "姓名", "计算机");
    s = head;
    while (true)
    {
        if (s->Mark4 < 60)
            printf("%10s%10s%8.2f\n", s->Name, s->ID, s->Mark4);
        s = s->next;
        if (!s)
            break;
    }
    system("pause");
}

void SearchHigh() // 搜索成绩最高者输出
{
    int max;
    printf("           语文最高分为%10s%10s%8s\n", "学号", "姓名", "语文");
    max = head->Mark1;
    Student *s = 0;
    s = head;
    while (true)
    {
        if (s->Mark1 > max)
            max = s->Mark1;
        s = s->next;
        if (!s)
            break;
    }
    s = head;
    while (true)
    {
        if (max == s->Mark1)
            printf("%10s%10s%8.2f\n", s->Name, s->ID, s->Mark1);
        s = s->next;
        if (!s)
            break;
    }
    printf("           数学最高分为%10s%10s%8s\n", "学号", "姓名", "数学");
    max = head->Mark2;
    s = head;
    while (true)
    {
        if (s->Mark2 > max)
            max = s->Mark2;
        s = s->next;
        if (!s)
            break;
    }
    s = head;
    while (true)
    {
        if (max == s->Mark2)
            printf("%10s%10s%8.2f\n", s->Name, s->ID, s->Mark2);
        s = s->next;
        if (!s)
            break;
    }

    printf("           英语最高分为%10s%10s%8s\n", "学号", "姓名", "英语");
    max = head->Mark3;
    s = head;
    while (true)
    {
        if (s->Mark3 > max)
            max = s->Mark3;
        s = s->next;
        if (!s)
            break;
    }
    s = head;
    while (true)
    {
        if (max == s->Mark3)
            printf("%10s%10s%8.2f\n", s->Name, s->ID, s->Mark3);
        s = s->next;
        if (!s)
            break;
    }

    printf("           计算机最高分为%10s%10s%8s\n", "学号", "姓名", "计算机");
    max = head->Mark4;
    s = head;
    while (true)
    {
        if (s->Mark4 > max)
            max = s->Mark4;
        s = s->next;
        if (!s)
            break;
    }
    s = head;
    while (true)
    {
        if (max == s->Mark4)
            printf("%10s%10s%8.2f\n", s->Name, s->ID, s->Mark4);
        s = s->next;
        if (!s)
            break;
    }
    system("pause");
}
void Save()
{
    FILE *fp = fopen("temp.txt", "w+");
    fprintf(fp, "%d\n", num);
    Student *s = head;
    if (!head)
        return;
    while (true)
    {
        fprintf(fp, "%s %s %f %f %f %f %f %f\n", s->ID, s->Name, s->Mark1, s->Mark2, s->Mark3, s->Mark4, s->All, s->Average);
        s = s->next;
        if (!s)
            break;
    }
    fclose(fp);
}
void Load()
{
    FILE *fp = fopen("temp.txt", "r");
    if (!fp)
        return;
    fscanf(fp, "%d", &num);
    char ID[20];   // 学号
    char Name[10]; // 姓名
    float Mark1;   // 语文成绩
    float Mark2;   // 数学成绩
    float Mark3;   // 英语成绩
    float Mark4;   // 计算机成绩
    float All;     // 总分
    float Average; // 平均成绩
    Student *s = head;
    for (int i = 0; i < num; i++)
    {
        fscanf(fp, "%s %s %f %f %f %f %f %f\n", ID, Name, &Mark1, &Mark2, &Mark3, &Mark4, &All, &Average);
        if (!head)
        {
            head = CreateList(0, ID, Name, Mark1, Mark2, Mark3, Mark4, i);
        }
        else
        {
            s = GetLast();
            s = CreateList(s, ID, Name, Mark1, Mark2, Mark3, Mark4, i);
        }
    }
    fclose(fp);
}
/*主程序*/

int main()
{
    int i;
    Load();
    while (1)
    {

        printf("\t\t\t\t\t-------- 学生成绩管理系统-------\n\n\n\n"); // 菜单
        printf("\t\t\t\t\t1. 增加学生记录\n\n");
        printf("\t\t\t\t\t2. 修改学生记录\n\n");
        printf("\t\t\t\t\t3. 删除学生记录\n\n");
        printf("\t\t\t\t\t4. 插入学生记录\n\n");
        printf("\t\t\t\t\t5. 显示所有记录\n\n");
        printf("\t\t\t\t\t6. 查询学生记录\n\n");
        printf("\t\t\t\t\t7. 按平均成绩排序\n\n");
        printf("\t\t\t\t\t8. 输出各科目不及格学生\n\n");
        printf("\t\t\t\t\t9. 输出各科目最高分\n\n");
        printf("\t\t\t\t\t0. 退出\n\n\n");
        printf("请选择(0-9):");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            inputt();
            break;
        case 2:
            modify();
            break;
        case 3:
            deletee();
            break;
        case 4:
            insert();
            break;
        case 5:
            display();
            break;
        case 6:
            search();
            break;
        case 7:
            sort();
            break;
        case 8:
            SearchLow();
            break;
        case 9:
            SearchHigh();
            break;
        case 0:
            exit(0);
        default:;
        }
        Save();
    }
    return 0;
}