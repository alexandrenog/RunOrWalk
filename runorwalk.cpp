#include <iostream>
#include <vector>
using namespace std;
class Drop{
    public:
    double x,y;
    bool floor,wet;
	  Drop(double x, double y){
        floor = wet = false;
        this->x=x;
        this->y=y;
    }
};
double  ammount_drops(double walk_speed){
	double  rain_speed=9.0; //meters per second	
	double  adms=500.0; //ammount of drops per meter per second
	double  person_depth=0.35;
	double  person_height=1.7;
	double  x=-4.0;
	double  xfinal=30.0+person_depth/2.0;
	double  dt=0.01;
	vector <Drop*> drops;
	double  how_wet=0.0;
    double  times = (int)(dt*adms*xfinal);
	while(x<=xfinal){
		for(int i=0; i < times; i++){
			drops.push_back(new Drop((double)rand()/RAND_MAX*xfinal,2.5)); 
		}
		for(auto & dr : drops){
            Drop d = *dr;
			d.y-=rain_speed*dt;
			if (d.y<=0)
                d.floor = true;
			if (d.y>0 && d.y<person_height && d.x>x-person_depth && d.x<x+person_depth){
                d.wet = true; 
                how_wet+=1;
            }
            *dr=d;
        }
        for(int i = drops.size()-1;i>=0;i--){
            if(drops[i]->floor || drops[i]->wet){
                drops.erase (drops.begin()+i);
            }
        }
        x+=walk_speed*dt;
	}

	return (how_wet/adms);
}

int main(){
  cout<<"Walk on rain wetness = " << ammount_drops(1.4)<<endl;
  cout<<" Run on rain wetness = " << ammount_drops(5.0)<<endl;
}

//compile with lang++-7 -pthread -std=c++17 -o runorwalkcpp runorwalk.cpp
