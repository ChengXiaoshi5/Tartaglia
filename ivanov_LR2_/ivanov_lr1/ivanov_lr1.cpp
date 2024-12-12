#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "Pipe.h"
#include "Station.h"
#include "Utilities.h"
using namespace std;

template <typename T>
T& SelectElement(unordered_map<int, T>& notes)
{
	int id;
	cout << "Enter ID: ";
	cin >> id;
	while (notes.find(id) == notes.end())
	{
		cout << "Exceeding the number of available elements!" << endl
			<< "Please, try again (number of elements: " << notes.size() << "): ";
	}
	return x;
}

//void FileRecord(Pipe& pipeData, Station& stationData)
//{
//	ofstream fout("info");
//	if (pipeData.pipe_name == "None")
//	{
//		cout << "Nothing to record about pipe!\n";
//	}
//	else
//	{
//		cout << "Info about the pipe is written to a file!\n";
//		if (fout)
//		{
//			fout << "Info about your pipe...\n";
//			fout << pipeData.pipe_name << endl;
//			fout << pipeData.pipe_length << endl;
//			fout << pipeData.pipe_diameter << endl;
//			fout << pipeData.pipe_repair << endl;
//		}
//	}
//	if (stationData.station_name == "None")
//	{
//		cout << "Nothing to record about station!\n";
//	}
//	else
//	{
//		cout << "Info about the station is written to a file!\n";
//		if (fout)
//		{
//			fout << "Info about your station...\n";
//			fout << stationData.station_name << endl;
//			fout << stationData.station_workshops << endl;
//			fout << stationData.station_act_workshops << endl;
//			fout << stationData.station_efficiency << endl;
//		}
//	}
//	fout.close();
//}
//
//void FileOutput(Pipe& pipe_data, Station& station_data)
//{
//	ifstream fin("info");
//	if (fin)
//	{
//		string zero_mean;
//		int pipe_flag = 0;
//		int station_flag = 0;
//		while (getline(fin, zero_mean))
//		{
//			if (zero_mean == "Info about your pipe...")
//			{
//				cout << "\nThe pipe data is obtained from the file!" << endl;
//				cout << "\nInfo about your pipe..." << endl;
//				getline(fin, pipe_data.pipe_name);
//				cout << "Name of the pipe: " << pipe_data.pipe_name << endl;
//				fin >> pipe_data.pipe_length;
//				cout << "Length of the pipe: " << pipe_data.pipe_length << endl;
//				fin >> pipe_data.pipe_diameter;
//				cout << "Diameter of the diameter: " << pipe_data.pipe_diameter << endl;
//				fin >> pipe_data.pipe_repair;
//				cout << "Repair status of the pipe: " << pipe_data.pipe_repair << endl;
//				pipe_flag += 1;
//			}
//			if (zero_mean == "Info about your station...")
//			{
//				cout << "\nThe station data is obtained from the file!" << endl;
//				cout << "\nInfo about your station..." << endl;
//				getline(fin, station_data.station_name);
//				cout << "Name of the station: " << station_data.station_name << endl;
//				fin >> station_data.station_workshops;
//				cout << "Number of workshops: " << station_data.station_workshops << endl;
//				fin >> station_data.station_act_workshops;
//				cout << "Number of active workshops: " << station_data.station_act_workshops << endl;
//				fin >> station_data.station_efficiency;
//				cout << "Station efficiency indicator: " << station_data.station_efficiency << endl;
//				station_flag += 1;
//			}
//		}
//		if (pipe_flag == 0)
//		{
//			cout << "\nNo info about pipe!" << endl;
//		}
//		if (station_flag == 0)
//		{
//			cout << "\nNo info about station!" << endl;
//		}
//		fin.close();
//	}
//}

int main()
{
	Pipe pipe0;
	Station station0;
	unordered_map<int, Pipe> Pipes = {};
	unordered_map<int, Station> Stations = {};
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
		cout << "8) Search" << endl;
		cout << "0) Exit" << endl;
		cout << endl << "Please, enter the command number: ";
		switch (GetCorrectData(0, 8))
		{
		case 1:
		{
			cout << "\n[1] Adding a new pipe..." << endl;
			Pipe pipe0;
			cin >> pipe0;
			Pipes.insert({ pipe0.GetId(), pipe0 });
			break;
		}
		case 2:
		{
			cout << "\n[2] Adding a new CS..." << endl;
			Station station0;
			cin >> station0;
			Stations.insert({ station0.GetId(), station0 });
			break;
		}
		case 3:
		{
			cout << "\n[3] Viewing all objects: " << endl;
			if (Pipes.size() == 0)
				cout << "\nNo pipes have been added!" << endl;
			for (const auto& elem : Pipes)
				cout << elem.second;

			if (Stations.size() == 0)
				cout << "\nNo stations have been added!" << endl;
			for (const auto& elem : Stations)
			{
				cout << elem.second;
			}
			break;
		}
		case 4:
		{
			cout << "\n[4] Edit pipe: " << endl;
			Pipe pipe0 = SelectElement(Pipes);
			EditPipe(pipe0);
			break;
		}
		case 5:
		{
			cout << "\n[5] Edit CS: " << endl;
			Station station0 = SelectElement(Stations);
			EditStation(station0);
			break;
		}
		//case 6:
//{
//	FileRecord(pipe0, station0);
//	break;
//}
//case 7:
//{
//	FileOutput(pipe0, station0);
//	break;
//}
		case 0:
		{
			return false;
			break;
		}
		default:
		{
			cout << endl << "There is no such command, please, try again" << endl;
			break;
		}
		}
	}
	return 0;
