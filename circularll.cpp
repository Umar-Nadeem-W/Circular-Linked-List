#include <iostream>
using namespace std;
class node{

private:

    int value;
    node* next_node;

public:

    void set_val(int v){value = v;}
    void set_next_node(node* nn){next_node = nn;}

    int get_val(){return value;}
    node* get_next_node(){return next_node;}

    node(){
    value = -1;
    next_node = NULL;}

    ~node()
    {
    delete next_node;
    }
};


class circular_ll{


    private :
        node* header;
        node* last_current_node;
        node* current_node;
        node* tail_node;
        int list_size;

    public:

        circular_ll()
        {
            header = new node();
            header->set_next_node(NULL);
            header->set_val(0);
            current_node =NULL;
            last_current_node =NULL;
            tail_node =NULL;
            list_size =0;
        }

        void create_list()
        {
        int elements;
         cout<<"Please enter the number of values you wish to store in the list."<<endl;
         cin>>elements;
         for (int i = 1; i<= elements; i++)
            {
                int myval;
             if (header->get_next_node()==NULL)
             {
               node* newnode = new node();
               cout <<"Please enter the value you wish to store at node # "<<i<<endl;
               cin>>myval;
               newnode->set_val(myval);
               header->set_next_node(newnode);
               current_node = header->get_next_node();
               last_current_node = current_node;
               current_node=newnode;
               newnode->set_next_node(header->get_next_node());
               list_size++;
             }

            else
                {
                node* newnode = new node();
                cout <<"Please enter the value you wish to store at node # "<<i<<endl;
                cin>>myval;
                newnode->set_val(myval);
                current_node->set_next_node(newnode);
                last_current_node = current_node;
                current_node = newnode;
                newnode->set_next_node(header->get_next_node());
                list_size++;
                }



            }


        }
        void Display()
        {
            int i =1;
        int check = 0;
        current_node = header->get_next_node();
        while(check != -1)
            {
            if(current_node->get_next_node() == header ->get_next_node()){check = -1;}
            cout <<"Value stored at node # " <<i<<" is "<<current_node->get_val()<<endl;
            current_node = current_node->get_next_node();
            i++;
            }

        }


        ~circular_ll(){
        delete header;
        delete last_current_node;
        delete current_node;
        delete tail_node;
        }
};

circular_ll l1;

int main(){
l1.create_list();
l1.Display();
return 0;

}

