#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <time.h> 
#include "classes.h"


using namespace std;

// Vechicle Methods---------------------------------------------------

Vehicle::Vehicle(int NSegs){
	isready = false;
	exit = rand() % 4;
	cout << "Vechicle is created" << endl;
}

Vehicle::~Vehicle()
{
	//cout << "Vechile exited" << endl;
}

int Vehicle::Getexit()
{
	return exit;
}

// Toll methods-------------------------------------------------------------

Toll::Toll(int NSeg)
{
	Nseg = NSeg;
	cout << "Toll is created" << endl;
}

Toll::~Toll()
{
	cars.clear();
	//cout << "Toll deleted" << endl;
}

void Toll::Createvehicles(int Nseg)
{
	int n = rand() % 20;
	cars.reserve(n);
	for (int i = 0; i < n; i++)
		cars.emplace_back(Vehicle(Nseg));

}

std::vector<Vehicle>& Toll::Getvector()
{
	return cars;
}


// Entrance methods------------------------------------------------

Entrance::Entrance(int Name, int Nseg)
{
	name = Name;
	NSeg = Nseg;
	int n = rand() % 8 + 1;
	tolls.reserve(n);
	for (int i = 0; i < n; i++)
		tolls.emplace_back(Toll(Nseg));

	n = rand() % 8 + 1;
	autotolls.reserve(n);
	autotolls.emplace_back(Toll(Nseg));
	cout << "Entrance is created" << endl;
}

Entrance::~Entrance()
{
	
	//cout << "Entrance is deleted" << endl;
}

void Entrance::Createvehicles()
{
	for (int i = 0; i < tolls.size(); i++)
		tolls[i].Createvehicles(NSeg);
}

int Entrance::Sizeoftolls(){
	return tolls.size();
}

int Entrance::Sizeofautotolls(){
	return autotolls.size();
}

int Entrance::Getname()
{
	return name;
}

std::vector<Toll>& Entrance::Getcarsfromtoll()
{
	return tolls;
}

std::vector<Toll>& Entrance::Getcarsfromautotoll(int i)
{
	return autotolls;
}


//Seg methods----------------------------------------------------------

Seg::Seg(int Ename, int Nseg)
{
	totalcars = 0;
	maxcars = 20;
	i = Nseg;
	g = Ename;
	cout << "Seg is created" << endl;
}

Seg::~Seg()
{
	segcars.clear();
	//cout << "Seg is deleted" << endl;
}

void Seg::Createvehicles()
{
	entrance.Createvehicles();
}

void Seg::Setentrancecars(int k)
{
	int i;
	for (i = 0; i < entrance.Sizeoftolls(); i++) {													//tolls
		for (int g = 0; g < k; g++) {

			if (totalcars == maxcars)
				break;

			if (entrance.Getcarsfromtoll()[i].Getvector().empty())
				break;

			segcars.push_back(entrance.Getcarsfromtoll()[i].Getvector().back());
			totalcars++;
			entrance.Getcarsfromtoll()[i].Getvector().pop_back();	
			cout << "A car entered From regular Tolls" << endl;
		}
		if (totalcars == maxcars)
			break;
	}

	for (i = 0; i < entrance.Sizeofautotolls(); i++) {											//autotolls
		for (int g = 0; g < 2*k; g++) {

			if (totalcars == maxcars) {
				cout << "Delays in Node Entrance"  << endl;
				break;
			}
			if (entrance.Getcarsfromtoll()[i].Getvector().empty())
				break;

			segcars.push_back(entrance.Getcarsfromtoll()[i].Getvector().back());
			totalcars++;
			entrance.Getcarsfromtoll()[i].Getvector().pop_back();
			cout << "A car entered From Automatic Tolls" << endl;
		}

		if (totalcars == maxcars)
			break;
	}
}

int Seg::Gettotalcars(){
	return totalcars;
}

void Seg::Settotalcars(int n)
{
	totalcars = n;
}

int Seg::Getmaxcars()
{
	return maxcars;
}

void Seg::increasetotalcars()
{
	totalcars++;
}

void Seg::decrasetotalcars()
{
	totalcars--;
}

std::vector<Vehicle>& Seg::Getsegcars()
{
	return segcars;
}

//Attiki methods-------------------------------------------------------

Attiki::Attiki(int Nseg)
{
	totalvehicles = 0;
	segs.reserve(Nseg);
	for (int i = 0; i < Nseg; i++)
		segs.emplace_back(Seg{ i, Nseg });

	cout << "Attiki is created" << endl;
}

Attiki::~Attiki()
{
	segs.clear();
	cout << "Attiki is deleted" << endl;
}

void Attiki::Createvehicles()
{
	for (int i = 0; i < segs.size(); i++)
		segs[i].Createvehicles();
}

void Attiki::vechiclesmoving(int k) {
	for (int i = 0; i < segs.size(); i++) {	
		cout << "For the segment " << i << endl;					//enter for tolls
		segs[i].Setentrancecars(k);
	}


	int i, g;

	for (i = 0; i < segs.size() - 1; i++) {											//checks for exit at a specific segment
		for (g = 0; g < segs[i].Getsegcars().size(); g++)
			if (segs[i].Getsegcars()[g].Getexit() == i) {
				segs[i].Getsegcars().erase(segs[i].Getsegcars().begin() + g);
				segs[i].Settotalcars(segs[i].Getsegcars().size());
				segs[i].decrasetotalcars();		//counter decrease
				cout << "A car exited From Node " << i+1 << endl;
			}
	}
		for (g = 0; g < segs.back().Getsegcars().size(); g++) {   
			
			if (segs[i].Getsegcars().empty())
				break;                                                                   // last segment

			segs[i].Getsegcars().erase(segs[i].Getsegcars().begin() + g);
			segs[i].Settotalcars(segs[i].Getsegcars().size());
			segs[i].decrasetotalcars();		//counter decrease
			cout << "A car exited From Last Node"<< endl;
		}

		for (i = 1; i < segs.size(); i++) {											//movement between segments
			int prev = i - 1;

			if (segs[i].Gettotalcars() == segs[i].Getmaxcars())
				break;

			for (int g = 0; g < segs[i].Getmaxcars(); g++) {
				if (segs[prev].Getsegcars().empty())
					break;

				if (segs[i].Gettotalcars() == segs[i].Getmaxcars()) {
					cout << "Delays after Node " << i << endl;
					break;
				}

				segs[i].Getsegcars().push_back(segs[prev].Getsegcars().back());
				segs[prev].Getsegcars().pop_back();
				segs[i].increasetotalcars();
				segs[prev].decrasetotalcars();
				cout << "A car moved From Segment" << prev << " to Segment" << i << endl;
			}

		}
}