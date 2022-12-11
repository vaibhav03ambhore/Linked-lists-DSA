
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

class node
{

    char name[100];
    string PRN;
    double ie1,ie2,mte,ete,f_ie_sc,f_mte_sc,f_ete_sc,total,credit;
    string grade;
    node *next;

    public:
    node *create(node *);
    void insert(node *);
    void display(node *);
    void rec_rev(node *);
    void delete1(node *);
    void result(node *);
};


node *node ::create(node *head)
{
    head= new node;
    head->next=NULL;
    return head;
}

//insert function
void node:: insert(node *head)
{
    static int P;
    node *temp,*curr;
    temp =new node;

    cout<<"\nenter name: ";
    cin>>temp->name;
    cout<<"enter PRN number: ";
    cin>>temp->PRN;
    cout<<"enter the marks of IE1(20) , MTE(50) , IE2(20) , ETE(80):"<<endl;
    cin>>temp->ie1>>temp->mte>>temp->ie2>>temp->ete;
    if(temp->ie1>20||temp->mte>50||temp->ie2>20||temp->ete>80)
    {
      cout<<endl<<"please check marks of IE,MTE or ETE - marks should not exceed 20,50,20,80 respectively"<<endl;
      cout<<"enter marks again:"<<endl;
      cin>>temp->ie1>>temp->mte>>temp->ie2>>temp->ete;
      cout<<endl;
    }

    else{
            cout<<"";
        }
    temp->next=NULL;
    curr=head;
    int ch1;
    cout<<endl<<"1.Insert at_first \t 2.Insert after a PRN NO. \t 3.Insert at_last\n";
    cin>>ch1;
    if(ch1==1)
    {
        if(curr->next==NULL)
        curr->next=temp;
        else
        temp->next=curr->next;
        curr->next=temp;
        cout<<endl<<"data is added succesfully"<<endl;
    }

    if(ch1==3)
    {
        P++;
        if(curr->next==NULL)
        curr->next=temp;
    else
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
    curr->next=temp;

    cout<<endl<<"data is added successfully"<<endl;
    }
    if(ch1==2)
    {
        if(curr->next==NULL)
        curr->next=temp;
        else if(P!=0)
        {
            string prn;
            cout<<"enter PRN NO. after which you want to add data"<<endl;
            cin>>prn;
            while(curr->PRN!=prn)
            {
                curr=curr->next;
            }
        temp->next=curr->next;
        curr->next=temp;

        }

        else
        {
            while(curr->next!=NULL)
            {
                curr=curr->next;
            }
        curr->next=temp;
        }

        cout<<endl<<"data is added successfully"<<endl;
    }
    cout<<endl;
}


//display function
void node::display(node *head)
{
    node *curr;
    curr=head->next;

    int ch;

    cout<<endl"enter choice"<<endl<<"1.normal display(given marks) \t 2.result display(final marks & grades)"<<endl;
    cin>>ch;


    if(curr==NULL)
        cout<<"nothing to display the list is empty"<<endl;
    else
    {
        switch(ch)
        {
            case 1:
                {
                    cout<<"\n********saved data********\n\n";

                    cout<<left<<setw(17)<<"NAME"<<left<<setw(17)<<"PRN"
                        <<left<<setw(17)<<"IE1(20)"<<left<<setw(17)<<"MTE(50)"
                        <<left<<setw(17)<<"IE2(20)"<<left<<setw(17)<<"ETE(80)"<<endl;
                    while(curr!=NULL)
                {
                cout<<left<<setw(17)<<curr->name<<left<<setw(17)<<curr->PRN
                <<left<<setw(17)<<curr->ie1<<left<<setw(17)<<curr->mte
                <<left<<setw(17)<<curr->ie2<<left<<setw(17)<<curr->ete<<endl;
                curr=curr->next;
                }
                }
            break;

            case 2:
            {
                cout<<"\n********saved data********\n\n";

                cout<<left<<setw(17)<<"NAME"<<left<<setw(17)<<"PRN"
                    <<left<<setw(17)<<"FINAL IE(20)"<<left<<setw(17)<<"FINAL MTE(30)"
                    <<left<<setw(17)<<"FINAL ETE(50)"<<left<<setw(17)<<"total(100)"
                    <<left<<setw(17)<<"credits"<<left<<setw(17)<<"Grades"<<endl;
              while(curr!=NULL)
                {
                cout<<left<<setw(17)<<curr->name<<left<<setw(17)<<curr->PRN
                <<left<<setw(17)<<curr->f_ie_sc<<left<<setw(17)<<curr->f_mte_sc
                <<left<<setw(17)<<curr->f_ete_sc<<left<<setw(17)<<curr->total
                <<left<<setw(17)<<curr->credit<<left<<setw(17)<<curr->grade<<endl;
                curr=curr->next;
                }
            }

            break;

       }

    }
    cout<<endl;
}


