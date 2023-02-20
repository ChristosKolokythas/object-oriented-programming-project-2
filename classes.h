//header files

class Vehicle {
	int exit;
	bool isready;

public:
	Vehicle(int NSegs);
	~Vehicle();
	int Getexit();

};

class Toll {
	int Nseg;
	std::vector<Vehicle> cars;

public:
	Toll(int NSeg);
	~Toll();
	void Createvehicles(int NSeg);
	std::vector<Vehicle> &Getvector();
};

class Entrance {
	int name,NSeg;
	std::vector<Toll> tolls;
	std::vector<Toll> autotolls;

public:
	Entrance(int Name, int Nseg);
	~Entrance();
	void Createvehicles();
	int Sizeoftolls();
	int Sizeofautotolls();
	int Getname();
	std::vector<Toll> &Getcarsfromtoll();
	std::vector<Toll> &Getcarsfromautotoll(int i);
};

class Seg {
	int totalcars, maxcars, i, g ;
	Entrance entrance{g, i};
	std::vector<Vehicle> segcars;

public:
	Seg(int Ename, int Nseg);
	~Seg();
	void Createvehicles();
	void Setentrancecars(int k);
	int Gettotalcars();
	void Settotalcars(int n);
	int Getmaxcars();
	void increasetotalcars();
	void decrasetotalcars();
	std::vector<Vehicle> &Getsegcars();
};

class Attiki {
	std::vector<Seg> segs;
	int totalvehicles;

public:
	Attiki(int Nseg);
	~Attiki();
	void Createvehicles();
	void vechiclesmoving(int k);
};
