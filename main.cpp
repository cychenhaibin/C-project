#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"    //����Ҫ���س�ȷ�ϣ�scanf��getchar����Ҫ���س�ȷ��
void regist();
void login();
void welcome();
void keykeyDown();
void keyDown();
//int flag=0;
/**
 * @brief ��ӡǰ���ʽ��Ϊ����ʾ��Ծ���
 * @author �º���
 * @date 2023/4/29
 */
void format()
{
    printf("\t                               ");
}
void pattern()
{
    printf("|                                            |\n");
}
/**
 * @brief ��format��printf()�ٴη�װ������ʽ��ӡһ���ַ���
 * @author �º���
 * @date 2023/5/2
 */
void format_p(char *str){
    format();
    printf(str);
}
/**
 * @brief �û��ṹ��
 * @author �º���
 * @date 2023/5/2
 */
typedef struct user
{
    char name[20];//�û���
    char password[20];//����
}USER;

struct userLink{//�û�����
    struct user data;
    struct userLink *next;//ָ��ָ��ṹ��
};

/**
 * @brief ѧ���ṹ��
 * @author �º���
 * @date 2023/4/29
 */
struct Student
{
    //ѧ������ ���� �꼶 ѧ�� ¼ȡ���� ��� ���� Ժϵ ��Դ��
    char name[10];     //����
    int age;           //����
    int grade;         //�꼶
    char education[10];//ѧ��
    int score;         //¼ȡ����
    int height;        //���
    float weight;      //����
    char college[50];  //Ժϵ
    char ofStudent[20];//��Դ��
};
//ѧ������->�������йصĶ�Ҫ��
/*struct Node
{
    int data;
    struct Node* next;
};
 */
struct Node
{
    struct Student data;
    struct Node* next;
};
//����һ��Ϊ�յ�����
struct Node* list = NULL;
//��������->�õ�һ������ʾ��������
//����һ���ṹ�����
struct Node* createList()
{
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    //����ʹ��ǰҪ��ʼ��
    //�������б�ͷ������Ҫ���컯������һ�����������
    /*if (headNode == NULL)//�ж����ڴ治��
    {
        return NULL;
    }*/
    headNode->next = NULL;
    return headNode;
}

void startInfo(){
    system("cls");
    printf("\n\n\n\n");
    format();
    printf("����������������������������������������������������������������������������\n");
    format();
    printf("|                                    |\n");
    format();
    printf("|                                    |\n");
    format();
    printf("|  ��ӭ���������ʵ��ѧѧ������ϵͳ  |\n");
    format();
    printf("|                                    |\n");
    format();
    printf("|                                    |\n");
    format();
    printf("|               1.ע��               |\n");
    format();
    printf("|                                    |\n");
    format();
    printf("|                                    |\n");
    format();
    printf("|               2.��¼               |\n");
    format();
    printf("|                                    |\n");
    format();
    printf("|                                    |\n");
    format();
    printf("|               0.�˳�               |\n");
    format();
    printf("|                                    |\n");
    format();
    printf("|                                    |\n");
    format();
    printf("|      �������Ӧ�����ֽ��빦�ܣ�    |\n");
    format();
    printf("|                                    |\n");
    format();
    printf("����������������������������������������������������������������������������\n");
    //format();
    keykeyDown();
    format();
    /*int n;
    while (scanf_s("%d",&n)!=1 || !(n==1||n==2||n==0))
    {
        format();
        printf("��������,����������\n");
        format();
        fflush(stdin);//���������
    }
    switch (n)
    {
        case 1:regist();
            break;
        case 2:login();
            break;
        case 0:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n");
            format();
            printf("��лʹ�������ʵ��ѧѧ������ϵͳ\n");
            format();
            printf("��ӭ�ٴ�ʹ�ã��ݰݣ�\n");
            system("pause");
            exit(0);
            break;
    }*/
}
void keykeyDown()
{
    format();
    char userKey = getch();//����Ҫ���س�ȷ�ϣ�scanf��getchar����Ҫ���س�ȷ��
    switch (userKey)
    {
        case '1':
            regist();
            break;
        case '2':
            login();
            break;
        case '0':
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n");
            format();
            printf("��лʹ�������ʵ��ѧѧ������ϵͳ\n");
            format();
            printf("��ӭ�ٴ�ʹ�ã��ݰݣ�\n");
            format();
            system("pause");
            exit(0);
            break;
        default:
            //format();
            printf("��������,����������\n");
            format();
            system("pause");
            startInfo();
            fflush(stdin);//���������
    }
}

