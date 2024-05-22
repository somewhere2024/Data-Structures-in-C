#include"MYSTL.h"

TreeNode* createNode(void* data)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); // �����½ڵ���ڴ�ռ�
    newNode->data = data; // �����ݴ洢���½ڵ���
    if (newNode == NULL)
    { // ����ڴ�����Ƿ�ɹ�
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1); // ��ʧ�ܣ����˳�����
    }
    // ��ʼ����������ָ��Ϊ��
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; // �����½ڵ�
}
TreeNode* search(TreeNode* root, void* key, int (*compare)(const void*, const void*))
{
    if (root == NULL || compare(key, root->data) == 0)
    { // �����ڵ�Ϊ�ջ��ߵ���Ŀ��ֵ
        return root; // ���ظ��ڵ�
    }
    if (compare(key, root->data) < 0)
    { // ��Ŀ��ֵС�ڸ��ڵ�ֵ
        return search(root->left, key, compare); // ���������еݹ����
    }
    else
    { // ��Ŀ��ֵ���ڸ��ڵ�ֵ
        return search(root->right, key, compare); // ���������еݹ����
    }
}

// ����ڵ�
void insert(TreeNode** root, void* data, int (*compare)(const void*, const void*))
{
    if (*root == NULL)
    {   // �����ڵ�Ϊ��
        *root = createNode(data); // �����½ڵ㲢������Ϊ���ڵ�
    }
    else
    {
        if (compare(data, (*root)->data) < 0)
        {   // ������С�ڸ��ڵ�����
            insert(&((*root)->left), data, compare); // ���������в���ڵ�
        }
        else
        {   // �����ݴ��ڵ��ڸ��ڵ�����
            insert(&((*root)->right), data, compare); // ���������в���ڵ�
        }
    }
}

// �������:��->��->�� 
void preOrder(TreeNode* root, void (*visit)(void*))
{
    if (root != NULL)
    { // �����ڵ�ǿ�
        visit(root->data); // ���ʸ��ڵ�����
        preOrder(root->left, visit); // �ݹ��������������
        preOrder(root->right, visit); // �ݹ��������������
    }
}

// �������:��->��->�� 
void inOrder(TreeNode* root, void (*visit)(void*))
{
    if (root != NULL)
    { // �����ڵ�ǿ�
        inOrder(root->left, visit); // �ݹ��������������
        visit(root->data); // ���ʸ��ڵ�����
        inOrder(root->right, visit); // �ݹ��������������
    }
}

// �������:��->��->�� 
void postOrder(TreeNode* root, void (*visit)(void*))
{
    if (root != NULL)
    { // �����ڵ�ǿ�
        postOrder(root->left, visit); // �ݹ�������������
        postOrder(root->right, visit); // �ݹ�������������
        visit(root->data); // ���ʸ��ڵ�����
    }
}

// �ȽϺ���������
int compareInt(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b); // �Ƚ��������ݣ�*(int*)a��aָ����ָ����ڴ�λ���ϴ洢������ֵ 
}

// �ȽϺ�����������
int compareFloat(const void* a, const void* b)
{
    if (*(float*)a < *(float*)b) return -1; // �Ƚϸ���������
    if (*(float*)a > *(float*)b) return 1;
    return 0;
}

// �ȽϺ������ַ���
int compareChar(const void* a, const void* b)
{
    return (*(char*)a - *(char*)b); // �Ƚ��ַ�������
}

// ���ʺ�������ӡ��������
void tree_printInt(void* data)
{
    printf("%d ", *(int*)data); // ��ӡ��������
}

// ���ʺ�������ӡ����������
void tree_printFloat(void* data)
{
    printf("%f ", *(float*)data); // ��ӡ����������
}

// ���ʺ�������ӡ�ַ�������
void tree_printChar(void* data)
{
    printf("%c ", *(char*)data); // ��ӡ�ַ�������
}

//�ͷ��ڴ� 
void freeTree(TreeNode* node)
{
    if (node != NULL)
    {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}