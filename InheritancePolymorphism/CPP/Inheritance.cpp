#include<bits/stdc++.h>
using namespace std;

class Car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;

    public:
        Car(string brand, string model){
            this->brand = brand;
            this->model = model;
            isEngineOn = false;
            currentSpeed = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << " : Engine started." << endl;
        }

        void stopEngine(){
            isEngineOn = false;
            currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
        }

        void accelerate(){
            if (!isEngineOn) {
                cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;    
        }

        void brake(){
            currentSpeed -= 20;
            if (currentSpeed < 0) currentSpeed = 0;
            cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;    
        }

        virtual ~Car(){}
};

class ManualCar : public Car{
    private:
        int currentGear;

    public:
        ManualCar(string b, string m) : Car(b, m){
            currentGear = 0;
        }

        void shiftGear(int gear){
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;    
        }
};

class ElectricCar : public Car{
    private:
        int batteryLevel;

    public:
        ElectricCar(string b, string m) : Car(b, m){
            batteryLevel = 100;
        }

        void chargeBattery(){
            batteryLevel = 100;
            cout << brand << " " << model << " : Battery fully charged!" << endl;    
        }
};

int main(){
    ManualCar* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1); //specific to manual car
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout << "----------------------" << endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery(); //specific to electric car
    myElectricCar->startEngine(); 
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar; 

    return 0;    
}