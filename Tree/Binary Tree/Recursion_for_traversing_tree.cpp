node  * root;
node  * create()
{
    if(temp==NULL)
    {
        return NULL;
    }
    else
    {
        while(temp!=NULL)
            {
                if(temp->data>d)
                    temp=temp->left;
                else
                {
                    if(temp->data<d)
                        temp=temp->right;
                }    
            }
        return temp;    
    }
}