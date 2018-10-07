/*Author : Kanishk Gautam*/


#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	string name;
	string number;
	string action;
	char* time;
	Node*next;

	Node(string name,string number)
	{
		this->name=name;
		this->number=number;
		next=NULL;
	}
};
class Nodejs
{
public:
	string name;
	string number;
	string action;
	char* time;
	Nodejs(string name,string number,string action,char * time)
	{
		this->name=name;
		this->number=number;
		this->action=action;
		this->time=time;
	}
};

class phonebook
{
	Node*head;
	Node*tail;
	queue<Nodejs*>recent;

public:

	phonebook()
	{
		head=NULL;
		tail=NULL;
	}

	void insertcontact(string name,string number)
	{
		Node*temp=new Node(name,number);
		temp->action="Inserted";

	   time_t now=time(0);
	   char*st=ctime(&now);
	   temp->time=st;

		Nodejs*xx=new Nodejs(temp->name,temp->number,temp->action,temp->time);
		act(xx);

		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}

		else
		{
			tail->next=temp;
			tail=tail->next;
		}
	}


Node* deletecontact(Node* head,string name,bool & temp)
{
	if(head==NULL)
		{return NULL;}

	if(head->name==name)
	{
		Node*x=head->next;
		head->action="Deleted";
		 time_t now=time(0);
	     char*st=ctime(&now);
	     head->time=st;
		 Nodejs*xx=new Nodejs(head->name,head->number,head->action,head->time);
		act(xx);
		delete head;
		temp=true;
		return x;
	}

	Node*f=deletecontact(head->next,name,temp);
	head->next=f;
	return head;
}





	void deletecontact(string name)
	{
		bool temp=false;
		head=deletecontact(head,name,temp);

		if(temp)
			{cout<<"The desired contact has been successfully deleted"<<endl;}
		else
		{
			cout<<"No such contact found in the phonebook"<<endl;
		}

	}

void searchcontact(Node*head,string name)
{
	if(head==NULL)
		{return;}

	if(head->name.find(name)!=-1)
	{
		cout<<head->name<<" "<<head->number<<endl;
		head->action="Searched";
		 time_t now=time(0);
	     char*st=ctime(&now);
	     head->time=st;
		 Nodejs*xx=new Nodejs(head->name,head->number,head->action,head->time);
		act(xx);
		
	}

	searchcontact(head->next,name);
}


	void searchcontact(string name)
	{
		searchcontact(head,name);
	}



	void updatecontactnumber(Node*head,string name,string number,bool &temp,string newnumber)
	{
		if(head==NULL)
			{return;}

		if(head->name==name && head->number==number)
		{
			head->number=newnumber;
			temp=true;
			head->action="Updated Number";
			 time_t now=time(0);
	     char*st=ctime(&now);
	     head->time=st;
		 Nodejs*xx=new Nodejs(head->name,head->number,head->action,head->time);
			
		act(xx);
			
			return;
		}

		updatecontactnumber(head->next,name,number,temp,newnumber);

	}

	void updatecontactnumber(string name, string number,string newnumber)
	{
		bool temp=false;
		updatecontactnumber(head,name,number,temp,newnumber);
		if(temp)
		{
			cout<<"The mobile phone number of "<<name<<" has been updated successfully as "<<newnumber<<endl;
		}
		else
		{
			cout<<"No such contact name found in the phonebook :("<<endl;
		}
	}

	void updatecontactname(Node*head,string name,string number,bool &temp,string newname)
	{
		if(head==NULL)
			{return;}

		if(head->number==number && head->name==name)
		{
			head->name=newname;
			temp=true;
			head->action="Updated Name";
			 time_t now=time(0);
	     char*st=ctime(&now);
	     head->time=st;
		 Nodejs*xx=new Nodejs(head->name,head->number,head->action,head->time);
			
		act(xx);
		
			return;
		}

		updatecontactname(head->next,name,number,temp,newname);

	}

	void updatecontactname(string name, string number,string newname)
	{
		bool temp=false;
		updatecontactname(head,name,number,temp,newname);
		if(temp)
		{
			cout<<"The contact name of "<<number<<" has been updated successfully as "<<newname<<endl;
		}
		else
		{
			cout<<"No such mobile phone number found in the phonebook :("<<endl;
		}
	}


    void display(Node*head)
    {
    	if(head==NULL)
    		{return;}
    	cout<<head->name<<" "<<head->number<<endl;
    	display(head->next);
    }

	void display()
	{
		display(head);
	}

	void act(Nodejs*head)
	{
		if(recent.size()>10)
		{
			recent.pop();
			recent.push(head);
		}

		else
		{
			recent.push(head);
		}
	}

	void recentdisplay()
	{
		queue<Nodejs*>qtemp=recent;
		stack<Nodejs*>s;
		while(qtemp.size()!=0)
		{
			Nodejs*temp=qtemp.front();
			qtemp.pop();
			s.push(temp);
		}
		
		while(s.size()!=0)
		{
			Nodejs*front=s.top();
			s.pop();
			cout<<"Name: "<<front->name<<"\nNumber: "<<front->number<<"\nAction: "<<front->action<<"\nDate & Time: "<<front->time<<endl;
		}
	}

	void activity(Node*head,string name)
	{
		if(head==NULL)
			{cout<<"No such account found"<<endl;
	        return;}
		if(head->name==name)
		{
			cout<<"Name: "<<head->name<<"\nActivity: "<<head->action<<"\nTime:"<<head->time<<endl;
			return;
		}
		activity(head->next,name);
	}

	void activity(string name)
	{
		activity(head,name);
		return;
	}


};



