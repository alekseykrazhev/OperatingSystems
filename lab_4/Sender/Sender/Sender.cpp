#include <windows.h>
#include <iostream>
#include <fstream>

#include "Queue.h"

using namespace std;

int main(int argc, char* argv[])
{
	int process_num = atoi(argv[2]);	

	cout << "Process Sender " << process_num << " started work." << endl << endl;

	char EventNum[256];					
	sprintf_s(EventNum, "Event of the process %d", process_num);

	char binary_file_path[1000];		
	sprintf_s(binary_file_path, "%s", argv[1]);

	HANDLE EventFromSender = OpenEvent(
		NULL,								
		TRUE,								
		TEXT(EventNum)					
	);

	SetEvent(EventFromSender);

	while (true)
	{
		cout << "Process Sender " << process_num << ": Waiting for the queue..." << endl;
		HANDLE Semaphore = OpenSemaphore(
			NULL,						
			TRUE,					
			TEXT("Sender")					
		);
	
		ReleaseSemaphore(
			Semaphore,				
			1,							
			NULL							
		);
		cout << "Process Sender " << process_num << ": Write the message to the Receiver or write \"exit\" to complete work:" << endl;
		char message[20];				
		cin.getline(message, 20);			
		if (!strncmp(message, "exit", 4))	
			break;				
		else
		{
			Queue MessagesQueue;			
			ifstream fin(binary_file_path);	
			while (fin.peek() != EOF)
			{
				char* temp = new char[20];
				fin.getline(temp, 20);
				AddToQueue(&MessagesQueue, temp);
				delete[] temp;
			}
			fin.close();
			ofstream fout(binary_file_path);
			while (!QueueIsEmpty(&MessagesQueue))
			{
				fout << MessagesQueue.first->msg << endl;
				DeleteFromQueue(&MessagesQueue);
			}
			fout << message << endl;
			cout << "Message from Process Sender " << process_num << " successfully sent" << endl;
			fout.close();	
		}
		cout << endl;
	}

	cout << "Process Sender " << process_num << " completed work." << endl;

	CloseHandle(EventFromSender);	

	return 0;
}