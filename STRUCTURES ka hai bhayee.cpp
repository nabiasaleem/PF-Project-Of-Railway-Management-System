#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

// STRUCTURES
struct Train {
    string tname;
    int tseats;
    int tfare;
};

struct Staff {
    string sname;
    string srole;
    string sphone;
};

struct Reservation {
    string cname;
    int bookedTrain;
    int bookedSeats;
};

// TRAIN MANAGEMENT CLASS
class TrainManagement {
public:
    Train trains[20];
    int trainCount;

    TrainManagement() {
    	
        trains[0].tname = "GreenLine"; trains[0].tseats = 100; trains[0].tfare = 2500;
        
        trains[1].tname = "Karakoram"; trains[1].tseats = 90; trains[1].tfare = 2200;
        
        trains[2].tname = "PakExpress"; trains[2].tseats = 120; trains[2].tfare = 1800;
        
        trains[3].tname = "TezGam"; trains[3].tseats = 80; trains[3].tfare = 2000;
        
        trainCount = 4;
    }

    void ViewTrain() {
        cout << "\n---------- TRAIN SCHEDULE -----------------\n"<<endl;
        
        cout << setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(10)<<"SEATS"<<setw(10)<<"FARE"<<endl;
        
        for(int i = 0; i < trainCount; i++) 
		{
            	cout << setw(3) << i+1 
                 << setw(15) << trains[i].tname 
                 << setw(10) << trains[i].tseats 
                 << setw(10)<< "Rs " << trains[i].tfare << endl;
        }
        cout<<endl<<"=================================================\n"<<endl;
    }

    void addTrain() {
        cout << "\nEnter Train Name: "; 
		cin >> trains[trainCount].tname;
        cout << "Enter Seats: "; 
		cin >> trains[trainCount].tseats;
        cout << "Enter Fare: "; 
		cin >> trains[trainCount].tfare;
        trainCount++;
        cout<<endl;
        cout << "Train Added Successfully!\n"<<endl<<endl;
    }

    void editTrain() {
        int id;
        cout << "Enter Train Number to Edit: "; 
		cin >> id;
        id--;
        
        if(id >= 0 && id < trainCount) {
            cout << "Enter New Name: "; 
			cin >> trains[id].tname;
            cout << "Enter New Seats: "; 
			cin >> trains[id].tseats;
            cout << "Enter New Fare: "; 
			cin >> trains[id].tfare;
            cout << "Train Updated!\n"<<endl<<endl;
            
        } else
		 { cout << "Invalid Train ID!\n"<<endl; }
    }

    void deleteTrain() {
        int id;
        cout << "Enter Train Number to Delete: "; 
		cin >> id;
        id--;
        
        if(id >= 0 && id < trainCount) {
            for(int i=id; i<trainCount-1; i++) 
			{ 
				trains[i] = trains[i+1]; 
			}
            trainCount--;
            cout<<" / / / / / TRAIN DELETED / / / / / "<<endl<<endl;
        } else 
		{ 
			cout<<"<<<<  INVALID ID >>>>"<<endl<<endl; 
		}
    }
};

// STAFF MANAGEMENT CLASS
class StaffManagement {
public:
    Staff staff[20];
    int staffCount;

    StaffManagement() {
        staffCount = 3;
        
        staff[0] = {"Ali","Manager","03001234567"};
        
        staff[1] = {"Sara","Clerk","03119876543"};
        
        staff[2] = {"Ahmed","Driver","03335557777"};
    }

    void viewStaff() {
        cout << "\n---------- STAFF DATA  -----------------\n"<<endl;
        
        cout << setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(10)<<"ROLE"<<setw(16)<<"PHONE"<<endl;
        
        for(int i = 0; i < staffCount; i++) {
            cout << setw(3) << i+1
                 << setw(15) << staff[i].sname
                 << setw(10) << staff[i].srole
                 << setw(16) << staff[i].sphone << endl;
        }
        cout<<endl<<"=================================================\n"<<endl;
    }

    void addStaff() 
	{
        cout << "\nEnter Staff Name: "; 
		cin >> staff[staffCount].sname;
        cout << "Enter Staff role : "; 
		cin >> staff[staffCount].srole;
        cout << "Enter Phone #  "; 
		cin >> staff[staffCount].sphone;
        staffCount++;
        
        cout<<endl<<" >>>>>> STAFF Added Successfully! <<<<<< "<<endl<<endl;
    }

    void editStaff() {
        int id;
        cout << "Enter STAFF ID to Edit: "; cin >> id;
        id--;
        if(id >= 0 && id < staffCount) 
		{
            cout << "Enter New Name: "; 
			cin >> staff[id].sname;
            cout << "Enter New Role: "; 
			cin >> staff[id].srole;
            cout << "Enter New Phone: "; 
			cin >> staff[id].sphone;
			
            cout<<endl<<" >>>>>>>>> STAFF Updated! <<<<<<<<<<"<<endl;
        } else 
		{ 
		cout << "Invalid STAFF ID!\n"<<endl; 
		}
    }