int main()
{
  phonebook mi;
   int var=1;
   cout<<"\nWelcome to your own personalized phonebook, press the below given buttons for appropriate functions "<<endl;

   while(var)
   {
   	int func;
   	cout<<"\n1: Inserting a contact\n2: Searching a contact\n3: Updating a contact\n4: Deleting a contact\n5: Displaying the entire phonebook\n6: Recent actions\n7: Recent activity with a contact\n8: Exiting the phonebook\n"<<endl;
    cin>>func;
    cin.ignore();
    string name;
    string number;

    switch(func)
    {
    	case 1:
    	
    		  		
    		cout<<"\nPlease enter the name of the person: "<<endl;
    		getline(cin,name);
    		cout<<"\nPlease enter the contact number of the person: "<<endl;
    		cin>>number;
    		mi.insertcontact(name,number);
    		break;

    	
    	case 2:
    	
    		
    		cout<<"\nPlease enter the contact to be searched: "<<endl;
    		getline(cin,name);
    		mi.searchcontact(name);
    		break;

    	
    	case 3:
    	
    		int temp;
            cout<<"\nIf you want to update contact number press: 1\n else if you want to update contact's name press: 0"<<endl;
            cin>>temp;
            cin.ignore();
            cout<<"\nEnter name to be updated "<<endl;
            getline(cin,name);
            cout<<"\nEnter number to be updated "<<endl;
            cin>>number;
            cin.ignore();
            
            
            if(temp)
            {

            	cout<<"\nEnter new number "<<endl;
                string newnumber;
                getline(cin,newnumber);
               mi.updatecontactnumber(name,number,newnumber);
            }
            else
            {
            	cout<<"\nEnter new name "<<endl;
                string newname;
                getline(cin,newname);
               mi.updatecontactname(name,number,newname);
            }
            break;
    	
    	case 4:
    	
    		cout<<"\nEnter the contact to be deleted "<<endl;
    		getline(cin,name);
    		mi.deletecontact(name);
    		break;
    	
    	case 5:
    	    mi.display();
    	    break;

    	case 6:
    	    mi.recentdisplay();
    	    break;

    	case 7:
    	    cout<<"\nEnter the contact name "<<endl;
    	    getline(cin,name);
    	    mi.activity(name);
    	    break;

    	case 8:
    	
           var=0;
           break;
    	
    	default:
    	cout<<"\nThanks for using the phonebook \a"<<endl;
    	return 0;
    	
    }



   }


}