//ע��ģ��
void regist(){
    USER oldUser;
    USER newUser;
    char name[20];
    system("cls");
    format();
    printf("��������Ҫע����û���:\n");
    format();
    scanf("%s",name);
    FILE* fd = NULL;
    fd = fopen("UserList.txt","rb");//���˺��ļ�  �򿪶������ļ���
    while (fread(&oldUser,sizeof(USER),1,fd))//����������ݣ����ж��û����Ƿ�һ��
    {
        if (strcmp(oldUser.name,name)==0)
        {
            //��������û������б��д���
            format();
            printf("���û������ڣ����������룡����\n");
            format();
            scanf("%s",name);
            fseek(fd,0,SEEK_SET);//���ļ�ָ�����¶�λ����ͷ
        }
    }
    fclose(fd);
    fd = NULL;
    //ȫ�������꣬����û�
    strcpy(newUser.name,name);
    format();
    printf("��������������:\n");
    format();
    scanf("%s",newUser.password);
    format();
    FILE* fw = NULL;
    fw = fopen("UserList.txt","ab");//���ļ�����������ݶ���һ���������ļ�
    fwrite(&newUser,sizeof(USER),1,fw);//�û���Ϣд���ļ�
    fclose(fw);
    fw = NULL;
    //format();
    printf("ע�����\n");
    format();
    system("pause");
    system("cls");
    startInfo();//�ص���ʼ����
    system("pause");
    //flag=1;
}


/**
 * @brief ��¼ģ��
 * @author �º���
 * @date 2023/5/2
 */

void login(){
    system("cls");
    USER userTemp;//��ȡ�û�
    format_p("�����������û���:\n");
    char name[20],password[20];
    format();
    scanf("%s",name);
    int index = 0;//������¼���˻����еڼ����û�
    FILE* fd = NULL;
    fd = fopen("UserList.txt","rb");//���˺��ļ�
    while (fread(&userTemp,sizeof(USER),1,fd))//����������ݣ����ж��û����Ƿ�һ��
    {
        index++;//ÿ��һ������¼+1
        if (strcmp(userTemp.name,name)==0)
        {
            //��������û������б��д���
            format_p("����������:\n");
            int count = 0;//�������
            do
            {
                format();
                scanf("%s",password);
                count++;
                if (strcmp(userTemp.password,password)==0)//������ȷ
                {
                    fclose(fd);//�ͷ���Դ
                    fd = NULL;
                    welcome();
                    //flag=0;
                    return;//������ȷ�⺯����������
                }
                else if(count<=3)
                {//�������
                    format_p("������󣡣���\n");
                    format();
                    printf("����������:(�㻹��%d�λ���!)\n",3-count);
                }
                else
                {//�����������
                    format_p("������󣡣�!,�����ص�������\n");
                    format();
                    system("pause");
                    startInfo();
                    //flag=1;
                }
            } while (1);//�����������3��
        }
    }
    fclose(fd);
    fd = NULL;
    //���û������ڣ���ʾ��������������
    format_p("���û������ڣ������������ص�������\n");
    format();
    system("pause");
    startInfo();
    //flag=1;
}

/**
 * @brief ��ʼ�˵�
 * @author �º���
 * @date 2023/4/29
 */
