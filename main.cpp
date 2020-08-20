# include <iostream>
# include <cstring>

 using namespace std;

 struct node {
    char data;
    node *next;
 };

 node *head = NULL;
 node *tail = NULL;
 node *temp;
 node *last;
 node *s_last;

 void push(const char sym) {
    temp = new node;
    temp->data = sym;
    temp->next = head;
    head = temp;
}


const char pop( ) {
    if (!head) {
        cout << "\n\n\n\tStack is empty\n" << endl;
        return ' ';
    }
    node* temp = head;
    head = head->next;
    char ch = temp->data;
    delete temp;
    return ch;
}

const bool is_empty() {
    return !head;
}

void i_to_p(const char *new_infix) {
    char infix[100]={NULL};
    char postfix[100]={NULL};

    strcpy(infix,"(");
    strcat(infix,new_infix);
    strcat(infix,")");

    char sym[5]={NULL};
    char new_temp[5]={NULL};

    for(int count=0;count<strlen(infix);count++) {
        sym[0]=infix[count];

        if(sym[0]=='(')
            push(sym[0]);

        else if(sym[0]==')') {
           sym[0]=pop( );

           while(sym[0]!='(')
              {
             strcat(postfix,sym);

             sym[0]=pop( );
              }
        }

        else if(sym[0]=='^' || sym[0]=='*' || sym[0]=='/' || sym[0]=='+' || sym[0]=='-')
        {
            if(sym[0]=='*' || sym[0]=='/')
            {
                    new_temp[0]=pop( );
                    while(new_temp[0]=='^' || new_temp[0]=='*' || new_temp[0]=='/')
                    {
                        strcat(postfix,new_temp);
                        new_temp[0]=pop( );
                    }
                    push(new_temp[0]);
            }

            else if(sym[0]=='+' || sym[0]=='-')
            {
                new_temp[0]=pop( );
                while(new_temp[0]!='(')
                {
                    strcat(postfix,new_temp);
                    new_temp[0]=pop( );
                }

                push(new_temp[0]);
            }
            push(sym[0]);
        }

        else
            strcat(postfix,sym);
      }

       cout<<"\n\n Postfix Expression : "<<postfix;
}

 int main( ) {
    char infix[100]={NULL};
    cout<<"\n\n Enter the Infix Expression : ";
    cin>>infix;
    i_to_p(infix);
    return 0;
}
