#include <iostream>
#include <string>
#define size 3


using namespace std;

struct store{
 int code;
 int year;
 string name;
 string type;
 store* next;
 store* prev;
 
};store *prev=NULL,*head=NULL,*tail=NULL,*temp=NULL,*cur=NULL,*next=NULL;


struct RentList{
 int code;
 int year;
 int ReturnDate;
 string name;
 string type;
 RentList* next2;
 RentList* prev2;
 
};RentList *prev2=NULL,*head2=NULL,*tail2=NULL,*temp2=NULL,*cur2=NULL,*next2=NULL;


struct CusList{
 string cosName;
 int code;
 int year;
 string name;
 string type;
 CusList* next3;
 CusList* prev3;
 
};CusList *prev3=NULL,*head3=NULL,*tail3=NULL,*temp3=NULL,*cur3=NULL,*next3=NULL;


int IdList[size]={1,2,3};
string NameList[size]={"TheShawshankRedemption","PulpFiction","StarWars"};
string movietype[size]={"drama","crime/drama","Action/adventure/fantasy"};
int date[size]={1994,1994,1997};


void CreateList()
{
    for(int i=0; i<size; i++){
	
	temp = new store;
    temp->code=IdList[i];
    temp->name=NameList[i];
    temp->type=movietype[i];
    temp->year=date[i];
    
    temp->prev=NULL;
    temp->next=NULL;
        
	 if(head == NULL){
 	head = temp;
 	tail = temp;
 }
 else{
 	tail->next = temp;
 	temp->prev = tail;
	tail = temp;
 }
}
}	

void movetoList(){
	temp = new store;
 
	temp->code=temp2->code;
	temp->name=temp2->name;
	temp->type=temp2->type;
	temp->year=temp2->year;


	 if(head == NULL){
 		head = temp;
 		tail = temp;
	}
 else{
	tail->next = temp;
	temp->prev = tail;
	tail = temp;
 }
 }
 



	

 void moveToCusList(string cosname){
 	
  
	temp3 = new CusList;
	temp3->cosName= cosname;
	temp3->code=temp->code;
	temp3->name=temp->name;
	temp3->type=temp->type;
	temp3->year=temp->year;


 	if(head3 == NULL){
 		head3 = temp3;
 		tail3 = temp3;
 }
 	else{
 		tail3->next3 = temp3;
		temp3->prev3 = tail3;
 		tail3 = temp3;
 }
 }

void moveToRent(int date){
	temp2 = new RentList;
 
	temp2->code=temp->code;
	temp2->name=temp->name;
	temp2->type=temp->type;
	temp2->year=temp->year;
	temp2->ReturnDate=date;

 	if(head2 == NULL){
 		head2 = temp2;
 		tail2 = temp2;
 }
	else{
		tail2->next2 = temp2;
		temp2->prev2 = tail2;
		tail2 = temp2;
 }
 }

void rent(){
  		
	string cosname;
	int date;
  	
	int c;
	temp = head;
 
	if(temp != NULL){
		cout<<"--Rent a movie--\n";
		cout<<"Enter Costemor Name:"<<endl;;
		cin>>cosname;	
	 	cout<<"How many days do you want to rent the movie?"<<endl;		
		cin>>date;
		cout<<"Enter the code: ";
		cin >> c;

	while(temp != NULL){
		if(temp->code == c){
			moveToRent(date);
			moveToCusList(cosname);
		if(temp->prev != NULL && temp->next !=NULL){ 
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
 }
	else if(temp->prev == NULL && temp->next !=NULL){
		head = temp->next;
		head->prev = NULL;
		delete temp;
					 
}	else if(temp->prev != NULL && temp->next ==NULL) {			 	
		tail = temp->prev;
		tail->next = NULL;
		delete temp;
}	else{		 	
		head = tail = NULL;
		delete temp;
 }
	break;
}
	else{
		temp = temp->next;
}
}
	if(temp == NULL){
		cout << c << " Not Found." << endl;
}	
}
	else{
		cout << "empty" << endl;
	 }
 }
 
 void return2list(){
 	RentList *temp2 = head2;
 	RentList *prev2 = NULL;
 	RentList *cur2=temp2;
 	if(head == NULL){
 		cout<<"List is empty"<<endl;
 }
 	else{
		int c;
		cout<<"Enter the code: ";
	 	cin >> c;
	while(cur2!=NULL&& cur2->code!=c){	
		prev2 = cur2;
		cur2 = cur2->next2;
 }
 	if(cur2==NULL){
 		cout<<"Not Found. "<<endl;
 }
 	if(temp2 != NULL && temp2->code == c){
 		head2 = temp2->next2;
 		movetoList();
 		delete temp;
 }
 	else{
 		while(temp2 != NULL && temp2->code != c){
 			prev2 = temp2;
			temp2 = temp2->next2;
 }
 	if(temp!=NULL){
 		prev2->next2 = temp2->next2;
 		delete temp;
 }
 }
 }
 }