void welcome()
{
    system("cls");
    printf("\n\n\n");
    format();
    printf("��������������������������������������������������������������������������������������������\n");
    format();
    pattern();
    format();
    printf("|      ��ӭʹ�������ʵ��ѧѧ������ϵͳ      |\n");
    format();
    //printf("������������������������������������������������������������������������������������\n");
    pattern();
    format();
    printf("|               ��ѡ�����б�               |\n");
    format();
    pattern();
    format();
    printf("|               1.¼��ѧ����Ϣ               |\n");
    format();
    pattern();
    format();
    printf("|               2.���ѧ����Ϣ               |\n");
    format();
    pattern();
    format();
    printf("|               3.����ѧ����Ϣ               |\n");
    format();
    pattern();
    format();
    printf("|               4.ɾ��ѧ����Ϣ               |\n");
    format();
    pattern();
    format();
    printf("|               5.�޸�ѧ����Ϣ               |\n");
    format();
    pattern();
    format();
    printf("|               6.ѧ��������ʾ               |\n");
    format();
    pattern();
    format();
    printf("|               0.�˳�����ϵͳ               |\n");
    format();
    pattern();
    format();
    printf("|         �������Ӧ���ֽ�����Ӧ����         |\n");
    format();
    pattern();
    format();
    printf("��������������������������������������������������������������������������������������������\n");
    keyDown();
}

/**
 * @brief �����ڵ�->���û���������ݱ�ɽڵ�
 * @author �º���
 * @date 2023/4/29
 */
