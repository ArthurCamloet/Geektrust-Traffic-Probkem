#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits>

using namespace std;

class VEHICLES
{
    public:
        VEHICLES(float vspeed, float timeforcrater)
        {
            speed = vspeed;
            cratercross = timeforcrater;
        }
        float speed, cratercross;
};

class ORBIT
{
    public:
        float trafficspeed;
        ORBIT(float mspeed, float noofcraters)
        {
            distance = mspeed;
            craters = noofcraters;
        }
        void weathereffect(char weather[10])
        {
            if(strcmpi(weather,"sunny")==0)
                craters=craters*0.9;
            else if(strcmpi(weather,"rainy")==0)
                craters=craters*1.2 ;
        }
        float distance, craters ;
};

float fastestway(VEHICLES &v, ORBIT &o)
{
    float time, maxspeed;
    if(v.speed>=o.trafficspeed)
        maxspeed=o.trafficspeed;
    else
        maxspeed=v.speed;

    time=(o.distance/maxspeed*60)+(o.craters*v.cratercross);
    return time;
}

int main()
{
    char currentweather[10];

    VEHICLES trans[3]={VEHICLES(10,2),VEHICLES(12,1),VEHICLES(20,3)};

    ORBIT orbit[2]={ORBIT(18,20),ORBIT(20,10)};

    cout<<"enter weather :";
    gets(currentweather);
    cout<<"enter traffic speed of orbit1 :";
    cin>>orbit[0].trafficspeed;
    cout<<"enter traffic speed of orbit2 :";
    cin>>orbit[1].trafficspeed;

    orbit[0].weathereffect(currentweather);
    orbit[1].weathereffect(currentweather);

    float smallest;
    int orb, veh;

    smallest = numeric_limits<int>::max();

    for(int i=0;i<2;i++)
    { for(int j=0;j<3;j++)
      {

        if(strcmpi(currentweather,"sunny")==0)
        { if(fastestway(trans[j],orbit[i])<smallest)
            {smallest = fastestway(trans[j],orbit[i]);
              veh = j+1; orb = i+1;}
        }
        else if(strcmpi(currentweather,"rainy")==0)
        {if(fastestway(trans[j],orbit[i])<smallest)
            {smallest = fastestway(trans[j],orbit[i]);
              veh = j+1; orb = i+1;}
        }
        else if(strcmpi(currentweather,"windy")==0)
        {if(fastestway(trans[j],orbit[i])<smallest)
            {smallest = fastestway(trans[j],orbit[i]);
              veh = j+1; orb = i+1;}

        }

        else
        {
           cout<<"wrong input!!!!";
           return 0;
        }
      }
    }

        if(veh==1)
            cout << "vehicle bike on orbit"<<orb;
        else if(veh==2)
            cout << "vehicle tuktuk on orbit"<<orb;
        else if(veh==3)
            cout<<"vehicle car on orbit"<<orb;

return 0;
}
