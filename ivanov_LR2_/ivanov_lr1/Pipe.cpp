#include "Pipe.h"
#include "Utilities.h"
int Pipe::maxId = 0;
int Pipe::GetId()
{
	return Id;
}
string Pipe::GetName() const
{
	return pipeName;
}
bool Pipe::GetStatus()
{
	return pipeRepair;
}
void Pipe::PrintPipeRepair()
{
	if (pipeRepair == true)
	{
		cout << "Pipe under repair [=1]\n";
	}
	else
		cout << "Pipe is not in repair [=0]\n";
}
void EditPipe(Pipe& pipe)
{
	cout << "Repair status will be changed, do you agree?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "Please, enter your choice: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		bool pipeRepair = false;
		GetCorrectData(pipeRepair, true);
		pipe.pipeRepair = pipeRepair;
		cout << "ID: " << pipe.Id << ": ";
		pipe.PrintPipeRepair();
		break;
	}
	case 2:
	{
		return;
	}
	default:
	{
		cout << "Please, enter the correct command!\n" << endl;
		break;
	}
	}
}
istream& operator >> (istream& in, Pipe& newPipe)
{
	newPipe.Id = ++newPipe.maxId;
	cout << "ID: " << newPipe.Id << endl;
	cout << "Enter the name of the pipe: ";
	in.ignore();
	getline(in, newPipe.pipeName);
	cout << "Enter the length of the pipe (in metres): ";
	newPipe.pipeLength = GetCorrectData(100.0, 1200.0);
	cout << "Enter the pipe diameter (in millimetres): ";
	newPipe.pipeDiameter = GetCorrectData(75, 1600);
	cout << "Enter the repair status: ";
	newPipe.pipeRepair = GetCorrectData(0, 1);
	return in;
}
ostream& operator << (ostream& out, const Pipe& newPipe)
{
	if (newPipe.pipeName == "None")
	{
		out << "No pipes available!\n";
	}
	else
	{
		out << "Name: " << newPipe.pipeName << "\tLength: " << newPipe.pipeLength
			<< "\tDiameter: " << newPipe.pipeDiameter << "\tRepair: " << newPipe.pipeRepair << endl;
	}
	return out;
}