    void deleteStaff() {
        int id;
        cout << "Enter STAFF Number to Delete: "; 
		cin >> id;
        id--;
        if(id >= 0 && id < staffCount) {
            for(int i=id;i<staffCount-1;i++){ staff[i]=staff[i+1]; }
            staffCount--;
            cout<<" / / / / / STAFF DELETED / / / / / "<<endl;
        } else { cout<<"<<<<  INVALID ID >>>>"<<endl; }
    }
};

// RESERVATION MANAGEMENT CLASS
class ReservationManagement {
public:
    Reservation bookings[20];
    int bookingCount;

    ReservationManagement() {
        bookingCount = 3;
        
        bookings[0] = {"Ahmed",0,2};
        
        bookings[1] = {"Fatima",1,4};
        
        bookings[2] = {"Omar",2,1};
    }

    void viewReservations(TrainManagement &tm) 
	{
        cout << "\n---------- RESERVATION DATA  -----------------\n"<<endl;
        cout << setw(3)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"TRAIN"<<setw(10)<<"SEATS"<<endl;
        
        for(int i = 0; i < bookingCount; i++) 
		{
            cout << setw(3) << i+1
                 << setw(15) << bookings[i].cname
                 << setw(15) << tm.trains[bookings[i].bookedTrain].tname
                 << setw(10) << bookings[i].bookedSeats << endl;
        }
        
        cout<<"===================================================="<<endl<<endl;
    }

    void reserveSeat(TrainManagement &tm) 
	{
        cout << "\nEnter Customer Name: "; 
		cin >> bookings[bookingCount].cname;
        tm.ViewTrain();
        cout << "Enter Train Number to Book: ";
        cin >> bookings[bookingCount].bookedTrain;
        bookings[bookingCount].bookedTrain--; // adjust index
        cout << "Enter Number of Seats: "; 
		cin >> bookings[bookingCount].bookedSeats;
        bookingCount++;
        
        cout << ">>>>>> SEAT RESERVED Successfully! <<<<<<<"<<endl;
    }

    void editSeat(TrainManagement &tm) {
        int id;
        cout << "Enter Reservation ID to Edit: "; 
		cin >> id;
        id--;
        if(id >= 0 && id < bookingCount) {
            cout << "Enter New Name: "; 
			cin >> bookings[id].cname;
            tm.ViewTrain();
            cout << "Enter New Train Number: "; 
			cin >> bookings[id].bookedTrain;
            bookings[id].bookedTrain--;
            cout << "Enter New No of Seats: "; 
			cin >> bookings[id].bookedSeats;
            cout << ">>>>>>>>> RESERVATION Updated! <<<<<<<<<<"<<endl;
            
        } else 
		{ 
		cout << "Invalid RESERVATION ID!\n"<<endl; 
		}
    }

    void deleteSeat() {
        int id;
        cout << "Enter RESERVATION Number to Delete: "; cin >> id;
        id--;
        if(id >= 0 && id < bookingCount) {
            for(int i=id;i<bookingCount-1;i++)
			{
			 bookings[i]=bookings[i+1]; 
			}
            bookingCount--;
            cout<<" / / / / / RESERVATION DELETED / / / / / "<<endl;
        } 
		else 
		{ 
		cout<<"<<<<  INVALID ID >>>>"<<endl<<endl; 
		}
    }
};

