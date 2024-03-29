#include <iostream>
#include <fstream>
#include <sstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

/*struct node{
   int data;
   node *next;
 };
 //To αντικείμενο λίστα συνολικά θα φτιαχτούν Κ αντικείμενα λιστες δηλαδή οσα και τα δρομολόγια
 class list{
   private:
   node *head, *tail;

   public:
   constructor(){
     head=NULL;
     tail=NULL;
   }

   void make_new_node(int value){
       node *temp=new node;
       temp->data=value;
       temp->next=NULL;
       if(head==NULL){
         head=temp;
         tail=temp;
         temp=NULL;
       }
       else{
         tail->next=temp;
         tail=temp;
       }
     }

   void display() {
    node *temp=new node;
    temp=head;
    while(temp!=NULL){
      cout<<temp->data<<"\t";
      temp=temp->next;
     }
   }

 };
*/

 struct node{
     int info;
     struct node *next;
     struct node *prev;
 }*start;
//Διπλά συνδεδεμένη Λίστα
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
       if (q->next->info == value) {
           tmp = q->next;
           free(tmp);
           q->next = NULL;
           cout<<"Element Deleted"<<endl;
           return;
       }
       cout<<"Element "<<value<<" not found"<<endl;
     }

     void display_dlist(){//Εμφάνισε όλα τα αντικείμενα
       struct node *q;
       if (start == NULL){
           cout<<"List empty,nothing to display"<<endl;
           return;
       }
       q = start;
       cout<<"The Doubly Link List is :"<<endl;
       while (q != NULL){
           cout<<q->info<<" <-> ";
           q = q->next;
       }
       cout<<"NULL"<<endl;
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

class tourist{
  //Πέρνει ως ορισμα το αρχειό και το διαβάζει ώστε να φτίαξει πίνακες για πιο εύκολη διαχείρηση των στοιχοίων
  public:
      void read_the_file(){
          int thesi;
          string line;
          ifstream plirofories ("t101.txt");

          if (plirofories.is_open()){
            /*Σπάει το αρχείο σε γραμμές και διαβαζεις τους αριθμούς και μόλις διαβάσει το κενό χαραχτήρα η μεταβλητή n
            εκχωρειτε στην εκάστοτε θεση στον πίνακα κ' γίνετε κενή*/
            int potision = -2;
            while ( getline (plirofories,line) ){
              istringstream is(line);
              int n;
              thesi = 0;
            while( is >> n ) {
              if (potision== -2){
                TOURISTAS[thesi] = n;
                thesi ++;
                }
              else if(potision == -1){
                HOTEL [thesi] = n;
                thesi ++;
              }
            }
            potision ++;
          }
          plirofories.close();
      /*Χρησιμοποιόντας της κλάση istringstream οπως και παραπάνω η γλωσσα ξεχωρίζει τους κενους χαρακτηρες και εκχωρει τους αριθμους
      οι οποιοι ειναι τυπου float(ο πίνακας με τα αξιοθέτα δηλώνετε δυναμικα χωρίς να χρειάζετε το πεδιο)*/
          landmarks = new float [potision] [22];
          potision = -2;
          ifstream plirofories ("t101.txt");
          while ( getline (plirofories,line) ){
            istringstream ss(line);
            float n;
            thesi = 0;
          while( ss >> n ) {
            if (potision>=0){
              landmarks[potision][thesi]=n;
              thesi ++;
            }
          }
            potision ++;
          }
        }
        plirofories.close();
        return;
      }
      int see_tourista(int x){ return TOURISTAS[x];} //επιστρέφει την τιμή για τον πινακα TOURISTAS απο την θέση χ
      int see_hotel(int x){return HOTEL[x];} //επιστρέφει την τιμή για τον πινακα HOTEL απο την θέση χ
      float see_landmark(int x,int y){return landmarks[x][y];} //επιστρέφει την τιμή για τον πινακα landmarks απο την θέση x , y
    private:
      int TOURISTAS[16];
      int HOTEL[7];
      float (*landmarks) [22];

};

float ofelos(float b,float apostasi_qi,float meso_xronos,float apostasi_ir,float apostasi_qr){
  return b/(apostasi_qi+meso_xronos+apostasi_ir-apostasi_qr);
}

int main(){
  float meg_ofelos=-122;
  tourist elias;
  elias.read_the_file(); //Φτίαχνει τους πίνακες για το αντικείμενο elias
  int total_landmarks = elias.see_tourista(3);
  int numbers_of_tours = elias.see_tourista(1);
  int start_day = elias.see_tourista(2);
  int diathesimi_wra = elias.see_hotel(6) - elias.see_hotel(5);
  //for(int i = 0;i <= numbers_of_tours;i++){//θα φτιαξει λιστε και θα τα βάζει σε πίνακες
    double_llist dromologia;
    dromologia.create_list(1);
    dromologia.add_begin(2);
    dromologia.add_begin(3);
    dromologia.display_dlist();
    int landamarks_to_see = total_landmarks;
    int z = 0;

        /*σκοπος ειναι να βαζει δρομολόγια μεχρι να diathesimi_wra na ginei 0 η να ειναι αδύνατο να πάει σε αλλα αξιοθέτα
        το flag θα γίνει false όταν δεν θα μπορέσει να βάλει αλλα δρομολόγια*/
    while (diathesimi_wra != 0 || flag = FALSE ) {
      //πιθανες θέσεις ειναι ολα τα αντικειμενα της λιστα -1
      int pithanes_thesis = dromologia.count() - 1;
      for(pithanes_thesis; pithanes_thesis<=1;pithanes_thesis--)
      landmark = dromologia.return_the_landmarks(pithenes_thesis);
      /*Θα αναζητήση πιο αξιοθεατο ειναι καταληλότερο για να μπει στην θεση pithenes_thesis και οταν τελείωσει την επαναληψη και βρει το καταλληλοτερο αφου
      πρωτα δει ολες τις θεσεις.Αυτο θα γινει φτιαχνοντας μια μεταβλητη η οποια οταν το οφελος ειναι μεγαλυτερο απο το προηγουμενο αντικαταστει την μεχρι
      προτινος καταχωρηση*/
      for(int z = 0;z >= total_landmarks;z++){
      int *landmark;
      int q = *(landmark+0);
      int r = *(landmark+1);
      if (q == 0){
        float apostasi_qi = sqrt(abs(( pow(elias.see_landmark(z,1),2) - pow(elias.see_hotel(q,2),2) ) + ( pow(elias.see_landmark(z,2),2) - pow(elias.see_hotel(q,2),2 ) ) ) );
        float apostasi_ir = sqrt(abs(( pow(elias.see_landmark(r,1),2) - pow(elias.see_landmark(z,2),2) ) + ( pow(elias.see_landmark(r,2),2) - pow(elias.see_landmark(z,2),2 ) ) ) );
        float apostasi_qr = sqrt(abs(( pow(elias.see_landmark(r,1),2) - pow(elias.see_hotel(q,2),2) ) + ( pow(elias.see_landmark(r,2),2) - pow(elias.see_hotel(q,2),2 ) ) ) );
      }
      else if(r == 0){
        float apostasi_qi = sqrt(abs(( pow(elias.see_landmark(z,1),2) - pow(elias.see_landmark(q,2),2) ) + ( pow(elias.see_landmark(z,2),2) - pow(elias.see_landmark(q,2),2 ) ) ) );
        float apostasi_ir = sqrt(abs(( pow(elias.see_hotel(r,1),2) - pow(elias.see_landmark(z,2),2) ) + ( pow(elias.see_hotel(r,2),2) - pow(elias.see_landmark(z,2),2 ) ) ) );
        float apostasi_qr = sqrt(abs(( pow(elias.see_hotel(r,1),2) - pow(elias.see_landmark(q,2),2) ) + ( pow(elias.see_hotel(r,2),2) - pow(elias.see_landmark(q,2),2 ) ) ) );
      }
      else if(q == 0 && r==0){
        float apostasi_qi = sqrt(abs(( pow(elias.see_landmark(z,1),2) - pow(elias.see_hotel(q,2),2) ) + ( pow(elias.see_landmark(z,2),2) - pow(elias.see_hotel(q,2),2 ) ) ) );
        float apostasi_ir = sqrt(abs(( pow(elias.see_hotel(r,1),2) - pow(elias.see_landmark(z,2),2) ) + ( pow(elias.see_hotel(r,2),2) - pow(elias.see_landmark(z,2),2 ) ) ) );
        float apostasi_qr = sqrt(abs(( pow(elias.see_hotel(r,1),2) - pow(elias.see_hotel(q,2),2) ) + ( pow(elias.see_hotel(r,2),2) - pow(elias.see_hotel(q,2),2 ) ) ) );
      }
      else{
      float apostasi_qi = sqrt(abs(( pow(elias.see_landmark(z,1),2) - pow(elias.see_landmark(q,2),2) ) + ( pow(elias.see_landmark(z,2),2) - pow(elias.see_landmark(q,2),2 ) ) ) );
      float apostasi_ir = sqrt(abs(( pow(elias.see_landmark(r,1),2) - pow(elias.see_landmark(z,2),2) ) + ( pow(elias.see_landmark(r,2),2) - pow(elias.see_landmark(z,2),2 ) ) ) );
      float apostasi_qr = sqrt(abs(( pow(elias.see_landmark(r,1),2) - pow(elias.see_landmark(q,2),2) ) + ( pow(elias.see_landmark(r,2),2) - pow(elias.see_landmark(q,2),2 ) ) ) );
      }
      float ofelos_z = ofelos(elias.see_landmark(z,4),apostasi_qi,elias.see_landmark(z,3),apostasi_ir,apostasi_qr);
      if(meg_ofelos<=ofelos_z){
        meg_ofelos = ofelos_z;
        mallon_thesi = pithanes_thesis;
      }
      }
    }
  return 0;
}
