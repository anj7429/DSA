#include<iostream>
using namespace std;
struct node{
    int key;
    struct node *left;
    struct node *right;
};
struct node *newnode(int el){
    struct node *nnew=(struct node *)malloc(sizeof(struct node));
    nnew->key=el;
    nnew->left=NULL;
    nnew->right=NULL;
    return nnew;
}
void inorder(struct node *x){
    if(x!=NULL){
        inorder(x->left);
        cout<<x->key<<" ";
        inorder(x->right);
    }
}
void preorder(struct node *x){
    if(x!=NULL){
        inorder(x->left);
        cout<<x->key<<" ";
        inorder(x->right);
    }
}
void postorder(struct node *x){
    if(x!=NULL){
        postorder(x->left);
        postorder(x->right);
        cout<<x->key<<" ";
    }
}
struct node *insert(struct node *x,int el){
    if(x==NULL)
    return newnode(el);
    if(el<x->key){
        x->left=insert(x->left,el);
    }
    else{
        x->right=insert(x->right,el);
    }
    return x;
}
struct node *search(struct node *x,int el){
    if(x==NULL || x->key==el){
        return x;
    }
    if(el<x->key){
        return search(x->left,el);
    }
    else{
        return search(x->right,el);
    }
}
struct node *maximum(struct node *root){
    struct node *x=root;
    while(x && x->right!=NULL){
        x=x->left;
    }
    return x;
}
struct node *minimum(struct node *root){
    struct node *x=root;
    while(x && x->left!=NULL){
        x=x->right;
    }
    return x;
}
struct node *deletenode(struct node *root,int el){
    if(root==NULL){
        return root;
    }
    if(el<root->key){
        root->left=deletenode(root->left,el);
    }
    else if(el>root->key){
        root->right=deletenode(root->right,el);
    }
    else{
        // no child (leaf node)
        if(root->left==NULL){
            struct node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp=root->left;
            delete root;
            return temp;
        }
        // delete node having two child
        struct node *temp=minimum(root->right);
        root->key=temp->key;
        root->right=deletenode(root->right,temp->key);
    }
    return root;
}
struct node *successor(struct node *root,struct node *target){
    if(target->right!=NULL){
        return minimum(target->right);
    }
    struct node *succ=NULL;
    struct node *ancestor=root;
    while(ancestor!=NULL){
        if(target->key<ancestor->key){
            succ=ancestor;
            ancestor=ancestor->left;
        }
        else if(target->key>ancestor->key){
            ancestor=ancestor->right;
        }
        else{
            break;
        }
    }
    return succ;
}
int main(){
    struct node *root=NULL;
    root=insert(root,8);
    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,6);
    root=insert(root,7);
    root=insert(root,10);
    root=insert(root,19);
    root=insert(root,4);
    cout<<"INORDER TRAVERSAL: "<<endl;
    inorder(root);
    cout<<endl<<"PREORDER TRAVERSAL: "<<endl;
    preorder(root);
    cout<<endl<<"POSTORDER TRAVERSAL: "<<endl;
    postorder(root);
    struct node *min_node=minimum(root);
    cout<<endl<<"MINIMUM OF TREE: "<<min_node->key<<endl;
    struct node *max_node=maximum(root);
    cout<<endl<<"MAXIMUM OF TREE: "<<max_node->key<<endl;
    int el;
    cout<<"Enter the element you want to search: ";
    cin>>el;
    struct node *s=search(root,el);
    if(s==NULL){
        cout<<"Element not found!";}
    else{
        cout<<"Element found!";}
    struct node *target=root->left->right->right;
    struct node *succ=successor(root,target);
    if(succ){
        cout<<"\nSuccessor of "<<target->key<<" : "<<succ->key;
    }
    else{
        cout<<"\nNo Successor found for "<<target->key;
    }
    int del;
    cout<<endl<<"Enter the element you want to delete: ";
    cin>>del;
    root=deletenode(root,del);
    cout<<"Inorder traversal after deleting: "<<del<<" is "<<endl;
    inorder(root);
    return 0; 
}