//function for reversing linked list using recursion
void node::rec_rev(node *head1)
{

    if (head1==NULL)
    {
      return ;
    }
    else {


            rec_rev(head1->next);
            if(head1->name!=0)
            {

                cout<<left<<setw(17)<<head1->name<<left<<setw(17)<<head1->PRN
                <<left<<setw(17)<<head1->f_ie_sc<<left<<setw(17)<<head1->f_mte_sc
                <<left<<setw(17)<<head1->f_ete_sc<<left<<setw(17)<<head1->total
                <<left<<setw(17)<<head1->credit<<left<<setw(17)<<head1->grade<<endl;


            }
         }

}


//delete function
void node::delete1(node *head)
{
    string nm;
    if(head->next==NULL)
        cout<<"nothing to delete the list is empty"<<endl;
    else
    {
        cout<<endl<<"enter name whom you want to delete data: ";
        cin>>nm;
        node *curr,*temp;
        curr=head;
        while(curr->next->name!=nm)
        {
            curr=curr->next;
        }
        temp=curr->next;
        curr->next=temp->next;

        cout<<endl<<temp->name<<"'s data is deleted"<<endl<<endl;
        delete temp;

    }

}


//calculating result //
void node ::result(node *head1)
{
    node *curr;
    curr=head1;
    while(curr->next!=NULL)
    {
        curr=curr->next;

        curr->f_ie_sc=(curr->ie1+curr->ie2)/2;
        curr->f_mte_sc=curr->mte*30/50;
        curr->f_ete_sc=curr->ete*50/80;
        curr->total=curr->f_ie_sc+curr->f_mte_sc+curr->f_ete_sc;
        curr->credit=curr->total/10;

        if(curr->credit<=10&&curr->credit>=9)
            curr->grade="O";
        else if(curr->credit<=8.9&&curr->credit>=8)
            curr->grade="A+";
        else if(curr->credit<=7.9&&curr->credit>=7)
            curr->grade="A";
        else if(curr->credit<=7.9&&curr->credit>=6)
            curr->grade="B+";
        else if(curr->credit<=6.9&&curr->credit>=5)
            curr->grade="B";
        else if(curr->credit<=4.9&&curr->credit>=4)
            curr->grade="P(pass)";
        else curr->grade="F(fail)";


    }
    cout<<endl<<"congrats result is calculated"<<endl;
    cout<<endl;
    display(head1);
}

//main function
int main()
{
    int ch;
    node obj;
    node *head;
    head=obj.create(head);

    while(1)
    {
        cout<<"1. Insert\t 2.calculate result \t 3. Display\t  4.reverse using recursion\t 5.delete\t 6.exit\t"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
    switch(ch)
        {
            case 1:
            obj.insert(head);
            break;

            case 2:
            obj.result(head);
            break;

            case 3:
            obj.display(head);
            break;


            case 4:
                {
                    cout<<endl<<"*******reversed data is *******"<<endl;
                    cout<<endl<<left<<setw(17)<<"NAME"<<left<<setw(17)<<"PRN"
                        <<left<<setw(17)<<"IE(20)"<<left<<setw(17)<<"MTE(30)"
                        <<left<<setw(17)<<"ETE(50)"<<left<<setw(17)<<"total(100)"
                        <<left<<setw(17)<<"credits"<<left<<setw(17)<<"Grades"<<endl;

                    obj.rec_rev(head);
                }

            break;


            case 5:
            obj.delete1(head);
            break;

            case 6:
            exit(0);
            break;

        }
    }

return 0;
}

