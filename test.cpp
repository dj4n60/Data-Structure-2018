#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

struct node{
    int info;
    struct node *next;
    struct node *prev;
}*start;

class double_llist{
    public:
    void create_list(int value){//Δημιουργεί την λίστα
      struct node *s, *temp;
      temp = new(struct node);
      temp->info = value;
      temp->next = NULL;
      if (start == NULL){
          temp->prev = NULL;
          start = temp;
      }
      else{
          s = start;
          while (s->next != NULL)
            s = s->next;
          s->next = temp;
          temp->prev = s;
      }
    }
    void add_begin(int value){//Προσθήκη στην αρχή
      if (start == NULL) {
          cout<<"First Create the list."<<endl;
          return;
      }
      struct node *temp;
      temp = new(struct node);
      temp->prev = NULL;
      temp->info = value;
      temp->next = start;
      start->prev = temp;
      start = temp;
      cout<<"Element Inserted"<<endl;
    }
    void add_after(int value, int pos){//Προσθήκα στον μετα απο το pos στην σειρα στοιχειο
      if (start == NULL){
          cout<<"First Create the list."<<endl;
          return;
      }
      struct node *tmp, *q;
      int i;
      q = start;
      for (i = 0;i < pos - 1;i++){
          q = q->next;
          if (q == NULL){
              cout<<"There are less than ";
              cout<<pos<<" elements."<<endl;
              return;
          }
      }
      tmp = new(struct node);
      tmp->info = value;
      if (q->next == NULL) {
          q->next = tmp;
          tmp->next = NULL;
          tmp->prev = q;
      }
      else{
          tmp->next = q->next;
          tmp->next->prev = tmp;
          q->next = tmp;
          tmp->prev = q;
      }
      cout<<"Element Inserted"<<endl;
    }
    int * return_the_landmarks(int pos){
      struct node *tmp, *q;
      int i;
      static int arr[2];
      q = start;
      /*θα πηγαίνει στο στοιχέιο που θέλουμε δηλάδη το επόμενο απο την θέση που θελουμε να ελένξουμε και θα επιστρέφει σε πινακα
      2 στοιχειων τους ακέραιους αριθμους που αντιστοιχουν στο προηγουημενο και στο τρέχων στοιχείο */
      for(i=0;i <=pos ; i++){
        q = q->next;
      }
      tmp = q->prev;
      arr[0]=tmp->info;
      arr[1]=q->info;
      return arr;
    }
    void delete_element(int value){//Διάγραψε το πρώτο στοιχείο αντικείμενο με value
      struct node *tmp, *q;
       /*first element deletion*/
      if (start->info == value){
          tmp = start;
          start = start->next;
          start->prev = NULL;
          cout<<"Element Deleted"<<endl;
          free(tmp);
          return;
      }
      q = start;
      while (q->next->next != NULL){
          /*Element deleted in between*/
          if (q->next->info == value){
              tmp = q->next;
              q->next = tmp->next;
              tmp->next->prev = q;
              cout<<"Element Deleted"<<endl;
              free(tmp);
              return;
          }
          q = q->next;
      }
       /*last element deleted*/
      if (q->next->info == value) {
          tmp = q->next;
          free(tmp);
          q->next = NULL;
          cout<<"Element Deleted"<<endl;
          return;
      }
      cout<<"Element "<<value<<" not found"<<endl;
    }
    int display_dlist(){//Εμφάνισε όλα τα αντικείμενα
      int x;
      struct node *q;
      if (start == NULL){
          cout<<"List empty,nothing to display"<<endl;
          return 232322332;
      }
      q = start;
      cout<<"The Doubly Link List is :"<<endl;
      bool logicc = true;
      while (q != NULL){
          cout<<q->info<<" <-> ";//me auto mporei na mporw na balw autin tin pliroforia ston pinaka
          if (logicc == true){
            x = q->info;
            logicc = false;
          }
          q = q->next;
      }
      cout<<"NULL"<<endl;
      return x;
    }
    void count(){//Συνολίκα αντικέιμενα
      struct node *q = start;
      int cnt = 0;
      while (q != NULL){
          q = q->next;
          cnt++;
      }
      cout<<"Number of elements are: "<<cnt<<endl;
    }
    //void reverse();
    double_llist(){
      start = NULL;
        }
};

/*int main(){
    int choice, element, position;
    double_llist dl;
    while (1)
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Operations on Doubly linked list"<<endl;
        cout<<endl<<"----------------------------"<<endl;
        cout<<"1.Create Node"<<endl;
        cout<<"2.Add at begining"<<endl;
        cout<<"3.Add after position"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Count"<<endl;
        cout<<"7.Reverse"<<endl;
        cout<<"8.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            dl.create_list(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            dl.add_begin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert Element after postion: ";
            cin>>position;
            dl.add_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (start == NULL)
            {
                cout<<"List empty,nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            dl.delete_element(element);
            cout<<endl;
            break;
        case 5:
            dl.display_dlist();
            cout<<endl;
            break;
        case 8:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}*/

int main(){
  double_llist test;
  test.create_list(4);
  test.add_begin(3);
  test.add_begin(2);
  test.add_begin(1);
  test.add_begin(0);
  test.display_dlist();
  int *p;
  p = test.return_the_landmarks(2);
  cout<<*(p+0)<<" "<<*(p+1)<<endl;
}
