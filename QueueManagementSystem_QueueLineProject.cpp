#include <iostream>
#include"ClsQueueLine.h"
using namespace std;
int main()
{
    ClsQueueLine PayBillsQueue("A0", 10);
    ClsQueueLine SubscriptionQueue("B0", 5);
    PayBillsQueue.IssueTickets();
    PayBillsQueue.IssueTickets();
    PayBillsQueue.IssueTickets();
    PayBillsQueue.IssueTickets();
    cout << "The pay bills queue info:";
    PayBillsQueue.PrintInfo();
    PayBillsQueue.PrintTicketsLineLTR();
    PayBillsQueue.PrintTicketsLineRTL();
    PayBillsQueue.PrintAllTickets();
    PayBillsQueue.ServeNextClient();
    cout << "\n\t\t\tPay Bills Queue After Serving One client\n";
    PayBillsQueue.PrintInfo();
    //////////////////////////////////////////////////////////////////
    cout << "\n\t\t\tSubscription Queue Info\n";
    SubscriptionQueue.IssueTickets();
    SubscriptionQueue.IssueTickets();
    SubscriptionQueue.IssueTickets();
    SubscriptionQueue.IssueTickets();

    cout << "The Subscription Queue info" << endl;
    SubscriptionQueue.PrintInfo();
    SubscriptionQueue.PrintTicketsLineLTR();
    SubscriptionQueue.PrintTicketsLineRTL();
    SubscriptionQueue.PrintAllTickets();
    SubscriptionQueue.ServeNextClient();
    cout << "\n\t\t\tSubscription Queue After Serving One client\n";
    SubscriptionQueue.PrintInfo();
    



    
}
