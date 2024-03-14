#include <stdio.h>
#include <stdlib.h>

const size_t SIZE = 100;

typedef int elem_t

struct node
{
    elem_t       data;
    struct node* left;
    struct node* right;
};

struct node *create_node (elem_t data)
{
    struct node* new_node = (struct node*) calloc (1, sizeof (struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_node (struct node* root, elem_t data)
{
    if (root == NULL)
    {
        return create_node(data);
    }
    else if (data <= root->data)
    {
        root->left = insert_node(root->left, data);
    }
    else
    {
        root->right = insert_node(root->right, data);
    }
    return root;
}

struct node* search_node (struct node* root, elem_t data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data == root->data)
    {
        return root;
    }
    else if (data <= root->data)
    {
        return search_node (root->left, data);
    }
    else
    {
        return search_node (root->right, data);
    }
}

struct node* delete_node (struct node* root, elem_t data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data == root->data)
    {
        // ���� ���� �� ����� ��������, ������� ���
        if (root->left == NULL && root->right == NULL)
        {
            free (root);
            return NULL;
        }
        // ���� � ���� ���� ������ ���� �������, ������ ��� ������
        else if (root->left == NULL)
        {
            struct node* temp = root->right;
            free (root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free (root);
            return temp;
        }
        // ���� � ���� ���� ��� �������, ������� ��� ��������� � �������� �� ����
        else
        {
            struct node* temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_node (root->right, temp->data);
            return root;
        }
    }
    else if (data <= root->data)
    {
        root->left = delete_node (root->left, data);
    }
    else
    {
        root->right = delete_node (root->right, data);
    }
    return root;
}

// ������� ������ ������ � ������� ������ � ������
void print_tree_bfs (struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    struct node* queue[SIZE] = {0};
    int front = 0;
    int rear = 0;
    queue[rear++] = root;

    while (front != rear)
    {
        struct node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }
        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
}

// ������� ������ ������ � ������� ������ � ������� � ���������
void print_tree_dfs_pre (struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf ("%d ", root->data);
    print_tree_dfs_pre (root->left);
    print_tree_dfs_pre (root->right);
}

// ������� ������ ������ � ������� ������ � ������� � ��������
void print_tree_dfs_in(struct node *root)
{
   if (root == NULL)
   {
        return;
    }
    print_tree_dfs_in (root->left);
    printf ("%d ", root->data);
    print_tree_dfs_in (root->right);
}

// ������� ������ ������ � ������� ������ � ������� � ����������
void print_tree_dfs_post(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree_dfs_post (root->left);
    print_tree_dfs_post (root->right);
    printf ("%d ", root->data);
}

// ������� ������������ ������, ���������� ��� ������
void free_tree (struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree (root->left);
    free_tree (root->right);
    free (root);
}

int main() {
  // ������� ������ ������
  struct node *root = create_node (10);

  // ��������� ���� � ������
  insert_node (root, 5);
  insert_node (root, 15);
  insert_node (root, 2);
  insert_node (root, 7);
  insert_node (root, 12);
  insert_node (root, 20);

  // �������� ������ � ������� ������ � ������
  printf ("����� � ������\n");
  print_tree_bfs (root);
  printf ("\n");

  // �������� ������ � ������� ������ � ������� � ���������
  printf ("����� � ������� � ���������\n");
  print_tree_dfs_pre (root);
  printf ("\n");

  // �������� ������ � ������� ������ � ������� � ��������
  printf ("����� � ������� � ��������\n");
  print_tree_dfs_in (root);
  printf ("\n");

  // �������� ������ � ������� ������ � ������� � ����������
  printf("����� � ������� � ����������\n");
  print_tree_dfs_post (root);
  printf ("\n");

  free_tree(root);

  return 0;
}
