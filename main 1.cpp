#include <iostream>
#include <queue>
#define Size 4
#define infinity 99999999
//graph of four cities
int graph[Size][Size]={{0,258,147,1133},{258,0,397,1032},{147,397,0,1106},{1133,1032,1106,0}};
using  namespace std;
//waiting list for reservation in case of any ticket cancellation;
queue<int> waiting_list;
queue<int>for_train;

//Date Class
class Date{
private:
    int day;
    int month;
    long year;
public:
    Date(){
    }
    //constructor
    Date(int day,int month,long  year){
        this->day=day;
        this->month=month;
        this->year=year;
    }
    //copy constructor
    Date(Date d,Date m,Date y){
        this->day=d.day;
        this->month=m.month;
        this->year=y.year;

    }
    int getDay(){
        return day;
    }
    int getMonth(){
        return month;

    }
    long getYear(){
        return year;
    }
    void setDay(int d){
        this->day=d;

    }
    void setMonth(int m){
        this->month=m;
    }
    void setYear(long yy){
        this->year=yy;
    }
    void display(){
        cout<<getDay()<<" "<<getMonth()<<" "<<getYear()<<endl;
    }
};
//time Class
class Time{
private:
    int minutes;
    int hour;

public:
    Time(){

    }
    Time(int h,int min){
        this->hour=h;
        this->minutes=min;
    }
    int getHour(){
        return hour;
    }
    int  getMinutes(){
        return minutes;
    }
    void setHour(int h){
        this->hour=h;
    }
    void setMinutes(int m){
        this->minutes=m;
    }
};

//train structure
struct train{

    int Train_No;
    string Train_Name;
    string Boarding_point;
    string Destination_point;
    int No_of_seats;
    double  Fare_per_ticket;
    Date date;
    Time time;
    train *next=NULL;
};

//customer class
struct  cust {
    string name;
    string password;
    int id;
    int age;
    cust *next=NULL;
};

class Customer  {
private :
    int len;
    int count=1000;
    cust *first=NULL;
    cust *last=NULL;

public:
    Customer(){
        len=0;
    }

    //Function for adding cust
    void adding_customer(){
        string name;
        string password;
        int age;
        cout<<"Enter Your Name :"<<endl;
        cin>>name;
        bool bo;
        do {
            cout << "Enter Your Age :" << endl;
            cin >> age;
            if(age>0){
                bo= cin.fail();
                cin.clear();
                cin.ignore(256, '\n');
            }
            else{
                cout<<"invalid age.."<<endl;
                bo=true;
                cin.clear();
                cin.ignore(256, '\n');
            }
        }
        while (bo== true);
        cout<<"Enter a Password for login :"<<endl;
        cin>>password;
        cust *current=new cust();

        if(first==NULL){
            current->id=count;
            current->name=name;
            current->password=password;
            current->age=age;
            count++;
            len++;
            first=current;
            last=current;
        }
        else{
            current->id=count;
            current->name=name;
            current->password=password;
            current->age=age;
            count++;
            len++;

            last->next=current;
            last=current;
        }
        cout<<"ID       Name          Age             Password"<<endl;
        cout<<current->id<<"\t"<<current->name<<"\t\t"<<current->age<<"\t\t"<<current->password<<endl;
        cout<<"\n";
    }

    //display function
    void displayCustomer(){
        if(first==NULL){
            cout<<"No customer exist"<<endl;
        }
        else{
            cout<<"    ID\t\tName\t\tPassword\t\tAge"<<endl;
            cust *temp=first;
            while (temp!=NULL){
                cout<<"\2 "<<temp->id<<"\t\t"<<temp->name<<"\t\t"<<temp->password<<"\t\t\t"<<temp->age<<endl;
                temp=temp->next;
                cout<<endl;
            }
            cout<<endl;
        }
    }

