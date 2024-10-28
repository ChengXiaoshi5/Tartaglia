#include <iostream>

using namespace std;

struct Pipe
{
	string pipe_name = "0km";
	double pipe_length = 0.0;
	int pipe_diameter = 0;
	bool pipe_repair = false;
};

struct Station
{
	string station_name = "None";
	int station_workshops = 0;
	int station_act_workshops = 0;
	double station_efficiency = 0.0;
};

Pipe AddPipe()
{
	Pipe new_pipe;
	cout << endl << "Adding a new pipe..." << endl;
	cout << "Enter the name of the pipe: ";
	cin >> new_pipe.pipe_name;
	cout << "Enter the length of the pipe (in metres): ";
	cin >> new_pipe.pipe_length;
	cout << "Enter the pipe diameter (in millimetres): ";
	cin >> new_pipe.pipe_diameter;
	new_pipe.pipe_repair = false;
	return new_pipe;
}

void PrintAddPipe(Pipe new_pipe)
{
	cout << endl << "Info about your pipe..." << endl;
	cout << "Name: " << new_pipe.pipe_name << "\tLength: " << new_pipe.pipe_length
		<< "\tDiameter: " << new_pipe.pipe_diameter << endl;
}

Station AddStation()
{
	Station new_station;
	cout << endl << "Adding a new CS..." << endl;
	cout << "Enter the station name: ";
	cin >> new_station.station_name;
	cout << "Enter the number of workshops: ";
	cin >> new_station.station_workshops;
	cout << "Enter the number of active workshops: ";
	cin >> new_station.station_act_workshops;
	cout << "Enter the station efficiency indicator (from 0 to 1 with tenths): ";
	cin >> new_station.station_efficiency;
	return new_station;
}

void PrintAddStation(Station new_station)
{
	cout << endl << "Info about your CS..." << endl;
	cout << "Name: " << new_station.station_name << "\tWorkshops: " << new_station.station_workshops
		<< "\tActive workshops: " << new_station.station_act_workshops << "\tEfficiency: "
		<< new_station.station_efficiency << endl;
}

int main()
{
	Pipe pipe0;
	Station station0;
	int num = 0;
	while (true) {
		cout << endl << "Menu:" << endl;
		cout << "1) Add pipe" << endl;
		cout << "2) Add a CS" << endl;
		cout << "3) View all objects" << endl;
		cout << "4) Edit pipe" << endl;
		cout << "5) Edit a CS" << endl;
		cout << "6) Save" << endl;
		cout << "7) Download" << endl;
		cout << "0) Exit" << endl;
		cout << endl << "Please, enter the command number: ";
		cin >> num;
		/*while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please, try again!";
			cin >> num;
		}*/
		switch (num)
		{
		case 1:
		{
			pipe0 = AddPipe();
			PrintAddPipe(pipe0);
			break;
		}
		case 2:
		{
			station0 = AddStation();
			PrintAddStation(station0);
			break;
		}
		case 3:
		{
			PrintAddPipe(pipe0);
			PrintAddStation(station0);
			break;
		}
		default:
		{
			cout << endl << "There is no such command, please, try again" << endl;
		}
		}
	}
	return 0;
}