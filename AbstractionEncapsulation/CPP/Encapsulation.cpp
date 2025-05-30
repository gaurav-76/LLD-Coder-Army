#include<bits/stdc++.h>
using namespace std;

// Field and methods encapsulated in a single class
class SportsCar{

    // data security - make them private 
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

        //Introduce new variable to explain setters
        string tyreCompany;

    public:
        SportsCar(string brand, string mode){
            this->brand = brand;
            this->model = model;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
        }

        int getSpeed(){
            return currentSpeed;
        }

        string getTyreCompany(){
            return tyreCompany;
        }

        void setTyreCompany(string tyreCompany){
            // we can add validation here
            // whether that tyre company exists or not
            this->tyreCompany = tyreCompany;
        }

        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << " : Engine starts with a roar!" << endl;
        } 

        void shiftGear(int gear){

            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
                return;
            }
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
        }

        void accelerate(){

            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
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

        void stopEngine(){
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout << brand << " " << model << " : Engine turned off." << endl;
        }
};

int main(){

    SportsCar* mySportsCar = new SportsCar("Ford", "Mustang");

    mySportsCar->startEngine();
    mySportsCar->shiftGear(1);
    mySportsCar->accelerate();
    mySportsCar->shiftGear(2);
    mySportsCar->accelerate();
    mySportsCar->brake();
    mySportsCar->stopEngine();

    //Setting arbitrary value to speed.
    // mySportsCar->currentSpeed = 500;

    // cout << "Current Speed of My Sports Car is set to " << mySportsCar->currentSpeed << endl;

    cout << "Current Speed of My Sports Car is " << mySportsCar->getSpeed() << endl;

    delete mySportsCar;    

    return 0;
}