struct Node* createNode(struct Student data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
/**
 * @brief ��ͷ����
 * @author �º���
 * @date 2023/4/29
 */
void insertByHead(struct Node* headNode, struct Student data)
{
    //�����½ڵ�
    struct Node* newNode = createNode(data);
    newNode->next = headNode->next;
    //�½ڵ���뵽������
    headNode->next = newNode;
}

/**
 * @brief ɾ����ʽ
 * @author �º���
 * @date 2023/4/29
 */
void deleteByName(struct Node* headNode, char *posName)
{
    //��ɾ���ڵ��ͷһ���ڵ�
    struct Node* posFrontNode = headNode;
    //��һ���ڵ�
    struct Node* posNode = headNode->next;
    //��ָ��λ��
    while (posNode != NULL && strcmp(posNode->data.name,posName))
    {
        //�ƶ���������ָ��
        posFrontNode = posNode;
        posNode = posFrontNode->next;
    }
    if (posNode == NULL)
    {
        return;
    }
    //��ΪNULL���ҵ��Ϳ�����ɾ��
    //���½�����ɾ���ڵ��ǰ���ͺ�̽ڵ�Ĺ�ϵ
    //Ҫɾ����ǰ��next��ָ��ָ���һ��ָ��
    posFrontNode->next = posNode->next;
    //�ͷ�ɾ���ڵ��ڴ�
    free(posNode);
    posNode = NULL;
}

/**
 * @brief ���ҷ�ʽ
 * @author �º���
 * @date 2023/4/29
 */
struct Node* searchByName(struct Node* headNode, char *posName)
{
    // ��ǰ�ڵ����ͷ�ڵ����һ��
    struct Node* pMove = headNode->next;
    while (pMove != NULL && strcmp(pMove->data.name,posName))
    {
        pMove = pMove->next;//��pMoveָ����һ���ڵ�
    }
    return pMove;
}

/**
 * @brief ��ӡ�ڵ�
 * @author �º���
 * @date 2023/4/29
 */
void printList(struct Node* headNode)
{
    system("cls");
    //����ָ�����
    struct Node* pMove = headNode->next;//��Ϊ�б�ͷ
    printf("\t");
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");
    printf("|                                         �����ʵ��ѧѧ����Ϣչʾ                                      |\n");
    printf("\t");
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");
    printf("|����\t����\t�꼶\tѧ��\t¼ȡ����\t���\t����\tԺϵ\t\t\t\t��Դ��\t|\n");
    while (pMove != NULL)
    {
        printf("\t|%s\t%d\t%d\t%s\t%d\t\t%d\t%.2f\t%s\t\t\t%s\t|\n",
               pMove->data.name,
               pMove->data.age,
               pMove->data.grade,
               pMove->data.education,
               pMove->data.score,
               pMove->data.height,
               pMove->data.weight,
               pMove->data.college,
               pMove->data.ofStudent
        );
        //ָ�����
        pMove = pMove->next;
    }
    printf("\t");
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    format();
}



/**
 * @brief �������е�����д���ļ���
 * @author �º���
 * @date 2023/4/29
 */
void saveInfoToFile(struct Node* headNode, char *fileName)
{
    //����һ���ļ�ָ�룬���ļ�
    FILE *fp = fopen(fileName, "w");
    //��NULL����

    //fprintf ��ʽ����д
    //�ӵڶ����ڵ㿪ʼ�������е����ݴ�ӡ���ļ�����
    struct Node* pMove = headNode->next;
    while (pMove != NULL)
    {
        fprintf(fp, "%s\t%d\t%d\t%s\t%d\t\t%d\t%.2f\t%s\t\t\t%s\n",
                pMove->data.name,
                pMove->data.age,
                pMove->data.grade,
                pMove->data.education,
                pMove->data.score,
                pMove->data.height,
                pMove->data.weight,
                pMove->data.college,
                pMove->data.ofStudent
        );
        //ָ�������ߣ�������һ��
        pMove = pMove->next;
    }
    //�ر��ļ�
    fclose(fp);
}

/**
 * @brief ��һ����Ҫ���ļ��е����ݶ���������ȥ
 * @author �º���
 * @date 2023/4/29
 */
void readInfoFromFile(struct Node* headNode, char *fileName)
{
    FILE *fp = fopen(fileName, "r");
    //��NULL����
    if (fp == NULL)//�տ�ʼ����ʱ�򻺴��ļ�������
    {
        //���д�������ʽ���ļ�
        fp = fopen(fileName, "w+");//�ɶ���д+��������
    }
    //fscanf
    struct Student data;
    while (fscanf(fp, "%s\t%d\t%d\t%s\t%d\t\t%d\t%f\t%s\t\t\t%s\n",
                  data.name,
                  &data.age,
                  &data.grade,
                  data.education,
                  &data.score,
                  &data.height,
                  &data.weight,
                  data.college,
                  data.ofStudent) != EOF)//EOF�ļ��������-1
    {
        insertByHead(headNode, data);//��data���뵽������ȥ
    }
    //�ر��ļ�
    fclose(fp);
}

/**
 * @brief ����ð������1.ɨ����������2.���ڵ�Ԫ���໥�Ƚ�
 * @author �º���
 * @date 2023/4/29
 */
void bubbleSortAge(struct Node* headNode)
{
    //�ƶ���ָ��
    struct Node* firstNode = headNode->next;
    struct Node* secondNode = headNode;
    while (firstNode != NULL)
    {
        while (firstNode->next != NULL)
        {
            if (firstNode->data.age>firstNode->next->data.age)
            {
                //ֻ��Ҫ�����ڵ������
                struct Student tempData;
                tempData= firstNode->data;//��ŵ�һ���ڵ��������
                firstNode->data = firstNode->next->data;//��һ����ŵڶ���
                firstNode->next->data = tempData;//�ڶ����ڵ�ŵ�һ������
            }
            firstNode = firstNode->next;
        }
        //���ڵ�
        firstNode = secondNode->next;
        secondNode = firstNode;
    }
}
void bubbleSortGrade(struct Node* headNode)
{
    struct Node* firstNode = headNode->next;
    struct Node* secondNode = headNode;
    while (firstNode != NULL)
    {
        while (firstNode->next != NULL)
        {
            if (firstNode->data.grade>firstNode->next->data.grade)
            {
                //ֻ��Ҫ�����ڵ������
                struct Student tempData;
                tempData= firstNode->data;
                firstNode->data = firstNode->next->data;
                firstNode->next->data = tempData;
            }
            firstNode = firstNode->next;
        }
        firstNode = secondNode->next;
        secondNode = firstNode;
    }
}
void bubbleSortScore(struct Node* headNode)
{
    struct Node* firstNode = headNode->next;
    struct Node* secondNode = headNode;
    while (firstNode != NULL)
    {
        while (firstNode->next != NULL)
        {
            if (firstNode->data.score<firstNode->next->data.score)
            {
                //ֻ��Ҫ�����ڵ������
                struct Student tempData;
                tempData= firstNode->data;
                firstNode->data = firstNode->next->data;
                firstNode->next->data = tempData;
            }
            firstNode = firstNode->next;
        }
        firstNode = secondNode->next;
        secondNode = firstNode;
    }
}
void bubbleSortHeight(struct Node* headNode)
{
    struct Node* firstNode = headNode->next;
    struct Node* secondNode = headNode;
    while (firstNode != NULL)
    {
        while (firstNode->next != NULL)
        {
            if (firstNode->data.height>firstNode->next->data.height)
            {
                //ֻ��Ҫ�����ڵ������
                struct Student tempData;
                tempData= firstNode->data;
                firstNode->data = firstNode->next->data;
                firstNode->next->data = tempData;
            }
            firstNode = firstNode->next;
        }
        firstNode = secondNode->next;
        secondNode = firstNode;
    }
}
void bubbleSortWeight(struct Node* headNode)
{
    struct Node* firstNode = headNode->next;
    struct Node* secondNode = headNode;
    while (firstNode != NULL)
    {
        while (firstNode->next != NULL)
        {
            if (firstNode->data.weight>firstNode->next->data.weight)
            {
                //ֻ��Ҫ�����ڵ������
                struct Student tempData;
                tempData= firstNode->data;
                firstNode->data = firstNode->next->data;
                firstNode->next->data = tempData;
            }
            firstNode = firstNode->next;
        }
        firstNode = secondNode->next;
        secondNode = firstNode;
    }
}
/**
 * @brief ��������
 * @author �º���
 * @date 2023/4/29
 */

void keyDown()
{
    struct Student data;//��ʱ�洢��Ϣ
    struct Node* result = NULL;//������ʱָ��洢���ҽ��
    format();
    char studentKey = getch();//����Ҫ���س�ȷ�ϣ�scanf��getchar����Ҫ���س�ȷ��
    switch (studentKey)
    {
        case '1':
            /**
            * @brief ���ѧ����Ϣ
            * @author �º���
            * @date 2023/4/29
            */
            system("cls");
            format();
            printf("������ѧ������:\n");
            format();
            scanf("%s",data.name);

            format();
            printf("������ѧ������:\n");
            format();
            scanf("%d",&data.age);

            format();
            printf("������ѧ���꼶:\n");
            format();
            scanf("%d",&data.grade);

            format();
            printf("������ѧ��ѧ��:\n");
            format();
            scanf("%s",data.education);

            format();
            printf("������¼ȡ�ɼ�:\n");
            format();
            scanf("%d",&data.score);

            format();
            printf("������ѧ�����:\n");
            format();
            scanf("%d",&data.height);

            format();
            printf("������ѧ������:\n");
            format();
            scanf("%f",&data.weight);

            format();
            printf("������ѧ��ѧԺ:\n");
            format();
            scanf("%s",data.college);

            format();
            printf("������ѧ����Դ��:\n");
            format();
            scanf("%s",data.ofStudent);

            format();
            printf("¼��ѧ����Ϣ�ɹ���\n");
            //��������
            insertByHead(list, data);
            format();
            //��ͣ
            system("pause");
            //����
            system("cls");
            //�����ļ�
            saveInfoToFile(list, "Student.txt");
            break;
        case '2':
            //���ѧ����Ϣ
            printList(list);
            //welcome();
            system("pause");
            //welcome();
            break;
        case '3':
            /**
            * @brief ����ѧ����Ϣ
            * @author �º���
            * @date 2023/4/29
            */
            system("cls");
            format();
            printf("������Ҫ���ҵ�ѧ��������:\n");
            format();
            scanf("%s",data.name);//������ʱ������
            result = searchByName(list, data.name);
            if (result == NULL)
            {
                format();
                printf("���޴���\n");
            }
            else
            {
                printf("\t");
                printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
                printf("\t");
                printf("|����\t����\t�꼶\tѧ��\t¼ȡ����\t���\t����\tԺϵ\t\t\t\t��Դ��\t|\n");
                printf("\t|%s\t%d\t%d\t%s\t%d\t\t%d\t%.2f\t%s\t\t\t%s\t|\n",
                       result->data.name,
                       result->data.age,
                       result->data.grade,
                       result->data.education,
                       result->data.score,
                       result->data.height,
                       result->data.weight,
                       result->data.college,
                       result->data.ofStudent
                );
                printf("\t");
                printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            }
            format();
            system("pause");
            break;
        case '4':
            /**
            * @brief ɾ��ѧ����Ϣ
            * @author �º���
            * @date 2023/4/29
            */
            system("cls");
            format();
            printf("������Ҫɾ����ѧ��������:\n");
            format();
            scanf("%s", data.name);
            format();
            deleteByName(list, data.name);
            printf("�����ɹ�!");
            saveInfoToFile(list, "Student.txt");
            break;
        case '5':
            /**
            * @brief �޸�ѧ����Ϣ
            * @author �º���
            * @date 2023/4/29
            */
            system("cls");
            format();
            printf("������Ҫ�޸ĵ�ѧ��������:\n");
            format();
            scanf("%s",data.name);
            format();
            result = searchByName(list, data.name);
            if (result == NULL)
            {
                printf("���޴��ˣ��޷��޸ģ�\n");
                format();
            }
            else
            {
                printf("������Ҫ�޸ĵ���Ϣ(����|����|�꼶|ѧ��|¼ȡ����|���|����|Ժϵ|��Դ��)\n");
                format();
                scanf("%s%d%d%s%d%d%f%s%s",
                      result->data.name,
                      &result->data.age,
                      &result->data.grade,
                      result->data.education,
                      &result->data.score,
                      &result->data.height,
                      &result->data.weight,
                      result->data.college,
                      result->data.ofStudent
                );
                format();
                printf("�޸ĳɹ���");
                saveInfoToFile(list, "Student.txt");
            }
            break;
        case '6':
            /**
            * @brief ѧ��������ʾ
            * @author �º���
            * @date 2023/4/29
            */
            system("cls");
            char arr[4];
            format_p("����������ʽ(����/�꼶/¼ȡ����/���/����):\n");
            format();
            scanf("%s",arr);
            if (strcmp(arr, "����")==0)
            {
                bubbleSortAge(list);
                printList(list);
                system("pause");
            }
            else if (strcmp(arr, "�꼶")==0)
            {
                bubbleSortGrade(list);
                printList(list);
                system("pause");
            }
            else if (strcmp(arr, "¼ȡ����")==0)
            {
                bubbleSortScore(list);
                printList(list);
                system("pause");
            }
            else if (strcmp(arr, "���")==0)
            {
                bubbleSortHeight(list);
                printList(list);
                system("pause");
            }
            else if (strcmp(arr, "����")==0)
            {
                bubbleSortWeight(list);
                printList(list);
                system("pause");
            }
            else
            {
                format_p("����������������룡");
                system("pause");
            }
            break;

        case '0':
            /**
            * @brief �˳�ϵͳ
            * @author �º���
            * @date 2023/4/29
            */
            //startInfo();
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n");
            format();
            printf("��лʹ�������ʵ��ѧѧ������ϵͳ\n");
            format();
            printf("��ӭ�ٴ�ʹ�ã��ݰݣ�\n");
            format();
            system("pause");//��ֹ����
            exit(0);
            break;
        default:
            printf("�����������������룡\n");
            format();
            system("pause");
            fflush(stdin);//���������
            break;
    }
    //welcome();
}

int main()
{
    list = createList();//��ʼ��������һ��list
    readInfoFromFile(list, "Student.txt");
    startInfo();
    //keykeyDown();
    /*while(flag==1)
    {
        startInfo();
        //keykeyDown();
    }*/
    while(1)
    {
        welcome();
        //keyDown();
        //system("pause");
        system("cls");
    }
    getchar();
    return 0;
}