void MovieDetails(){
	string mvn;
	temp = head;
 	
	if(temp != NULL){
		cout <<"Enter The Name of Movie : ";
	 	cin >> mvn;
	 		while(temp != NULL){
	 			if(temp->name == mvn){
	 				cout <<"Code of Movie : ";
	 				cout << temp->code << endl;
	 				cout <<"The Name of Movie : ";
	 				cout << temp->name << endl;
	 				cout <<"Type of Movie : ";
	 				cout << temp->type << endl;
	 				cout <<"The Year of Movie : ";
	 				cout << temp->year << endl <<endl;
	 			break;
			 }else{
			 	temp = temp->next;
			 }
		 }if(temp == NULL){
		 	cout <<"There is No " << mvn << " In Library" << endl;
		 }else{
		 }
	 }
	else{
	 	cout << "empty" << endl;
	 }
 }
 
void Chacking(){
 	string mvn;
 	temp = head;
 	
	if(temp != NULL){
		cout <<"Enter The Name of Movie : ";
	 	cin >> mvn;
	 		while(temp != NULL){
	 			if(temp->name == mvn){
	 				cout << mvn <<" Is Available." << endl << endl;
	 			break;
		 }else{
			temp = temp->next;
			 }
		 }if(temp == NULL){
		 		cout << mvn << " Is Unavailable." << endl << endl;
		 }
	 }
	 else{
		cout << "empty" << endl;
	 }
 }
 
 void printCusList(){
 	cur3 = head3;
 		if(head3 == NULL){
			 cout<<"There are no movies\n";
 }
 		else{
 			cout<<"---Rented Movies---\n";
 			while(cur3 != NULL){
 
				cout<<"Costemor name: "<<cur3->cosName<<endl;
				cout<<"Code the movie:"<<cur3->code<<endl;
				cout<<"Name the movie:"<<cur3->name<<endl;
				cout<<"Movie type: "<<cur3->type<<endl;
				cout<<"Made in: "<<cur3->year<<endl;
				cout<<"--------------------\n";
				
				cur3 = cur3->next3;
 }

 }
}

void printRentList(){
	cur2 = head2;
 		if(head2 == NULL){
 			cout<<"There are no movies\n";
 }
 		else{
 			cout<<"---Rented Movies---\n";
 				while(cur2 != NULL){
 
 					cout<<"Code the movie:"<<cur2->code<<endl;
					cout<<"Name the movie:"<<cur2->name<<endl;
					cout<<"Movie type: "<<cur2->type<<endl;
					cout<<"Made in: "<<cur2->year<<endl;
					cout<<"--------------------\n";
					
					cur2 = cur2->next2;
 }

 }
}

void printDateList(){
 	cur2 = head2;
 		if(head2 == NULL){
 		cout<<"There are no movies\n";
 }
 		else{
 		cout<<"---Rented Movies---\n";
 			while(cur2 != NULL){
 
 				cout<<"Code the movie:"<<cur2->code<<endl;
				cout<<"Name the movie:"<<cur2->name<<endl;
				cout<<"it will be available on "<<cur2->ReturnDate<<" days."<<endl;
 				cout<<"--------------------\n";
 				
				cur2 = cur2->next2;
 }

 }
}


void printStoreMovies(){
	cur = head;
	if(head == NULL){
 	cout<<"There are no movies\n";
 }
 	else{
 		cout<<"---All Movies---\n";
			 while(cur != NULL){
 
 			cout<<"Code the movie:"<<cur->code<<endl;
 			cout<<"Name the movie:"<<cur->name<<endl;
 			cout<<"Movie type: "<<cur->type<<endl;
			cout<<"Made in: "<<cur->year<<endl;
			cout<<"--------------------\n";
			
			cur = cur->next;
 }

 }
}



int main(){

	CreateList();	

	char x;
 
	cout<<"Welcome to the movie store!\n";
	cout<<endl;
		do{
			cout<<"1) Rent a movie\n";
			cout<<"2) Return a movie\n";
			cout<<"3) Print all movies\n";
			cout<<"4) Print rented movies\n";
			cout<<"5) Search About Movie\n";
			cout<<"6) Check About Movie\n";
			cout<<"7) Show Customers List\n";
			cout<<"8) Movie must returned in specfic date \n";
			cout<<"9) Exit\n";
			cin>>x;
				switch(x){
					case '1':
						rent();
						break;
					case '2':
 						cout<<"--Return a movie--\n";
 						return2list();
 						break;
					case '3':
						printStoreMovies();
						break;
 
					case '4':
 						printRentList();
 						break; 
 
					case '5':
 						MovieDetails();
	 					break;
 	
					case '6':
 						Chacking();
 						break;
					case '7':
    					printCusList();
    					break;
    	
					case '8':
    					printDateList();
   					 	break;
    	    	
					case '9':
 						cout<<"Thank you\n";
 						break;
    	
 					default:
						cout<<"Error\n";
 }
 					}while(x!='9');
 return 0;
}
