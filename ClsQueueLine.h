#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include"ClsDateLibrary.h"

using namespace std;

class ClsQueueLine
{
	
private:
	short _TotalNumberOfTickets=0;
	string _Prefix="";
	short _AverageTime=0;
	class ClsTickets
	{
		private:
		short _Number=0;
		string _Prefix;
		string  _TicketTime;
		short _WaitingClients=0;
		short _ExpectedServiceTime=0;
		short _AverageServiceTime = 0;
	public:
		ClsTickets(string prefix,short number,short WaitingClients,short AverageServiceTime)
		{
			_Number = number;
			_Prefix = prefix;
			_TicketTime = ClsDateLibrary::GetSystemDateTimeString();
			_WaitingClients = WaitingClients;
			_AverageServiceTime = AverageServiceTime;
		}
		string GetPrefix()
		{
			return _Prefix;
		}
		short GetNumber()
		{
			return _Number;
		}
		string FullNumber()
		{
			return _Prefix + to_string(_Number);
		}
		string TicketTime()
		{
			return _TicketTime;
	    }
		short WaitingClients()
		{
			return _WaitingClients;
		}
		short ExpectedTime()
		{
			return _AverageServiceTime * _WaitingClients;
		}
		void Print()
		{
			cout << "\n\t\t\t -------------------------\n";
			cout << "\n\t\t\t" << FullNumber() ;
			cout << "\n\t\t\t" <<  _TicketTime;
			cout << "\n\t\t\t Waiting Clients " << WaitingClients();
			cout << "\n\t\t\t Serve time in ";
			cout << "\t" << ExpectedTime() << " Minutes";
			cout << "\n\t\t\t -------------------------\n";
		}

	};
public:
	//Every element in the QueueLine is a ticket
	queue<ClsTickets>QueueLine;

	ClsQueueLine(string prefix,short AverageTime)
	{
		_Prefix = prefix;
		_AverageTime = AverageTime;
		_TotalNumberOfTickets = 0;
	}


	int WaitingClients()
	{
		return QueueLine.size();
	}

	int ServedClients()
	{
		return _TotalNumberOfTickets - WaitingClients();
	}

	void IssueTickets()
	{
		_TotalNumberOfTickets++;
		//Make new ticket object from the class of ClsTickets
		ClsTickets Ticket(_Prefix, _TotalNumberOfTickets, WaitingClients(),_AverageTime);
		QueueLine.push(Ticket);
	}
	string WhoIsNext()
	{
		if (QueueLine.empty())
			return "No Clients Left";
		else
			return QueueLine.front().FullNumber();
	}
	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;
		else
			QueueLine.pop();

		    return true;
	}
	void PrintInfo()
	{
		cout << "\n\t\t\t--------------------------------------\n";
		cout << "\n\t\t\t          Queue Info\t\t\t" << endl;
		cout << "\n\t\t\t--------------------------------------\n";
		cout << "\t\t\tPrefix " << _Prefix << endl;
		cout << "\t\t\tTotalTickets " << _TotalNumberOfTickets << endl;
		cout << "\t\t\tServed Clients " << ServedClients() << endl;
		cout << "\t\t\tWaiting Clients " << WaitingClients() << endl;
		cout << "\t\t\t--------------------------------------\n";
	}
	void PrintTicketsLineRTL()
	{
		if (QueueLine.empty())
			cout << "\n\t\t\t tickets:No tickets available";
		else
			cout << "\n\t\t\t tickets:";
		queue <ClsTickets>tempQueueLine = QueueLine;
		while (!tempQueueLine.empty())
		{
			ClsTickets Ticket = tempQueueLine.front();
			cout << "  " << Ticket.FullNumber()<<"<--- ";
			tempQueueLine.pop();
		}
		cout << "\n";
	}
	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty())
			cout << "\n\t\t\t tickets:No tickets available";
		else
			cout << "\n\t\t\t tickets:";
		queue <ClsTickets>tempQueueLine = QueueLine;
		stack<ClsTickets>tempStackLine;
		while (!tempQueueLine.empty())
		{
			tempStackLine.push(tempQueueLine.front());
			tempQueueLine.pop();
		}
		while (!tempStackLine.empty())
		{
			ClsTickets Ticket = tempStackLine.top();
			cout << "  " << Ticket.FullNumber() << "---> ";
			tempStackLine.pop();
		}
		cout << "\n";
	}
	void PrintAllTickets()
	{

		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";

		//we copy the queue in order not to lose the original
		queue <ClsTickets> TempQueueLine = QueueLine;


		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}
	}


};