    cust* mid(cust*l,cust *r){
        cust *follow=l;
        cust *forward=l;
        while (forward!=r){
            forward=forward->next;
            if(forward!=r){
                forward=forward->next;
                follow=follow->next;
            }
        }
        return follow;
    }
    cust* binary_searching(int key){
        cust *left=first;
        cust *right=NULL;
        while (left!=right||right == NULL ){

            cust *middle=mid(left,right);
            if(middle==NULL){
                return NULL;
            }
            if(middle->id==key){
                return middle;
            }
            else if(key<middle->id){
                right=middle;
            }
            else if(key>middle->id){
                left=middle->next;
            }
        }
        return NULL;
    }
    cust* linear_searching(int key){
        cust *temp=first;
        while (temp!=NULL){
            if(temp->id==key){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }

    void delete_customer(){
        int ID=0;
        bool b;
        do{
            cout<<"Enter ID You want to delete "<<endl;
            cin>>ID;
            b=cin.fail();
            cin.clear();
            cin.ignore(256, '\n');
        }
        while (b== true);

        if(first==NULL){
            cout<<"No user to delete"<<endl;
        }
        else if(linear_searching(ID)!=NULL){
            cust *p=first;
            cust *temp=first;
            while (p->id!=ID && p->next!=NULL){

                temp=p;
                p=p->next;
            }
            if(p==first){
                first=first->next;
                delete p;
                cout<<"Customer deleted Successfully"<<endl;
            }
            else if(p==last){
                last=temp;
                last->next=NULL;
                delete p;
                cout<<"Customer deleted Successfully"<<endl;
            }
            else{
                temp->next=p->next;
                delete p;
                cout<<"Customer deleted Successfully"<<endl;
            }
        }
        else{
            cout<<"No Such User exist"<<endl;
        }
    }
    void updatepass() {
        int ID = 0;
        bool b;
        do {
            cout << "Enter ID You want to Update " << endl;
            cin >> ID;
            b = cin.fail();
            cin.clear();
            cin.ignore(256, '\n');
        }
        while (b == true);

        cust *p = binary_searching(ID);
        if (p != NULL) {
            string password1;
            string password2;
            cout << "Enter You new password" << endl;
            cin >> password1;
            cout << "Enter password once again" << endl;
            cin >> password2;
            if (password2 == password1) {
                p->password = password2;
                cout << "Password Updated Successfully" << endl;
                cout << "    ID\t\tName\t\tPassword\t\tAge" << endl;
                cout << "\2 " << p->id << "\t\t" << p->name << "\t\t" << p->password << "\t\t\t" << p->age << endl;
            } else {
                cout << "Password not matched" << endl;
            }

        } else {
            cout << "No such customer found" << endl;
        }
    }
};
//train Record
class TrainRecord {

private:
    int length;
    train *first = NULL;
    train *last = NULL;

    long Train_No;
    string Train_Name;
    string Boarding_point;
    string Destination_point;
    int No_of_seats;
    double Fare_per_ticket;
    Date date;
    Time time;

public:
    //default constructor
    TrainRecord() {
        length=0;
    }

    //argument constructor
    TrainRecord(int number, string name, string Boarding_point,string destination,int no_of_seat,double fare,Date date,Time time) {
        length=0;
        this->Train_No = number;
        this->Train_Name = name;
        this->Boarding_point = Boarding_point;
        this->Destination_point = destination;
        this->No_of_seats = no_of_seat;
        this->Fare_per_ticket = fare;
        this->date = Date(date);
        this->time=Time(time);
    }

    int getTrainNo() {
        return getTrainNo();
    }

    int getSeats() {
        return getSeats();
    }
    string findd(int t)
    {
        train *p=first;
        bool search=false;
        string dest;
        while(p!=NULL)
        {
            if(p->Train_No==t)
            {
                search=true;
                dest=p->Destination_point;
                break;
            }
            else
            {
                search=false;
            }
            p=p->next;
        }
        return dest;
    }
    string findb(int t)
    {

        train *p=first;
        bool search=false;
        string board;
        while(p!=NULL)
        {
            if(p->Train_No==t)
            {
                search=true;
                board=p->Boarding_point;
                break;
            }
            else
            {
                search=false;
            }
            p=p->next;
        }
        return board;
    }
    //Add function
    void Add_Train(int Train_No, string Train_Name, string Boarding_point, string Destination_point, int No_of_seats,
                   double Fare_per_ticket, Date date1,Time t1) {
        train *current = new train;
        if (first == NULL) {
            current->Train_No = Train_No;
            current->Train_Name = Train_Name;
            current->Boarding_point = Boarding_point;
            current->Destination_point = Destination_point;
            current->No_of_seats = No_of_seats;
            current->Fare_per_ticket = Fare_per_ticket;
            current->date.setDay(date1.getDay());
            current->date.setMonth(date1.getMonth());
            current->date.setYear(date1.getYear());
            current->time.setHour(t1.getHour());
            current->time.setMinutes(t1.getMinutes());

            length++;
            first = current;
            last = current;
        }
        else {
            current->Train_No = Train_No;
            current->Train_Name = Train_Name;
            current->Boarding_point = Boarding_point;
            current->Destination_point = Destination_point;
            current->No_of_seats = No_of_seats;
            current->Fare_per_ticket = Fare_per_ticket;
            current->date.setDay(date1.getDay());
            current->date.setMonth(date1.getMonth());
            current->date.setYear(date1.getYear());
            current->time.setHour(t1.getHour());
            current->time.setMinutes(t1.getMinutes());

            length++;
            last->next = current;
            last = current;
            last->next = NULL;
        }
    }

//display function
    void display() {
        if (first == NULL) {
            cout << "No train record found" << endl;
        } else {
            cout<< "Train No\tTrain Name\tBoarding Point\tDestination\tseats\t\tFare \t\tDate"
                <<"\t\tTime "<< endl;
            train *temp = first;
            while (temp != NULL) {
                cout << temp->Train_No <<"\t\t" << temp->Train_Name << "\t" << temp->Boarding_point << "\t"<< temp->Destination_point << "\t"<< temp->No_of_seats << "\t\t" << temp->Fare_per_ticket<< "\t\t" << temp->date.getDay() << "," << temp->date.getMonth() << "," << temp->date.getYear()
                     <<"\t" << temp->time.getHour() << ":" << temp->time.getMinutes()<<"P.M"<<endl;
                temp = temp->next;
                cout << endl;
            }
            cout<<endl;
        }
    }
    train* linear_searching(int key){
        train *temp=first;
        while (temp!=NULL){
            if(temp->Train_No==key){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
    void sorting() {
        for (int i = 1; i <= length; i++) {
            train *p = first;
            for (int j = 1; j < length; j++) {
                if (p->Train_No > p->next->Train_No) {
                    int t_no = p->Train_No;
                    string name = p->Train_Name;
                    string destination = p->Destination_point;
                    string boarding = p->Boarding_point;
                    double fare = p->Fare_per_ticket;
                    int seat = p->No_of_seats;
                    Date date = p->date;
                    Time time=p->time;
                    p->Train_No = p->next->Train_No;
                    p->Train_Name = p->next->Train_Name;
                    p->No_of_seats = p->next->No_of_seats;
                    p->Fare_per_ticket = p->next->Fare_per_ticket;
                    p->Destination_point = p->next->Destination_point;
                    p->Boarding_point = p->next->Boarding_point;
                    p->date = p->next->date;
                    p->time=p->next->time;

                    p->next->Train_No = t_no;
                    p->next->Train_Name = name;
                    p->next->Boarding_point = boarding;
                    p->next->Destination_point = destination;
                    p->next->Fare_per_ticket = fare;
                    p->next->No_of_seats = seat;
                    p->next->date = date;
                    p->next->time=time;
                }
                p = p->next;
            }
        }
    }
};

struct tickets{
    int id;
    string NAME;
    int NoSeats;
    int train_NO;
    string destination;
    string boarding;
    double  fare;
    Date date;
    Time time;
    tickets *next=NULL;
};

//TicketReservation
class TicketReservation
{
private:
    int seats;
    int identity;
    tickets *first = NULL;
    tickets *last = NULL;
    train *train1;
    cust * cust1;
    string b,d;
    int distanceshot;
public:
    //constructor
    TicketReservation() {
    }

    int getShortest(int *distance,int *visited){
        int minvertex=-1;
        for(int i=0;i<Size;i++){
            if(visited[i]!=1 && (minvertex==-1 || distance[i]<distance[minvertex])){
                minvertex=i;
            }
        }
        return minvertex;
    }
    int  dijkstra(int pick,int dest) {
        int *visited = new int[Size];
        int *distance = new int[Size];
        for (int i = 0; i < Size; i++) {
            distance[i] = infinity;
            visited[i] = 0;
        }
        distance[pick] = 0;
        for (int i = 0; i < Size - 1; i++) {
            int minNode = getShortest(distance, visited);
            visited[minNode] = 1;
            for (int j = 0; j < Size; j++) {
                if (graph[minNode][j] != 0 && visited[j]!=1) {
                    int dist = distance[minNode] + graph[minNode][j];
                    if (dist < distance[j]) {
                        distance[j] = dist;
                    }
                }
            }
        }
        int short1;
        for(int i=0;i<4;i++)
        {
            if(i==dest)
            {

                if(pick==0 && dest==0)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==0 && dest==1)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==0 && dest==2)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==0 && dest==3)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==1 && dest==0)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==1 && dest==1)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==1 && dest==2)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==1 && dest==3)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==2 && dest==0)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==2 && dest==1)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==2 && dest==2)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==2 && dest==3)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==3 && dest==0)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==3 && dest==1)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick=3 && dest==2)
                {
                    short1=distance[i];
                    break;
                }
                else if(pick==3 && dest==3)
                {
                    short1=distance[i];
                    break;
                }
            }
        }
        return short1;

    }
    void seat_Reservation(TrainRecord train,Customer cust) {
        tickets *current = new tickets;

        bool boolean;
        do{
            cout << "enter your ID" << endl;
            cin >> identity;
            boolean=cin.fail();
            cin.clear();
            cin.ignore(256, '\n');
        }
        while (boolean==true);
        cust1=cust.linear_searching(identity);

        if(cust1!=NULL){
            cout<<"Following Trains Are Available!!"<<endl;
            train.display();
            int t_Number=0;
            bool  b;
            do{
                cout<<"Enter Train_No On Which You want to Travel "<<endl;
                cin>>t_Number;
                b=cin.fail();
                cin.clear();
                cin.ignore(256, '\n');
            }
            while (b==true);

            train1=train.linear_searching(t_Number);


            if(train1!=NULL)
            {
                string b1=train.findb(t_Number);
                string d1=train.findd(t_Number);
                if(b1=="Lahore  " && d1=="Karachi   ")
                {
                    distanceshot=dijkstra(0,1);
                    cout<<"The shortest distance from Lahore to Karachi is  " <<distanceshot<<"Km"<<endl;
                }
                else if(b1=="karachi " && d1=="Peshawar  ")
                {
                    distanceshot=dijkstra(0,3);
                    cout<<"The shortest distance from Karachi to Peshawar is  " <<distanceshot<<"Km"<<endl;
                }
                else if(b1=="Karachi " && d1=="lahore    ")
                {
                    distanceshot=dijkstra(2,1);
                    cout<<"The shortest distance from Karachi to Lahore is  " <<distanceshot<<"Km"<<endl;
                }
                else if(b1=="Peshawar" && d1=="Rawalpindi")
                {
                    distanceshot=dijkstra(3,1);
                    cout<<"The shortest distance from Peshawar to Rawalpindi is  " <<distanceshot<<"Km"<<endl;
                }
                else if(b1=="karachi "  && d1=="Peshawar  ")
                {
                    distanceshot=dijkstra(3,2);
                    cout<<"The shortest distance from Karachi to Peshawar is  " <<distanceshot<<"Km"<<endl;
                }
                else if(b1=="Lahore  "  && d1=="karachi   ")
                {
                    distanceshot=dijkstra(3,2);
                    cout<<"The shortest distance from Lahore to Karachi is  " <<distanceshot<<"Km"<<endl;
                }
                bool bo;
                do{
                    cout<<"Enter Number of seats You want to Reserve "<<endl;
                    cin>>seats;
                    bo=cin.fail();
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                while (bo==true);

                if(train1->No_of_seats>=seats){
                    train1->No_of_seats=train1->No_of_seats-seats;
                    cout<<"Seats Reserved Successfully"<<endl;
                    try {
                        if(first==NULL){
                            current->NAME=cust1->name;
                            current->NoSeats=seats;
                            current->id=cust1->id;
                            current->train_NO=train1->Train_No;
                            current->destination=train1->Destination_point;
                            current->boarding=train1->Boarding_point;
                            current->date=train1->date;
                            current->time=train1->time;
                            current->fare=train1->Fare_per_ticket*seats;

                            first=current;
                            last=current;
                        }
                        else
                        {
                            current->NAME=cust1->name;
                            current->NoSeats=seats;
                            current->id=cust1->id;
                            current->train_NO=train1->Train_No;
                            current->destination=train1->Destination_point;
                            current->boarding=train1->Boarding_point;
                            current->date=train1->date;
                            current->time=train1->time;
                            current->fare=train1->Fare_per_ticket*seats;

                            last->next=current;
                            last=current;
                        }
                    }
                    catch (const std::bad_alloc& e) {
                        std::cout << "Allocation failed: " << e.what() << '\n';
                    }
                    displayTicket();
                }
                else{
                    cout<<"This train have not enough seats for reservation"<<endl;
                    int y;
                    cout<<"Press (1) for waiting list"<<endl;
                    cin>>y;
                    if(y==1){
                        waiting_list.push(cust1->id);
                        for_train.push(train1->Train_No);
                    }
                }
            }
            else{
                cout<<"No such train exist "<<endl;
            }
        }
        else{
            cout<<"No such Customer Found"<<endl;
        }
    }
    tickets* reservation_search(int key){
        if(first==NULL){
            cout<<"No User "<<endl;
            return NULL;
        }
        else{
            tickets *p=first;
            while (p!=NULL){
                if(p->id==key){
                    return p;
                }
                p=p->next;
            }
        }
        return NULL;
    }
    void displayTicket(){
        if(first==NULL){
            cout<<"No tickets reservation available"<<endl;
        }
        else{
            tickets *temp=first;
            cout<<"Passenger ID\tTrain No\tName\tBoarding\tDestination\tSeats\tFare\tDate\t\tTime"<<endl;
            while (temp!=NULL){
                cout<<temp->id<<"\t\t"<<temp->train_NO<<"\t\t"<<temp->NAME<<"\t"<<temp->boarding<<" \t"<<temp->destination<<"\t"<<temp->NoSeats<<" \t"
                    <<temp->fare<<" \t"<<temp->date.getDay()<<","<<temp->date.getMonth()<<","<<temp->date.getYear()<<" \t"<<temp->time.getHour()<<":"<<temp->time.getMinutes()<<endl;
                temp=temp->next;
                cout<<endl;
            }
            cout<<endl;
        }
    }
    tickets* tickets_searching(int key){
        tickets *temp=first;
        while (temp!=NULL){
            if(temp->id==key){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
    void delete_ticket(int ID){

        if(first==NULL){
            cout<<"No user to delete"<<endl;
        }
        else if(reservation_search(ID)!=NULL){
            tickets *p=first;
            tickets *temp=first;
            while (p->id!=ID && p->next!=NULL){

                temp=p;
                p=p->next;
            }
            if(p==first){
                first=first->next;
                delete p;
                cout<<"Tickets has been cancelled successfully"<<endl;
            }
            else if(p==last){
                last=temp;
                last->next=NULL;
                delete p;
                cout<<"Tickets has been cancelled successfully"<<endl;
            }
            else{
                temp->next=p->next;
                delete p;
                cout<<"Tickets has been cancelled successfully"<<endl;
            }
        }
        else{
            cout<<"No Such passenger exist"<<endl;
        }
    }
    void cancellation(TicketReservation reservation,TrainRecord trainRecord){
        int Seats;
        int id;
        tickets *ticket1;
        bool boolean;
        do{
            cout<<"Enter Your ID to Cancel Ticket"<<endl;
            cin>>id;
            boolean=cin.fail();
            cin.clear();
            cin.ignore(256, '\n');
        }
        while (boolean== true);
        ticket1=reservation.tickets_searching(id);
        if(ticket1!=NULL){
            bool bo;
            do{
                cout<<"Enter No of seats to cancel"<<endl;
                cin>>Seats;
                boolean=cin.fail();
                cin.clear();
                cin.ignore(256, '\n');
            }
            while (bo== true);
            if(Seats<=ticket1->NoSeats){
                if(Seats==ticket1->NoSeats){
                    //deleting node
                    delete_ticket(ticket1->id);
                    int Id=ticket1->train_NO;
                    trainRecord.linear_searching(Id)->No_of_seats=trainRecord.linear_searching(Id)->No_of_seats+Seats;
                }
                else{
                    //reducing seats
                    double far=ticket1->fare/ticket1->NoSeats;
                    ticket1->fare=ticket1->fare-(far*Seats);
                    ticket1->NoSeats=ticket1->NoSeats-Seats;
                    int Id=ticket1->train_NO;
                    trainRecord.linear_searching(Id)->No_of_seats=trainRecord.linear_searching(Id)->No_of_seats+Seats;
                    cout<<"Tickets cancel Successfully"<<endl;
                }
            }
            else{
                cout<<"Do not have seats"<<endl;
            }
        }
        else{
            cout<<"No Such Passenger found"<<endl;
        }
    }

};
class Admin {
private:
    string name;
    int id;
    string pass;
    int age;
    int count;
public:
    Admin() {
        count = 100;
    }

    void sign_up() {
        id = count;
        cout << "Enter Your name :" << endl;
        cin >> name;
        bool boolean;
        do {
            cout << "Enter Your Age :" << endl;
            cin >> age;
            if(age>0)
            {
                boolean = cin.fail();
                cin.clear();
                cin.ignore(256, '\n');
            }
            else
            {
                cout<<"Invalid age"<<endl;
                boolean=true;
                cin.clear();
                cin.ignore(256, '\n');
            }

        } while (boolean == true);
        cout << "Enter Your password :" << endl;
        cin >> pass;

        count++;
    }

    bool sing_in() {
        bool result = false;
        int ID;
        string pas;
        bool b;
        do {
            cout << "Enter Your ID :" << endl;
            cin >> ID;
            b = cin.fail();
            cin.clear();
            cin.ignore(256, '\n');
        } while (b == true);
        cout << "Enter Your Password :" << endl;
        cin >> pas;
        if (pas == pass && id == ID) {
            cout << "Successfully signed In..." << endl;
            cout << endl;
            result = true;
        }
        return result;
    }

    void view_Admin() {
        if (id == 0) {
            cout << "Please sign up first.." << endl;
        } else {
            cout << "    ID\t\tName\t\tPassword\t\tAge" << endl;
            cout << "\2 " << id << "\t\t" << name << "\t\t" << pass << "\t\t\t" << age << endl;
        }

    }
};
//customer object
Customer customer;
//train class object
TrainRecord trainRecord;
//ticket reservation object
TicketReservation reservation;
//customer menu
Admin admin;
void customer_menu(){

    while(true){
        int choice=0;
        bool boolean;
        do{
            cout<<"1)Customer Menu\n2)Train Menu\n3)Ticket Reservation\n4)Ticket Cancellation\n5)Main menu"<<endl;
            cout<<"\nEnter Your Choice "<<endl;
            cin>>choice;
            boolean=cin.fail();
            cin.clear();
            cin.ignore(256, '\n');
        }
        while (boolean== true);

        //for customer menu
        if(choice==1){
            while(true){
                int choice=0;
                bool boolean;
                do{
                    cout<<"1)Sign up\n2)Search User\n3)Delete Account\n4)Update Password\n5)customer menu"<<endl;
                    cout<<"\nEnter Your Choice "<<endl;
                    cin>>choice;
                    boolean=cin.fail();
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                while (boolean== true);

                if(choice==1){
                    customer.adding_customer();
                }
                else if(choice==2){
                    int Id;
                    bool b;
                    do{
                        cout<<"Enter Id you want to search"<<endl;
                        cin>>Id;
                        b=cin.fail();
                        cin.clear();
                        cin.ignore(256, '\n');
                    }
                    while (boolean== true);
                    cust *p=customer.binary_searching(Id);
                    if( p==NULL){
                        cout<<"Not Found"<<endl;
                    }
                    else{
                        cout<<"    ID\t\tName\t\tPassword\t\tAge"<<endl;
                        cout<<"\2 "<<p->id<<"\t\t"<<p->name<<"\t\t"<<p->password<<"\t\t\t"<<p->age<<endl;
                        cout<<endl;
                    }
                }

                else if(choice==3){
                    customer.delete_customer();
                }
                else if(choice==4){
                    customer.updatepass();
                }
                else if(choice==5){
                    break;
                }
                else{
                    cout<<"invalid choice"<<endl;
                }
            }
        }
            //train menu
        else if(choice==2){
            while (true) {
                int choice;
                bool b;
                do {
                    cout << "1)View Available Trains\n2)Search Train\n3)Customer menu" << endl;
                    cout << "\nEnter Your Choice " << endl;
                    cin >> choice;
                    b = cin.fail();
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                while (b == true);
                if (choice == 1) {
                    trainRecord.display();
                }
                else if (choice == 2) {
                    int train_no;
                    bool b;
                    do{
                        cout<<"Enter Train NO. want to search"<<endl;
                        cin>>train_no;
                        b=cin.fail();
                        cin.clear();
                        cin.ignore(256, '\n');
                    }
                    while (b== true);
                    train *temp=trainRecord.linear_searching(train_no);
                    if( temp==NULL){
                        cout<<"Not Found"<<endl;
                    }
                    else{
                        cout<< "Train No\tTrain Name\tBoarding Point\tDestination\tseats\t\tFare \t\tDate\t\tTime"
                            <<"\t\tTime "<< endl;
                        cout << temp->Train_No <<"\t\t" << temp->Train_Name << "\t" << temp->Boarding_point << "\t"<< temp->Destination_point << "\t"<< temp->No_of_seats << "\t\t" << temp->Fare_per_ticket<< "\t\t" << temp->date.getDay() << "," << temp->date.getMonth() << "," << temp->date.getYear()
                             <<"\t" << temp->time.getHour() << ":" << temp->time.getMinutes()<<"P.M"<<endl;
                    }
                }
                else if (choice == 3) {
                    break;
                }
                else {
                    cout << "invalid choice" << endl;
                }
            }
        }
            //Ticket Reservation
        else if(choice==3){
            while (true) {
                int choice;
                bool b;
                do {
                    cout << "1)Ticket Reservation\n2)Display Ticket detail\n3)Ticket Searching\n4)waiting list\n5)customer menu" << endl;
                    cout << "\nEnter Your Choice " << endl;
                    cin >> choice;
                    b = cin.fail();
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                while (b == true);
                if (choice == 1) {

                    reservation.seat_Reservation(trainRecord, customer);
                }
                else if (choice == 2) {
                    reservation.displayTicket();
                }
                else if (choice == 3) {
                    int id;
                    bool b;
                    do{
                        cout<<"Enter ID of Passenger to search"<<endl;
                        cin>>id;
                        b=cin.fail();
                        cin.clear();
                        cin.ignore(256, '\n');
                    }
                    while (b== true);
                    tickets *p=reservation.tickets_searching(id);
                    if(p!=NULL){
                        cout<<"Passenger ID\tTrain No\tName\tBoarding\tDestination\tSeats\tFare\tDate\t\tTime"<<endl;
                        cout<<p->id<<"\t\t"<<p->train_NO<<"\t\t"<<p->NAME<<"\t"<<p->boarding<<" \t"<<p->destination<<"\t"<<p->NoSeats<<" \t"
                            <<p->fare<<" \t"<<p->date.getDay()<<","<<p->date.getMonth()<<","<<p->date.getYear()<<"\t"<<p->time.getHour()<<":"<<p->time.getHour()<<"P.M"<<endl;
                    }
                    else{
                        cout<<"No Such Passenger"<<endl;
                    }
                }
                else if(choice==4){
                    if(waiting_list.empty()){
                        cout<<"No customer in waiting list"<<endl;
                    }
                    else{
                        cout<<"\t\t\t WAITING LIST"<<endl;
                        cout<<"    ID\t\tName\t\tAge\t\tTrain Number\t\tTrain Name\t\t"<<endl;
                        int i=0;

                        while (!waiting_list.empty()){
                            int idd=waiting_list.front();
                            int t_no=for_train.front();
                            string name=customer.binary_searching(idd)->name;
                            int age=customer.binary_searching(idd)->age;
                            string t_name=trainRecord.linear_searching(t_no)->Train_Name;
                            cout<<"\2 "<<idd<<"\t\t"<<name<<"\t\t"<<age<<"\t\t"<<t_no<<"\t\t\t"<<t_name<<endl;
                            waiting_list.pop();
                            for_train.pop();
                        }
                    }
                }
                else if(choice==5){
                    break;
                }
                else {
                    cout << "invalid choice" << endl;
                }
            }
        }
        else if(choice==4){
            reservation.cancellation(reservation,trainRecord);
        }
        else if(choice==5){
            break;
        }
        else{
            cout<<"invalid choice"<<endl;
        }
    }
}

void admin_menu(){
    while (true){
        int choice=0;
        bool boolean;
        do{
            cout<<"1) Sign In\n2) Sign up\n3) View own Record\n4) Main menu"<<endl;
            cout<<"\nEnter Your Choice "<<endl;
            cin>>choice;
            boolean=cin.fail();
            cin.clear();
            cin.ignore(256, '\n');
        }
        while (boolean== true);

        if(choice==1){
            bool b=admin.sing_in();
            if(b== true){
                while (true){
                    int choice=0;
                    bool boolean;
                    do{
                        cout<<"1)View all Customer\n2)Search Particular Customer\n3)View All Train\n4)Search a Train \n5)Sort Trains\n6)Main menu"<<endl;
                        cout<<"\nEnter Your Choice "<<endl;
                        cin>>choice;
                        boolean=cin.fail();
                        cin.clear();
                        cin.ignore(256, '\n');
                    }
                    while (boolean== true);
                    if(choice==1){
                        customer.displayCustomer();
                    }
                    else if(choice==2){
                        int Id;
                        bool b;
                        do{
                            cout<<"Enter Id you want to search"<<endl;
                            cin>>Id;
                            b=cin.fail();
                            cin.clear();
                            cin.ignore(256, '\n');
                        }
                        while (boolean== true);
                        cust *p=customer.binary_searching(Id);
                        if( p==NULL){
                            cout<<"Not Found"<<endl;
                        }
                        else{
                            cout<<"    ID\t\tName\t\tPassword\t\tAge"<<endl;
                            cout<<"\2 "<<p->id<<"\t\t"<<p->name<<"\t\t"<<p->password<<"\t\t\t"<<p->age<<endl;
                            cout<<endl;
                        }
                    }
                    else if(choice==3){
                        trainRecord.display();
                    }
                    else if(choice==4){
                        int train_no;
                        bool b;
                        do{
                            cout<<"Enter Train NO. want to search"<<endl;
                            cin>>train_no;
                            b=cin.fail();
                            cin.clear();
                            cin.ignore(256, '\n');
                        }
                        while (b== true);
                        train *temp=trainRecord.linear_searching(train_no);
                        if( temp==NULL){
                            cout<<"Not Found"<<endl;
                        }
                        else{
                            cout<< "Train No\tTrain Name\tBoarding Point\tDestination\tseats\t\tFare \t\tDate\t\tTime"<< endl;
                            cout << temp->Train_No <<"\t\t" << temp->Train_Name << "\t" << temp->Boarding_point << "\t"<< temp->Destination_point << "\t"
                                 << temp->No_of_seats << "\t\t" << temp->Fare_per_ticket<< "\t\t" << temp->date.getDay() << "," << temp->date.getMonth() << "," << temp->date.getYear()
                                 << "\t"<<temp->time.getHour()<<":"<<temp->time.getMinutes()<<"P.M"<<endl;
                        }

                    } else if(choice==5){
                        trainRecord.sorting();
                    }
                    else if(choice==6){
                        break;
                        cout<<"invalid choice"<<endl;
                    }
                    else{

                        cout<<"invalid choice"<<endl;
                    }
                }
            }
            else{
                cout<<"Invalid ID or Password...try next time"<<endl;
                cout<<endl;
            }
        }
        else if(choice==2){
            admin.sign_up();
        }
        else if(choice==3){
            admin.view_Admin();
        }
        else if(choice==4){
            break;
        }
        else{
            cout<<"invalid choice"<<endl;
        }
    }
}
//main function
int main() {
    cout << "\t\t\t\t    Well Come " << endl;
    cout << "\t\t\t\t\t\5" << endl;
    cout << "\t\t\t   \5Railway Reservation System\5" << endl;
    cout << "\t\t\t\t\t\5" << endl;
    cout << "\t\t   <><><><><><><><><><><><><><><><><><><><><><><>\n";
    cout << "\t\t\tBook your tickets at affordable prices!" << endl;
    cout << "\t\t   <><><><><><><><><><><><><><><><><><><><><><><>";
    cout << endl;

    Date date(5, 1, 2021);
    Date date1(6, 1, 2021);
    Date date2(7, 1, 2021);
    Time time1(06, 23);
    Time t2(7,24);
    Time t3(4,33);

    trainRecord.Add_Train(3156, "Shalimar ", "Lahore  ","Karachi   ",4,2500,date1,time1);
    trainRecord.Add_Train(3113, "Express  ", "karachi ","Peshawar  ",4,2000,date2,t2);
    trainRecord.Add_Train(3133, "Karakuram", "Karachi ","lahore    ",4,3500,date,time1);
    trainRecord.Add_Train(3100, "Shalimar ", "Peshawar","Rawalpindi",4,2500,date2,t3);
    trainRecord.Add_Train(3155, "Express  ", "karachi ","Peshawar  ",4,2500,date1,t2);
    trainRecord.Add_Train(3126, "Shalimar ", "Lahore  ","karachi   ",4,2300,date,t3);

    while (true){
        int choice=0;
        bool boolean;
        do{
            cout<<"1) Admin Menu\n2) Customer Menu\n3) Exit"<<endl;
            cout<<"\nEnter Your Choice "<<endl;
            cin>>choice;
            boolean=cin.fail();
            cin.clear();
            cin.ignore(256, '\n');
        }
        while (boolean== true);

        if(choice==1){
            admin_menu();
        }
        else if(choice==2){
            customer_menu();
        }
        else if(choice==3){
            cout<<"Thanks for using Railway Reservation System..."<<endl;
            break;
        }
        else{
            cout<<"invalid choice"<<endl;
        }
    }
}
