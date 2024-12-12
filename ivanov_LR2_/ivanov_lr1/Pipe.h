#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pipe
{
	static int maxId;
	int Id;
	string pipeName = "None";
	double pipeLength = 0.0;
	int pipeDiameter = 0;
	bool pipeRepair = false;

public:
	int GetId();
	string GetName() const;
	bool GetStatus();
	void PrintPipeRepair();

	friend void EditPipe(Pipe& pipe);
	friend ostream& operator << (ostream& out, const Pipe& newPipe);
	friend istream& operator >> (istream& in, Pipe& newPipe);
}; 
