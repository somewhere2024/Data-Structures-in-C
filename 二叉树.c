#include"MYSTL.h"

TreeNode* createNode(void* data)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); // 分配新节点的内存空间
    newNode->data = data; // 将数据存储到新节点中
    if (newNode == NULL)
    { // 检查内存分配是否成功
        printf("内存分配失败！\n");
        exit(1); // 若失败，则退出程序
    }
    // 初始化左右子树指针为空
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; // 返回新节点
}
TreeNode* search(TreeNode* root, void* key, int (*compare)(const void*, const void*))
{
    if (root == NULL || compare(key, root->data) == 0)
    { // 若根节点为空或者等于目标值
        return root; // 返回根节点
    }
    if (compare(key, root->data) < 0)
    { // 若目标值小于根节点值
        return search(root->left, key, compare); // 在左子树中递归查找
    }
    else
    { // 若目标值大于根节点值
        return search(root->right, key, compare); // 在右子树中递归查找
    }
}

// 插入节点
void insert(TreeNode** root, void* data, int (*compare)(const void*, const void*))
{
    if (*root == NULL)
    {   // 若根节点为空
        *root = createNode(data); // 创建新节点并将其作为根节点
    }
    else
    {
        if (compare(data, (*root)->data) < 0)
        {   // 若数据小于根节点数据
            insert(&((*root)->left), data, compare); // 在左子树中插入节点
        }
        else
        {   // 若数据大于等于根节点数据
            insert(&((*root)->right), data, compare); // 在右子树中插入节点
        }
    }
}

// 先序遍历:根->左->右 
void preOrder(TreeNode* root, void (*visit)(void*))
{
    if (root != NULL)
    { // 若根节点非空
        visit(root->data); // 访问根节点数据
        preOrder(root->left, visit); // 递归先序遍历左子树
        preOrder(root->right, visit); // 递归先序遍历右子树
    }
}

// 中序遍历:左->根->右 
void inOrder(TreeNode* root, void (*visit)(void*))
{
    if (root != NULL)
    { // 若根节点非空
        inOrder(root->left, visit); // 递归中序遍历左子树
        visit(root->data); // 访问根节点数据
        inOrder(root->right, visit); // 递归中序遍历右子树
    }
}

// 后序遍历:左->右->根 
void postOrder(TreeNode* root, void (*visit)(void*))
{
    if (root != NULL)
    { // 若根节点非空
        postOrder(root->left, visit); // 递归后序遍历左子树
        postOrder(root->right, visit); // 递归后序遍历右子树
        visit(root->data); // 访问根节点数据
    }
}

// 比较函数：整型
int compareInt(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b); // 比较整型数据，*(int*)a：a指针所指向的内存位置上存储的整数值 
}

// 比较函数：浮点型
int compareFloat(const void* a, const void* b)
{
    if (*(float*)a < *(float*)b) return -1; // 比较浮点型数据
    if (*(float*)a > *(float*)b) return 1;
    return 0;
}

// 比较函数：字符型
int compareChar(const void* a, const void* b)
{
    return (*(char*)a - *(char*)b); // 比较字符型数据
}

// 访问函数：打印整型数据
void tree_printInt(void* data)
{
    printf("%d ", *(int*)data); // 打印整型数据
}

// 访问函数：打印浮点型数据
void tree_printFloat(void* data)
{
    printf("%f ", *(float*)data); // 打印浮点型数据
}

// 访问函数：打印字符型数据
void tree_printChar(void* data)
{
    printf("%c ", *(char*)data); // 打印字符型数据
}

//释放内存 
void freeTree(TreeNode* node)
{
    if (node != NULL)
    {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}