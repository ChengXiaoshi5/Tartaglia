#include "Station.h"
#include "Utilities.h"

int Station::maxId = 0;

int Station::GetId()
{
    return Id;
}

string Station::GetName() const
{
    return stationName;
}

int Station::GetWorkshops() const
{
    return stationWorkshops;
}

int Station::GetActWorkshops() const
{
    return stationActWorkshops;
}

void Station::PrintWorkshops() const
{
    cout << "At the moment " << stationActWorkshops <<
        " out of " << stationWorkshops << " are working" << endl;
}

void EditStation(Station& station)
{
    cout << "Tne number of active workshops will be changed, do you agree?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Please, enter you choice: ";
    switch (GetCorrectData(1, 2))
    {
    case 1:
    {
        cout << "Enter the number of active workshops: ";
        GetCorrectData(1, station.GetWorkshops());
        cout << "ID: " << station.Id << " - ";
        station.PrintWorkshops();
    }
    case 2:
        return;
    default:
    {
        cout << "Please, enter the correct command!\n" << endl;
        break;
    }
    }
}

istream& operator >> (istream& in, Station& newStation)
{
    newStation.Id = ++newStation.maxId;
    cout << "ID: " << newStation.Id << endl;
    cout << "Enter CS name: ";
    in.ignore();
    getline(in, newStation.stationName);
    cout << "Enter the number of workshops: ";
    newStation.stationWorkshops = GetCorrectData(1, 12);
    cout << "Enter the number of active workshops: ";
    newStation.stationActWorkshops = GetCorrectData(1, newStation.stationWorkshops);
    cout << "Enter the efficiency of CS (from 0 to 1 with tenths): ";
    newStation.stationEfficiency = GetCorrectData(0.0, 1.0);
    return in;
}

ostream& operator << (ostream& out, const Station& newStation)
{
    if (newStation.stationName == "None")
    {
        out << "No CS available!\n";
    }
    else
    {
        out << "Name: " << newStation.stationName << "\tWorkshops: " << newStation.stationWorkshops
            << "\tActive workshops: " << newStation.stationActWorkshops << "\tEfficiency: " << newStation.stationEfficiency << endl;
    }
    return out;
}