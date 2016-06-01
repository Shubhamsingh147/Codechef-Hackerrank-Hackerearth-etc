#include <iostream>
#include <stdio.h>
#include <stdc/c++.h>

using namespace std;

#define pi 3.14159265358979323846


double deg2rad(double deg) {
  return (deg * pi / 180);
}
double rad2deg(double rad) {
  return (rad * 180 / pi);
}
double distance(double lat1, double lon1, double lat2, double lon2, char unit = 'K') {
  double theta, dist;
  theta = lon1 - lon2;
  dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
  dist = acos(dist);
  dist = rad2deg(dist);
  dist = dist * 60 * 1.1515;
  switch(unit) {
    case 'M':
      break;
    case 'K':
      dist = dist * 1.609344;
      break;
    case 'N':
      dist = dist * 0.8684;
      break;
  }
  return (dist);
}
int main()
{
	double x1,x2,y1,y2;
	ifstream infile("");
	string line;
	int k = 0;
	int f_no,length;
	double metric;
	string MAC_ADDR_src, type_broadcast, type_security, info1, info2, info3, info4, info5, SSID_dest;

	while (std::getline(infile, line))
	{
		if(k%8 == 1)
	    {	//get input line by line
	    	istringstream iss(line);
	    	iss>>f_no>>metric>>MAC_ADDR_src>>type_broadcast>>type_security>>length>>info1>>info2>>info3>>info4>>info5>>SSID_dest ;
	    	
	    	//insert in map
	    	if(SSID_dest.compare("SSID=Broadcast") != 0)	    		
		    	mp[make_pair(MAC_ADDR_src,SSID_dest.substr(5))] = true;
	 	}
	 	k++;
	}
	x1 = stod (orbits,&sz);
	y1 = stod (orbits,&sz);
	ifstream infile("wiresharkData.txt");
	string line;
	int k = 0;
	int f_no,length;
	double metric;
	string MAC_ADDR_src, type_broadcast, type_security, info1, info2, info3, info4, info5, SSID_dest;

	while (std::getline(infile, line))
	{
		if(k%8 == 1)
	    {	//get input line by line
	    	istringstream iss(line);
	    	iss>>f_no>>metric>>MAC_ADDR_src>>type_broadcast>>type_security>>length>>info1>>info2>>info3>>info4>>info5>>SSID_dest ;
	    	
	    	//insert in map
	    	if(SSID_dest.compare("SSID=Broadcast") != 0)	    		
		    	mp[make_pair(MAC_ADDR_src,SSID_dest.substr(5))] = true;
	 	}
	 	k++;
	}
	x2 = stod (orbits,&sz);
	y2 = stod (orbits,&sz);

}