// MAIN FUNCTION
int main() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    TrainManagement tm;
    StaffManagement sm;
    ReservationManagement rm;

    int choice;
    string user, pass;

    while (true) 
	{
        cout << "  _________\033[32m______________________________________ "  << "\033[0m"<<endl;
        cout << " |         \033[32m                                      |" << "\033[0m"<<endl;
        cout << " |         \033[32m        WELCOME TO PAKISTAN           |" << "\033[0m"<<endl;
        cout << " |         \033[32m                                      |" << "\033[0m"<<endl;
        cout << " |         \033[32m     TRAIN MANAGEMENT SYSTEM          |" << "\033[0m"<<endl;
        cout << " |_________\033[32m______________________________________|" << "\033[0m"<<endl;
        cout << endl;
        cout << " |  1.  ADMIN MODE                               |" << endl;
        cout << " |  2.  EMPLOYEE MODE                            |" << endl;
        cout << " |  3.  EXIT                                     |" << endl;
        cout << " -------------------------------------------------" << endl;
        cout<<endl;
        cout << " <----------- Enter your choice -----------> ";
        cin >> choice;
        cout<<endl;

        if(choice==1) {
            cout<<"UserName :  "; cin>>user;
            cout<<"Password :  "; cin>>pass;
            cout<<endl;

            while(true) {
                int a;
                if(user == "admin" && pass == "123") {
                    cout << "\033[32m |-------------ADMIN PANEL-----------------------|" << endl;
                    cout << " |  1.  VIEW TRAINS                              |" << endl;
                    cout << " |  2.  ADD TRAINS                               |" << endl;
                    cout << " |  3.  EDIT TRAIN                               |" << endl;
                    cout << " |  4.  DELETE TRAIN                             |" << endl;
                    cout << " |  5.  VIEW STAFF                               |" << endl;
                    cout << " |  6.  ADD STAFF                                |" << endl;
                    cout << " |  7.  EDIT STAFF                               |" << endl;
                    cout << " |  8.  DELETE STAFF                             |" << endl;
                    cout << " |  9.  VIEW RESERVATIONS                        |" << endl;
                    cout << " |  10. LOG OUT                                  | \033[0m " << endl;

                    cout<<endl<<" <----------- Enter your choice -----------> ";
                    cin>>a;
                    cout<<endl;

                    if(a==1) tm.ViewTrain();
                    else if(a==2) tm.addTrain();
                    else if(a==3) tm.editTrain();
                    else if(a==4) tm.deleteTrain();
                    else if(a==5) sm.viewStaff();
                    else if(a==6) sm.addStaff();
                    else if(a==7) sm.editStaff();
                    else if(a==8) sm.deleteStaff();
                    else if(a==9) rm.viewReservations(tm);
                    else if(a==10) break;
                    else cout<<">>>>>>>>>>>>> INVALID CHOICE <<<<<<<<<<<<"<<endl;
                }
            }
        }

        else if(choice==2) {
            cout<<"UserName :  "; 
			cin>>user;
            cout<<"Password :  "; 
			cin>>pass;
            cout<<endl;

            if(user == "employee" && pass == "789") {
                while(true) {
                    int a;
                    
                    cout<<" \033[33m ";
                    cout << " |-------------EMPLOYEE PANEL-----------------------|" << endl;
                    cout << " |  1.  TRAIN MANAGEMENT                            |" << endl;
                    cout << " |  2.  RESERVATION MANAGEMENT                      |" << endl;
                    cout << " |  3.  STAFF MANAGEMENT                            |" << endl;
                    cout << " |  4.  LOGOUT                                      |" << endl;
                    cout<<endl;
                    cout<<"\033[0m";
                    
                    cout << " <----------- Enter your choice -----------> "; 
					cin>>a;
					

                    if (a==1) {
                        int t;
                        
                        cout<<" \033[34m ";
                        cout << " |  1.  VIEW TRAIN                                  |" << endl;
                        cout << " |  2.  ADD TRAIN                   			     |" << endl;
                        cout << " |  3.  EDIT TRAIN                                  |" << endl;
                        cout << " |  4.  DELETE TRAIN                                |" << endl;
                        cout << " |  5.  EXIT                                        |" << endl;
                        cout<<endl;
                        
                        cout<<"\033[0m";
                        
                        cout << " <----------- Enter your choice -----------> "; 
						cin>>t;
						
                        if(t==1) tm.ViewTrain();
                        else if(t==2) tm.addTrain();
                        else if(t==3) tm.editTrain();
                        else if(t==4) tm.deleteTrain();
                        else if(t==5) break;
                    }
                    else if(a==2) 
					{
                        int r;
                        
                        cout<<" \033[35m ";
                        cout << " |  1.  VIEW RESERVATIONS                                  |" << endl;
                        cout << " |  2.  ADD RESERVATIONS                     			    |" << endl;
                        cout << " |  3.  EDIT RESERVATIONS                                  |" << endl;
                        cout << " |  4.  DELETE RESERVATIONS                                |" << endl;
                        cout << " |  5.  EXIT                                               |" << endl;
                        cout<<endl;
                        cout<<"\033[0m";
                        
                        cout << " <----------- Enter your choice -----------> "; 
						cin>>r;
                        
                        if(r==1) rm.viewReservations(tm);
                        else if(r==2) rm.reserveSeat(tm);
                        else if(r==3) rm.editSeat(tm);
                        else if(r==4) rm.deleteSeat();
                        else if(r==5) break;
                    }
                    else if(a==3) 
					{
                        int r;
                        
                        cout<<" \033[36m ";
                        cout << " |  1.  VIEW STAFF                                         |" << endl;
                        cout << " |  2.  ADD STAFF                      			        |" << endl;
                        cout << " |  3.  EDIT STAFF                                         |" << endl;
                        cout << " |  4.  DELETE STAFF                                       |" << endl;
                        cout << " |  5.  EXIT                                               |" << endl;
                        cout<<endl;
                        cout<<"\033[0m";
                        
                        cout << " <----------- Enter your choice -----------> "; 
						cin>>r;
						
                        if(r==1) sm.viewStaff();
                        else if(r==2) sm.addStaff();
                        else if(r==3) sm.editStaff();
                        else if(r==4) sm.deleteStaff();
                        else if(r==5) break;
                    }
                    else if(a==4) 
					{
                        cout<<">>>>>>>>>>>> EXITING <<<<<<<<<<"<<endl;
                        break;
                    }
                }
            }
        }
        else if(choice==3) break;
    }
    return 0;
}

