
#include <cstdlib>
#include <cstring>

import std;


using namespace std ;
class SmartDevice{
public:
	SmartDevice(){
		name=(char*)malloc(sizeof(char)*10);
		strcpy(name, "default");
		type=(char*)malloc(sizeof(char)*10);
		strcpy(name, "default");
		status=false;
		powerConsumption=0;
		usageCount=0;
	}

	SmartDevice(const char* nameStart,const char* typeStart,int powerConsumptionStart){
		name=(char*)malloc(sizeof(char)*10);
		strcpy(name, nameStart);
		type=(char*)malloc(sizeof(char)*10);
		strcpy(name, typeStart);
		status=false;
		powerConsumption=powerConsumptionStart;
		usageCount=0;	
	}
	
	SmartDevice(SmartDevice *sd){
		name=(char*)malloc(sizeof(char)*10);
	strcpy(name, sd->name);
		type=(char*)malloc(sizeof(char)*10);
		strcpy(name,sd->type );
		status=sd->status;
		powerConsumption=sd->powerConsumption;
		usageCount=sd->usageCount;	
	}
	~SmartDevice(){
		free(name);
		free(type);
	}
	void togglePower(){
		status=!status;
		cout<<status;
	}
	void showStatus() const{
		println("{} {} {} {} {} {}",name,type,status,powerConsumption,usageCount,deviceCount);
		usageCount++;
	}
	int getUsageCount() const{
		println("{}",usageCount);
		return usageCount;
	}
	int getDeviceCount() const{
		print("{}",usageCount);
		return deviceCount;
	}
	const char* getName() const{
		print("{}",name);
		return name;	
	}
	void setName(const char* newName){
		strcpy(name,newName);	
	}
	private:
	char* name;
	char* type;
	bool status;
	int powerConsumption;
	mutable	int usageCount;

	int deviceCount; 
};
class SmartHome{
	public:
	SmartHome(const char* name,int maxDevices){
		homeName=(char*)malloc(sizeof(char)*10);
		strcpy(homeName,name);
		devices=(SmartDevice*)malloc(sizeof(SmartDevice)*maxDevices);
		deviceindex=0;
	}
	~SmartHome(){
		free(homeName);
		free(devices);
	}
	void addDevice(SmartDevice sd){
		if(deviceindex>=maxdevices)return;
		devices[deviceindex]=sd;
		deviceindex++;
	}
	void removeDevice(const char* name){
		int i=0;
		while (i<maxdevices && !strcmp(name,devices[i].getName()))i++;
		if(!strcmp(name,devices[i].getName())){
			for (;i<maxdevices-1;i++) {
				devices[i]=devices[i+1];		
			}	
			deviceindex--;
		}			

		

		
	}
	void showDevices(){
		for (int i =0;i< maxdevices;i++) {
			print("{} {} {} ",devices[i].getName(),devices[i].getDeviceCount(),devices[i].getUsageCount());
		}		
	}
	private:
	char* homeName;
	SmartDevice* devices;
	int deviceindex;
	int maxdevices;
};
int main(){
	char k='k';
	char* p= &k;
	const char* bal=p;
	print("{}",bal);
	SmartDevice sd{};

	return 0;
}
